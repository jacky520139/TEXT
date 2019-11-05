
#include "BK2425.h"
#include "ALL_Includes.h"
//#include "time.h"
//#include "Rf.h"
//extern void UT_Delay_Nms (uint16_t N);
//extern uint32_t standby_cnt;
u8 Rf_Buf_Data[];
extern void Receive_Data_Process(void);
uint8_t	Lock_Head;
unsigned long const Bank1_Reg0_13[]=
{       
0xE2014B40,
0x00004BC0,
0x028CFCD0,
0x21390099,
//0x218A96F9,	//0xDB8A96F9,																	//250Ksps
0xDB8A96F9,
0xB60F0624,																		//250Ksps  
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00127300,																		//120us mode
0x36B48000,																		//initialize
//	0xE2014B40,		//写入顺序40,4b,01,e2
//0x00004BC0,
//0x028CFCD0,
//0x213900f9,
//0xDB8a96F9, 
//0xB60F0624, 
//0x00000000,
//0x00000000,
//0x00000000,
//0x00000000,
//0x00000000,
//0x00000000,
//0x00127300,
//0x46B48000,		//0x36b48000
};

unsigned char  Bank1_Reg14[]=
{
0x41,0x20,0x08,0x04,0x81,0x20,0xCF,0xF7,0xFE,0xFF,0xFF
};

unsigned char const Bank0_Reg[][2]={
{0x20,0x3F},																	//PTX,POWER DOWN, 1 byte, disable CRC, 0x33
{0x21,0x00},																	//
{0x22,0x3f},																	//Pipe0,Pipe1
{0x23,0x03},																	//4byte 
{0x24,0xff},																	//4000us
{0x25,0x00},																	//(0x52=82d)
{0x26,0x27},																	//250Kbps data rate, output power=5dBm	
{0x27,0x77},	
{0x28,0x00},	
{0x29,0x00},	
{0x2C,0xc3},	
{0x2D,0xc4},	
{0x2E,0xc5},	
{0x2F,0xc6},	
{0x31,0x0A},																	//PX_PW_P0 10 bytes
{0x32,0x0A},	
{0x33,0x0A},	
{0x34,0x0A},	
{0x35,0x0A},	
{0x36,0x0A},	
{0x37,0x00},
{0x3D,0x00},	
{0x3C,0x00}																		//0x07	
//{0,0x02},		//02//enable 2 byte CRC,Power Up,Rx mode
//{1,0x00},		//Enable AUTO-ACK in data pipe[1:0] 
//{2,0x03},		//enable data pipe0,pipe1 
//{3,0x03},		//5 byte Address Field width(高两字节用于识别 客户，低3字节用于识别设备）
//{4,0x02},		//Auto retransmit delay 4000us，最大连续重发15次
//{5,0},		//select channel 0x52=82d
//{6,0x27},		//27//27:250K,07:1M //1Mbps data rate, output power=0dBm,High Gain
//{7,0x70},		//77//clear Tx buffer and Rx buffer
//{8,0x00},		//reset lost packet counter and retransmit packet counter 
//{9,0x00},		//carrier detect
//{12,0xc3},		//set data pipe address
//{13,0xc4},
//{14,0xc5},
//{15,0xc6},
//{17,0x20},		//set RX Payload Pipe0=7byte
//{18,0x20},		//set RX Payload Pipe1=5byte
//{19,0x20},
//{20,0x20},
//{21,0x20},
//{22,0x20},
//{23,0x00},
//{28,0x3F},	//enable dynamic payload length  //0x3f,0x07：启动动态数据长度接收
//{29,0x07}		//7
};

//????????
unsigned char const CH_LIST_DM[4]=
{	  
	9, 32, 48, 64,
};

//?????????,???RF_address_set()??
unsigned char P0_Address[5]=
{
	0x7f,0xff,0xff,0xff,0xfe
//	0xAB,//Data5				 
//	0xAC,//Data4						
//	0xAD,//Data3
//	0xAE,//Data2
//	0xAF,//Data1
};

//????AA????
unsigned char const CH_LIST_WK[36]=
{
10,26,42,58, 
	 
//WORK_01
18,34,50, 66, 		         
 		    
//WORK_02
42,10,66,34, 	
	
//WORK_03
26,58,18, 50,
};

//????
uint8_t XY_Ver=0;

//????BB????
uint8_t Channel_Tab[16];	

