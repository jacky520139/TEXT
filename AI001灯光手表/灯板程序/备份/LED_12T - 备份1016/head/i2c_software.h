#ifndef _I2C_SOFTWARE_H_
#define _I2C_SOFTWARE_H_

#define SCL0_HIGH()		  SCLK=1
#define SCL0_LOW()		  SCLK=0
#define SDA0_HIGH()		  SDAT=1
#define SDA0_LOW()		  SDAT=0
#define SDA0_SetInput()	  {P1M2&=~0x10;P1M1|=0x10;}
#define SDA0_SetOutput()  {P1M2|=0x10;P1M1&=~0x10;}
#define SDA0_READ()		     SDAT







void i2cs_init( );
void i2cs_tx_data(uint8_t devAddr7,uint8_t addr,uint8_t*buf,uint8_t size);
void i2cs_rx_data(uint8_t devAddr7,uint8_t addr,uint8_t*buf,uint8_t size);
#endif 