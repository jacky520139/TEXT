
#include "ALL_Includes.h"
void main (void)
{	 
	InitSystem();
  while(1)
	{   
    SysTimer_Process();
			if(bsystem2Msec)
			{
//				clr_HIRCST;		
			}
		if(bsystem5Msec)
		{	
//			EA=0;
//			set_PD;//进入休眠		
			}
		  if(bsystem10Msec)
        {	
                    }
										
		  if(bsystem1Sec)
        {	
					EA=0;
					//set_PD;//进入休眠	
                    }

  }		
}

