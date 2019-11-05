
#include "ALL_Includes.h"
bit SL_SC7A21_Click_Timer_Cnt_f=0;
 void SL_Open_Sc7a21_Click_Timer(void)
 {SL_SC7A21_Click_Timer_Cnt_f=1;}
 void SL_Close_Sc7a21_Click_Timer(void)
 {SL_SC7A21_Click_Timer_Cnt_f=0;}
void main (void)
{		signed short x_agg,y_agg,z_agg; 
	u8 Click_count;
	u8 SL_SC7A21_Click_Timer_Count=0;
	InitSystem();


  while(1)
	{ 	
//		P0M2|=0x20; 
//      P0M1&=~0x20; 		
//		
//		AINDIDS=Bin(00000000);	
//		Lignt_IN=0;
//		set_PD;//进入休眠	  
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
		{
			if(SL_SC7A21_Click_Timer_Cnt_f)
			{SL_SC7A21_Click_Timer_Count++;
				if(SL_SC7A21_Click_Timer_Count==5)
				{SL_SC7A21_Click_Timer_Count=0;
			   Click_count=SL_SC7A21_Click_Timer_Cnt();
			ANO_DT_Send_Version(0XF1, x_agg, y_agg,z_agg , Click_count, 0);}}
		
		 }
		  if(bsystem500Msec)
        {	
					SL_SC7A21_GET_PEDO_VALUE();
					
                    }
							
		  if(bsystem1Sec)
        {	
				//	EA=0;
					//set_PD;//进入休眠	

                    }

  }		
}

