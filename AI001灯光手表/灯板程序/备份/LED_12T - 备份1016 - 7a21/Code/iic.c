

#include "ALL_Includes.h"

#define DELAY1_TIME    10
#define FALSE          0
#define TRUE           1
/********** Function Definition************/
//void Timer0_DELAY1_ms(int ms)
//{
//   int i;                              // millisecond counter

//   TCON  &= ~0x30;                     // STOP Timer0 and clear overflow flag
//   TMOD  &= ~0x0f;                     // configure Timer0 to 16-bit mode
//   TMOD  |=  0x01;
//   CKCON |=  0x08;                     // Timer0 counts SYSCLKs

//   for (i = 0; i < ms; i++) {          // count milliseconds
//      TR0 = 0;                         // STOP Timer0
//      TH0 = (-SYSCLK/1000) >> 8;       // set Timer0 to overflow in 1ms
//      TL0 = -SYSCLK/1000;
//      TR0 = 1;                         // START Timer0
//      while (TF0 == 0);                // wait for overflow
//      TF0 = 0;                         // clear overflow indicator
//   }
//}




  void DELAY1(unsigned int t) /**/
  {
      while(t != 0)
          t--;
  }


  void I2C_Start(void)
  {
      /**/
      SDA = 1;
      SCL = 1;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SDA = 0;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SCL = 0;
      DELAY1(DELAY1_TIME);
  }


  void I2C_Stop(void)
  {
      /**/
      SDA = 0;
      SCL = 1;
      DELAY1(DELAY1_TIME);
      SDA = 1;
      DELAY1(DELAY1_TIME);
      //SCL=0;
      DELAY1(DELAY1_TIME);
	  SCL = 1;/*new*/
  }


  void SEND_0(void)   /* new*/
  {
      /**/
      SDA = 0;
      SCL = 0;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SCL = 1;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SCL = 0;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      //DELAY1(DELAY1_TIME);
  }


  void SEND_1(void)	 /* new*/
  {
      /**/
      SDA = 1;
      SCL = 0;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SCL = 1;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SCL = 0;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      //DELAY1(DELAY1_TIME);
  }


  bit Check_Acknowledge(void)
  {
      /**/
      bit ack;

      SDA = 1;
	  DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      SCL = 1;
      DELAY1(DELAY1_TIME);
	  DELAY1(DELAY1_TIME);
      ack = SDA;
      DELAY1(DELAY1_TIME);
      SCL = 0;
	  DELAY1(DELAY1_TIME);
      //DELAY1(DELAY1_TIME);
      if(ack == 1)
          return FALSE;
      return TRUE;
  }


  void WriteI2CByte(char b) //reentrant
  {
      /**/
      char i;
      for(i = 0; i < 8; i++)
          if((b << i) & 0x80)
              SEND_1();
          else
              SEND_0();
  }



  char ReadI2CByte(void) //reentrant
  {
      /**/
      char b = 0,i;
      for(i = 0; i < 8; i++)
      {
			DELAY1(DELAY1_TIME);
			SDA = 1;    /**/
			DELAY1(DELAY1_TIME);
			DELAY1(DELAY1_TIME);
			SCL = 1;    /**/
			DELAY1(DELAY1_TIME);
			DELAY1(DELAY1_TIME);
			F0 = SDA;
			DELAY1(DELAY1_TIME);
			DELAY1(DELAY1_TIME);
			SCL = 0;
			if(F0 == 1)
					{
							b = b << 1;
							b = b | 0x01;
					}
			else
					b = b << 1;
      }
      return b;
  }


/********************/
void Write_One_Byte(char addr, char thedata)
{
        bit acktemp = 1;
        /*write a byte to mem*/
        I2C_Start();
        WriteI2CByte(0x8c);
        acktemp = Check_Acknowledge();
		WriteI2CByte(addr);/*address*/
        acktemp = Check_Acknowledge();
        WriteI2CByte(thedata);/*thedata*/
        acktemp = Check_Acknowledge();
        I2C_Stop();
}


