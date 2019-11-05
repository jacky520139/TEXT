   #ifndef ADC_H
   #define ADC_H
/*****************************************************************************************
* For ADC INIT setting 
*****************************************************************************************/
#define Enable_ADC_AIN0			ADCCON0&=0xF0;P17_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT0;ADCCON1|=SET_BIT0									//P17
#define Enable_ADC_AIN1			ADCCON0&=0xF0;ADCCON0|=0x01;P30_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT1;ADCCON1|=SET_BIT0		//P30
#define Enable_ADC_AIN2			ADCCON0&=0xF0;ADCCON0|=0x02;P07_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT2;ADCCON1|=SET_BIT0		//P07
#define Enable_ADC_AIN3			ADCCON0&=0xF0;ADCCON0|=0x03;P06_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT3;ADCCON1|=SET_BIT0		//P06
#define Enable_ADC_AIN4			ADCCON0&=0xF0;ADCCON0|=0x04;P05_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT4;ADCCON1|=SET_BIT0		//P05
#define Enable_ADC_AIN5			ADCCON0&=0xF0;ADCCON0|=0x05;P04_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT5;ADCCON1|=SET_BIT0		//P04
#define Enable_ADC_AIN6			ADCCON0&=0xF0;ADCCON0|=0x06;P03_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT6;ADCCON1|=SET_BIT0		//P03
#define Enable_ADC_AIN7			ADCCON0&=0xF0;ADCCON0|=0x07;P11_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT7;ADCCON1|=SET_BIT0		//P11
#define Enable_ADC_BandGap	ADCCON0|=SET_BIT3;ADCCON0&=0xF8;ADCCON1|=SET_BIT0																							//Band-gap 1.22V

#define ADC0_Por         0
#define ADC1_Por         1
#define ADC2_Por         2
#define ADC3_Por         3
#define ADC4_Por         4
#define AD_S1_Por        5
#define AD_S2_Por        6
#define Temp_Por         7
	 /*****************ADC×ª»»º¯Êý**********************/
	 void ADC_Init(void);
   u16 ADC_get_val(u8 CH); 
	 #endif