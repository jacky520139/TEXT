//#include "STM8S103F.h"
//#include "bk2421.h"
#include "ALL_Includes.h"
//#include	"EEPROM.h"
extern unsigned char Tx_Buffer[];
unsigned char op_status;

unsigned char  Tx_Address[6];
unsigned char Work_Address[5];
unsigned char Work_Frequency[5];

//Bank1 register initialization value
bit Bind_On=1;
bit Lost_Signal_f=0;//遥控信号丢失表示
code unsigned char RX_P0_Addr[5]= {0xD9,0x6A,0xCD,0x56,0x5B};//P0端地址对码接收端口
code unsigned char RX_P1_Addr[5]= {0x13,0x34,0xcc,0x78,0x9a};//P1端地址接收工作数据端口
	 u8 Lost_time=0;//遥控信号丢失时间
//code unsigned char Link_Address[]=
//{
//	//0x69,0x6b,0x26,0x5a,0x54,Factory_ID,
//	//0xd2,0xb3,0xb5,0x99,Factory_ID,
////	0x7f,0xff,0xff,0xff,0xfe,
//	0xD9,0x6A,0xCD,0x56,0x5B
//};
	u8 rx_buf[MAX_PACKET_LEN];//接收缓存

//In the array Bank1_Reg0_13,all[] the register value is the byte reversed!
code unsigned long  Bank1_Reg0_13[]={       
0xE2014B40,		//写入顺序40,4b,01,e2
0x00004BC0,
0x028CFCD0,
0x213900f9,
0xDB8a96F9, 
0xB60F0624, 
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00127300,
0x46B48000,		//0x36b48000
};

code unsigned char  Bank1_Reg14[]=
{
  0x41,0x20,0x08,0x04,0x81,0x20,0xCF,0xF7,0xFE,0xFF,0xFF
};

//Bank0 register initialization value
code unsigned char  Bank0_Reg[][2]={
{0,0x0f},		//02//enable 2 byte CRC,Power Up,Rx mode
{1,0x03},		//Enable AUTO-ACK in data pipe[1:0] 
{2,0x03},		//enable data pipe0,pipe1 
{3,0x03},		//5 byte Address Field width(高两字节用于识别 客户，低3字节用于识别设备）
{4,0x02},		//Auto retransmit delay 4000us，最大连续重发15次
{5,23},		//select channel 0x52=82d
{6,0x27},		//27//27:250K,07:1M //1Mbps data rate, output power=0dBm,High Gain
{7,0x70},		//77//clear Tx buffer and Rx buffer
{8,0x00},		//reset lost packet counter and retransmit packet counter 
{9,0x00},		//carrier detect
{12,0xc3},		//set data pipe address
{13,0xc4},
{14,0xc5},
{15,0xc6},
{17,0x20},		//set RX Payload Pipe0=7byte
{18,0x20},		//set RX Payload Pipe1=5byte
{19,0x20},
{20,0x20},
{21,0x20},
{22,0x20},
{23,0x00},
{28,0x3F},	//enable dynamic payload length  //0x3f,0x07：启动动态数据长度接收
{29,0x07}		//7
};


/**************************************************         
Function: DelayMs();                                  

Description:                                                
	delay ms,please implement this function according to your MCU.
/**************************************************/  

void DelayMs(unsigned int ms)
{
	unsigned char i, j;
 for(;ms>0;ms--)
	{
	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
} 
}
///////////////////////////////////////////////////////////////////////////////
//                  SPI access                                               //
///////////////////////////////////////////////////////////////////////////////

/**************************************************         
Function: SPI_RW();                                         
                                                            
Description:                                                
	Writes one unsigned char to BK2421, and return the unsigned char read 
/**************************************************/        
unsigned char SPI_RW(unsigned char value)                                    
{                                                           
	unsigned char bit_ctr;
	SCLK = 0;
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
		SCLK = 1;                      // Set SCK high..
		if(MISO)
		value	|=	0x01;								// capture current MISO bit
		SCLK = 0;            		  		// ..then set SCK low again
	}
	return(value);           		  	// return read unsigned char
}                                                           
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Write_Reg();                                  
                                                            
