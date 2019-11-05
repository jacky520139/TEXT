/******************** (C) COPYRIGHT 2011 SONiX *******************************
* COMPANY:		SONiX
* DATE:			2012/07
* AUTHOR:		SA1
* IC:			SN32F700
* DESCRIPTION:	RF related functions.
*____________________________________________________________________________
* REVISION	Date		User		Description
* 0.1		2012/07/02	SA1			1. First release
*
*____________________________________________________________________________
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS TIME TO MARKET.
* SONiX SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
* DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH SOFTWARE
* AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN 
* IN CONNECTION WITH THEIR PRODUCTS.
*****************************************************************************/


/*_____ I N C L U D E S ____________________________________________________*/

#include "ALL_Includes.h"
/*_____ D E C L A R A T I O N S ____________________________________________*/

//***************** RF Protocol ******************//
u8 RF_Channel_JMP=0;
u8 RF_Channel_DMFlag=1;
u8 RF_Channel;
unsigned char RF_R_Data[10];		
u8 RF_RX_Status;

 u8 XY_Ver;
 u8 Channel_Tab[16];

/*_____ F U N C T I O N S __________________________________________________*/

/*****************************************************************************
* Function		: RF_Read_Data_From_RXFIFO
* Description	: 
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*****************************************************************************/
void RF_Read_Data_From_RXFIFO(void)	//= Read_Data_From_RFBuf:
{
	//u8 temp;
	//temp=SPI_Read_Reg(0x07);
	
	//if(F_RF_ModeStatus==1)
	//{
  SPI_Read_Buf(RD_RX_PLOAD,&RF_R_Data[0],10);
	//}	
	//else
	//{
	// SPI_Read_Buf(RD_RX_PLOAD,&RF_R_Data[0],10);
  //}
  // SPI_Write_Reg(WRITE_REG|STATUS , temp|0x70);
	
}
void RF_PowerOff(void)	//= BK2423_PowerOFF
{
// 	SW_Rf_BK(0);
// 	RF_Write_1Byte(CONFIG_W,00);	
// 	UT_Delay_Nms(2);

}




/********************************************************************************
* Function		: RF_Set_Channel
* Description	: Lookup and set the channel of nRF24L01 when Frequency hopping.
* Input			: None
* Output		: None
* Return		: None
* Note			: None
*********************************************************************************/
/*
void RF_Set_Channel(u8 rf_Channel)	//= nRF24L01_SetChannel
{
// 	RF_Write_1Byte(RF_CH_W, rf_Channel);
	//CE_LOW;
	SPI_Write_Reg((unsigned char)(WRITE_REG|0x05),(unsigned char)(rf_Channel));
	//SET_CE;
}
*/
/********************************************************************************
* Function		: RF_Flush_RX_FIFO
* Description	: MCU flushes RX_FIFO of RF IC.
* Input			: None
* Output		: None
* Return		: None
* Note			: Please do NOT modify unless RF protocol changes!
*********************************************************************************/
/*
void RF_Flush_RX_FIFO(void)
{
// 	RF_Write_Command(FLUSH_RX);//RF_Write_1Byte(FLUSH_RX, 0x0);
	u8 temp;
	SPI_Write_Reg(FLUSH_RX,0);//flush Rx

}

*/



/************************FSK COMMAND and REGISTER****************************************/

void  io_rf_init(void)
{
//	SN_GPIO3->MODE = 0xffB;
//  SN_GPIO3->CFG =0;	
 }
void Delay1ms(u8 Nms)		//@18.432MHz
{
	unsigned char i, j;
 for(;Nms>0;Nms--)
	{
	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}
}

//对频地址
unsigned char   P0_Address[]=
{
	0x7f,0xff,0xff,0xff,0xfe
//	0xAB,						//Pip0 for Pairing 
//	0xAC,						//dongle address
//	0xAD,
//	0xAE,
//	0xAF,
};
/*
unsigned char const  P1_Address[]=
{
	0xc2,0xc2,0xc2,0xc2,0xc2,
};
unsigned char const  P2_Address[]=
{
	0xc2,0xc2,0xc2,0xc2,0xc3,
};

//#define	LT8900_INIT_REG_COUNT		93
*/
unsigned long const Bank1_Reg0_13[]={       
0xE2014B40,		//????40,4b,01,e2
0x00004BC0,
0x028CFCD0,
0x21390099,  //?????reg4=0xd9be8621--???0x2186bed9
//0xDB8A96F9, //Change REG4[29:27] from 00 to 11,Bk1[Reg4.bit[20]]:BK0[Reg6.bit[2:1]]=111-->Tx_PWR=3dbm
			// BK1[Reg4.bit[21]]=1--> ???????
0x218296F9,
	
0xB60F0624,  //Disable RSSI measurement
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00000000,
0x00127300,
0x36B48000,		//0x36b48000
};


