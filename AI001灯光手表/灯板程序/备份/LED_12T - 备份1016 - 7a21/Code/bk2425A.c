//#include "bk2425.h"
#include "ALL_Includes.h"
u8 op_status;



/* Bank1 register initialization value,updated on May 17,2012 */

//In the array Bank1_Reg0_13[],all the register values are the byte reversed!!!!!!!!!!!!!!!!!!!!!
unsigned long const Bank1_Reg0_13[]={
0x1B8296f9,
/*REG4,
----------------------------------------------------------------
|		     1Mbps      | 2Mbps	          |	250Kbps		
| Normal Mode      0x1B8296f9	| 0xdB8296f9      | 0xdB8a96f9
| CW Normal Mode   0x218296f9	
| 外部PA           0xDB8A96C1   | 0x1B8296C1      | 0xDB8296C1
----------------------------------------------------------------
*/
0xA60F0624,
/*REG5,
----------------------------------------------------------------
|     1Mbps:0xA60F0624                  disable rssi
|     2Mbps:0xB60F0624			disable rssi
|     259kbps:0xB60F0624		disable rssi
----------------------------------------------------------------
*/
0x00127300,
/*REG12,120517
0x00127300:PLL locking time 120us 
0x00127305(chip default):PLL locking time 130us compatible with nRF24L01;
*/
0x36B48000,//REG13
};



//Bank0 register initialization value


u8 Bank1_Reg14[11];
u8 RX0_Address[5]={0x7f,0xff,0xff,0xff,0xfe};
u8 RX1_Address[5]={0x3f,0xff,0xff,0xff,0xfe};

///////////////////////////////////////////////////////////////////////////////
//                  SPI access                                               //
///////////////////////////////////////////////////////////////////////////////

/**************************************************         
Function: SPI_RW();                                         
                                                            
Description:                                                
	Writes one u8 to BK2425, and return the u8 read 
/**************************************************/        
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
	op_status = SPI_RW(reg);      // select register
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
	op_status=SPI_RW(reg);            // Select register to read from..
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
                                                            
	CSN = 0;                   // Set CSN low, init SPI tranaction
	op_status = SPI_RW(reg);    // Select register to write to and read status u8
	for(byte_ctr=0; byte_ctr<length; byte_ctr++) // then write all u8 in buffer(*pBuf) 
		SPI_RW(*pBuf++);                                    
	CSN = 1;                 // Set CSN high again      

}                                                           
/**************************************************/        


/**************************************************
Function: SwitchToRxMode();
Description:
	switch to Rx mode
/**************************************************/
void SwitchToRxMode()
{
	u8 value;

	SPI_Write_Reg(FLUSH_RX,0);//flush Rx

	value=SPI_Read_Reg(STATUS);	// read register STATUS's value
	SPI_Write_Reg(WRITE_REG|STATUS,value);// clear RX_DR or TX_DS or MAX_RT interrupt flag

	CE=0;

	value=SPI_Read_Reg(CONFIGG);	// read register CONFIG's value
//PRX
	value=value|0x01;//set bit 1
  	SPI_Write_Reg(WRITE_REG | CONFIGG, value); // Set PWR_UP bit, enable CRC(2 length) & Prim:RX. RX_DR enabled..
	
	CE=1;
}

