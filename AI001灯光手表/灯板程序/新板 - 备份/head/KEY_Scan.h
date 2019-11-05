#ifndef KEYSCAN_H
#define KEYSCAN_H
#define Long_Trg_Value    0xff
//#define KeyClean 		KEY1_Dev.Value=0;KEY2_Dev.Value=0;KEY3_Dev.Value=0;KEY4_Dev.Value=0;KEY5_Dev.Value=0;
//#define KeySecOn    KEY1_Dev.Value==1||KEY2_Dev.Value==1||KEY3_Dev.Value==1||KEY4_Dev.Value==1||KEY5_Dev.Value==1

enum Mode_Name{Single=0,Variety};
/*****************变量声明**********************/
typedef struct  
{	
	u8	 Mode;//按键模式（0：按下触发 1：弹起触发，支持长按，多击）
	u8	 Lock;//自锁标志
	u8   Trg;//击打次数
	u32  Up_Time;//按下时间
	u32  Down_Time;//上弹时间
  u8   Value;//按键值（点击次数，长按为oxff）	
}_KEY_Dev;
extern _KEY_Dev xdata	 KEY1_Dev;
 /*****************函数声明**********************/
void Key_Scan(void) ;
#endif


