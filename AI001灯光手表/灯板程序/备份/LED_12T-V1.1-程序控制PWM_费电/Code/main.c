
#include "ALL_Includes.h"
bit SL_SC7A21_Click_Timer_Cnt_f=0;
 void SL_Open_Sc7a21_Click_Timer(void)
 {SL_SC7A21_Click_Timer_Cnt_f=1;}
 void SL_Close_Sc7a21_Click_Timer(void)
 {SL_SC7A21_Click_Timer_Cnt_f=0;}
void main (void)
{		signed short x_agg,y_agg,z_agg; 
	u8 SL_SC7A21_Click_Timer_Count=0;
	InitSystem();
	while(1)
	{set_PD;//进入休眠	  
		};
//	Send_Data_To_UART0 (0xab);
//	Send_Data_To_UART0 (0xba);

//	while(1)
//	{
//		if(LED_Minute>=1)
//		{ LED_0FF;
//		  clr_WKTR;
//			PIF=0;
	
	
	
//		  set_EPI;}//周期到了后不运行自动唤醒
////		  BG_1_22V=ADC_Read(8);
////			VDD_VAL=(u32)4096*122/BG_1_22V;
////		  ANO_DT_Send_Version(0XF1, VDD_VAL, ADC_Read(4),0 , 0, 0);
//		//  
//		}

  while(1)
	{ 	
		//set_PD;//进入休眠	  
    SysTimer_Process();
			if(bsystem2Msec)
			{
	
			  SL_SC7A21_Read_XYZ_FIFO_Data(&x_agg,&y_agg,&z_agg);
			
				ANO_DT_Send_Version(0XF1, x_agg, y_agg,z_agg , 0, 0);
			}
		if(bsystem5Msec)
		{	
//			EA=0;
//			set_PD;//进入休眠		
			}
		if(bsystem10Msec)
		{ if(SL_SC7A21_Click_Timer_Cnt_f)
			{SL_SC7A21_Click_Timer_Count++;
				if(SL_SC7A21_Click_Timer_Count==5)
				{SL_SC7A21_Click_Timer_Count=0;
			   SL_SC7A21_Click_Timer_Cnt();}}
		
		 }
		  if(bsystem500Msec)
        {	SL_SC7A21_GET_PEDO_VALUE();
					
                    }
							
		  if(bsystem1Sec)
        {	
				//	EA=0;
					//set_PD;//进入休眠	

                    }

  }		
}

