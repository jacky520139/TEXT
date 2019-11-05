/*
    Copyright (c) 2006 Michael P. Thompson <mpthompson@gmail.com>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use, copy,
    modify, merge, publish, distribute, sublicense, and/or sell copies
    of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.

    $Id$
*/


#include "ALL_Includes.h"
//////////////////////////////////////////////////////////////////
///////////////// Driver Buffer Definitions //////////////////////
//////////////////////////////////////////////////////////////////
// 1,2,4,8,16,32,64,128 or 256 bytes are allowed buffer sizes

#define TWI_RX_BUFFER_SIZE (4)
#define TWI_RX_BUFFER_MASK (TWI_RX_BUFFER_SIZE - 1)

#if (TWI_RX_BUFFER_SIZE & TWI_RX_BUFFER_MASK)
        #error TWI RX buffer size is not a power of 2
#endif

#define TWI_CHK_WRITE_BUFFER_SIZE (16)
#define TWI_CHK_WRITE_BUFFER_MASK (TWI_CHK_WRITE_BUFFER_SIZE - 1)

#if (TWI_CHK_WRITE_BUFFER_SIZE & TWI_CHK_WRITE_BUFFER_MASK)
        #error TWI CHK WRITE buffer size is not a power of 2
#endif

//////////////////////////////////////////////////////////////////

// TWI acknowledgment values.
#define TWI_ACK                             (0x00)
#define TWI_NAK                             (0x01)

// Data state values.
#define TWI_DATA_STATE_COMMAND              (0x00)
#define TWI_DATA_STATE_DATA                 (0x01)
#if TWI_CHECKED_ENABLED
#define TWI_DATA_STATE_CHECKED_COUNTING     (0x02)
#define TWI_DATA_STATE_CHECKED_ADDRESS      (0x03)
#define TWI_DATA_STATE_CHECKED_DATA         (0x04)
#endif

static volatile u8 twi_address;
static volatile u8 twi_data_state;
static volatile u8 twi_overflow_state;

static volatile u8 twi_rxhead;
static volatile u8 twi_rxtail;
static u8 twi_rxbuf[TWI_RX_BUFFER_SIZE];

#if TWI_CHECKED_ENABLED
static u8 twi_chk_count;            // current byte in transaction当前字节
static u8 twi_chk_count_target;     // How many bytes are we reading/writing
static u8 twi_chk_sum;              // Accumulator for checksum
static u8 twi_chk_write_buffer[TWI_CHK_WRITE_BUFFER_SIZE];
#endif

static u8 twi_registers_read(u8 address)
// Read the byte from the specified register.  This function handles the
// reading of special registers such as unused registers, redirect and
// redirected registers.
//从指定寄存器读取字节。此函数处理特殊寄存器的读取，如未使用的寄存器、重定向和重定向寄存器。
{
    // Mask the most significant bit of the address.
    address &= 0x7F;

    // Are we reading a normal register?我们在读普通的注册吗？
    if (address <= MAX_WRITE_PROTECT_REGISTER)
    {
        // Yes. Complete the read.
        return registers_read_byte(address);
    }

    // Are we reading an unused register.
    if (address <= MAX_UNUSED_REGISTER)
    {
        // Block the read.
        return 0;
    }

    // Are we reading a redirect register.
    if (address <= MAX_REDIRECT_REGISTER)
    {
        // Yes. Complete the read.
        return registers_read_byte(address - (MIN_REDIRECT_REGISTER - MIN_UNUSED_REGISTER));
    }

    // Are we reading a redirected register?
    if (address <= MAX_REDIRECTED_REGISTER)
    {
        // Adjust address to reference appropriate redirect register.
        address = MIN_REDIRECT_REGISTER  + (address - MIN_REDIRECTED_REGISTER);

        // Get the address from the redirect register.
        address = registers_read_byte(address - (MIN_REDIRECT_REGISTER - MIN_UNUSED_REGISTER));

        // Prevent infinite recursion.
        if (address <= MAX_REDIRECT_REGISTER)
        {
            // Recursively read redirected address.
//            return twi_registers_read(address);
//					return twi_registers_read(address);
        }
    }

    // All other reads are blocked.
    return 0;
}


