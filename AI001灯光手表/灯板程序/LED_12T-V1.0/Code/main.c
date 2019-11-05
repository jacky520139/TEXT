
#include "ALL_Includes.h"
void main (void)
{	 
	InitSystem();
	while(1)
	{	if(LED_Cycle>=1)
		{ LED_0FF;
		  clr_WKTR;
			PIF=0;
		  set_EPI;}//周期到了后不运行自动唤醒
//		  BG_1_22V=ADC_Read(8);
//			VDD_VAL=(u32)4096*122/BG_1_22V;
//		  ANO_DT_Send_Version(0XF1, VDD_VAL, ADC_Read(4),0 , 0, 0);
		  set_PD;//进入休眠	
		}
	
//  while(1)
//	{   
//    SysTimer_Process();
//			if(bsystem2Msec)
//			{
////				clr_HIRCST;		
//			}
//		if(bsystem5Msec)
//		{	
////			EA=0;
////			set_PD;//进入休眠		
//			}
//		  if(bsystem10Msec)
//        {	
//                    }
//										
//		  if(bsystem1Sec)
//        {	
//					EA=0;
//					//set_PD;//进入休眠	
//                    }

//  }		
}