//??????,???5Bytes
uint8_t Channel_Add[5];	//?????????Data0-Data4,???????????
uint8_t RF_Channel_DMFlag=1,RF_DMLED_Flag=1;	//????1,???????
uint8_t RF_Channel_JMP=0;
uint8_t RF_Channel;
unsigned char RF_R_Data[10];
unsigned char save_buf[10];		//????????, ????
uint8_t RF_NotRec_Cnt=0;
//uint8_t RF_RX_Status;
uint8_t Link_Page_Cnt = 0;	//?????????
unsigned char RF_Not_Flag;	//??????????, ??????????



u8 SPI_RW(u8 value)                                    
{                                                           
	u8 bit_ctr;
	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   // output 8-bit
	{
		if(value & 0x80)
		{
			MOSI=1;
		}
		else
		{
			MOSI=0;		
		}

		value = (value << 1);           // shift next bit into MSB..
		SCLK = 1;                      // Set SCLK high..
		value |= MISO;
		//DelayUs(1);       		  // capture current MISO bit
		SCLK = 0;            		  // ..then set SCLK low again
		//DelayUs(1); 
	}
	return(value);           		  // return read u8
} 
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Write_Reg();                                  
                                                            
Description:                                                
	Writes value 'value' to register 'reg'              
/**************************************************/        
void SPI_Write_Reg(u8 reg, u8 value)                 
{
	CSN = 0;                   // CSN low, init SPI transaction
	SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	CSN = 1;                   // CSN high again
}                                                           
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Read_Reg();                                   
                                                            
Description:                                                
	Read one u8 from BK2425 register, 'reg'           
/**************************************************/        
u8 SPI_Read_Reg(u8 reg)                               
{                                                           
	u8 value;
	CSN = 0;                // CSN low, initialize SPI communication...
	SPI_RW(reg);            // Select register to read from..
	value = SPI_RW(0);    // ..then read register value
	CSN = 1;                // CSN high, terminate SPI communication

	return(value);        // return register value
}                                                           
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Read_Buf();                                   
                                                            
Description:                                                
	Reads 'length' #of length from register 'reg'         
/**************************************************/        
void SPI_Read_Buf(u8 reg, u8 *pBuf, u8 length)     
{                                                           
	u8 status,byte_ctr;                              
                                                            
	CSN = 0;                    		// Set CSN l
	status = SPI_RW(reg);       		// Select register to write, and read status u8
                                                            
	for(byte_ctr=0;byte_ctr<length;byte_ctr++)           
		pBuf[byte_ctr] = SPI_RW(0);    // Perform SPI_RW to read u8 from BK2425
                                                            
	CSN = 1;                           // Set CSN high again
               
}                                                           
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Write_Buf();                                  
                                                            
Description:                                                
	Writes contents of buffer '*pBuf' to BK2425         
/**************************************************/        
void SPI_Write_Buf(u8 reg, u8 *pBuf, u8 length)    
{                                                           
	u8 byte_ctr;                              
                                                            
	CSN = 0;        // Set CSN low, init SPI tranaction
	SPI_RW(reg);    // Select register to write to and read status u8
	for(byte_ctr=0; byte_ctr<length; byte_ctr++) // then write all u8 in buffer(*pBuf) 
	SPI_RW(*pBuf++);                                    
	CSN = 1;                 // Set CSN high again      

}     




void BK2425_Check(void)
{
	unsigned char test_buf[5] = {0xC0,0xC1,0xC2,0xC3,0xC4};
	unsigned char test_buf1[5];
	
	SPI_Write_Buf(Write_Reg | RX_ADDR_P0, test_buf,5);	//TX_ADDR, RX_ADDR_P5

	SPI_Read_Buf(Read_Reg | RX_ADDR_P0,test_buf1,5); 
}

/**************************************************
Function: 		SwitchCFG();                                                      
Description:	access switch between Bank1 and Bank0 
Parameter:		_cfg
				1:register bank1
				0:register bank0
Return:			None
*************************************************/
void SwitchCFG(char _cfg)
{
	unsigned char Tmp;

	Tmp=SPI_Read_Reg(STATUS);	//Reg Bank Status
	
	Tmp=Tmp&0x80;		//0: Bank0; 1: Bank1

	if( ( (Tmp)&&(_cfg==0) )||( ((Tmp)==0)&&(_cfg) ) )
	{
		SPI_Write_Reg(ACTIVATE,	0x53);	//SPI Command followed by 0x53 toggles register bank
	}
}

