#include "ALL_Includes.h"

//       读写FIFO 16位缓存器          //
unsigned char RegH;
unsigned char RegL;              //Used to store the Registor Value which is read.
//#define  RST        = P1^1;
#define SPI_SS       P11			    
#define SPI_CLK      P14 
#define SPI_MOSI          P13
#define SPI_MISO          P12

#define LED11          P10
#define LED22          P15
//#define PKT        = P3^2;


/*****************************************/
// SPI Write and Read ,as well as Read8  // 
/*****************************************/

void SPI_WriteReg(unsigned char addr, unsigned char H, unsigned char L)
{
	int i;

	SPI_SS = 0;

	for(i = 0; i < 8; ++ i)
	{
		MOSI = addr & 0x80;

		SPI_CLK = 1;                       //capturing at the down side.
		SPI_CLK = 0;

		addr = addr << 1;                    //There is no Delay here. determines the rate of SPI.
	}

	for(i = 0; i < 8; ++i)                 //Write H
	{
		
		MOSI = H & 0x80;
		SPI_CLK = 1;
		SPI_CLK = 0;

		H = H << 1;
	}

	for(i = 0; i < 8; ++i)                 //Write L
	{  
		MOSI = L & 0x80;

		SPI_CLK = 1;
		SPI_CLK = 0;

		L = L << 1;
	}

	SPI_SS = 1;
}


void SPI_ReadReg(unsigned char addr)
{
	int i;
	
	SPI_SS = 0;
	addr += 0x80;                    //when reading a Register,the Address should be added with 0x80.

	for(i = 0; i < 8; ++ i)
	{
		MOSI = addr & 0x80;

		SPI_CLK = 1;
		SPI_CLK = 0;

		addr = addr << 1;                      //Move one bit to the left.
	}

	for(i = 0; i < 8; ++ i)
	{
		SPI_CLK = 1;                         //transmit at the up side.
		SPI_CLK = 0;

		RegH = RegH << 1;  
		RegH |= MISO;
	}

	
	
	for(i = 0; i < 8; ++ i)
	{
		SPI_CLK = 1;                         //transmit at the up side.
		SPI_CLK = 0;

		RegL = RegL << 1; 
		RegL |= MISO;
	}

	SPI_SS = 1;
}


/***************************************/
// LT8900 Initializing Function        //
/***************************************/

void LT8900_Init(void)
{

//    RST  = 0;
//	Delay_ms(2);
//	RST  = 1;
//	Delay_ms(5);
//	PKT = 1;

	SPI_WriteReg( 0, 0x6f, 0xef );
	SPI_WriteReg( 1, 0x56, 0x81 );
	SPI_WriteReg( 2, 0x66, 0x17 );
	SPI_WriteReg( 4, 0x9c, 0xc9 );
	SPI_WriteReg( 5, 0x66, 0x37 );
	SPI_WriteReg( 7, 0x00, 0x00 );							  //channel is 2402Mhz
	SPI_WriteReg( 8, 0x6c, 0x90 );
	SPI_WriteReg( 9, 0x48, 0x00 );			  				  //PA -12.2dbm
	SPI_WriteReg(10, 0x7f, 0xfd );
	SPI_WriteReg(11, 0x00, 0x08 );
	SPI_WriteReg(12, 0x00, 0x00 );
	SPI_WriteReg(13, 0x48, 0xbd );
	SPI_WriteReg(22, 0x00, 0xff );
	SPI_WriteReg(23, 0x80, 0x05 );
	SPI_WriteReg(24, 0x00, 0x67 );
	SPI_WriteReg(25, 0x16, 0x59 );
	SPI_WriteReg(26, 0x19, 0xe0 );
	SPI_WriteReg(27, 0x13, 0x00 );
	SPI_WriteReg(28, 0x18, 0x00 );
	SPI_WriteReg(32, 0x58, 0x00 );
	SPI_WriteReg(33, 0x3f, 0xc7 );
	SPI_WriteReg(34, 0x20, 0x00 );
	SPI_WriteReg(35, 0x0a, 0x00 );				    /* 重发次数为9次 一共发送10次*/

	SPI_WriteReg(36, 0x03, 0x80 );
	SPI_WriteReg(37, 0x03, 0x80 );
	SPI_WriteReg(38, 0x5a, 0x5a );
	SPI_WriteReg(39, 0x03, 0x80 );

	SPI_WriteReg(40, 0x44, 0x02 );
	//SPI_WriteReg(41, 0xb4, 0x00 );	                /*CRC is ON; scramble is OFF; AUTO_ACK is OFF*/
	SPI_WriteReg(41, 0xb8, 0x00 );	                    /*CRC is ON; scramble is OFF; AUTO_ACK is ON*/
	
    #ifdef LT8910
	SPI_WriteReg(42, 0xfd, 0xff );					/*等待RX_ACK时间 255us  62.5KBPS*/
    #else
	SPI_WriteReg(42, 0xfd, 0xb0 );					/*等待RX_ACK时间 176us*/
	#endif
	
	SPI_WriteReg(43, 0x00, 0x0f );
}



/*****************************************************/
/*   写寄存器突发模式  入口参数 */
/*****************************************************/
/*
 void SPIBurst_WriteReg(unsigned char add, unsigned char num)
{
	unsigned char temp;
	unsigned char i;
	

	SPI_SS = 0;

	for(i = 0; i < 8; ++ i)
	{
		MOSI = add & 0x80;

		SPI_CLK = 1;                       //capturing at the down side.
		SPI_CLK = 0;

		add = add << 1;                    //There is no Delay here. determines the rate of SPI.
	}
	
	while(num)						          //一共写入num个bytes，分别为 num, num-1，num-2，num-3...
	{
		temp = num;
		
		for(i = 0; i < 8; ++i)                 //Write H
			{
		
				MOSI = temp & 0x80;
				SPI_CLK = 1;
				SPI_CLK = 0;

				temp = temp << 1;
			}

		-- num;
	}
	
	SPI_SS = 1;
}
 */
 u8 index_state;
 #define TX_DAT1 0x01	 //发送数据1			
