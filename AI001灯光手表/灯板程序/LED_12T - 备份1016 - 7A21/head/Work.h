   #ifndef _WORK_H
   #define _WORK_H
#define LED_0FF  {GET1=0;GET2=0;GET3=0;COM1=1;COM2=1;COM3=1;COM4=1;LED_State=0;}
#define LED_OPEN_Time 10   //LED亮的时间

#define LED_OPEN_T  (0xff-(127-LED_OPEN_Time))
#define LED_CLOSE_T (0xff-LED_OPEN_Time)
//#define LED_0FF  {P0=0;P1=LED_State=0;}
void Forward_PWM_Dir(void);
void WriteEeprom(void);
u8 ReadEeprom(void);
void Scan_LED(void);
extern bit LED_State;
extern u8 LED_Count;   
extern u8 LED_Cycle;//LED运行周期，走完12点为一个周期
   #endif