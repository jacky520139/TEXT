
#ifndef _OS_ADC_H_
#define _OS_ADC_H_ 

#define ADC_CHANNEL_CURRENT         1//µçÁ÷

void adc_init(void);
void ADC_GO(void);
u16 ADC_Read(u8 CHS);

#endif