#define TX_DAT2 0x02     //发送数据2
#define INT_RX  0x03     //初始化接收模式
#define RX_MOD  0x00     //常规接收模式
unsigned char RBUF[32];
 void RF_STAK(void)
 {bit PKT=0;
	 u8 count=0,i,j;
//#ifdef LT8910
//	//8910设置成62.5kbps Reg44 地址上配置 1000H, Reg45 配置 0552H， 是 62.5Kbps
//	SPI_WriteReg(44, 0x10, 0x00);
//	SPI_WriteReg(45, 0x05, 0x52);	
//	#endif
	//-----------------
	//读出寄存器的值检查硬件读写时序是否正确
	SPI_ReadReg(40);
	if (RegH==0x44 && RegL==0x02)
	{
//		LED1_ON();
//		LED2_ON();
//		Delay_ms(200);
//		LED1_OFF();
//		LED2_OFF();
	}
    //-----------------
    count=0;
    //-----------------
	while (1)
	{
//	    if(time_5ms_flag)
//	    	{
//		    Get_KeyValue(&keyvalue);         //cost 50us
//		    time_5ms_flag=FALSE;
//			
//			if(count<600)
//               count++;
//			if(count==600)
//				{
//				LED2_OFF();
//				LED1_OFF();				
//				}
//	    	}
//		switch(keyvalue)
//		{
//		    case (KEY1|KEY_PRESS):
//            index_state=TX_DAT1;
//			break;

//			case (KEY2|KEY_PRESS):
//            index_state=TX_DAT2;
//			break;

//			default :  break;
//		}
         SysTimer_Process();
		if(bsystem5Msec)  
		{if(index_state!=TX_DAT1)
			{index_state=TX_DAT1;}

         }
		switch(index_state)
		{
		    case INT_RX:
            //设置成数据接收模式
  	        SPI_WriteReg(52, 0x80, 0x80);
    	      SPI_WriteReg(7, 0x00, 0x80 + 0x20);	
			      index_state=RX_MOD;
			break;
        case RX_MOD:
			//检查是否接收到数据
				SPI_ReadReg(48);
		    if((RegL&0x40)==1)
				{PKT=1;}
				else
				{PKT=0;}
		    if(PKT == 1)
			{
		    i=0;
		    SPI_ReadReg(50);
	        j=RegH;//读取包长度
		    while(i<j)
			 {
			 //读取数据
			 SPI_ReadReg(50);
			 RBUF[i++]=RegH;
			 RBUF[i++]=RegL;
			 if(i==32)
			 	break;
			 }   
		    //一旦发生错误，寄存器 Reg48 bit15 位 CRC_ERROR 将被自动置 1，在下次开始 RX 或 TX 时它将被清除。
            //Test CRC
		    SPI_ReadReg(48);
		    if((RegH&0x80)==0)
			 {
			 //判断数据点亮灯
			 if(RBUF[0]==1)
			 	{
			 	LED11=1;
				count=0;
			 	}
			 else if(RBUF[0]==2)
			 	{
			 	LED22=1;
				count=0;
			 	}
			 }
			//再次初始化为接收模式
			index_state=INT_RX;
			//LED1_OFF();
		    }
			break;

			case TX_DAT1:
 		   //将数据发送出去
		   SPI_WriteReg(52, 0x80, 0x80);
		   //i=0;
		   //写入长度 长度包含长度字节本身
		   SPI_WriteReg(50, 2,0);
           //写入数据
		   SPI_WriteReg(50, 1,0);
           //开始发送
		   SPI_WriteReg(7, 0x01, 0x20);
			
		   while (PKT== 0)
			 { SPI_ReadReg(48);
		    if((RegL&0x40)==1)
				{PKT=1;}
				else
				{PKT=0;}      }; //等待发送完成
           //判断是否收到对方自动应答信号,REG52<13:8>应为0
           SPI_ReadReg(52);
		   if((RegH& 0x3F)==0)//如果收到应答信号点亮本地对应的LED
		   	{
		   	   LED11=1;
			   count=0;
		   	}
		   //发送完成初始化为接收模式
		   index_state=INT_RX;
			break;

			case TX_DAT2:
 		   //将数据发送出去
		   SPI_WriteReg(52, 0x80, 0x80);
		   i=0;
		   //写入长度 长度包含长度字节本身
		   SPI_WriteReg(50, 2,0);
           //写入数据
		   SPI_WriteReg(50, 2,0);
           //开始发送
		   SPI_WriteReg(7, 0x01, 0x20);

		   while (PKT== 0)
			 { SPI_ReadReg(48);
		    if((RegL&0x40)==1)
				{PKT=1;}
				else
				{PKT=0;}      }; //等待发送完成
           //判断是否收到对方自动应答信号,REG52<13:8>应为0
           SPI_ReadReg(52);
		   if((RegH& 0x3F)==0)//如果收到应答信号点亮本地对应的LED
		   	{
		   	   LED22=1;
			   count=0;
		   	}
		   //发送完成初始化为接收模式
		   index_state=INT_RX;
			break;

		    default:break;
		}
		
	}
}