static void twi_registers_write(u8 address, u8 Data)
// Write non-write protected registers.  This function handles the
// writing of special registers such as unused registers, redirect and
// redirected registers.
{
    // Mask the most significant bit of the address.
    address &= 0x7F;

    // Are we writing a read only register?
    if (address <= MAX_READ_ONLY_REGISTER)
    {
        // Yes. Block the write.
        return;
    }

    // Are we writing a read/write register?
    if (address <= MAX_READ_WRITE_REGISTER)
    {
        // Yes. Complete the write.
        registers_write_byte(address, Data);

        return;
    }

    // Is writing to the upper registers disabled?
    if (registers_is_write_disabled())
    {
        // Yes. Block the write.
        return;
    }

    // Are we writing a write protected register?
    if (address <= MAX_WRITE_PROTECT_REGISTER)
    {
        // Yes. Complete the write if writes are enabled.
        registers_write_byte(address, Data);

        return;
    }

    // Are we writing an unused register.
    if (address <= MAX_UNUSED_REGISTER)
    {
        // Yes. Block the write.
        return;
    }


    // Are we writing a redirect register.
    if (address <= MAX_REDIRECT_REGISTER)
    {
        // Yes. Complete the write.
        registers_write_byte(address - (MIN_REDIRECT_REGISTER - MIN_UNUSED_REGISTER), Data);

        return;
    }

    // Are we writing a redirected register?
    if (address <= MAX_REDIRECTED_REGISTER)
    {
        // Adjust address to reference appropriate redirect register.调整地址以引用适当的重定向寄存器。
        address = MIN_REDIRECT_REGISTER  + (address - MIN_REDIRECTED_REGISTER);

        // Get the address from the redirect register.从重定向寄存器获取地址
        address = registers_read_byte(address - (MIN_REDIRECTED_REGISTER - MIN_UNUSED_REGISTER));

        // Prevent infinite recursion.防止无限递归
        if (address <= MAX_REDIRECT_REGISTER)
        {
            // Recursively write redirected address.
//            twi_registers_write(address, Data);

            return;
        }
    }

    // All other writes are blocked.
    return;
}


#if TWI_CHECKED_ENABLED
static void twi_write_buffer(void)
// 将接收缓冲区写入内存。
{
    // 循环写入缓冲区内的数据。
    for (twi_chk_count = 0; twi_chk_count < twi_chk_count_target; twi_chk_count++)
    {
        // 将数据写入地址寄存器
        twi_registers_write(twi_address, twi_chk_write_buffer[twi_chk_count & TWI_CHK_WRITE_BUFFER_MASK]);

        // 增量到下一个地址
        ++twi_address;
    }
}
#endif


static u8 twi_read_data()
// Handle checked/non-checked read of data.
//处理检查/未检查的数据读取。
{
    // By default read the data to be returned.
    u8 Data = twi_registers_read(twi_address);

#if TWI_CHECKED_ENABLED
    // Are we handling checked data?
    if (twi_data_state == TWI_DATA_STATE_CHECKED_DATA)
    {
        // Have we reached the end of the read?
        if (twi_chk_count < twi_chk_count_target)
        {
            // Add the data to the check sum.
            twi_chk_sum += Data;

            // Increment the check sum data count.
            ++twi_chk_count;

            // Increment the address.
            ++twi_address;
        }
        else
        {
            // Replace the data with the checksum.
            Data = twi_chk_sum;
        }
    }
    else
    {
        // Increment the address.
        ++twi_address;
    }
#else
    // Increment the address.
    ++twi_address;
#endif

    return Data;
}