void RF_address_set(uint8_t *add_buf)
{
	SPI_Write_Reg(Write_Reg|EN_RXADDR,0x01);				//Enable Data Pipe 0					
	SPI_Write_Buf((Write_Reg|RX_ADDR_P0),add_buf,5);//??????????, 5 Bytes Long
}
void SwitchToRxMode(void)
{
	unsigned char value;

	SPI_Write_Reg(FLUSH_RX,0);//flush Rx

	value=SPI_Read_Reg(STATUS);	// read register STATUS's value
	SPI_Write_Reg(WRITE_REG|STATUS,value);// clear RX_DR or TX_DS or MAX_RT interrupt flag

	CE=0;

	value=SPI_Read_Reg(CONFIG);	// read register CONFIG's value
//PRX
	value=value|0x01;//set bit 1
  	SPI_Write_Reg(WRITE_REG | CONFIG, value); // Set PWR_UP bit, enable CRC(2 length) & Prim:RX. RX_DR enabled..

	CE=1;
}
//void SwitchToRxMode(void)
//{
//	unsigned char value, Work_Channel_Num;
//	
//	RF_Channel_JMP = RF_Channel_JMP & 0x03;			//4?????
//	
//	if (RF_Channel_DMFlag == 1)
//	{
//		Work_Channel_Num = CH_LIST_DM[RF_Channel_JMP];
//	}
//	else
//	{
//		value = ((RF_Channel >> 3) & 0x03) *4;		//RF_Channel: ??????????????????,bit4&bit3?????
//		value =	value + (RF_Channel_JMP & 0x03);
//						
//		if (XY_Ver == 0XAA)
//			Work_Channel_Num =	CH_LIST_WK[value];
//		else
//			Work_Channel_Num = Channel_Tab[value];
//		
//		Work_Channel_Num = Work_Channel_Num + (RF_Channel & 0x07);	//????
//		
//		if ((Work_Channel_Num & 0x0f) == 0)		//???16???,?1
//			Work_Channel_Num ++ ;
//	}
//	SPI_Write_Reg(Write_Reg|RF_CH, Work_Channel_Num);
//}
void SwitchToTxMode()
{
	u8 value;
	SPI_Write_Reg(FLUSH_TX,0);//flush Tx

	CE=0;
	value=SPI_Read_Reg(CONFIG);	// read register CONFIG's value
//PTX
	value=value&0xfe;//set bit 1
  	SPI_Write_Reg(WRITE_REG | CONFIG, value); // Set PWR_UP bit, enable CRC(2 length) & Prim:RX. RX_DR enabled.

	CE=1;
}
void time_waitMs(unsigned char Time)
{

	unsigned char i, j;
 for(;Time>0;Time--)
	{
	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}
}
/**************************************************   
Function: 		BK2425_Initialize();                                  
Description:  register initialization
**************************************************/   
void BK2425_Init(void)	//-??Bank0,1; -??Bank0,1;
{
	signed char i,j;
 	unsigned char WriteArr[4],getID;	//WriteArr[4]??Bank1?????

	while((getID!=0x63))
	{
//		SPI_CSN_HIGH();	//active low
		CSN=1;
		time_waitMs(50);
		SwitchCFG(0);		//??Bank0

	//********************Write Bank0 register******************
		for(i=20;i>=0;i--)
			SPI_Write_Reg((Write_Reg|Bank0_Reg[i][0]),Bank0_Reg[i][1]);
	
  		SPI_Write_Reg(ACTIVATE,0x73);// Active
			
		for(i=22;i>=21;i--)
			SPI_Write_Reg((Write_Reg|Bank0_Reg[i][0]),Bank0_Reg[i][1]);
		
	//********************Write Bank1 register******************
		SwitchCFG(1);
	
		for(i=0;i<=8;i++)//reverse
		{
			for(j=0;j<4;j++)
				WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(j) ) )&0xff;
	
			SPI_Write_Buf((Write_Reg|i),&(WriteArr[0]),4);
		}

		for(i=9;i<=13;i++)
		{
			for(j=0;j<4;j++)
				WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(3-j) ) )&0xff;
	
			SPI_Write_Buf((Write_Reg|i),&(WriteArr[0]),4);
		}

		SPI_Write_Buf((Write_Reg|14),&(Bank1_Reg14[0]),11);
	
		//toggle REG4<25,26>
		for(j=0;j<4;j++)
			WriteArr[j]=(Bank1_Reg0_13[4]>>(8*(j) ) )&0xff;
	
		WriteArr[0]=WriteArr[0]|0x06;
		SPI_Write_Buf((Write_Reg|4),&(WriteArr[0]),4);
	
		WriteArr[0]=WriteArr[0]&0xf9;
		SPI_Write_Buf((Write_Reg|4),&(WriteArr[0]),4);
	
		time_waitMs(50);
	//********************switch back to Bank0 register access******************
		SwitchCFG(0);
		i=SPI_Read_Reg(CONFIG);
		if (i==Bank0_Reg[0][1])
			getID=0x63;																				
		else
			getID=0x00;	
	}
	
		time_waitMs(20);
		SPI_Write_Reg(FLUSH_RX, NOP);	//?????????RX FIFO, ??????
		RF_address_set(P0_Address);		//?? Data Pipe 0 ??
