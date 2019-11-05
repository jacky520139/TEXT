
#include "ALL_Includes.h"


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
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DRDY_REG,1, &SL_Read_Buf[0]);
    
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
    
    SL_SC7A21_I2c_Spi_Read(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_DRDY_REG,1, &SL_Read_Buf[0]);
    
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
    //INT_SET  WRIST_EN
    SL_SC7A21_I2c_Spi_Write(SL_SC7A21_SPI_IIC_MODE,SL_SC7A21_WRIST_CTRL_REG0, wrist_reg_value[0]);
    sl_wrist_int_status=wrist_reg_value[0];  
    sl_wrist_int_pin=0;
    if(sl_wrist_int_status&0xC0)
    {
        sl_wrist_int_pin=0x40;
    }
    if(sl_wrist_int_status&0x30)
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

//recommend IN INT READ THIS

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


