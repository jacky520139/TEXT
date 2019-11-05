#ifndef __RF_24L01P_H
#define __RF_24L01P_H
#include "ALL_Includes.h"
/*----------------------BK2425 SPI Command-----------------------------------*/
#define Read_Reg	 0x00		// Define read command to register
#define Write_Reg    0x20		// Define write command to register
#define RD_RX_PLOAD  0x61		// Read RX-payload 1-32 bytes spi command  Define RX payload register address
#define WR_TX_PLOAD  0xA0		// Write RX-payload 1-32 bytes spi command Define TX payload register address
#define FLUSH_TX     0xE1		// Define flush TX register command
#define FLUSH_RX     0xE2		// Define flush RX register command
#define REUSE_TX_PL  0xE3		// Define reuse TX payload register command
#define ACTIVATE     0x50		// 
#define NOP          0xFF		// Define No Operation, might be used to read status register

/*----------------------BK2425 Register Address------------------------------*/
#define CONFIG       0x00  		// 'Config' register address
#define EN_AA        0x01  		// 'Enable Auto Acknowledgment' register address
#define EN_RXADDR    0x02  		// 'Enabled RX addresses' register address
#define SETUP_AW     0x03  		// 'Setup address width' register address
#define SETUP_RETR   0x04  		// 'Setup Auto. Retrans' register address
#define RF_CH        0x05  		// 'RF channel' register address
#define RF_SETUP     0x06  		// 'RF setup' register address
#define STATUS       0x07  		// 'Status' register address
#define OBSERVE_TX   0x08  		// 'Observe TX' register address
#define CD           0x09  		// 'Carrier Detect' register address
#define RX_ADDR_P0   0x0A  		// 'RX address pipe0' register address
#define RX_ADDR_P1   0x0B  		// 'RX address pipe1' register address
#define RX_ADDR_P2   0x0C  		// 'RX address pipe2' register address
#define RX_ADDR_P3   0x0D  		// 'RX address pipe3' register address
#define RX_ADDR_P4   0x0E  		// 'RX address pipe4' register address
#define RX_ADDR_P5   0x0F  		// 'RX address pipe5' register address
#define TX_ADDR      0x10  		// 'TX address' register address
#define RX_PW_P0     0x11  		// 'RX payload width, pipe0' register address
#define RX_PW_P1     0x12  		// 'RX payload width, pipe1' register address
#define RX_PW_P2     0x13  		// 'RX payload width, pipe2' register address
#define RX_PW_P3     0x14  		// 'RX payload width, pipe3' register address
#define RX_PW_P4     0x15  		// 'RX payload width, pipe4' register address
#define RX_PW_P5     0x16  		// 'RX payload width, pipe5' register address
#define FIFO_STATUS  0x17  		// 'FIFO Status Register' register address

extern uint8_t RF_Channel_DMFlag;

void BK2425_Check(void);

void SwitchCFG(char _cfg);
void RF_address_set(uint8_t *add_buf);
void SwitchToRxMode(void);
void BK2425_Init(void);

void RF_Read_Data_From_RXFIFO(void);
//void Receive_Data_Process(void);
uint8_t Remote_Check(void);
#endif	/* __RF_24L01P_H */
