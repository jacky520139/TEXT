#include "ALL_Includes.h"
u16 filter_Rudder=1000;
u16 Rudder_buff[8];
void Init_Capture(void)
{
		TIMER2_Auto_Reload_Delay_Mode;

	  IC3_P00_CAP0_RisingEdge_Capture;
//  CAPCON0|=SET_BIT4;
//	CAPCON1&=0xfc;
//	CAPCON1|=0x10;
//	
//	CAPCON2|=SET_BIT4;
//	CAPCON3&=0xF0;
//	CAPCON3|=0x03;
//  set_ET2;                                    //Enable Timer2 interrupt
    set_ECAP;                                   //Enable Capture interrupt
    set_TR2;                                    //Triger Timer2
    set_EA;
}
