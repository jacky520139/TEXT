#ifndef _UART_H_
#define _UART_H_

#define __DEBUG__
#ifdef __DEBUG__
#define PRINT \
    printf
#else
#define PRINT
#endif
void InitialUART0_Timer3(u32 Baudrate);
u8 Receive_Data_From_UART0(void);
void Send_Data_To_UART0 (u8 Data);
void Send_Word_To_UART0 (u16 Data);
void InitialUART1_Timer3(u32 Baudrate); //use timer3 as Baudrate generator
void Send_Data_To_UART1 (u8 Data);
void Send_Word_To_UART1 (u16 Data);
void ANO_DT_Send_Version(u8 type, u16 Data1, u16 Data2, u16 Data3, u16 Data4, u16 Data5);
#endif