unsigned char  Bank1_Reg14[]=
{
		0x41,0x20,0x08,0x04,0x81,0x20,0xCF,0xF7,0xFE,0xFF,0xFF
//	0x41,0x10,0x04,0x82,0x20,0x08,0x08,0xf2,0x7d,0xef,0xff
};

//Bank0 register initialization value
unsigned char const Bank0_Reg[][2]={
{0x20,0x3F},	//0x33
{0x21,0x00},	//不允许自动应答
{0x22,0x3f},	//Pipe0,Pipe1
{0x23,0x03},	//4byte 地址宽度
{0x24,0xff},	//????15?,????4000us
//{0x25,0x06},	//????82??(0x52=82d)
{0x25,0x00},	//????82??(0x52=82d)
{0x26,0x26},	//250Kbps data rate, output power=5dBm	//?????,????2423???2421???
{0x27,0x77},	//??????//??????0x077,????0x07,?????????!!!!!!
{0x28,0x00},	//??
{0x29,0x00},	//??
{0x2C,0xc3},	//??2????
{0x2D,0xc4},	//??3????
{0x2E,0xc5},	//??4????
{0x2F,0xc6},	//??5????
{0x31,0x0A},	//16byte
{0x32,0x0A},	//
{0x33,0x0A},	//
{0x34,0x0A},	//
{0x35,0x0A},	//
{0x36,0x0A},	//
{0x37,0x00},
{0x3D,0x00},	//??????????????
{0x3C,0x00}		//0x07	
};

unsigned char const CH_LIST_DM[4]=
{
	  //BIND_00	
0, 
0, 
0, 
0, 	
//		9,    
// 		32,
//		48,
//		64,
};

unsigned char const CH_LIST_WK[36]=
{
		10,
  	26,
  	42,   
  	58, 		         
 		 69,
  	//WORK_01
		18,
  	34,
  	50,   
  	66, 		         
 		    
    //WORK_02
		42,
  	10,
  	66,   
  	34, 		         
       
    //WORK_03
    26,
  	58,
  	18,   
  	50,
	
};
/*
unsigned char const CH_LIST_WK[36]=
{
		50,
  	58,
  	66,   
  	74, 		         
 		 
  	//WORK_01
		54,
  	61,
  	67,   
  	74, 		         
 		    
    //WORK_02
		50,
  	64,
  	61,   
  	74, 		         
       
    //WORK_03
    58,
  	70,
  	54,   
  	67,
	
};
*/
/*************************************************         
Function: SPI_RW();                                         
                                                            
Description:                                                
	Writes one unsigned char to BK2421, and return the unsigned char read 
*************************************************/        
/*
unsigned char SPI_R()                                    
{                                                           
	unsigned char bit_ctr,value;
	u8 i;
 	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   // output 8-bit
	{
		value = (value << 1);           // shift next bit into MSB..
		for(i=0;i<10;i++);
		SCK_LOW;                 // Set SCK high..
  	if(READ_MISO)
		value	|=	0x01;								// capture current MISO bit
		SCK_SET;         		  		// ..then set SCK low again
	}
	return(value);           		  	// return read unsigned char
} 
*/
 /**************************************************         
Function: SPI_RW();                                         
                                                            
Description:                                                
	Writes one unsigned char to BK2421, and return the unsigned char read 
*************************************************/        
unsigned char SPI_RW(unsigned char value)                                    
{                                                           
	unsigned char bit_ctr;
	u8 i;
 	for(bit_ctr=0;bit_ctr<8;bit_ctr++)   // output 8-bit
	{
		if(value & 0x80)
		{
			MOSI_SET;
		}
		else
		{
			MOSI_LOW;		
		}

		value = (value << 1);           // shift next bit into MSB..
		
		for(i=0;i<5;i++);
		SCK_SET;                      // Set SCK high..
                
		if(MISO)
		value	|=	0x01;								// capture current MISO bit
		SCK_LOW;            		  		// ..then set SCK low again
	}
	return(value);           		  	// return read unsigned char
}   
/**************************************************         
Function: SPI_Write_Reg();                                  
                                                            
Description:                                                
	Writes value 'value' to register 'reg'              
*************************************************/        
void SPI_Write_Reg(unsigned char reg, unsigned char value)                 
{
	CSN_LOW;                   // CSN low, init SPI transaction
	SPI_RW(reg);      // select register
	SPI_RW(value);             // ..and write value to it..
	CSN_SET;                   // CSN high again
} 
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Read_Reg();                                   
                                                            
