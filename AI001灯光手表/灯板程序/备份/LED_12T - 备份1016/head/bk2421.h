
//#include	"STM8S103F.h" 
#ifndef __BK2421__
#define __BK2421__

#define CustomerID			0x8001
#define	Factory_ID			'T'
//#define	CRC_Mode

#define		Up_Key	0x20
#define		Dn_Key	0x10

//1			2			3			4			5			6			7		:SIP
//5,		4,		2,		1,		20,		8,		6		:TSSOP
//PA2,	PA1,	PD6,	PD5,	PD4,	Vss,	Vcc	:Name
//MISO,	MOSI,	CSK,	CSN,	CE,		Vss,	Vcc
//  _Bool	CE		@PD_ODR:4;
//  _Bool	CSN		@PD_ODR:5;
//  _Bool	SCK		@PD_ODR:6;
//  _Bool	MOSI	@PA_ODR:1;
//  _Bool	MISO	@PA_IDR:2;
  
//  _Bool	BackLight	@PD_ODR:2;
//#define		BackLight_Off	(PD_ODR	|=	0x04)
//#define		BackLight_On	(PD_ODR	&=	~0x04)
 // _Bool	IRQ		@PC_IDR:3;
 // _Bool	Led		@PD_ODR:1;


#define TRUE 1
#define FALSE 0


#define sBitCE   (1<<3)
#define BitCE_bit   (3)	

#define MAX_PACKET_LEN  32// max value is 32


//************************FSK COMMAND and REGISTER****************************************//
// SPI(BK2421) commands
#define READ_REG        0x00  // Define read command to register
#define WRITE_REG       0x20  // Define write command to register
#define RD_RX_PLOAD     0x61  // Define RX payload register address
#define WR_TX_PLOAD     0xA0  // Define TX payload register address
#define FLUSH_TX        0xE1  // Define flush TX register command
#define FLUSH_RX        0xE2  // Define flush RX register command
#define REUSE_TX_PL     0xE3  // Define reuse TX payload register command
#define W_TX_PAYLOAD_NOACK_CMD	0xb0
#define W_ACK_PAYLOAD_CMD	0xa8//¼ÓÔØÓ¦´ðÃüÁî
#define ACTIVATE_CMD		0x50
#define R_RX_PL_WID_CMD		0x60
#define NOP             0xFF  // Define No Operation, might be used to read status register

// SPI(BK2421) registers(addresses)
#define CONFIG          0x00  // 'Config' register address
#define EN_AA           0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR       0x02  // 'Enabled RX addresses' register address
#define SETUP_AW        0x03  // 'Setup address width' register address
#define SETUP_RETR      0x04  // 'Setup Auto. Retrans' register address
#define RF_CH           0x05  // 'RF channel' register address
#define RF_SETUP        0x06  // 'RF setup' register address
#define STATUS          0x07  // 'Status' register address
#define OBSERVE_TX      0x08  // 'Observe TX' register address
#define CD              0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0      0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1      0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2      0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3      0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4      0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5      0x0F  // 'RX address pipe5' register address
#define TX_ADDR         0x10  // 'TX address' register address
#define RX_PW_P0        0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1        0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2        0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3        0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4        0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5        0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS     0x17  // 'FIFO Status Register' register address
#define PAYLOAD_WIDTH   0x1f  // 'payload length of 256 bytes modes register address

//interrupt status
#define STATUS_RX_DR 0x40
#define STATUS_TX_DS 0x20
#define STATUS_MAX_RT 0x10

#define STATUS_TX_FULL 0x01

//FIFO_STATUS
#define FIFO_STATUS_TX_REUSE 0x40
#define FIFO_STATUS_TX_FULL 0x20
#define FIFO_STATUS_TX_EMPTY 0x10

#define FIFO_STATUS_RX_FULL 0x02
#define FIFO_STATUS_RX_EMPTY 0x01


unsigned char SPI_Read_Reg(unsigned char reg);
void SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);

void SPI_Write_Reg(unsigned char reg, unsigned char value);
void SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char bytes);


void SwitchToTxMode(void);
void SwitchToRxMode(void);

void SPI_Bank1_Read_Reg(unsigned char reg, unsigned char *pBuf);
void SPI_Bank1_Write_Reg(unsigned char reg, unsigned char *pBuf);
void SwitchCFG(char _cfg);

//void DelayMs(unsigned int ms);
void BK2421_Initialize(void);

void SetChannelNum(unsigned char ch);

void Hop(void);
void Receive_Packet();
extern unsigned char Work_Address[5];
extern unsigned char Work_Frequency[5];
extern bit Bind_On;
extern bit Lost_Signal_f;//Ò£¿ØÐÅºÅ¶ªÊ§±íÊ¾
#endif