//		SwitchToTxMode();		//SwitchToRxMode();	
SwitchToRxMode();		//SwitchToRxMode();
while(1)
{	
	Receive_Packet();
}
//Send_Packet(W_TX_PAYLOAD_NOACK_CMD,time_waitMs,4);
}
/**************************************************
Function: Send_Packet
Description:
	fill FIFO to send a packet
Parameter:
	type: WR_TX_PLOAD or  W_TX_PAYLOAD_NOACK_CMD
	pbuf: a buffer pointer
	len: packet length
Return:
	None
**************************************************/
void Send_Packet(UINT8 type,UINT8* pbuf,UINT8 len)
{
	UINT8 Read_STATUS;
	  EA=0;
	time_waitMs(5);
		SPI_Write_Reg(WRITE_REG|FLUSH_TX,0);//flush Tx
		SPI_Write_Reg(WRITE_REG|FLUSH_RX,0);//flush Tx
	  Read_STATUS=SPI_Read_Reg(FIFO_STATUS);	// read register FIFO_STATUS's value
		while(Read_STATUS & FIFO_STATUS_TX_FULL);

    Read_STATUS=SPI_Read_Reg(CONFIG);	// read register FIFO_STATUS's value
	  Read_STATUS=SPI_Read_Reg(STATUS);	// read register FIFO_STATUS's value
		  CE=0;
	time_waitMs(5);
	 CE=1;
	  SPI_Write_Buf(type, pbuf, len); // Writes data to buffer  A0,B0,A8
	  CE=1;
//	  time_waitMs(5);

	  Read_STATUS=SPI_Read_Reg(STATUS);	// read register FIFO_STATUS's value
		while((Read_STATUS&0x70)==0)
		{Read_STATUS=SPI_Read_Reg(STATUS);}

	        if(Read_STATUS&STATUS_RX_DR){
//            R_RX_PAYLOAD(RXAckBuf, TRX_RX_RPL_WIDTH);
              Read_STATUS = STATUS_RX_DR;
						  SPI_Write_Reg(WRITE_REG|STATUS, Read_STATUS);
//            RXAckBuf[31]=0;
//            PRINT(RXAckBuf);
//            PRINT("\r\n");
            }
         if(Read_STATUS&STATUS_TX_DS){
            Read_STATUS=STATUS_TX_DS;
					  SPI_Write_Reg(WRITE_REG|STATUS, Read_STATUS);
            }
         if(Read_STATUS&STATUS_MAX_RT){
            Read_STATUS=STATUS_MAX_RT;
					  SPI_Write_Reg(WRITE_REG|STATUS, Read_STATUS);
					 	SPI_Write_Reg(FLUSH_TX,0);//flush Tx
//            FLUSH_TX;
            }
	  	 	
}

/**************************************************
Function: Receive_Packet
Description:
	read FIFO to read a packet
Parameter:
	None
Return:
	None
**************************************************/
void Receive_Packet()
{
	UINT8 len,sta,fifo_sta;
	UINT8 rx_buf[MAX_PACKET_LEN];

	sta=SPI_Read_Reg(STATUS);	// read register STATUS's value
	if(sta&STATUS_RX_DR)				// if receive data ready (RX_DR) interrupt
	{
//		do
//		{
//			len=SPI_Read_Reg(R_RX_PL_WID_CMD);	// read len

//			if(len<=MAX_PACKET_LEN)
//			{
//				SPI_Read_Buf(RD_RX_PLOAD,rx_buf,len);// read receive payload from RX_FIFO buffer

//				
//			}
//			else
//			{
//				SPI_Write_Reg(FLUSH_RX,0);//flush Rx
//			}

//			fifo_sta=SPI_Read_Reg(FIFO_STATUS);	// read register FIFO_STATUS's value
//						
//		}while((fifo_sta&FIFO_STATUS_RX_EMPTY)==0); //while not empty
		     len=SPI_Read_Reg(R_RX_PL_WID_CMD);
		
		     SPI_Read_Buf(RD_RX_PLOAD,rx_buf,10);
				 SPI_Write_Reg(WRITE_REG|STATUS,0x70); 
			   SPI_Write_Reg(FLUSH_RX,0);
		    
	}

//	SPI_Write_Reg(WRITE_REG|STATUS,sta);// clear RX_DR or TX_DS or MAX_RT interrupt flag
//				  SPI_Write_Reg(WRITE_REG|STATUS,0x70);
//			  SPI_Write_Reg(FLUSH_RX,0);
}