Description:                                                
	Read one unsigned char from BK2421 register, 'reg'     
*************************************************/        
unsigned char SPI_Read_Reg(unsigned char reg)                               
{                                                           
	unsigned char value;
	CSN_LOW;                // CSN low, initialize SPI communication...
	SPI_RW(reg);            // Select register to read from..
	value = SPI_RW(0);    // ..then read register value
	CSN_SET;                // CSN high, terminate SPI communication
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
	unsigned char byte_ctr;                              
                                                            
	CSN_LOW;                    		// Set CSN l
	SPI_RW(reg);       		// Select register to write, and read status unsigned char
                                                            
	for(byte_ctr=0;byte_ctr<length;byte_ctr++)           
		pBuf[byte_ctr] = SPI_RW(0);    // Perform SPI_RW to read unsigned char from BK2421 
                                                            
	CSN_SET;                           // Set CSN high again
               
}                                    
/**************************************************/        
                                                            
/**************************************************         
Function: SPI_Write_Buf();                                  
                                                            
Description:                                                
	Writes contents of buffer '*pBuf' to BK2421         
**************************************************/      

void SPI_Write_Buf(unsigned char reg, unsigned char *pBuf, unsigned char length)    
{                                                           
	unsigned char byte_ctr;                              
                                                            
	CSN_LOW;                   // Set CSN low, init SPI tranaction
	SPI_RW(reg);    // Select register to write to and read status unsigned char
	for(byte_ctr=0; byte_ctr<length; byte_ctr++) // then write all unsigned char in buffer(*pBuf) 
	SPI_RW(*pBuf++);                                    
	CSN_SET;                 // Set CSN high again      

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
*************************************************/

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
Function: SwitchToRxMode();
Description:
	switch to Rx mode
**************************************************/
void SwitchToRxMode(void)
{
 	unsigned char value,Work_Channel_Num;
	
//	SPI_Write_RegSetup(7,0x00,0x00);
//	SPI_Write_RegSetup(52,0x80,0x80);
	
	
	RF_Channel_JMP = RF_Channel_JMP & 0x03;
	
	if (RF_Channel_DMFlag == 1)
	{
		Work_Channel_Num = CH_LIST_DM[RF_Channel_JMP];
	}
	else
	{
		value = ((RF_Channel >> 3) & 0x03) *4;
		value =	value + (RF_Channel_JMP & 0x03);
		
		if (XY_Ver == 0XAA)
			Work_Channel_Num =	CH_LIST_WK[value];
		else
			Work_Channel_Num = Channel_Tab[value];
		
		Work_Channel_Num = Work_Channel_Num + (RF_Channel & 0x07);
		if ((Work_Channel_Num & 0x0f) == 0)
			Work_Channel_Num ++ ;
	}
	
	SPI_Write_Reg(0x25,Work_Channel_Num);
	//SPI_Write_Reg(0x20,0x33);
}
/**************************************************         
Function: SPI_Bank1_Read_Reg();                                  
                                                            
Description:                                                
	read a Bank1 register
**************************************************/ 

void SPI_Bank1_Read_Reg(unsigned char reg, unsigned char *pBuf)
{
	SwitchCFG(1);
	SPI_Read_Buf(reg,pBuf,4);
	SwitchCFG(0);
}

/**************************************************
Function: Get_Chip_ID();

Description:
	Get chip ID
**************************************************/

unsigned char Get_Chip_ID(void)
{
	unsigned char ReadArr[4];
	SPI_Bank1_Read_Reg(0x08,ReadArr);
	return ReadArr[0];
}

/**************************************************
Function: SwitchToTxMode();
Description:
	switch to Tx mode
**************************************************/

void SwitchToTxMode(void)
{
	unsigned char value;
	SPI_Write_Reg(FLUSH_TX,0);//flush Tx

	//CE_LOW;
	value=SPI_Read_Reg(CONFIG);	// read register CONFIG's value
//PTX
	value=value&0xfe;//set bit 1
	SPI_Write_Reg(WRITE_REG | CONFIG, value); // Set PWR_UP bit, enable CRC(2 length) & Prim:RX. RX_DR enabled.
	//CE_SET;
	value=SPI_Read_Reg(CONFIG);	// read register CONFIG's value
}

/**************************************************
Function: SetChannelNum();
Description:
	set channel number
??????????1MHz
**************************************************/
void Send_Packet(u8 type,u8* pbuf,u8 len)
{
	u8 fifo_sta;

	fifo_sta=SPI_Read_Reg(FIFO_STATUS);	// read register FIFO_STATUS's value

	if((fifo_sta&FIFO_STATUS_TX_FULL)==0)//if not full, send data  
	  	SPI_Write_Buf(type, pbuf, len); // Writes data to buffer  A0,B0,A8
	  	 	
}

/**************************************************   

Function: BK2421_Initialize();                                  

Description:                                                
	register initialization
**************************************************/   
void BK2425_Init(void)
{
	signed char i,j;
 	unsigned char WriteArr[4],getID;
	io_rf_init();
	while((getID!=0x63))
	{
// 	  CSN_SET;
//		SCK_SET;
//		CE_SET;
//		MOSI_SET;
//	  UT_Delay_Nms(50);
		CSN=1;
		Delay1ms(50);
//		CE_LOW;
		SwitchCFG(0); //point to bank0
	
	//********************Write Bank0 register******************
		for(i=20;i>=0;i--)
			SPI_Write_Reg((WRITE_REG|Bank0_Reg[i][0]),Bank0_Reg[i][1]);
	        

			 SPI_Write_Reg(ACTIVATE_CMD,0x73);// Active
			

	
			for(i=22;i>=21;i--)
	  SPI_Write_Reg((WRITE_REG|Bank0_Reg[i][0]),Bank0_Reg[i][1]);
		
		

	//********************Write Bank1 register******************
		SwitchCFG(1);
	
		for(i=0;i<=8;i++)//reverse
		{
			for(j=0;j<4;j++)
				WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(j) ) )&0xff;
	
			SPI_Write_Buf((WRITE_REG|i),&(WriteArr[0]),4);
		}
	
		for(i=9;i<=13;i++)
		{
			for(j=0;j<4;j++)
				WriteArr[j]=(Bank1_Reg0_13[i]>>(8*(3-j) ) )&0xff;
	
			SPI_Write_Buf((WRITE_REG|i),&(WriteArr[0]),4);
		}
	
		SPI_Write_Buf((WRITE_REG|14),&(Bank1_Reg14[0]),11);
	
	//toggle REG4<25,26>
		for(j=0;j<4;j++)
			WriteArr[j]=(Bank1_Reg0_13[4]>>(8*(j) ) )&0xff;
	
		WriteArr[0]=WriteArr[0]|0x06;
		SPI_Write_Buf((WRITE_REG|4),&(WriteArr[0]),4);
	
		WriteArr[0]=WriteArr[0]&0xf9;
		SPI_Write_Buf((WRITE_REG|4),&(WriteArr[0]),4);
	
//		UT_Delay_Nms(50);
		Delay1ms(50);
	//********************switch back to Bank0 register access******************
		SwitchCFG(0);
		i=SPI_Read_Reg(0x00);
		if (i==Bank0_Reg[0][1])
			getID=0x63;																				//Get_Chip_ID();
		else
			getID=0x00;	
	}
//	 CE_SET;
//	 UT_Delay_Nms(20);
	Delay1ms(20);
       // Get_WorkID();
        //delay(1);//delay more than 50ms.
	RF_address_set(P0_Address);
//	SwitchToRxMode();		//switch to RX mode	
	SwitchToTxMode();


}
void  work_address_set(void)
{
 	RF_address_set(P0_Address);
	SwitchToRxMode();		//switch to RX mode
}
void  RF_address_set(u8 *add_buf)
{
	CE_LOW;
  SPI_Write_Reg(WRITE_REG|0x02,0x01);			//???Pipe0
  SPI_Write_Buf((WRITE_REG|0x0a),add_buf,5);	//?????P0????,????P0?0x0a,???0x10;
  CE_SET;
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
	u8 len,sta,fifo_sta;
	u8 rx_buf[32];

	sta=SPI_Read_Reg(STATUS);	// read register STATUS's value
	if(sta&STATUS_RX_DR)				// if receive data ready (RX_DR) interrupt
	{
		do
		{
			len=SPI_Read_Reg(R_RX_PL_WID_CMD);	// read len

			if(len<=32)
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



