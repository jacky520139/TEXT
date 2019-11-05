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
void UartSendBuf(char*buf,u8 sz){
    u8 i;

    for(i=0;i<sz;i++){
        Send_Data_To_UART0(buf[i]);
    }
}

//数据拆分宏定义，在发送大于1字节的数据类型时，比如int16、float等，需要把数据拆分成单独字节进行发送
#define BYTE0(dwTemp)       ( *( (char *)(&dwTemp)		) )
#define BYTE1(dwTemp)       ( *( (char *)(&dwTemp) + 1) )
//#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
//#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )
u8 data_to_send[50];	//发送数据缓存


void ANO_DT_Send_Version(u8 type, u16 Data1, u16 Data2, u16 Data3, u16 Data4, u16 Data5)
{
	u8 _cnt=0;
	u8 sum = 0;
	u8 i;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=type;
	data_to_send[_cnt++]=0;
	data_to_send[_cnt++]=BYTE0(Data1);
	data_to_send[_cnt++]=BYTE1(Data1);
	data_to_send[_cnt++]=BYTE0(Data2);
	data_to_send[_cnt++]=BYTE1(Data2);
	
		data_to_send[_cnt++]=BYTE0(Data3);
	data_to_send[_cnt++]=BYTE1(Data3);
	
		data_to_send[_cnt++]=BYTE0(Data4);
	data_to_send[_cnt++]=BYTE1(Data4);
			data_to_send[_cnt++]=BYTE0(Data5);
	data_to_send[_cnt++]=BYTE1(Data5);
	data_to_send[3] = _cnt-4;
	

	for( i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	UartSendBuf(data_to_send, _cnt);

}