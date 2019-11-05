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
// Register values.
//u8 registers[REGISTER_COUNT];

//void registers_init(void)
//// Function to initialize all registers.
//{
//    // Initialize all registers to zero.
//    memset(&registers[0], 0, REGISTER_COUNT);

//    // Set device and software identification information.
////    registers_write_byte(REG_DEVICE_TYPE, OPENSERVO_DEVICE_TYPE);//写入伺服类型
////    registers_write_byte(REG_DEVICE_SUBTYPE, OPENSERVO_DEVICE_SUBTYPE);//定义子类型
////    registers_write_byte(REG_VERSION_MAJOR, SOFTWARE_VERSION_MAJOR);//写入版本号
////    registers_write_byte(REG_VERSION_MINOR, SOFTWARE_VERSION_MINOR);

//    // Restore the read/write protected registers from EEPROM.  If the
//    // EEPROM fails checksum this function will return zero and the
//    // read/write protected registers should be initialized to defaults.
//    if (!eeprom_restore_registers())
//    {
//        // Reset read/write protected registers to zero.
//        memset(&registers[MIN_WRITE_PROTECT_REGISTER], WRITE_PROTECT_REGISTER_COUNT + REDIRECT_REGISTER_COUNT, REGISTER_COUNT);

//        registers_defaults();
//    }
////		 pwm_registers_defaults();
//}


//void registers_defaults(void)
//// Reset safe read/write registers to defaults.
//{

//    pwm_registers_defaults();


//    pid_registers_defaults();
//}


//u16 registers_read_word(u8 address_hi, u8 address_lo)
//// Read a 16-bit word from the registers.
//// Interrupts are disabled during the read.
//{
////    u8 sreg;
//    u16 value;


//    // Clear interrupts.
////    asm volatile ("in %0,__SREG__\n\tcli\n\t" : "=&r" (sreg));
//    EA=0;
//    // Read the registers.
//    value = (registers[address_hi] << 8) | registers[address_lo];

//    // Restore status.
////    asm volatile ("out __SREG__,%0\n\t" : : "r" (sreg));
// EA=1;
//    return value;
//}


//void registers_write_word(u8 address_hi, u8 address_lo, u16 value)
//// Write a 16-bit word to the registers.
//// Interrupts are disabled during the write.
//{
////    u8 sreg;

//    // Clear interrupts.
////    asm volatile ("in %0,__SREG__\n\tcli\n\t" : "=&r" (sreg));
//    EA=0;
//    // Write the registers.
//    registers[address_hi] = value >> 8;
//    registers[address_lo] = value;
//    EA=1;
//    // Restore status.
////    asm volatile ("out __SREG__,%0\n\t" : : "r" (sreg));
//}