static u8 twi_write_data(u8 Data)
// Handle checked/non-checked write of data or command.
{
    // By default, return ACK from write.
    u8 ack = TWI_ACK;

    // Handle the write depending on the write state.
    switch (twi_data_state)
    {
        case TWI_DATA_STATE_COMMAND:

            // This is a byte.
            if (Data < TWI_CMD_RESET)
            {
                // Capture the address.
                twi_address = Data;

                // Update the write state.
                twi_data_state = TWI_DATA_STATE_DATA;
            }
#if TWI_CHECKED_ENABLED
            else if (Data == TWI_CMD_CHECKED_TXN)
            {
                // Update the write state.
                twi_data_state = TWI_DATA_STATE_CHECKED_COUNTING;
            }
#endif
            else
            {
                // Handle the command asynchronously.
                twi_rxhead = (twi_rxhead + 1) & TWI_RX_BUFFER_MASK;
                twi_rxbuf[twi_rxhead] = Data;
            }

            break;

        case TWI_DATA_STATE_DATA:

            // Write the data to the addressed register.
            twi_registers_write(twi_address, Data);

            // Increment to the next address.
            ++twi_address;

            break;

#if TWI_CHECKED_ENABLED
        case TWI_DATA_STATE_CHECKED_COUNTING:

            // Read in the count (Make sure it's less than the max count)
            // and start the checksum
            twi_chk_sum = twi_chk_count_target = Data & TWI_CHK_WRITE_BUFFER_MASK;

            // Clear the checksum and count.
            twi_chk_count = 0;

            // Update the write state.
            twi_data_state = TWI_DATA_STATE_CHECKED_ADDRESS;

            break;

        case TWI_DATA_STATE_CHECKED_ADDRESS:

            // Capture the address and include it in the checksum
            twi_chk_sum += twi_address = Data;

            // Update the write state.
            twi_data_state = TWI_DATA_STATE_CHECKED_DATA;

            break;

        case TWI_DATA_STATE_CHECKED_DATA:

            // Have we reached the end of the write?
            if (twi_chk_count < twi_chk_count_target)
            {
                // No. Write the data to the checksum buffer
                twi_chk_write_buffer[twi_chk_count & TWI_CHK_WRITE_BUFFER_MASK] = Data;

                // Add the data to the checksum.
                twi_chk_sum += Data;

                // Increment the check sum data count.
                ++twi_chk_count;
            }
            else
            {
                // Verify the checksum
                if (Data == twi_chk_sum)
                {
                    // Write the checksum buffer to addressed registers.
                    twi_write_buffer();
                }
                else
                {
                    // Checksum failed so return NACK.
                    ack = TWI_NAK;
                }
            }

            break;
#endif
    }

    return ack;
}


void twi_slave_init(u8 slave_address)
// Initialise USI for TWI slave mode.
{
    // Flush the buffers.
    twi_rxtail = 0;
    twi_rxhead = 0;

    // Set own TWI slave address.
//    TWAR = slave_address << 1;

//    // Default content = SDA released.
//    TWDR = 0xFF;

//    // Initialize the TWI interrupt to wait for a new event.
//    TWCR = (1<<TWEN) |                                  // Keep the TWI interface enabled.
//           (1<<TWIE) |                                  // Keep the TWI interrupt enabled.
//           (0<<TWSTA) |                                 // Don't generate start condition.
//           (0<<TWSTO) |                                 // Don't generate stop condition.
//           (1<<TWINT) |                                 // Clear the TWI interrupt.
//           (1<<TWEA) |                                  // Acknowledge the data.
//           (0<<TWWC);                                   //
}


u8 twi_receive_byte(void)
// Returns a byte from the receive buffer. Waits if buffer is empty.
{
    // Wait for data in the buffer.
    while (twi_rxhead == twi_rxtail);

    // Calculate buffer index.
    twi_rxtail = (twi_rxtail + 1 ) & TWI_RX_BUFFER_MASK;

    // Return data from the buffer.
    return twi_rxbuf[twi_rxtail];
}


u8 twi_data_in_receive_buffer(void)
// Check if there is data in the receive buffer.
{
    // Return 0 (FALSE) if the receive buffer is empty.
    return (twi_rxhead != twi_rxtail);
}


