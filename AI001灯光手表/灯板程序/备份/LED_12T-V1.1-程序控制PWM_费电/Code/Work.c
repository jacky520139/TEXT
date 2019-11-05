
#include "ALL_Includes.h"
#define SaveCount     10
u16 EEPROM_DATA[SaveCount];
bit LED_State=0;
u8 LED_Minute=0;//LED运行周期，走完12点为一个周期
u8 LED_Bri=3;//led的亮度
u8 LED_OPEN_T=Default_LED_OPEN_T;
u8 LED_CLOSE_T=Default_LED_CLOSE_T;
u8 LED_OPEN_Time=Default_LED_OPEN_Time;
void Delay1us(u8 cnt)		//@5.5296MHz
{
//	unsigned char i;
//	_nop_();
//	i = cnt;
	while (--cnt);
}

/***************************************************************
* 函数功能：写入工作参数
* 输入参数：
* 输出参数：
***************************************************************/		
void WriteEeprom(void)
{
////////////////////写入工作参数/////////////////////////////	
//	EEPROM_DATA[0]=Software_NO;
//	EEPROM_DATA[1]=Work_Address[0];
//	EEPROM_DATA[2]=Work_Address[1];
//	EEPROM_DATA[3]=Work_Address[2];
//	EEPROM_DATA[4]=Work_Address[3];
//	EEPROM_DATA[5]=Work_Address[4];
	
  writerom(EEPROM_DATA,SaveCount);
} 
/***************************************************************
* 函数名称void ParameterReset(void)
* 函数功能：重置参数
* 输入参数无
* 输出参数：无
***************************************************************/
void ParameterReset(void)
{ 
//	Work_Address[0]=0xf1;
//	Work_Address[1]=0xf2;
//	Work_Address[2]=0xf3;
//	Work_Address[3]=0xf4;
//	Work_Address[4]=0xf5;
	WriteEeprom();
	readrom(EEPROM_DATA,SaveCount);	

}

/***************************************************************
* 函数名称void ReadEeprom(void)
* 函数功能：读取工作参数
* 输入参数无
* 输出参数：无
***************************************************************/
u8 ReadEeprom(void)
{
//	 readrom(EEPROM_DATA,SaveCount);
//	if(EEPROM_DATA[0]!=Software_NO)//初片设置出厂数据"14代表版本号"  
//	{
//		ParameterReset();
//   if(EEPROM_DATA[0]!=Software_NO)
//   return 1;}    
//		////////////////////读取工作参数////////////////////////////////
//	Work_Address[0]=EEPROM_DATA[1];
//	Work_Address[1]=EEPROM_DATA[2];
//	Work_Address[2]=EEPROM_DATA[3];
//	Work_Address[3]=EEPROM_DATA[4];
//	Work_Address[4]=EEPROM_DATA[5];
 
	 return 0;
		}

enum 
    { LED11,LED10,LED21,LED20,LED31,LED30,LED41,LED40,LED51,LED50,LED61,LED60,LED71,LED70,LED81,LED80,\
			LED91,LED90,LEDA1,LEDA0,LEDB1,LEDB0,LEDC1,LEDC0};
 
u8 LED_Count=0,LED_Count2=0;  
bit LED_ON_F=1;	
u8 LED_cycle=30;//LED的pwm周期
u8 LED_Duty=1;//LED的pwm的占空比
u8 LED_cycle_cnt=7;//LED的pwm周期数			
void Scan_LED(void)
{	static u8 Seconds=0;
  u8 RWK_T;
	u8 i;
	switch(LED_Count)
	{
	case LEDC1:
          GET3=0;
		      GET1=1;
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM4=0;
					Delay1us(LED_Duty);
					COM4=1;
					Delay1us(LED_cycle-LED_Duty);
					}
					LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LEDC0:
		      COM4=1;
		      RELOAD_RWK(0xff-LED_CLOSE_T);
	        Seconds++;
		     if(Seconds%5==4)
			 {LED_Count=LED11;}
			 else
			 {LED_Count--;}
	break;		
	case LED11:
				  COM4=1;
		      GET1=1;
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM1=0;
					Delay1us(LED_Duty);
					COM1=1;
					Delay1us(LED_cycle-LED_Duty);
					}
					LED_Count++; 
          RELOAD_RWK(0xfe);					
	break;
	case LED10:
		     COM1=1;
	       RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;		
	case LED21:
