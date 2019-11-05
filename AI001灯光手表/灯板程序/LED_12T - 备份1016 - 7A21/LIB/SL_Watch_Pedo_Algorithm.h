/* 
Copyright (c) 2017 Silan MEMS. All Rights Reserved.
*/

#ifndef SL_Watch_PEDO_ALGO_DRV__H__
#define SL_Watch_PEDO_ALGO_DRV__H__

/***使用驱动前请根据实际接线情况配置******/
/**SC7A20的SDO 脚接地：  0****************/
/**SC7A20的SDO 脚接电源：1****************/
#define SL_SC7A20_SDO_VDD_GND            0
/*****************************************/

/***使用驱动前请根据实际IIC情况进行配置***/
/**SC7A20的IIC 接口地址类型 7bits：  0****/
/**SC7A20的IIC 接口地址类型 8bits：  1****/
#define SL_SC7A20_IIC_7BITS_8BITS        1
/*****************************************/

#if SL_SC7A20_SDO_VDD_GND==0
#define SL_SC7A20_IIC_7BITS_ADDR        0x18
#define SL_SC7A20_IIC_8BITS_WRITE_ADDR  0x30
#define SL_SC7A20_IIC_8BITS_READ_ADDR   0x31
#else
#define SL_SC7A20_IIC_7BITS_ADDR        0x19
#define SL_SC7A20_IIC_8BITS_WRITE_ADDR  0x32
#define SL_SC7A20_IIC_8BITS_READ_ADDR   0x33
#endif

#if SL_SC7A20_IIC_7BITS_8BITS==0
#define SL_SC7A20_IIC_ADDRESS        SL_SC7A20_IIC_7BITS_ADDR
#else
#define SL_SC7A20_IIC_WRITE_ADDRESS  SL_SC7A20_IIC_8BITS_WRITE_ADDR
#define SL_SC7A20_IIC_READ_ADDRESS   SL_SC7A20_IIC_8BITS_READ_ADDR
#endif

/********客户需要进行的IIC接口封包函数****************/
extern unsigned char SL_SC7A20_I2c_Spi_Write(unsigned char sl_spi_iic,unsigned char reg, unsigned char Data);
extern unsigned char SL_SC7A20_I2c_Spi_Read(unsigned char sl_spi_iic,unsigned char reg, unsigned char len, unsigned char *buf);
/**SL_SC7A20_I2c_Spi_Write 函数中， sl_spi_iic:0=spi  1=i2c  Reg：寄存器地址   data：寄存器的配置值******************/
/**SL_SC7A20_I2c_Spi_Write 函数 是一个单次写的函数*******************************************************************/
/***SL_SC7A20_I2c_Spi_Read 函数中， sl_spi_iic:0=spi  1=i2c Reg 同上，len:读取数据长度，buf:存储数据首地址（指针）***/
/***SL_SC7A20_I2c_Spi_Read 函数 是可以进行单次读或多次连续读取的函数*************************************************/

/*************驱动初始化函数**************/
signed char SL_SC7A20_Driver_Init(unsigned char Sl_spi_iic_init,unsigned char Sl_pull_up_mode);
/***输入参数:1,Sl_spi_iic_init:0-1***2,PULL_UP_MODE:0x00 0x08 0x04 0x0c********/
/****Sl_spi_iic_init=0：SPI MODE, Sl_pull_up_mode config failed****************/
/****Sl_spi_iic_init=1：IIC MODE***********************************************/
/****Sl_pull_up_mode=0x00: SDO  I2C  pull up***********************************/
/****Sl_pull_up_mode=0x08: I2C  pull up and  SDO  open drain*******************/
/****Sl_pull_up_mode=0x04: SDO  pull up and  I2C  open drain*******************/
/****Sl_pull_up_mode=0x0C: SDO  I2C  open drain********************************/
/****SDO脚接地，推荐关闭SDO内部上拉电阻****************************************/
/****SPI通讯，推荐关闭SDA，SCL内部上拉电阻，SDO内部上拉电阻会自动关闭**********/

/*************返回数据情况如下*****************/
/**return : 0x11    表示CHIP ID 正常***********/
/**return : 0       表示读取异常***************/
/**return :-1;      SPI 通信问题***************/
/**return :-2;      IIC 通信问题***************/
/**return :-3;      连续读取 通信问题***********/

/***************执行算法前需要读取FIFO数据*****/
/***************FIFO数据读取后，FIFO会清空*****/
/***************所以FIFO只能定时读取一次*******/
unsigned char SL_SC7A20_Read_FIFO(void);
/**return : FIFO_LEN    表示数组长度***********/

/***************获取当天的当前计步值***************/
unsigned int SL_Watch_Pedo_Algo(void);
/**************输出数据为：计步值(步)**************/

/***************获取三轴原始数据***************/
unsigned char SL_SC7A20_GET_FIFO_Buf(signed short *sl_x_buf,signed short *sl_y_buf,signed short *sl_z_buf);
/****************执行算法后执行该命令**********/
/**x_buf  y_buf  z_buf : 长度32的数组首地址****/
/****************返回数据情况如下**************/
/**return : FIFO_LEN    表示数组长度***********/


/******************复位计步值************************/
void SL_Pedo_ResetStepCount(void);
/**********输入数据为：无******输出数据为：无********/
/*使用方法: 系统时间到第二天时，调用该函数清除计步值*/

/******************升级后，设置计步值,距离,热量************************/
/******************升级后，请在初始化函数后，增加该函数*****************/
void SL_Pedo_StepCount_Set(unsigned int sl_pedo_value);
/**********输入数据为：sl_pedo_value  计步值*****/


/******************计步灵敏度设置********************/
void SL_PEDO_TH_SET(unsigned char sl_pedo_amp,unsigned char sl_pedo_th,unsigned char sl_pedo_weak);
/******sl_pedo_amp>10&&sl_pedo_amp<50**********************/
/******sl_pedo_amp:越小灵敏度越高，越容易计步**************/
/******sl_pedo_amp:越大灵敏度越高，越难计步****************/
/******sl_pedo_amp:默认值26，不设置就是26******************/

/******sl_pedo_th>5&&sl_pedo_th<50**********************/
/******sl_pedo_th:越小灵敏度越高，越容易计步**************/
/******sl_pedo_th:越大灵敏度越高，越难计步****************/
/******sl_pedo_th:默认值10，不设置就是10******************/

/******sl_pedo_weak>=0&&sl_pedo_weak<5**********************/
/******sl_pedo_th:0,不打开轻微走路计步功能******************/
/******sl_pedo_th:1,打开轻微走路计步功能********************/
/******sl_pedo_th:2,打开轻微走路计步功能********************/
/******sl_pedo_th:3,打开轻微走路计步功能********************/
/******sl_pedo_th:4,打开轻微走路计步功能********************/
/******sl_pedo_th:默认值0,设置的值越大，检测计步的越灵敏****/

/*******计步主轴设置****************/
void SL_PEDO_SET_AXIS(unsigned char sl_xyz);
/***sl_xyz:0  x轴*******************/
/***sl_xyz:1  y轴*******************/
/***sl_xyz:2  z轴*******************/
/***sl_xyz:3  算法决定**************/

/***********关闭IIC设备**************/
/***********Power down 函数**********/
/********不使用该设备情况下**********/
/****如需重启，使用驱动初始化函数****/
signed char  SL_SC7A20_Power_Down(void);
/*************输入参数:无************/
/**********返回参数情况说明**********/
/**return  1: Power Down Success*****/
/**return -1: Power Down Fail********/


#endif/****SL_Watch_ALGO_DRV__H__****/



