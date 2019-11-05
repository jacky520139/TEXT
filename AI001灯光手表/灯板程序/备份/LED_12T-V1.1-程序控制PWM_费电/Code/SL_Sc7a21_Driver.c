
#include "ALL_Includes.h"


#define SL_SC7A21_DEBUG 0
#if SL_SC7A21_DEBUG==1
#include "usart.h"
#endif

static unsigned int   SL_Step_Value_Temp=0; 

/***************在线测试**********************/
signed char  SL_SC7A21_Online_Test(unsigned char Sl_pull_up_mode)
{
    unsigned char SL_Read_Reg=0xff;
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE, SL_SC7A21_SDO_I2C_PU_CFG, 1, &SL_Read_Reg);
    SL_Read_Reg=(SL_Read_Reg&0xF3)|Sl_pull_up_mode;
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SDO_I2C_PU_CFG, SL_Read_Reg); 
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SC7A21_CHIP_ID_ADDRESS,1, &SL_Read_Reg); 
    if(SL_Read_Reg==SC7A21_CHIP_ID_VALUE)   return  1;
    else                                    return -1;
}

/***************复位,同时BOOT 重载内部寄存器值*********************/
signed char  SL_SC7A21_BOOT_RESET(void)
{
    unsigned char SL_Read_Reg=0xff;
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SOFT_RESET_REG,1, &SL_Read_Reg);
    SL_Read_Reg=SL_Read_Reg|SL_SC7A21_SOFT_RESET_VALUE;
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SOFT_RESET_REG, SL_Read_Reg);//RESET
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG5,1, &SL_Read_Reg);
    SL_Read_Reg=SL_SC7A21_BOOT_EN|SL_Read_Reg;
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG5, SL_Read_Reg);//BOOT 
    
    return  1;
}

/***************传感器量程设置**********************/
signed char  SL_SC7A21_FS_Config(unsigned char SC7A21_FS_Reg)
{
    unsigned char SL_Read_Reg=0xff,SL_Write_Reg;
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG4,1, &SL_Read_Reg); 
    SL_Write_Reg=0x80|SC7A21_FS_Reg|SL_SC7A21_DATA_DLPF_EN;
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG4, SL_Write_Reg);
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG4,1, &SL_Read_Reg); 
    if(SL_Read_Reg==SL_Write_Reg)   return  1;
    else                            return -1;
}

/***************数据更新速率**加速度计使能**********/
signed char  SL_SC7A21_Power_Config(unsigned char ODR_Config_Reg,unsigned char Power_Mode)
{
    unsigned char SL_Read_Reg;
    unsigned char SL_Write_Reg; 
    if(Power_Mode == 0 ||Power_Mode == 1)//disable hi-pwr mode
    {
        SL_Write_Reg=SL_SC7A21_ABW_50HZ|SL_SC7A21_ALPF_EN|SL_SC7A21_HI_PWR_EN;
        SL_Write_Reg=~SL_Write_Reg;
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG0,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg&SL_Write_Reg;
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG0, SL_Read_Reg);
    }
    else if(Power_Mode == 2)
    {
        SL_Read_Reg  = 0x00;
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG0,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg|SL_SC7A21_ABW_50HZ|SL_SC7A21_ALPF_EN|SL_SC7A21_HI_PWR_EN;
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG0, SL_Read_Reg);    
    }
    
    if(Power_Mode == 0&& ODR_Config_Reg<0x97)
    {
        ODR_Config_Reg=ODR_Config_Reg|0x0F;
    }

    SL_Read_Reg  = 0xff;
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG1, ODR_Config_Reg);
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG1,1, &SL_Read_Reg); 

    if(SL_Read_Reg==ODR_Config_Reg)   return  1;
    else                                return -1;
}

