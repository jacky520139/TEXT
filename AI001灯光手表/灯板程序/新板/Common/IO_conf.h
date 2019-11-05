   #ifndef IO_CONF_H
   #define IO_CONF_H
/***************IO端口定义***********************/
			#define COM4 		          P00	
			#define COM3		        P01	//
			#define GET2              P02
			#define GET3 		          P03	
			#define COM2 		      P04
			#define COM1          P05//光敏检测
			#define TXD			          P06//串口输出
			#define GET1       	      P07 
			
			#define P0M2_D             Bin(11111111)      
			#define P0M1_D             Bin(00000000)
	    #define P0_D               Bin(11001100)//端口状态
/********************************************************/			
			#define LED_SING 		           P10
			#define Lignt_IN 		           P11
			#define P12_NC               P12
			#define SCLK 		           P13
			#define SDAT 		           P14
			#define Lignt_VDD          P15
			#define P16_NC			       P16
			#define INT1       	       P17
			
			#define P1M2_D             Bin(01111101)			
			#define P1M1_D             Bin(00000010)
      #define P1_D               Bin(11111000)//端口状态
/********************************************************/
			#define KEY                 P20
			
      #define P2_D                Bin(10011111)//端口状态
/********************************************************/			 
			#define INT0 			            P30    //电流检测端口       
			
			#define P3M2_D              Bin(00000000)		
			#define P3M1_D              Bin(00000000)
      #define P3_D                Bin(11111111)//端口状态

   #endif