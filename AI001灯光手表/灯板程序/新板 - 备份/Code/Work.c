
#include "ALL_Includes.h"
#define SaveCount     10
u16 EEPROM_DATA[SaveCount];

u8 TIME_MIN=0;//1分钟时间
u8 LED_Bri=3;//led的亮度
u8 LED_OPEN_T=Default_LED_OPEN_T;
u8 LED_CLOSE_T=Default_LED_CLOSE_T;
u8 LED_OPEN_Time=Default_LED_OPEN_Time;
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
 		
void Scan_LED(void)
{	static u8 LED_Count1=0;

	switch(LED_Count)
	{
	case LEDC1:
					if((LED_Count1&0x01)==1)
		      {GET3=0;
		      GET1=1;
		      COM4=0;
					}
					else
					{COM4=1;}
		      RWK=LED_OPEN_T;
	break;
	case LEDC0:
		      COM4=1;
		      RWK=LED_CLOSE_T;
	break;		
	case LED11:
        if((LED_Count1&0x01)==1)
				{
		     COM4=1;
		     GET1=1;
		     COM1=0;
				}
				else
				{COM1=1;}
	       RWK=LED_OPEN_T;
//	       LED_Count++;
	break;
	case LED10:
		     COM1=1;
	       RWK=LED_CLOSE_T;
//	   LED_Count1++;
//	if(LED_Count1>=5)
//	{LED_Count1=0;
//	 LED_Count++;}
//	else LED_Count--;
	break;		
	case LED21:
		 if((LED_Count1&0x01)==1)
				{
	       COM2=0;
				}
				else
				{COM2=1;}
	       RWK=LED_OPEN_T;
//	       LED_Count++;
	break;
	case LED20:
	       COM2=1;
	       RWK=LED_CLOSE_T;
	break;	
	case LED31:
 if((LED_Count1&0x01)==1)
				{
	       COM3=0;
				}
				else
				{COM3=1;}
	       RWK=LED_OPEN_T;
	break;
	case LED30:
	       COM3=1;
	       RWK=LED_CLOSE_T;
	break;	
	case LED41:
		 if((LED_Count1&0x01)==1)
		 {
		     GET1=0;
	       GET2=1;
	       COM1=0;
		 }
		 else
		 {COM1=1;}
	       RWK=LED_OPEN_T;
	break;
	case LED40:
	       COM1=1;
	       RWK=LED_CLOSE_T;
	break;	
	
	case LED51:
 if((LED_Count1&0x01)==1)
		 {
	       COM2=0;
		 }
		 else
		 { COM2=1;}
	       RWK=LED_OPEN_T;
	break;
	case LED50:
	       COM2=1;
	       RWK=LED_CLOSE_T;
	break;	
	case LED61:
		 if((LED_Count1&0x01)==1)
		 {
	       COM3=0;
		 }
		 else
		 { COM3=1;}
	       RWK=LED_OPEN_T;
	break;
	case LED60:
	       COM3=1;
	       RWK=LED_CLOSE_T;
	break;	
	case LED71:
				 if((LED_Count1&0x01)==1)
		 {
	      COM4=0;
		 }
		 else
		 {COM4=1;}
	      RWK=LED_OPEN_T;
	break;
	case LED70:
		
	      COM4=1;
	      RWK=LED_CLOSE_T;
	break;	
	case LED81:
		   if((LED_Count1&0x01)==1)
			 {
	       GET2=0;
	       GET3=1;
	       COM1=0;
			 }
			 else
			 {COM1=1;}
		     RWK=LED_OPEN_T;
	break;
	case LED80:
	      COM1=1;
	      RWK=LED_CLOSE_T;
	break;	
	case LED91:
		 if((LED_Count1&0x01)==1)
		 {
	       COM2=0;
		 }
		 else
		 { COM2=1;}
	       RWK=LED_OPEN_T;
	break;
	case LED90:
	      COM2=1;
	      RWK=LED_CLOSE_T;
	break;	
	case LEDA1:
		if((LED_Count1&0x01)==1)
		{
	       COM3=0;	
		}else
		{ COM3=1;}
         RWK=LED_OPEN_T;	
	break;
	case LEDA0:
	       COM3=1;
         RWK=LED_CLOSE_T;	
	break;
	case LEDB1:
				if((LED_Count1&0x01)==1)
		{
	       COM4=0;}
			else
			{ COM4=1;}
         RWK=LED_OPEN_T;	
	break;	
	case LEDB0:
	      COM4=1;
        RWK=LED_CLOSE_T;	
	break;
	}

 //LED_Count++;
if((LED_Count&0x01)==0)
{ LED_Count++;}
else
{  
	if(LED_Count1%5==4)
	{
//		LED_Count1=0;
	 LED_Count++;}
	
	else LED_Count--;
	 
	 LED_Count1++;
}
	if(LED_Count>=24)
	{  LED_Count=0;
	   TIME_MIN++;}
	 
}	

 #define RELOAD_RWK(CNT) { clr_WKTR;RWK=CNT;set_WKTR;  }
 code u8 LED_MA[13]={0X33,0X93,0XA3,0XB1,0X17,0X27,0X35,0X36,0X1B,0X2B,0X39,0X3A,0XB2};
 u8 LED_CNT=1;
 u8 TIME_S=0;
 u8 LED_T;
 bit LED_state=0;
 void Scan_LED1(void)
 {static u8 STEP=1;
switch(STEP)
	 {
		 case 1:
			RELOAD_RWK(Default_LED_OPEN_T);
		 // if(TIME_S&0x01)
//		 	P0=LED_MA[(TIME_S/5)+1];
         LED_state=1;
		  STEP++;
		 break;
		 case 2:
			RELOAD_RWK(Default_LED_CLOSE_T);
		 LED_state=0;
//		 	P0=LED_MA[0];
		  
		 TIME_S++;
		 if(TIME_S>=60)
		 {TIME_S=0;
		  TIME_MIN++;}
		 STEP--;
		 break;
}
  clr_WKTF;
 }
	u8 LED_Duty=2,LED_cycle=5;   

 void LED_Ctrl(void)
 { u8 i,temp,temp2;
	 if(LED_state==1)
	 {temp=TIME_S/5+1;
	  temp2=LED_cycle-LED_Duty;}
	 while(LED_state==1)
 { 
	for(i=0;i<LED_Duty;i++) 
  {P0=LED_MA[temp];}
	for(i=0;i<temp2;i++)
	{
   P0=LED_MA[0];
	}
 }

 }