/***************数据更新速率**加速度计使能**********/
signed char  SL_SC7A21_FIFO_Config(unsigned char Fifo_Mode,unsigned char Fifo_Bit)
{
    unsigned char SL_Read_Reg;
    unsigned char SL_Write_Reg;
           
    if(Fifo_Mode == SL_SC7A21_FIFO_MODE_DIS)//disable hi-pwr mode
    {
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg&SL_SC7A21_FIFO_FM_MSK;
        SL_Read_Reg=SL_Read_Reg|SL_SC7A21_FIFO_FM_BYPASS;
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG, SL_Read_Reg);
    }
    else if(Fifo_Mode == SL_SC7A21_FIFO_MODE_EN)
    {
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg&SL_SC7A21_FIFO_FM_MSK;
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG, SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg|SL_SC7A21_FIFO_FM_FIFO;
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG, SL_Read_Reg);   
    }
    else if(Fifo_Mode == SL_SC7A21_STREAM_MODE_EN)
    {
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg&SL_SC7A21_FIFO_FM_MSK;
        SL_Read_Reg=SL_Read_Reg|SL_SC7A21_FIFO_FM_STREAM;
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_CTRL_REG, SL_Read_Reg);     
    }
    
    if(Fifo_Bit == SL_SC7A21_FIFO_16BITS_MODE)//16BITS FIFO MODE
    {
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG5,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg&SL_SC7A21_FIFO_BITS_MSK;
        SL_Read_Reg=SL_Read_Reg|SL_SC7A21_FIFO_16BITS;       
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG5, SL_Read_Reg);
    }
    else if(Fifo_Bit == SL_SC7A21_FIFO_8BITS_MODE)//8BITS FIFO MODE
    {
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG5,1, &SL_Read_Reg);
        SL_Read_Reg=SL_Read_Reg&SL_SC7A21_FIFO_BITS_MSK;
        SL_Read_Reg=SL_Read_Reg|SL_SC7A21_FIFO_8BITS;       
        SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG5, SL_Read_Reg);   
    }
    
    return  1;
}

unsigned char SL_SC7A21_INT_Config(unsigned char int_para)
{
    unsigned char SL_Read_Reg;

    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG6, int_para);
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG6,1, &SL_Read_Reg);
    
    if(SL_Read_Reg==int_para)     return 1;
    else                          return 0;
}


#if   SL_SC7A21_16BIT_8BIT==0
/***************加速度计数据读取*8bits*********/
signed char  SL_SC7A21_Read_XYZ_Data(signed char *SL_SC7A21_Data_XYZ_Buf)
{
    unsigned char SL_Read_Buf[6];
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DRDY_REG,1, &SL_Read_Buf[0]);//数据状态寄存器
    
    if((SL_Read_Buf[0]&0x0f)==0x0f)
    {
#if   SL_SC7A21_SPI_IIC_MODE ==1//IIC
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DATA_OUT,6, &SL_Read_Buf[0]);
#elif SL_SC7A21_SPI_IIC_MODE ==0//SPI
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_OUT_X_L,6, &SL_Read_Buf[0]);  
#endif
        SL_SC7A21_Data_XYZ_Buf[0]=(signed char)SL_Read_Buf[1];
        SL_SC7A21_Data_XYZ_Buf[1]=(signed char)SL_Read_Buf[3];
        SL_SC7A21_Data_XYZ_Buf[2]=(signed char)SL_Read_Buf[5];

        return  1;
    }
    else
    {
        return 0;
    }
}
#elif SL_SC7A21_16BIT_8BIT==1
/***************加速度计数据读取*16bits*********/
signed char  SL_SC7A21_Read_XYZ_Data(signed short *SL_SC7A21_Data_XYZ_Buf)
{
    unsigned char SL_Read_Buf[6];
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DRDY_REG,1, &SL_Read_Buf[0]);//数据状态寄存器
    
    if((SL_Read_Buf[0]&0x0f)==0x0f)
    {
#if   SL_SC7A21_SPI_IIC_MODE ==1//IIC
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DATA_OUT,6, &SL_Read_Buf[0]);
#elif SL_SC7A21_SPI_IIC_MODE ==0//SPI
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_OUT_X_L,6, &SL_Read_Buf[0]);  
#endif   
        SL_SC7A21_Data_XYZ_Buf[0]=(signed short)((SL_Read_Buf[1]<<8) + SL_Read_Buf[0]);
        SL_SC7A21_Data_XYZ_Buf[1]=(signed short)((SL_Read_Buf[3]<<8) + SL_Read_Buf[2]);
        SL_SC7A21_Data_XYZ_Buf[2]=(signed short)((SL_Read_Buf[5]<<8) + SL_Read_Buf[4]);
         
        return  1;
    }
    else
    {
        return 0;
    }
}
#endif


