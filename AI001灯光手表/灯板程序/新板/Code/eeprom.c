
#include "ALL_Includes.h"

#define  PAGE_ERASE_AP         0x22//页擦除命令（每一页是 128字节）
#define  BYTE_PROGRAM_AP       0x21//字节写入命令
#define  DATA_FLASH_ADDRESS    0X4000


/****************************************
关闭ISP
*****************************************/
void ISP_DIS(void)
{
TA = 0xAA;  //IAPUEN is TA protected
TA = 0x55;
IAPUEN &= ~0x01; //APUEN = 0, disable APROM update
TA = 0xAA;  //CHPCON is TA protected
TA = 0x55;
CHPCON &= ~0x01; //IAPEN = 0, disable IAP mode
}
/****************************************
关闭ISP
*****************************************/
void ISP_OPEN(void)
{
TA = 0xAA;  //CHPCON is TA protected
TA = 0x55;
CHPCON |= 0x01; //IAPEN = 1, enable IAP mode
TA = 0xAA;  //IAPUEN is TA protected
TA = 0x55;
IAPUEN |= 0x01; //APUEN = 1, enable APROM update
}
/****************************************
擦除扇区
*****************************************/
void ERASE(u16 addr)
{
ISP_OPEN();
IAPCN = PAGE_ERASE_AP;  //Erase page 200h~27Fh
IAPAH = addr>>8;
IAPAL = addr;
IAPFD = 0xFF;
TA = 0xAA;  //IAPTRG is TA protected
TA = 0x55;
IAPTRG |= 0x01;  //write ‘1’ to IAPGO to trigger IAP process
ISP_DIS();	
}
/****************************************
读取一BYTE
*****************************************/
u8 Read_APROM_BYTE(u16 code *u16_addr)
{
	u8 rdata;
	rdata = *u16_addr>>8;
	return rdata;
}
/****************************************
读取一DATA
*****************************************/
u16 ReadDATA_ISP(u16 bite_addr)
{
	u16 DATA;
  u8 BITE;
	EA=0;
	BITE=Read_APROM_BYTE((u16 code *)bite_addr);
	DATA=Read_APROM_BYTE((u16 code *)(bite_addr+1));
	DATA=(DATA<<8)+BITE;
	EA=1;
	return DATA; 

}

/****************************************
写入一BYTE
*****************************************/
void Write_ISP (u16 bite_addr,u8 DATA)
{ 
ISP_OPEN();
IAPCN = BYTE_PROGRAM_AP;  // Program 201h with 55h
IAPAH = bite_addr >> 8;
IAPAL = bite_addr;
IAPFD = DATA;
TA = 0xAA;
TA = 0x55;
IAPTRG |= 0x01;  //write ‘1’ to IAPGO to trigger IAP process
ISP_DIS();	
}
/****************************************
写入一DATA
*****************************************/
void WriteDATA_ISP (u16 bite_addr,u16 DATA)
{ 
	EA=0;
//	ERASE(bite_addr);
	Write_ISP (bite_addr,DATA);
	Write_ISP (bite_addr+1,DATA>>8);
	EA=1;
}
void eeprom_read_block(u8 *Data_Buf,u16 bite_addr,u8 n)
{
u8 i=0;

  for(i=0;i<n;i++)
  {Data_Buf[i]=Read_APROM_BYTE((u16 code *)(DATA_FLASH_ADDRESS+bite_addr+i));}

}
void eeprom_write_block(u8 *Data_Buf,u16 bite_addr,u8 n)
{u8 i=0;
	for(i=0;i<n;i++)
	{
		Write_ISP(DATA_FLASH_ADDRESS+bite_addr+i,*(Data_Buf+i));
	}

}
void writerom(unsigned int *Data_Buf,unsigned char n )
{u8  dispLine;
 	ERASE(DATA_FLASH_ADDRESS);	
	for(dispLine=0;dispLine<n;dispLine++)
	{
		WriteDATA_ISP(DATA_FLASH_ADDRESS+2*dispLine,*(Data_Buf+dispLine));
	}
}

void readrom(unsigned int *Data_Buf,unsigned char n)
{ u16 i=0;

  for(i=0;i<n;i++)
  {Data_Buf[i]=ReadDATA_ISP((DATA_FLASH_ADDRESS+2*i));}
		}
/***************************************************************
* 函数功能：校验和
* 输入参数：
* 输出参数：
***************************************************************/
static u8 eeprom_checksum(const u8 *buffer, size_t Size, u8 sum)
{
    while (Size)
    {
        sum += *buffer;
        ++buffer;
        --Size;
    }
    return sum;
}

/***************************************************************
* 函数功能：擦除eeprom
* 输入参数：
* 输出参数：
***************************************************************/
u8 eeprom_erase(void)
{
ERASE(DATA_FLASH_ADDRESS);
    return 1;
}


u8 eeprom_restore_registers(void)
{
    u8 header[2];

    // XXX Disable PWM to servo motor while reading registers.

    // Read EEPROM header which is the first two bytes of EEPROM.
    //    eeprom_read_block(&header[0], (void *) 0, 2);
     header[0]=Read_APROM_BYTE((u16 code *)DATA_FLASH_ADDRESS+0);
	   header[1]=Read_APROM_BYTE((u16 code *)DATA_FLASH_ADDRESS+1);
    // Does the version match?
    if (header[0] != EEPROM_VERSION) return 0;

    // Read the write protected and redirect registers from EEPROM.
//    eeprom_read_block(&registers[MIN_WRITE_PROTECT_REGISTER],2, WRITE_PROTECT_REGISTER_COUNT + REDIRECT_REGISTER_COUNT);

    // Does the checksum match?
//	Work_Address[5]
//    if (header[1] != eeprom_checksum(Work_Address,5, EEPROM_VERSION))
//			return 0;

    // XXX Restore PWM to servo motor.
    // Return success.
    return 1;
}


u8 eeprom_save_registers(void)
// Save registers to EEPROM.
{
    u8 header[2];

    // XXX Disable PWM to servo motor while reading registers.

    // Fill in the EEPROM header.
    header[0] = EEPROM_VERSION;
//    header[1] = eeprom_checksum(&registers[MIN_WRITE_PROTECT_REGISTER], WRITE_PROTECT_REGISTER_COUNT + REDIRECT_REGISTER_COUNT, EEPROM_VERSION);
    ERASE(DATA_FLASH_ADDRESS);
	
    // Write the EEPROM header which is the first two bytes of EEPROM.
    eeprom_write_block(&header[0], 0, 2);

    // Write the write protected and redirect registers from EEPROM.
//    eeprom_write_block(&registers[MIN_WRITE_PROTECT_REGISTER], 2, WRITE_PROTECT_REGISTER_COUNT + REDIRECT_REGISTER_COUNT);

    // XXX Restore PWM to servo motor.

    // Return success.
    return 1;
}