/**************************************************
Function: SwitchToTxMode();
Description:
	switch to Tx mode
/**************************************************/
void SwitchToTxMode()
{
	u8 value;
	SPI_Write_Reg(FLUSH_TX,0);//flush Tx

	CE=0;
	value=SPI_Read_Reg(CONFIGG);	// read register CONFIG's value
//PTX
	value=value&0xfe;//set bit 1
  	SPI_Write_Reg(WRITE_REG | CONFIGG, value); // Set PWR_UP bit, enable CRC(2 length) & Prim:RX. RX_DR enabled.

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
	u8 Tmp;

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

/**************************************************/
void SetChannelNum(u8 ch)
{
	SPI_Write_Reg((u8)(WRITE_REG|5),(u8)(ch));
}



///////////////////////////////////////////////////////////////////////////////
//                  BK2425 initialization                                    //
///////////////////////////////////////////////////////////////////////////////
/**************************************************         
Function: BK2425_Initialize();                                  

Description:                                                
	register initialization
/**************************************************/   
void BK2425_Initialize()
{
	INT8 i,j;
 	u8 WriteArr[4];

	DelayMs(100);//delay more than 50ms.
	
	SwitchCFG(0);

//********************Write Bank0 register******************
	
		SPI_Write_Reg((WRITE_REG|23),0x00);

SPI_Write_Reg((WRITE_REG|22),0x20);
SPI_Write_Reg((WRITE_REG|21),0x20);
SPI_Write_Reg((WRITE_REG|20),0x20);
SPI_Write_Reg((WRITE_REG|19),0x20);
SPI_Write_Reg((WRITE_REG|18),0x20);
SPI_Write_Reg((WRITE_REG|17),0x20);

SPI_Write_Reg((WRITE_REG|15),0xc6);
SPI_Write_Reg((WRITE_REG|14),0xc5);
SPI_Write_Reg((WRITE_REG|13),0xc4);
SPI_Write_Reg((WRITE_REG|12),0xc3);

SPI_Write_Reg((WRITE_REG|9),0x00);
SPI_Write_Reg((WRITE_REG|8),0x00);
SPI_Write_Reg((WRITE_REG|7),0x07);
//SPI_Write_Reg((WRITE_REG|6),0x0F);
SPI_Write_Reg((WRITE_REG|6),0x27);
//SPI_Write_Reg((WRITE_REG|5),0x17);
SPI_Write_Reg((WRITE_REG|5),0);
SPI_Write_Reg((WRITE_REG|4),0xff);
SPI_Write_Reg((WRITE_REG|3),0x03);
SPI_Write_Reg((WRITE_REG|2),0x3F);
SPI_Write_Reg((WRITE_REG|1),0x3F);
SPI_Write_Reg((WRITE_REG|0),0x0F);
//SPI_Write_Reg((WRITE_REG|5),0x17);
SetChannelNum(0);
//WriteArr[0]=SPI_Read_Reg((WRITE_REG|5));
//RX0_Address[0]=0x15;
//RX0_Address[1]=0x59;
//RX0_Address[2]=0x23;
//RX0_Address[3]=0xC6;
//RX0_Address[4]=0x29;

//RX1_Address[0]=0x10;
//RX1_Address[1]=0x56;
//RX1_Address[2]=0x24;
//RX1_Address[3]=0xCD;
//RX1_Address[4]=0x78;

Bank1_Reg14[0]=0x41;
Bank1_Reg14[1]=0x20;
Bank1_Reg14[2]=0x08;
Bank1_Reg14[3]=0x04;
Bank1_Reg14[4]=0x81;
Bank1_Reg14[5]=0x20;
Bank1_Reg14[6]=0xcf;
Bank1_Reg14[7]=0xF7;
Bank1_Reg14[8]=0xfe;
Bank1_Reg14[9]=0xff;
Bank1_Reg14[10]=0xff;
//reg 10 - Rx0 addr
	SPI_Write_Buf((WRITE_REG|10),RX0_Address,5);
	
//REG 11 - Rx1 addr
	SPI_Write_Buf((WRITE_REG|11),RX1_Address,5);

//REG 16 - TX addr
	SPI_Write_Buf((WRITE_REG|16),RX0_Address,5);
//	printf("\nEnd Load Reg");

	i=SPI_Read_Reg(29);

	if(i==0) // i!=0 showed that chip has been actived.so do not active again.
		SPI_Write_Reg(ACTIVATE_CMD,0x73);// Active

	
		SPI_Write_Reg((WRITE_REG|29),0x07);
		SPI_Write_Reg((WRITE_REG|28),0x3F);
//********************Write Bank1 register******************
	SwitchCFG(1);

	for(i=0;i<=1;i++)//reverse
	{
		for(j=0;j<4;j++)
			WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(j) ) )&0xff;

		SPI_Write_Buf((WRITE_REG|i+4),&(WriteArr[0]),4);
	}

	for(i=2;i<=3;i++)
	{
		for(j=0;j<4;j++)
			WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(3-j) ) )&0xff;

		SPI_Write_Buf((WRITE_REG|i+10),&(WriteArr[0]),4);
	}

	SPI_Write_Buf((WRITE_REG|14),&(Bank1_Reg14[0]),11);


	for(j=0;j<4;j++)
	WriteArr[j]=(Bank1_Reg0_13[0]>>(8*(j) ) )&0xff;

	WriteArr[0]=WriteArr[0]|0x06;
	SPI_Write_Buf((WRITE_REG|4),&(WriteArr[0]),4);

	WriteArr[0]=WriteArr[0]&0xf9;
	SPI_Write_Buf((WRITE_REG|4),&(WriteArr[0]),4);


	DelayMs(10);
	
//********************switch back to Bank0 register access******************
	SwitchCFG(0);

	SwitchToRxMode();//switch to RX mode
//	SPI_Write_Reg((WRITE_REG|5),0x17);
//	i=SPI_Read_Reg((WRITE_REG|5));
  SwitchToTxMode();

}

              
//******************************************** 
//函数名称：DelayMs
//功能：    短延时函数
//输入参数：Time  延时时间长度   延时时长Timems
//返回参数：无 
//********************************************
void DelayMs(unsigned char Time)
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
void Send_Packet(u8 type,u8* pbuf,u8 len)
{
	u8 fifo_sta;

	fifo_sta=SPI_Read_Reg(FIFO_STATUS);	// read register FIFO_STATUS's value

	if((fifo_sta&FIFO_STATUS_TX_FULL)==0)//if not full, send data  
	  	SPI_Write_Buf(type, pbuf, len); // Writes data to buffer  A0,B0,A8
	  	 	
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
	u8 len,i,sta,fifo_sta;
	u8 rx_buf[MAX_PACKET_LEN];

	sta=SPI_Read_Reg(STATUS);	// read register STATUS's value
	if(sta&STATUS_RX_DR)				// if receive data ready (RX_DR) interrupt
	{
		do
		{
			len=SPI_Read_Reg(R_RX_PL_WID_CMD);	// read len

			if(len<=MAX_PACKET_LEN)
			{
				SPI_Read_Buf(RD_RX_PLOAD,rx_buf,len);// read receive payload from RX_FIFO buffer
        Send_Data_To_UART0 (len);
			}
			else
			{
				SPI_Write_Reg(FLUSH_RX,0);//flush Rx
			}

			fifo_sta=SPI_Read_Reg(FIFO_STATUS);	// read register FIFO_STATUS's value
						
		}while((fifo_sta&FIFO_STATUS_RX_EMPTY)==0); //while not empty
	}

	SPI_Write_Reg(WRITE_REG|STATUS,sta);// clear RX_DR or TX_DS or MAX_RT interrupt flag
	
}