#if   SL_SC7A21_FIFO_16BIT_8BIT==0
/***************加速度计数据读取*8bits*********/
signed char  SL_SC7A21_Read_XYZ_FIFO_Data(signed char *SL_SC7A21_Data_X_Buf,signed char *SL_SC7A21_Data_Y_Buf,signed char *SL_SC7A21_Data_Z_Buf)
{
    unsigned char SL_Read_Buf[6],FIFO_LEN;
    unsigned char sl_i;
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_SRC_REG,1, &SL_Read_Buf[0]);
    if((SL_Read_Buf[0]&SL_SC7A21_FIFO_OVER_FLAG)==SL_SC7A21_FIFO_OVER_FLAG)
        FIFO_LEN=64;
    else
        FIFO_LEN=SL_Read_Buf[0]&SL_SC7A21_FIFO_8FSS_FLAG;
    
    for(sl_i=0;sl_i<FIFO_LEN;sl_i++)
    {   
#if     SL_SC7A21_SPI_IIC_MODE ==1//IIC
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DATA_OUT,6, &SL_Read_Buf[0]);
#elif   SL_SC7A21_SPI_IIC_MODE ==0//SPI
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_OUT_X_L,6, &SL_Read_Buf[0]);  
#endif
        SL_SC7A21_Data_X_Buf[sl_i]=SL_Read_Buf[0];
        SL_SC7A21_Data_Y_Buf[sl_i]=SL_Read_Buf[2];
        SL_SC7A21_Data_Z_Buf[sl_i]=SL_Read_Buf[4];
        sl_i++;
        SL_SC7A21_Data_X_Buf[sl_i]=SL_Read_Buf[1];
        SL_SC7A21_Data_Y_Buf[sl_i]=SL_Read_Buf[3];
        SL_SC7A21_Data_Z_Buf[sl_i]=SL_Read_Buf[5];
    }
    
    return  FIFO_LEN;
}
#elif SL_SC7A21_FIFO_16BIT_8BIT==1
/***************加速度计数据读取*16bits*********/
signed char  SL_SC7A21_Read_XYZ_FIFO_Data(signed short *SL_SC7A21_Data_X_Buf,signed short *SL_SC7A21_Data_Y_Buf,signed short *SL_SC7A21_Data_Z_Buf)
{
    unsigned char SL_Read_Buf[6],FIFO_LEN;
    unsigned char sl_i;
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_FIFO_SRC_REG,1, &SL_Read_Buf[0]);
    if((SL_Read_Buf[0]&SL_SC7A21_FIFO_OVER_FLAG)==SL_SC7A21_FIFO_OVER_FLAG)
        FIFO_LEN=32;
    else
        FIFO_LEN=SL_Read_Buf[0]&SL_SC7A21_FIFO_16FSS_FLAG;
 
    for(sl_i=0;sl_i<FIFO_LEN;sl_i++)
    {   
#if     SL_SC7A21_SPI_IIC_MODE ==1//IIC
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DATA_OUT,6, &SL_Read_Buf[0]);
#elif   SL_SC7A21_SPI_IIC_MODE ==0//SPI
        SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_OUT_X_L,6, &SL_Read_Buf[0]);  
#endif
        
        SL_SC7A21_Data_X_Buf[sl_i]=(signed short)((SL_Read_Buf[1]<<8) + SL_Read_Buf[0]);
        SL_SC7A21_Data_Y_Buf[sl_i]=(signed short)((SL_Read_Buf[3]<<8) + SL_Read_Buf[2]);
        SL_SC7A21_Data_Z_Buf[sl_i]=(signed short)((SL_Read_Buf[5]<<8) + SL_Read_Buf[4]);
    }
    return  FIFO_LEN;
}
#endif

void SL_SC7A21_Pedo_Reset(void)
{
    unsigned char SL_Read_Reg;
 
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_CTRL_REG0,1, &SL_Read_Reg);
    SL_Read_Reg=SL_Read_Reg|SL_SC7A21_STEP_CLEAR_EN;
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_CTRL_REG0, SL_Read_Reg); 
    SL_Step_Value_Temp=0;
    
}

void SL_SC7A21_Pedo_Config(unsigned char *pedo_reg_value)
{
    unsigned char SL_Write_Reg;
    
    //INT_SET  STEP_EN
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_CTRL_REG0, pedo_reg_value[0]);
    //STEP_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_CTRL_REG1, pedo_reg_value[1]);
    //STEP_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_CTRL_REG2, pedo_reg_value[2]);
    //STEP_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_CTRL_REG3, pedo_reg_value[3]);
    //DELTA
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_DELTA_REG, pedo_reg_value[4]);
    //WTM_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_WTM_REG0, pedo_reg_value[5]);//WTM0_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_WTM_REG1, pedo_reg_value[6]);//WTM1_SET

    SL_SC7A21_Pedo_Reset();

}