void Write_One_Byte_iicaddr(char iicchar, char addr, char thedata)
{
        bit acktemp = 1;
        /*write a byte to mem*/
        I2C_Start();
        WriteI2CByte(iicchar);
        acktemp = Check_Acknowledge();
		WriteI2CByte(addr);/*address*/
        acktemp = Check_Acknowledge();
        WriteI2CByte(thedata);/*thedata*/
        acktemp = Check_Acknowledge();
        I2C_Stop();
}



void Write_A_Page(char *buffer, char iicaddr, unsigned char length)
{
        bit acktemp = 1;
//        bit wrtmp;
        int i;
        /*write a page to at24c02*/
        I2C_Start();
        WriteI2CByte(iicaddr);
        acktemp=Check_Acknowledge();
        //WriteI2CByte(addr);/*address*/
        //acktemp=Check_Acknowledge();
        for(i = 0; i < length; i++)
        {
          WriteI2CByte(buffer[i]);
          if(!Check_Acknowledge())
              {
                  I2C_Stop();
              }
         }

        I2C_Stop();


}


void Write_A_Page_Discont_Addr(char *buffer, char iicaddr, unsigned char length)
{
        bit acktemp = 1;
//        bit wrtmp;
        int i;
        /*write a page to at24c02*/
		for(i = 0; i < length; i++)
        {
        	I2C_Start();
        	WriteI2CByte(iicaddr);//device address
        	acktemp = Check_Acknowledge();
				if(~acktemp)
				while(1);
        	WriteI2CByte(buffer[2 * i]);//reg address
        	acktemp = Check_Acknowledge();
				if(~acktemp)
				while(1);
				WriteI2CByte(buffer[2 * i + 1]);
				acktemp = Check_Acknowledge();
				if(~acktemp)
				while(1);
				I2C_Stop();
				DELAY1(1000);
         }    	
}

void Read_A_Page_Discont_Addr(char *buffer, char device_addr, unsigned char length)
{
        bit acktemp = 1;
		char mydata;
        int i;
        /*write a page to at24c02*/
		for(i = 0; i < length; i++)
        {
				I2C_Start();
				WriteI2CByte(device_addr);
				acktemp = Check_Acknowledge();
				WriteI2CByte(buffer[2 * i + 0]);/*address*/
				acktemp = Check_Acknowledge();
				I2C_Start();
				WriteI2CByte(device_addr + 0x01);
				acktemp = Check_Acknowledge();
				mydata  = ReadI2CByte();
				acktemp = Check_Acknowledge();
				I2C_Stop();
				buffer[2 * i + 1] = mydata;
				DELAY1(1000);
         }    	
}



char Read_One_Byte(char device_addr, char reg_addr)
{         
		bit acktemp = 1;
        char mydata;
         /*read a byte from mem*/
        I2C_Start();
        WriteI2CByte(device_addr);
        acktemp = Check_Acknowledge();
        WriteI2CByte(reg_addr);/*address*/
        acktemp = Check_Acknowledge();
        I2C_Start();
        WriteI2CByte(device_addr + 0x01);
        acktemp = Check_Acknowledge();

        mydata  = ReadI2CByte();
        acktemp = Check_Acknowledge();
		I2C_Stop();
        return mydata;
        
}


//
  void Read_N_Bytes(char device_addr, char *buffer, char n, char addr)
  {
        bit acktemp = 1;
        int i = 0;
         /*read 8 bytes from mem*/					 
        I2C_Start();
        WriteI2CByte(device_addr);
        acktemp = Check_Acknowledge();
        WriteI2CByte(addr);/*address*/
        acktemp = Check_Acknowledge();
        I2C_Start();
        WriteI2CByte(device_addr + 0x01);
        acktemp = Check_Acknowledge();


        for(i = 0; i < n; i++)
        {
              buffer[i] = ReadI2CByte();
              if(i != n - 1)
                  SEND_0();    /*¡¤¡é?¨ª¨®|¡äe*/
              else
                  SEND_1();    /*¡¤¡é?¨ª¡¤?¨®|¡äe*/
        }

     	I2C_Stop();
  }