Description:                                                
	Writes value 'value' to register 'reg'              
/**************************************************/        
void SPI_Write_Reg(unsigned char reg, unsigned char value)                 
{
	CSN = 0;                   // CSN low, init SPI transaction
	op_status = SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	CSN = 1;                   // CSN high again
}                                                           
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Read_Reg();                                   
                                                            
Description:                                                
	Read one unsigned char from BK2421 register, 'reg'     
/**************************************************/        
unsigned char SPI_Read_Reg(unsigned char reg)                               
{                                                           
	unsigned char value;
	CSN = 0;                // CSN low, initialize SPI communication...
	op_status=SPI_RW(reg);            // Select register to read from..
	value = SPI_RW(0);    // ..then read register value
	CSN = 1;                // CSN high, terminate SPI communication
	return(value);        // return register value
}                                                           
/**************************************************/        
                                                            
/**************************************************/   
//Function: SPI_Read_Buf();                  
//Description:                                  
//	Reads 'length' #of length from register 'reg'         
/**************************************************/        
void SPI_Read_Buf(unsigned char reg, unsigned char *pBuf, unsigned char length)     
{                                                           
	unsigned char status,byte_ctr;                              
                                                            
	CSN = 0;                    		// Set CSN l
	status = SPI_RW(reg);       		// Select register to write, and read status unsigned char
                                                            
	for(byte_ctr=0;byte_ctr<length;byte_ctr++)           
		pBuf[byte_ctr] = SPI_RW(0);    // Perform SPI_RW to read unsigned char from BK2421 
                                                            
	CSN = 1;                           // Set CSN high again
               
}                                                           
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Write_Buf();                                  
                                                            
Description:                                                
	Writes contents of buffer '*pBuf' to BK2421         
/**************************************************/        
void SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char length)    
{                                                           
	unsigned char byte_ctr;                              
                                                            
	CSN = 0;                   // Set CSN low, init SPI tranaction
	op_status = SPI_RW(reg);    // Select register to write to and read status unsigned char
	for(byte_ctr=0; byte_ctr<length; byte_ctr++) // then write all unsigned char in buffer(*pBuf) 
		SPI_RW(*pBuf++);                                    
	CSN = 1;                 // Set CSN high again      

}                                                           
/**************************************************/        


/**************************************************
Function: SwitchToRxMode();
Description:
	switch to Rx mode
/**************************************************/
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

/**************************************************
Function: SwitchToTxMode();
Description:
	switch to Tx mode
/**************************************************/
void SwitchToTxMode(void)
{
	unsigned char value;
	SPI_Write_Reg(FLUSH_TX,0);//flush Tx

	CE=0;
	value=SPI_Read_Reg(CONFIG);	// read register CONFIG's value
//PTX
	value=value&0xfe;//set bit 0
  SPI_Write_Reg(WRITE_REG | CONFIG, value); // Set PWR_UP bit, enable CRC(2 length) & Prim:RX. RX_DR enabled.

	CE=1;
}

/**************************************************
Function: SwitchCFG();
                                                            
Description:
	 access switch between Bank1 and Bank0 

Parameter:
	_cfg      1:register bank1
	          0:register bank0
Return:
     None
/**************************************************/
void SwitchCFG(char _cfg)//1:Bank1 0:Bank0
{
	unsigned char Tmp;

	Tmp=SPI_Read_Reg(7);
	Tmp=Tmp&0x80;

	if( ( (Tmp)&&(_cfg==0) )
	||( ((Tmp)==0)&&(_cfg) ) )
	{
		SPI_Write_Reg(ACTIVATE_CMD,0x53);
	}
}