static unsigned char sl_wrist_int_status=0;
static unsigned char sl_wrist_int_pin=0;
void SL_SC7A21_Wrist_Config(unsigned char *wrist_reg_value)
{
    //INT_SET  WRIST_EN 0x31,0x31,0x00,0x93
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_CTRL_REG0, wrist_reg_value[0]);
    sl_wrist_int_status=wrist_reg_value[0];  
    sl_wrist_int_pin=0;
    if(sl_wrist_int_status&0xC0)//映射到中断2脚
    {
        sl_wrist_int_pin=0x40;
    }
    if(sl_wrist_int_status&0x30)//*映射到中断1脚
    {
        sl_wrist_int_pin=sl_wrist_int_pin|0x10;
    }

    //WRIST_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_CTRL_REG1, wrist_reg_value[1]);
    //WRIST_ANGLE
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_CTRL_REG2, wrist_reg_value[2]);
    //WRIST_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_CTRL_REG3, wrist_reg_value[3]);  
}

void SL_SC7A21_Sleep_Config(unsigned char *sleep_reg_value)
{
    unsigned char SL_Write_Reg;

    //SLEEP_SET SLEEP_EN
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SLEEP_CTRL_REG0, SL_Write_Reg); 
    //SLEEP_SET
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SLEEP_CTRL_REG1, SL_Write_Reg); 

}

//recommend IN TIMER  1s
unsigned int  SL_SC7A21_Get_Pedo_Count(void)
{
    unsigned char SL_Step_Reg[3];
    unsigned int  SL_Step_Value;
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_STEP_OUT_REG,3, &SL_Step_Reg[0]);
    
    SL_Step_Value=(SL_Step_Reg[2]<<16)|(SL_Step_Reg[1]<<8)|(SL_Step_Reg[0]);

    if(SL_Step_Value-SL_Step_Value_Temp>100)
    {
        return SL_Step_Value_Temp;
    }
    else
    {
        SL_Step_Value_Temp=SL_Step_Value;
        return SL_Step_Value;
    }
}

//recommend IN INT SERVICE READ THIS
unsigned char  SL_SC7A21_Get_Wrist_Status(void)
{
    unsigned char SL_Read_Reg;
    unsigned char SL_Write_Reg;  

    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_STATUS_REG,1, &SL_Read_Reg);

    if(SL_Read_Reg&0x06)//on or down
    {   
        //now on int happen,and set on int before
        if((((SL_Read_Reg&0x02)==0x02)&&((sl_wrist_int_status&sl_wrist_int_pin)==0x00))||
           (((SL_Read_Reg&0x04)==0x04)&&((sl_wrist_int_status&sl_wrist_int_pin)!=0x00)))
        {    
            SL_Write_Reg = (~sl_wrist_int_status)&sl_wrist_int_pin;  
            sl_wrist_int_status = (sl_wrist_int_status&0xAF)|SL_Write_Reg;        
            SL_Write_Reg=sl_wrist_int_status;
            SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_CTRL_REG0, SL_Write_Reg);
        }         
    }
  
    if((SL_Read_Reg&SL_SC7A21_WRIST_ON_STATUS)==SL_SC7A21_WRIST_ON_STATUS)
    {     
        //open down function 
        return 1;//turn on wrist
    }
    else if((SL_Read_Reg&SL_SC7A21_WRIST_DOWN_STATUS)==SL_SC7A21_WRIST_DOWN_STATUS)
    {
        //open on function
        return 2;//turn down wrist
    }
    else
    {
        return 0;//no wrist action
    }
}

//IN TIMER  60s 
#define SL_SLEEP_STATUS_ENABLE    1
unsigned char  SL_SC7A21_Get_Sleep_Status(void)
{
    unsigned char SL_Sleep_Status;

#if SL_SLEEP_STATUS_ENABLE==1
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SLP_LEVEL_REG,1, &SL_Sleep_Status);
#else
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_SLP_ACT_SRC_REG,1, &SL_Sleep_Status);
#endif
    //0：wake        7:deep sleep
    return SL_Sleep_Status;
}

void SL_SC7A21_Single_Click_Config(unsigned char *click_para)//if config the click function
{
	//if config the click function
	if(click_para[0]==0x00)
	{
		SL_SC7A21_Power_Config(SL_SC7A21_ODR_200HZ,1);//200Hz
	}
	else
	{
		SL_SC7A21_Power_Config(SL_SC7A21_ODR_400HZ,0);//400Hz
	}
	
	SL_SC7A21_FIFO_Config(SL_SC7A21_STREAM_MODE_EN,SL_SC7A21_FIFO_8BITS_MODE);//STREAM MODE，8BITS MODE

	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG2, click_para[1]);//High-Pass
	
	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG6, click_para[2]);//CLICK_INT2 ENABLE
	
	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CLICK_CFG, click_para[3]);//Single_Click

	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CLICK_THS_REG, click_para[4]);//Click_VTH
	
	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_TIME_LIMIT_REG, click_para[5]);//Click_TTH
	
	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_TIME_LATENCY_REG, click_para[6]);//Click_Latency
	
	SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_CTRL_REG4, 0x90);//Disable DLPF 4g Scale

}

