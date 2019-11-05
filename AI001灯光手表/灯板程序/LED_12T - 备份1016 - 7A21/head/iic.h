#ifndef __IIC_H__
#define __IIC_H__
//#include <main.h>
	

//	sbit SDA = P0^4;
//	sbit SCL = P0^3;/**/
 			#define SCL            SCLK
			#define SDA            SDAT 


	void Read_A_Page_Discont_Addr(char *buffer, char device_addr, unsigned char length);
	char Read_One_Byte(char device_addr, char reg_addr);
	void Read_N_Bytes(char device_addr, char *buffer, char n, char addr);
	void Write_A_Page_Discont_Addr(char *buffer, char iicaddr, unsigned char length);
	void Write_A_Page(char *buffer, char iicaddr, unsigned char length);
	void Write_One_Byte_iicaddr(char iicchar, char addr, char thedata);
	void Write_One_Byte(char addr, char thedata);
	char ReadI2CByte(void); //reentrant
	void WriteI2CByte(char b); //reentrant
	bit Check_Acknowledge(void);
	void SEND_1(void);	 /* new*/
	void SEND_0(void);   /* new*/
	void I2C_Stop(void);
	void I2C_Start(void);
	void DELAY(unsigned int t); /**/
	void Timer0_Delay_ms(int ms);
#endif