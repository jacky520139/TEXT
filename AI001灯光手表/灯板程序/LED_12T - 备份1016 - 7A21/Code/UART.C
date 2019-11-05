#include "ALL_Includes.h"
//---------------------------------------------------------------
void InitialUART0_Timer3(u32 Baudrate) //use timer3 as Baudrate generator
{
		P06_Quasi_Mode;
		P07_Quasi_Mode;	
	
    SCON = 0x52;     //UART0 Mode1,REN=1,TI=1
    set_SMOD;        //UART0 Double Rate Enable
    T3CON &= 0xF8;   //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
    set_BRCK;        //UART0 baud rate clock source = Timer3
		RH3    = HIBYTE(65536 - (1000000/Baudrate)-1);  		/*16 MHz */
		RL3    = LOBYTE(65536 - (1000000/Baudrate)-1);			/*16 MHz */

    set_TR3;         //Trigger Timer3
}
u8 Receive_Data_From_UART0(void)
{
    u8 c;
    
    while (!RI);
    c = SBUF;
    RI = 0;
    return (c);
}

void Send_Data_To_UART0 (u8 Data)
{
    TI = 0;
    SBUF = Data;
    while(TI==0);
}
void Send_Word_To_UART0 (u16 Data)
{
    TI = 0;
    SBUF = Data>>8;
    while(TI==0);
    TI = 0;
    SBUF = Data;
    while(TI==0);	
}

void InitialUART1_Timer3(u32 Baudrate) //use timer3 as Baudrate generator
{

//    SCON = 0x52;     //UART0 Mode1,REN=1,TI=1
//    set_SMOD;        //UART0 Double Rate Enable
//    T3CON &= 0xF8;   //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
//    set_BRCK;        //UART0 baud rate clock source = Timer3
   set_SM1_1;
		RH3    = HIBYTE(65536 - (1000000/Baudrate)-1);  		/*16 MHz */
		RL3    = LOBYTE(65536 - (1000000/Baudrate)-1);			/*16 MHz */

    set_TR3;         //Trigger Timer3
}

void Send_Data_To_UART1 (u8 Data)
{
    TI_1 = 0;
    SBUF_1 = Data;
    while(TI_1==0);
}
void Send_Word_To_UART1 (u16 Data)
{
    TI_1 = 0;
    SBUF_1 = Data>>8;
    while(TI_1==0);
    TI_1 = 0;
    SBUF_1 = Data;
    while(TI_1==0);	
}