   #ifndef IO_CONF_H
   #define IO_CONF_H
/***************IO端口定义***********************/
			#define COM4 		          P00	
			#define P01_NC		        P01	//
			#define GET2              P02
			#define GET3 		          P03	
			#define LED_Sing 		      P04
			#define Lignt_IN          P05//光敏检测
			#define TXD			          P06//串口输出
			#define GET1       	      P07 
			
			#define P0M2_D             Bin(11011101)      
			#define P0M1_D             Bin(00100000)
	    #define P0_D               Bin(11101110)//端口状态
/********************************************************/			
			#define COM3 		           P10
			#define COM2 		           P11
			#define COM1               P12
			#define SCLK 		           P13
			#define SDAT 		           P14
			#define Lignt_VDD          P15
			#define P16_NC			       P16
			#define INT1       	       P17
			
			#define P1M2_D             Bin(01111111)			
			#define P1M1_D             Bin(00000000)
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