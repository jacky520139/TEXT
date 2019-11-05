   #ifndef _WORK_H
   #define _WORK_H
#define LED_0FF  {GET1=0;GET2=0;GET3=0;COM1=1;COM2=1;COM3=1;COM4=1;LED_State=0;}
#define RELOAD_RWK(CNT) {clr_WKTR;RWK=CNT;set_WKTR;}

#define Default_LED_OPEN_Time 15   //LED亮的时间
#define Default_LED_OPEN_T  (0xff-Default_LED_OPEN_Time)

#define Default_LED_CLOSE_T 120
//#define LED_OPEN_T  (0xff-(127-LED_OPEN_Time))
//#define LED_CLOSE_T (0xff-LED_OPEN_Time)
//#define LED_OPEN_T  (0xff-10)
//#define LED_CLOSE_T (0xff-10)
//#define LED_0FF  {P0=0;P1=LED_State=0;}
//#define LED_OPEN_T  (0xff)
//#define LED_CLOSE_T (0xff-3)
	
extern u8 LED_OPEN_T;
extern u8 LED_CLOSE_T;
extern u8 LED_OPEN_Time;

void Forward_PWM_Dir(void);
void WriteEeprom(void);
u8 ReadEeprom(void);
void Scan_LED(void);
extern bit LED_State;
extern u8 LED_Count;   
extern u8 LED_Minute;//LED运行周期，走完12点为一个周期
   #endif