/**************************************************
Function: SetChannelNum();
Description:
	set channel number
每通道的最小分辨率为1MHz
/**************************************************/
void SetChannelNum(unsigned char ch)
{
	SPI_Write_Reg((unsigned char)(WRITE_REG|5),(unsigned char)(ch));
}

///////////////////////////////////////////////////////////////////////////////
//                  BK2421 initialization                                    //
///////////////////////////////////////////////////////////////////////////////
/**************************************************         
Function: BK2421_Initialize();                                  

Description:                                                
	register initialization
/**************************************************/   
void BK2421_Initialize(void)
{
	signed char i,j;
 	unsigned char WriteArr[4];
	CSN	=	1;
	SCLK	=	0;
	CE	=	0;

	DelayMs(100);//delay more than 50ms.
	SwitchCFG(0);//point to bank0
	
	i=SPI_Read_Reg(29);
//********************Write Bank0 register******************
	for(i=20;i>=0;i--)
		SPI_Write_Reg((WRITE_REG|Bank0_Reg[i][0]),Bank0_Reg[i][1]);
		i=SPI_Read_Reg(29);
//reg 10 - Rx0 addr
	SPI_Write_Buf((WRITE_REG|RX_ADDR_P0),RX_P0_Addr,5);
  SPI_Write_Buf((WRITE_REG|RX_ADDR_P1),Work_Address,5);
//REG 16 - TX addr
	SPI_Write_Buf((WRITE_REG|TX_ADDR),RX_P0_Addr,5);
	

//REG 11 - Rx1 addr
	//SPI_Write_Buf((WRITE_REG|11),&Tx_Address[0],5);
//	SPI_Write_Buf(0x20|11,&Tx_Address[0],5);


	i=SPI_Read_Reg(29);

	if(i==0) // i!=0 showed that chip has been actived.so do not active again.
		SPI_Write_Reg(ACTIVATE_CMD,0x73);// Active

	for(i=22;i>=21;i--)
		SPI_Write_Reg((WRITE_REG|Bank0_Reg[i][0]),Bank0_Reg[i][1]);

//********************Write Bank1 register******************
	SwitchCFG(1);

	for(i=4;i<6;i++)		//  只写reg4,reg5		//for(i=0;i<=8;i++)
	{
		for(j=0;j<4;j++)
			WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(j) ) )&0xff;

		SPI_Write_Buf((WRITE_REG|i),&(WriteArr[0]),4);
	}
	//SPI_Read_Buf(0x04,&(Tx_Buffer[0]),4);
	//SPI_Read_Buf(0x05,&(Tx_Buffer[0]),4);
	//SPI_Read_Buf(0x08,&(Tx_Buffer[0]),4);
	for(i=12;i<=13;i++)			//只写reg12,reg13	//for(i=9;i<=13;i++)
	{
		for(j=0;j<4;j++)
			WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(3-j) ) )&0xff;

		SPI_Write_Buf((WRITE_REG|i),&(WriteArr[0]),4);
	}
	//SPI_Read_Buf(12,&(Tx_Buffer[0]),4);
	//SPI_Read_Buf(13,&(Tx_Buffer[0]),4);
	
	SPI_Write_Buf((WRITE_REG|14),&(Bank1_Reg14[0]),11);
/*
//toggle REG4<25,26>
	for(j=0;j<4;j++)
		WriteArr[j]=(Bank1_Reg0_13[4]>>(8*(j) ) )&0xff;

	WriteArr[0]=WriteArr[0]|0x06;
	SPI_Write_Buf((WRITE_REG|4),&(WriteArr[0]),4);

	WriteArr[0]=WriteArr[0]&0xf9;
	SPI_Write_Buf((WRITE_REG|4),&(WriteArr[0]),4);

*/
	DelayMs(10);
//********************switch back to Bank0 register access******************
	SwitchCFG(0);
	SwitchToRxMode();