SIGNAL(SIG_TWI)
// Handle the TWI interrupt condition.
{
	/*
    switch (TWSR)
    {
        // Own SLA+R has been received; ACK has been returned.
        case TWI_STX_ADR_ACK:
        // Data byte in TWDR has been transmitted; ACK has been received.
        case TWI_STX_DATA_ACK:

            // Read the checked/non-checked data.
            TWDR = twi_read_data();

            // Data byte will be transmitted and ACK should be received.
            TWCR = (1<<TWEN) |                              // Keep the TWI interface enabled.
                   (1<<TWIE) |                              // Keep the TWI interrupt enabled.
                   (0<<TWSTA) |                             // Don't generate start condition.
                   (0<<TWSTO) |                             // Don't generate stop condition.
                   (1<<TWINT) |                             // Clear the TWI interrupt.
                   (1<<TWEA) |                              // Acknowledge the data.
                   (0<<TWWC);                               //
            break;

        // Data byte in TWDR has been transmitted; NOT ACK has been received.
        case TWI_STX_DATA_NACK:
        // Last data byte in TWDR has been transmitted (TWEA = "0"); ACK has been received.
        case TWI_STX_DATA_ACK_LAST_BYTE:

            // Switched to the not addressed slave mode; own SLA will be recognized.
            TWCR = (1<<TWEN) |                              // Keep the TWI interface enabled.
                   (1<<TWIE) |                              // Keep the TWI interrupt enabled.
                   (0<<TWSTA) |                             // Don't generate start condition.
                   (0<<TWSTO) |                             // Don't generate stop condition.
                   (1<<TWINT) |                             // Clear the TWI interrupt.
                   (1<<TWEA) |                              // Acknowledge the data.
                   (0<<TWWC);                               //
            break;

        // Own SLA+W has been received; ACK has been returned.
        case TWI_SRX_ADR_ACK:

            // Reset the data state.
            twi_data_state = TWI_DATA_STATE_COMMAND;

            // Data byte will be received and ACK will be returned.
            TWCR = (1<<TWEN) |                              // Keep the TWI interface enabled.
                   (1<<TWIE) |                              // Keep the TWI interrupt enabled.
                   (0<<TWSTA) |                             // Don't generate start condition.
                   (0<<TWSTO) |                             // Don't generate stop condition.
                   (1<<TWINT) |                             // Clear the TWI interrupt.
                   (1<<TWEA) |                              // Acknowledge the data.
                   (0<<TWWC);                               //

            break;

        // Previously addressed with own SLA+W; data has been received; ACK has been returned.
        case TWI_SRX_ADR_DATA_ACK:

            // Write the data.
            twi_write_data(TWDR);

            // Next data byte will be received and ACK will be returned.
            TWCR = (1<<TWEN) |                          // Keep the TWI interface enabled.
                   (1<<TWIE) |                          // Keep the TWI interrupt enabled.
                   (0<<TWSTA) |                         // Don't generate start condition.
                   (0<<TWSTO) |                         // Don't generate stop condition.
                   (1<<TWINT) |                         // Clear the TWI interrupt.
                   (1<<TWEA) |                          // Acknowledge the data.
                   (0<<TWWC);                           //

            break;

        // Previously addressed with own SLA+W; data has been received; NOT ACK has been returned.
        case TWI_SRX_ADR_DATA_NACK:
        // A STOP condition or repeated START condition has been received while still addressed as Slave.
        case TWI_SRX_STOP_RESTART:

             // Switch to the not addressed slave mode; own SLA will be recognized.
             TWCR = (1<<TWEN) |                              // Keep the TWI interface enabled.
                    (1<<TWIE) |                              // Keep the TWI interrupt enabled.
                    (0<<TWSTA) |                             // Don't generate start condition.
                    (0<<TWSTO) |                             // Don't generate stop condition.
                    (1<<TWINT) |                             // Clear the TWI interrupt.
                    (1<<TWEA) |                              // Acknowledge the data.
                    (0<<TWWC);                               //

            break;

        // Bus error due to an illegal START or STOP condition.
        case TWI_BUS_ERROR:

            // Only the internal hardware is affected, no STOP condition is sent on the bus.
            // In all cases, the bus is released and TWSTO is cleared.
            TWCR = (1<<TWEN) |                              // Keep the TWI interface enabled.
                   (1<<TWIE) |                              // Keep the TWI interrupt enabled.
                   (0<<TWSTA) |                             // Don't generate start condition.
                   (1<<TWSTO) |                             // Don't generate stop condition.
                   (1<<TWINT) |                             // Clear the TWI interrupt.
                   (1<<TWEA) |                              // Acknowledge the data.
                   (0<<TWWC);                               //
            break;

        // No relevant state information available; TWINT="0".
        case TWI_NO_STATE:

            // No action required.
            break;

        default:

            // Reset the TWI interrupt to wait for a new event.
            TWCR = (1<<TWEN) |                                  // Keep the TWI interface enabled.
                   (1<<TWIE) |                                  // Keep the TWI interrupt enabled.
                   (0<<TWSTA) |                                 // Don't generate start condition.
                   (0<<TWSTO) |                                 // Don't generate stop condition.
                   (1<<TWINT) |                                 // Clear the TWI interrupt.
                   (1<<TWEA) |                                  // Acknowledge the data.
                   (0<<TWWC);                                   //
            break;
    }
		*/
}