//		        if((Seconds&0x01)==1)
//				{
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM2=0;
					Delay1us(LED_Duty);
					COM2=1;
					Delay1us(LED_cycle-LED_Duty);
					}
					LED_Count++;   
					RELOAD_RWK(0xfe);
//				}
//				else
//				{COM2=1;
//				 RWK=235;
//				 LED_Count++;
//				}
//		 if((Seconds&0x01)==1)
//				{
//	       COM2=0;
//				}
//				else
//				{COM2=1;}
//	       RWK=LED_OPEN_T;
//	       LED_Count++;
	break;
	case LED20:
	       COM2=1;
         RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LED31:
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM3=0;
					Delay1us(LED_Duty);
					COM3=1;
					Delay1us(LED_cycle-LED_Duty);
					}
					LED_Count++; 
          RELOAD_RWK(0xfe);						
// if((Seconds&0x01)==1)
//				{
//	       COM3=0;
//				}
//				else
//				{COM3=1;}
//	       RWK=LED_OPEN_T;
//				LED_Count++;
	break;
	case LED30:
	       COM3=1;
         RELOAD_RWK(0xff-LED_CLOSE_T);
//	       RWK=LED_CLOSE_T;
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LED41:
		      GET1=0;
	        GET2=1;
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM1=0;
					Delay1us(LED_Duty);
					COM1=1;
					Delay1us(LED_cycle-LED_Duty);
					}
		 LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LED40:
	       COM1=1;
	       RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	
	case LED51:
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM2=0;
					Delay1us(LED_Duty);
					COM2=1;
					Delay1us(LED_cycle-LED_Duty);
					}
		 LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LED50:
	       COM2=1;
	       RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LED61:
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM3=0;
					Delay1us(LED_Duty);
					COM3=1;
					Delay1us(LED_cycle-LED_Duty);
					}
		 LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LED60:
	       COM3=1;
	        RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LED71:
					for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM4=0;
					Delay1us(LED_Duty);
					COM4=1;
					Delay1us(LED_cycle-LED_Duty);
					}
		 LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LED70:
		
	      COM4=1;
	       RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LED81:

	       GET2=0;
	       GET3=1;
	      for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM1=0;
					Delay1us(LED_Duty);
					COM1=1;
					Delay1us(LED_cycle-LED_Duty);
					}
			 LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LED80:
	      COM1=1;
	      RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LED91:
	      for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM2=0;
					Delay1us(LED_Duty);
					COM2=1;
					Delay1us(LED_cycle-LED_Duty);
					}
		 LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LED90:
	      COM2=1;
	      RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;	
	case LEDA1:
	      for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM3=0;
					Delay1us(LED_Duty);
					COM3=1;
					Delay1us(LED_cycle-LED_Duty);
					}
		LED_Count++;
					RELOAD_RWK(0xfe);	
	break;
	case LEDA0:
	       COM3=1;
         RELOAD_RWK(0xff-LED_CLOSE_T);
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count++;}
			 else
			 {LED_Count--;}
	break;
	case LEDB1:
	      for(i=0;i<LED_cycle_cnt;i++)
					{
		      COM4=0;
					Delay1us(LED_Duty);
					COM4=1;
					Delay1us(LED_cycle-LED_Duty);
					}
LED_Count++;
RELOAD_RWK(0xfe);						
	break;	
	case LEDB0:
	      COM4=1;
         RELOAD_RWK(0xff-LED_CLOSE_T);
	  LED_Count=LEDC1;
	       Seconds++;
	     if(Seconds%5==4)
			 {LED_Count=LEDC1;}
			 else
			 {LED_Count--;}
	break;
	}
//RWK=0xff-LED_OPEN_T;
//RWK=0xff-RWK_T;	
// //LED_Count++;
//if((LED_Count&0x01)==0)
//{ LED_Count++;}
//else
//{  
//	if(Seconds%5==4)
//	{
////		Seconds=0;
//	 LED_Count++;}
//	
//	else LED_Count--;
//	 
//	 Seconds++;
//}
//	if(LED_Count>=24)
//	{  LED_Count=0;
//	   LED_Cycle++;}

 
		 
		 
		 
		 
		 
		 
}	
 
 
 