unsigned int SL_Click_Sqrt(unsigned int sqrt_data)
{
	unsigned int SL_SQRT_LOW,SL_SQRT_UP,SL_SQRT_MID;
	unsigned char sl_sqrt_num=0;
	
	SL_SQRT_LOW=0;
	SL_SQRT_UP=sqrt_data;
	SL_SQRT_MID=(SL_SQRT_UP+SL_SQRT_LOW)/2;	
	while(sl_sqrt_num<200)
	{
		if(SL_SQRT_MID*SL_SQRT_MID>sqrt_data)
		{
			SL_SQRT_UP=SL_SQRT_MID;
		}
		else
		{
			SL_SQRT_LOW=SL_SQRT_MID;				
		}
		if(SL_SQRT_UP-SL_SQRT_LOW==1)
		{
			if(SL_SQRT_UP*SL_SQRT_UP-sqrt_data>sqrt_data-SL_SQRT_LOW*SL_SQRT_LOW)
			{
				return SL_SQRT_LOW;
			}
			else
			{
				return SL_SQRT_UP;
			}
		}
		SL_SQRT_MID=(SL_SQRT_UP+SL_SQRT_LOW)/2;	
		sl_sqrt_num++;
	}
	return 0;
}

#if SL_SC7A21_DEBUG==1
extern signed short         SL_DEBUG_DATA[10][128];
extern unsigned char        SL_DEBUG_DATA_LEN;
#endif

unsigned char sl_pp_num=0;

unsigned char SL_Get_CLICK_PP_CNT(unsigned char fun_flag)
{
	if(fun_flag==0)
		sl_pp_num=0;
	return sl_pp_num;	
}

//default set: 4g TH=90
unsigned char SL_SC7A21_Click_Algo(unsigned int Click_TH,unsigned char Click_E)//Service function in Int Function
{
	unsigned char i=0,j=0,k=0;
	unsigned char click_num=0;
	signed char   fifo_data[3][64];
	unsigned char fifo_len;
	unsigned int  sc7a20_data=0;
	unsigned int  fifo_data_xyz[64];
	unsigned char click_result=0x00;	
	unsigned int   click_sum=0;	
	
	fifo_len=SL_SC7A21_Read_XYZ_FIFO_Data(&fifo_data[0][0],&fifo_data[1][0],&fifo_data[2][0]);
	
	for(i=0;i<fifo_len;i++)
	{
		sc7a20_data=(fifo_data[0][i])*(fifo_data[0][i])+(fifo_data[1][i])*(fifo_data[1][i])+(fifo_data[2][i])*(fifo_data[2][i]);
		sc7a20_data= SL_Click_Sqrt(sc7a20_data);
		fifo_data_xyz[i]=sc7a20_data;
#if SL_SC7A21_DEBUG==1
		SL_DEBUG_DATA[0][i]=fifo_data[0][i];
		SL_DEBUG_DATA[1][i]=fifo_data[1][i];	
		SL_DEBUG_DATA[2][i]=fifo_data[2][i];		
		SL_DEBUG_DATA[3][i]=fifo_data_xyz[i];
		SL_DEBUG_DATA_LEN=fifo_len;	
#endif
	}

	k=0;
	for(i=1;i<fifo_len-1;i++)
	{
		if((fifo_data_xyz[i+1]>Click_TH)&&(fifo_data_xyz[i-1]<30))
		{
			if(click_num==0)
			{
				click_sum=0;//first peak
				for(j=0;j<i-1;j++)
				{
					if(fifo_data_xyz[j]>fifo_data_xyz[j+1])
					{
						click_sum+=fifo_data_xyz[j]-fifo_data_xyz[j+1];	
					}
					else
					{
						click_sum+=fifo_data_xyz[j+1]-fifo_data_xyz[j];	
					}						
				}
#if SL_SC7A21_DEBUG==1
				USART_printf( USART1, "click_sum:%d!\r\n",click_sum);
#endif
				if(click_sum>Click_E)
				{
					sl_pp_num++;
					break;
				}
				k=i;
			}
			else
			{
				k=i;//sencond peak
			}
		}

		if(k!=0)
		{
			if(fifo_data_xyz[i-1]-fifo_data_xyz[i+1]>Click_TH-10)
			{
				if(i-k<5)
				{
					click_num=1;
					break;
				}
			}
		}
	}
	if(click_num==1)
	{
		click_result=1;
	}
	else
	{
		click_result=0;
	}
	
	return click_result;
}
