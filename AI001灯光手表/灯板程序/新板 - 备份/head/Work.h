   #ifndef _WORK_H
   #define _WORK_H
#define LED_0FF  {GET1=0;GET2=0;GET3=0;COM1=1;COM2=1;COM3=1;COM4=1;LED_State=0;}
#define Default_LED_OPEN_Time 55   //LED亮的时间
#define Default_LED_OPEN_T  (0xff-Default_LED_OPEN_Time)
#define Default_LED_CLOSE_T (0xff-(126-Default_LED_OPEN_Time))

//#define LED_OPEN_T  (0xff-(127-LED_OPEN_Time))
//#define LED_CLOSE_T (0xff-LED_OPEN_Time)
//#define LED_OPEN_T  (0xff-10)
//#define LED_CLOSE_T (0xff-10)
//#define LED_0FF  {P0=0;P1=LED_State=0;}
//#define LED_OPEN_T  (0xff)
//#define LED_CLOSE_T (0xff-3)
extern code u8 LED_MA[13];
extern u8 LED_OPEN_T;
extern u8 LED_CLOSE_T;
extern u8 LED_OPEN_Time;
extern u8 LED_Duty,LED_cycle; 
void Forward_PWM_Dir(void);
void WriteEeprom(void);
u8 ReadEeprom(void);
void Scan_LED(void);
extern bit LED_State;
extern u8 TIME_S;   
extern u8 TIME_MIN;//1分钟时间
 void Scan_LED1(void);
  void LED_Ctrl(void);
   #endif