//	SPI_Write_Reg(WRITE_REG | CONFIG, 0xff);
	i=SPI_Read_Reg(CONFIG);
  i++;
}
//加载遥控数据
u8 Load_RF_Date(unsigned char *pBuf, unsigned char length){
    /*xdata*/ u8 i,sum,cnt=0;

    sum=0;

    for(i=0;i<(length-1);i++){
        sum+=pBuf[i];
		
    }
		if(sum==pBuf[length-1])
		{cnt=0;
			memcpy((u8*)&Control, pBuf, length);
			Bind_On=0;//禁止对频
			Lost_time=0;
			Lost_Signal_f=0;
     }
    else
			cnt=1;
    return(cnt);
}
u8 Channel_Number=0;
void	Work_Hop(void)
{
	Channel_Number++;
	if(Channel_Number>3)
		Channel_Number	=	0;
//	RF_Set_Chn(Work_Frequency[Channel_Number]);
	SPI_Write_Reg((WRITE_REG|Bank0_Reg[5][0]),Work_Frequency[Channel_Number]);
	SwitchToRxMode();
}
void Receive_Packet()
{
	UINT8 len,sta,fifo_sta;


		Lost_time++;
    if((Lost_time%5==4)&&(Bind_On==0))
		{Work_Hop();}
     
if(Lost_time>200)
{Control.Throttle=1500;
 Control.Direc=1500;
	Lost_Signal_f=1;
   } 
	sta=SPI_Read_Reg(STATUS);	// read register STATUS's value
	if(sta&0x70)				// if receive data ready (RX_DR) interrupt
	{		
		switch((sta>>1)&0x07)//判断是哪个通道数据
		{
			case 0:fifo_sta=0;//对码通道
					     len=SPI_Read_Reg(R_RX_PL_WID_CMD);
		           SPI_Read_Buf(RD_RX_PLOAD,rx_buf,len);
			         if((rx_buf[0]==0xab)&&(rx_buf[1]==0xba)&&(Bind_On==1))
			         {SPI_Write_Buf((WRITE_REG|RX_ADDR_P1),rx_buf+2,5);
                SPI_Write_Buf((WRITE_REG|TX_ADDR),rx_buf+2,5);
								  SPI_Write_Buf((WRITE_REG|TX_ADDR),rx_buf+2,5);
								 memcpy(Work_Address,rx_buf+2, 5);
								 	Work_Frequency[0]	=	6;		//6-21
	                Work_Frequency[1]	=	23;		//23-38
	                Work_Frequency[2]	=	(Work_Address[0]&0x0f)+43;		//43-58
	                Work_Frequency[3]	=	(Work_Address[0]&0x0f)+60;		//60-75
								 WriteEeprom();
			          SwitchToRxMode();
							  }
//			
				break;
			case 1:fifo_sta=1;//工作通道
							Lost_time=0;
							 len=SPI_Read_Reg(R_RX_PL_WID_CMD);
		           SPI_Read_Buf(RD_RX_PLOAD,rx_buf,len);
			         Load_RF_Date(rx_buf,len);
			        
			
				break;
          }

				 SPI_Write_Reg(WRITE_REG|STATUS,0x70); 
			   SPI_Write_Reg(FLUSH_RX,0);
		    
	}

}

//void RF_Task(void)
//{
//	static	unsigned int RF_Time;
//	static	u8 Hop_Interval;
//	if((System_Timer-RF_Time)>Hop_Interval)
//		{//一个接收周期没有收到数据，也要跳频
//			RF_Time	=	System_Timer;

//			if(Bind)
//				{//对码，固定12ms跳一次
//					Hop_Interval	=	12;		//对码跳频3个频道，发射端每4ms发送一个频道
//					Link_Hop();
//				}
//			else
//				{//正常工作，连续4个周期没有收到数据，确定已经失去同步，启动长跳，否则短跳
//					if(++Lost_Count>4)
//						Hop_Interval	=	16;
//					else
//						Hop_Interval	=	4;
//					Work_Hop();
//				}
//		}




















//}




