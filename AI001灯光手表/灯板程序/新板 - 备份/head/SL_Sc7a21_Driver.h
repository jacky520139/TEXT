#ifndef __SL_SC7A21_DRIVER_H__
#define __SL_SC7A21_DRIVER_H__

/***********Silan****************/
/***********MEMS*****************/
/***********ZHOUMIN**************/
/***********20190226*************/

/***使用驱动前请根据实际接线情况配置******/
/**SC7A21的SDO 脚接地：  0****************/
/**SC7A21的SDO 脚接电源：1****************/
#define SC7A21_SDO_VDD_GND            0
/*****************************************/

/***使用驱动前请根据实际IIC情况进行配置***/
/**SC7A21的IIC 接口地址类型 7bits：  0****/
/**SC7A21的IIC 接口地址类型 8bits：  1****/
#define SC7A21_IIC_7BITS_8BITS        0
/*****************************************/

#if SC7A21_SDO_VDD_GND==0
#define SC7A21_IIC_7BITS_ADDR        0x18
#define SC7A21_IIC_8BITS_ADDR        0x30
#else
#define SC7A21_IIC_7BITS_ADDR        0x19
#define SC7A21_IIC_8BITS_ADDR        0x32
#endif

#if SC7A21_IIC_7BITS_8BITS==0
#define SC7A21_IIC_ADDRESS  SC7A21_IIC_7BITS_ADDR
#else
#define SC7A21_IIC_ADDRESS  SC7A21_IIC_8BITS_ADDR
#endif

#define  SL_SC7A21_16BIT_8BIT         1
/**SC7A21的数据位数选择  16bits：    1******/
/**SC7A21的数据位数选择   8bits：    0******/
/*******************************************/

#define  SL_SC7A21_FIFO_16BIT_8BIT    1
/**SC7A21 FIFO 的数据位数选择  16bits：1****/
/**SC7A21 FIFO 的数据位数选择   8bits：0****/
/*******************************************/

#define SL_SC7A21_SPI_IIC_MODE        1
/***SL_SC7A21_SPI_IIC_MODE==0  :SPI*********/
/***SL_SC7A21_SPI_IIC_MODE==1  :IIC*********/



#define SC7A21_CHIP_ID_ADDRESS       (unsigned char)0x0F
#define SC7A21_CHIP_ID_VALUE         (unsigned char)0x13

/**IN SPI MODE,IIC MODE NEED CLOSE**/
#define SC7A21_IIC_EN_REG            (unsigned char)0x0E
#define SC7A21_IIC_DISEN_VALUE       (unsigned char)0x04


/**WRIST REG**/
#define  SL_SC7A21_WRIST_STATUS_REG  (unsigned char)0x06
#define  SL_SC7A21_WRIST_STATUS_EN   (unsigned char)0x01
#define  SL_SC7A21_WRIST_ON_STATUS   (unsigned char)0x02
#define  SL_SC7A21_WRIST_DOWN_STATUS (unsigned char)0x04    

#define  SL_SC7A21_WRIST_CTRL_REG0   (unsigned char)0x08
#define  SL_SC7A21_WRIST_EN          (unsigned char)0x01 
#define  SL_SC7A21_WRIST_INT1_MODE0  (unsigned char)0x00//NO INT1
#define  SL_SC7A21_WRIST_INT1_MODE1  (unsigned char)0x10//ON&DOWN-->INT1
#define  SL_SC7A21_WRIST_INT1_MODE2  (unsigned char)0x20//ON     -->INT1 
#define  SL_SC7A21_WRIST_INT1_MODE3  (unsigned char)0x30//DOWN   -->INT1
#define  SL_SC7A21_WRIST_INT2_MODE0  (unsigned char)0x00//NO INT2
#define  SL_SC7A21_WRIST_INT2_MODE1  (unsigned char)0x40//ON&DOWN-->INT2
#define  SL_SC7A21_WRIST_INT2_MODE2  (unsigned char)0x80//ON     -->INT2
#define  SL_SC7A21_WRIST_INT2_MODE3  (unsigned char)0xC0//DOWN   -->INT2

#define  SL_SC7A21_WRIST_CTRL_REG1   (unsigned char)0x09//WRIST ANGLE SCALE
#define  SL_SC7A21_WRIST_A_SCALE0    (unsigned char)0x00
#define  SL_SC7A21_WRIST_A_SCALE1    (unsigned char)0x10
#define  SL_SC7A21_WRIST_A_SCALE2    (unsigned char)0x20
#define  SL_SC7A21_WRIST_A_SCALE3    (unsigned char)0x30
#define  SL_SC7A21_WRIST_A_SCALE4    (unsigned char)0x40
#define  SL_SC7A21_WRIST_A_SCALE5    (unsigned char)0x50
#define  SL_SC7A21_WRIST_A_SCALE6    (unsigned char)0x60
#define  SL_SC7A21_WRIST_A_SCALE7    (unsigned char)0x70
#define  SL_SC7A21_WRIST_SENSOR_POS0 (unsigned char)0x00//Refer Datasheet
#define  SL_SC7A21_WRIST_SENSOR_POS1 (unsigned char)0x01
#define  SL_SC7A21_WRIST_SENSOR_POS2 (unsigned char)0x02
#define  SL_SC7A21_WRIST_SENSOR_POS3 (unsigned char)0x03
#define  SL_SC7A21_WRIST_SENSOR_POS4 (unsigned char)0x04
#define  SL_SC7A21_WRIST_SENSOR_POS5 (unsigned char)0x05
#define  SL_SC7A21_WRIST_SENSOR_POS6 (unsigned char)0x06
#define  SL_SC7A21_WRIST_SENSOR_POS7 (unsigned char)0x07

#define  SL_SC7A21_WRIST_CTRL_REG2   (unsigned char)0x0A//WRIST TARGET ANGLE
#define  SL_SC7A21_WRIST_ANGLE_5     (unsigned char)0x05
#define  SL_SC7A21_WRIST_ANGLE_10    (unsigned char)0x0A
#define  SL_SC7A21_WRIST_ANGLE_15    (unsigned char)0x0A
#define  SL_SC7A21_WRIST_ANGLE_20    (unsigned char)0x0A
#define  SL_SC7A21_WRIST_ANGLE_25    (unsigned char)0x0A
#define  SL_SC7A21_WRIST_ANGLE_30    (unsigned char)0x0A
#define  SL_SC7A21_WRIST_ANGLE_35    (unsigned char)0x0A
#define  SL_SC7A21_WRIST_ANGLE_40    (unsigned char)0x0A    

#define  SL_SC7A21_WRIST_CTRL_REG3   (unsigned char)0x0B//WRIST SEN TT_TH FT_TH
#define  SL_SC7A21_WRIST_SEN0        (unsigned char)0x00
#define  SL_SC7A21_WRIST_SEN1        (unsigned char)0x40    
#define  SL_SC7A21_WRIST_SEN2        (unsigned char)0x80
#define  SL_SC7A21_WRIST_SEN3        (unsigned char)0xC0
#define  SL_SC7A21_WRIST_TT_TH0      (unsigned char)0x00
#define  SL_SC7A21_WRIST_TT_TH1      (unsigned char)0x08
#define  SL_SC7A21_WRIST_TT_TH2      (unsigned char)0x10
#define  SL_SC7A21_WRIST_TT_TH3      (unsigned char)0x18
#define  SL_SC7A21_WRIST_TT_TH4      (unsigned char)0x20
#define  SL_SC7A21_WRIST_TT_TH5      (unsigned char)0x28
#define  SL_SC7A21_WRIST_TT_TH6      (unsigned char)0x30
#define  SL_SC7A21_WRIST_TT_TH7      (unsigned char)0x38
#define  SL_SC7A21_WRIST_FT_TH0      (unsigned char)0x00    
#define  SL_SC7A21_WRIST_FT_TH1      (unsigned char)0x01 
#define  SL_SC7A21_WRIST_FT_TH2      (unsigned char)0x02 
#define  SL_SC7A21_WRIST_FT_TH3      (unsigned char)0x03                             
#define  SL_SC7A21_WRIST_FT_TH4      (unsigned char)0x04 
#define  SL_SC7A21_WRIST_FT_TH5      (unsigned char)0x05 
#define  SL_SC7A21_WRIST_FT_TH6      (unsigned char)0x06 
#define  SL_SC7A21_WRIST_FT_TH7      (unsigned char)0x07 
/**WRIST REG END**/

/**PEDO REG**/
#define  SL_SC7A21_STEP_CTRL_REG0   (unsigned char)0x10//PEDO
#define  SL_SC7A21_STEP_EN          (unsigned char)0x01
#define  SL_SC7A21_STEP_MODE_25Hz   (unsigned char)0x00
#define  SL_SC7A21_STEP_MODE_50Hz   (unsigned char)0x02
#define  SL_SC7A21_STEP_CLEAR_EN    (unsigned char)0x04
#define  SL_SC7A21_STEP_INT1_MODE0  (unsigned char)0x00//NO INT1
#define  SL_SC7A21_STEP_INT1_MODE1  (unsigned char)0x10//OVERRUN-->INT1
#define  SL_SC7A21_STEP_INT1_MODE2  (unsigned char)0x20//DELTA  -->INT1 
#define  SL_SC7A21_STEP_INT1_MODE3  (unsigned char)0x30//WTM    -->INT1
#define  SL_SC7A21_STEP_INT2_MODE0  (unsigned char)0x00//NO INT2
#define  SL_SC7A21_STEP_INT2_MODE1  (unsigned char)0x40//OVERRUN-->INT2
#define  SL_SC7A21_STEP_INT2_MODE2  (unsigned char)0x80//DELTA  -->INT2
#define  SL_SC7A21_STEP_INT2_MODE3  (unsigned char)0xC0//WTM    -->INT2

#define  SL_SC7A21_STEP_DELTA_REG    (unsigned char)0x11
#define  SL_SC7A21_STEP_DELTA_5      (unsigned char)0x05
#define  SL_SC7A21_STEP_DELTA_10     (unsigned char)0x0A
#define  SL_SC7A21_STEP_DELTA_50     (unsigned char)0x32    
#define  SL_SC7A21_STEP_DELTA_100    (unsigned char)0x64

#define  SL_SC7A21_STEP_WTM_REG0     (unsigned char)0x12
#define  SL_SC7A21_STEP_WTM_REG1     (unsigned char)0x13    

#define  SL_SC7A21_STEP_SRC_REG      (unsigned char)0x14
#define  SL_SC7A21_STEP_SRC_OVER     (unsigned char)0x01
#define  SL_SC7A21_STEP_SRC_DELTA    (unsigned char)0x02
#define  SL_SC7A21_STEP_SRC_WTM      (unsigned char)0x04

#define  SL_SC7A21_STEP_OUT_L        (unsigned char)0x15
#define  SL_SC7A21_STEP_OUT_M        (unsigned char)0x16
#define  SL_SC7A21_STEP_OUT_H        (unsigned char)0x17
#define  SL_SC7A21_STEP_OUT_REG      (unsigned char)(SL_SC7A21_STEP_OUT_L|0x80)

#define  SL_SC7A21_STEP_CTRL_REG1    (unsigned char)0x18//PEDO
#define  SL_SC7A21_STEP_AXC_TH0      (unsigned char)0x00
#define  SL_SC7A21_STEP_AXC_TH1      (unsigned char)0x40   
#define  SL_SC7A21_STEP_AXC_TH2      (unsigned char)0x80  
#define  SL_SC7A21_STEP_AXC_TH3      (unsigned char)0xC0
	
#define  SL_SC7A21_STEP_ST_TH0       (unsigned char)0x00
#define  SL_SC7A21_STEP_ST_TH1       (unsigned char)0x08
#define  SL_SC7A21_STEP_ST_TH2       (unsigned char)0x10
#define  SL_SC7A21_STEP_ST_TH3       (unsigned char)0x18
#define  SL_SC7A21_STEP_ST_TH4       (unsigned char)0x20
#define  SL_SC7A21_STEP_ST_TH5       (unsigned char)0x28
#define  SL_SC7A21_STEP_ST_TH6       (unsigned char)0x30
#define  SL_SC7A21_STEP_ST_TH7       (unsigned char)0x38
	
#define  SL_SC7A21_STEP_DIFF0        (unsigned char)0x00
#define  SL_SC7A21_STEP_DIFF1        (unsigned char)0x01
#define  SL_SC7A21_STEP_DIFF2        (unsigned char)0x02
#define  SL_SC7A21_STEP_DIFF3        (unsigned char)0x03
#define  SL_SC7A21_STEP_DIFF4        (unsigned char)0x04
#define  SL_SC7A21_STEP_DIFF5        (unsigned char)0x05
#define  SL_SC7A21_STEP_DIFF6        (unsigned char)0x06
#define  SL_SC7A21_STEP_DIFF7        (unsigned char)0x07
 
#define  SL_SC7A21_STEP_CTRL_REG2    (unsigned char)0x19//PEDO
#define  SL_SC7A21_STEP_AXS_TH0      (unsigned char)0x00//ALGO
#define  SL_SC7A21_STEP_AXS_TH1      (unsigned char)0x40//X   
#define  SL_SC7A21_STEP_AXS_TH2      (unsigned char)0x80//Y 
#define  SL_SC7A21_STEP_AXS_TH3      (unsigned char)0xC0//Z
	
#define  SL_SC7A21_STEP_BL_TH0       (unsigned char)0x00
#define  SL_SC7A21_STEP_BL_TH1       (unsigned char)0x08
#define  SL_SC7A21_STEP_BL_TH2       (unsigned char)0x10
#define  SL_SC7A21_STEP_BL_TH3       (unsigned char)0x18
#define  SL_SC7A21_STEP_BL_TH4       (unsigned char)0x20
#define  SL_SC7A21_STEP_BL_TH5       (unsigned char)0x28
#define  SL_SC7A21_STEP_BL_TH6       (unsigned char)0x30
#define  SL_SC7A21_STEP_BL_TH7       (unsigned char)0x38 
	
#define  SL_SC7A21_STEP_UL_TH0       (unsigned char)0x00
#define  SL_SC7A21_STEP_UL_TH1       (unsigned char)0x01
#define  SL_SC7A21_STEP_UL_TH2       (unsigned char)0x02
#define  SL_SC7A21_STEP_UL_TH3       (unsigned char)0x03
#define  SL_SC7A21_STEP_UL_TH4       (unsigned char)0x04
#define  SL_SC7A21_STEP_UL_TH5       (unsigned char)0x05
#define  SL_SC7A21_STEP_UL_TH6       (unsigned char)0x06
#define  SL_SC7A21_STEP_UL_TH7       (unsigned char)0x07

#define  SL_SC7A21_STEP_CTRL_REG3    (unsigned char)0x1A//PEDO
#define  SL_SC7A21_STEP_SEN_TH0      (unsigned char)0x00
#define  SL_SC7A21_STEP_SEN_TH1      (unsigned char)0x10
#define  SL_SC7A21_STEP_SEN_TH2      (unsigned char)0x20
#define  SL_SC7A21_STEP_SEN_TH3      (unsigned char)0x30
#define  SL_SC7A21_STEP_SEN_TH4      (unsigned char)0x40
#define  SL_SC7A21_STEP_SEN_TH5      (unsigned char)0x50
#define  SL_SC7A21_STEP_SEN_TH6      (unsigned char)0x60
#define  SL_SC7A21_STEP_SEN_TH7      (unsigned char)0x70
/**PEDO REG END**/


#define  SL_SC7A21_CTRL_REG0         (unsigned char)0x1F  
#define  SL_SC7A21_ABW_400HZ         (unsigned char)0x00
#define  SL_SC7A21_ABW_200HZ         (unsigned char)0x01
#define  SL_SC7A21_ABW_100HZ         (unsigned char)0x02
#define  SL_SC7A21_ABW_50HZ          (unsigned char)0x03
#define  SL_SC7A21_ALPF_EN           (unsigned char)0x04
#define  SL_SC7A21_HI_PWR_EN         (unsigned char)0x08

#define  SL_SC7A21_CTRL_REG1         (unsigned char)0x20
/***************数据更新速率**加速度计使能**********/
#define  SL_SC7A21_ODR_POWER_DOWN    (unsigned char)0x00
#define  SL_SC7A21_ODR_1HZ           (unsigned char)0x17
#define  SL_SC7A21_ODR_12HZ          (unsigned char)0x27
#define  SL_SC7A21_ODR_25HZ          (unsigned char)0x37
#define  SL_SC7A21_ODR_50HZ          (unsigned char)0x47
#define  SL_SC7A21_ODR_100HZ         (unsigned char)0x57
#define  SL_SC7A21_ODR_200HZ         (unsigned char)0x67
#define  SL_SC7A21_ODR_400HZ         (unsigned char)0x77
#define  SL_SC7A21_ODR_800HZ         (unsigned char)0x87
#define  SL_SC7A21_ODR_1600HZ        (unsigned char)0x97
#define  SL_SC7A21_ODR_2560HZ        (unsigned char)0xA7    
#define  SL_SC7A21_ODR_4067HZ        (unsigned char)0xBF
    
#define  SL_SC7A21_LOWER_POWER       (unsigned char)0x00
#define  SL_SC7A21_NORMAL_POWER      (unsigned char)0x01
#define  SL_SC7A21_HI_PWR_POWER      (unsigned char)0x02
/***************数据更新速率**加速度计使能**********/

#define  SL_SC7A21_CTRL_REG2         (unsigned char)0x21
#define  SL_SC7A21_HPF_HPM0          (unsigned char)0x00
#define  SL_SC7A21_HPF_HPM1          (unsigned char)0x40
#define  SL_SC7A21_HPF_HPM2          (unsigned char)0x80//Normal Mode
#define  SL_SC7A21_HPF_HPM3          (unsigned char)0xC0
#define  SL_SC7A21_HPF_HPCF0         (unsigned char)0x00
#define  SL_SC7A21_HPF_HPCF1         (unsigned char)0x10
#define  SL_SC7A21_HPF_HPCF2         (unsigned char)0x20
#define  SL_SC7A21_HPF_HPCF3         (unsigned char)0x30
#define  SL_SC7A21_HPF_OUT_EN        (unsigned char)0x08
#define  SL_SC7A21_HPF_CLICK_EN      (unsigned char)0x04   
#define  SL_SC7A21_HPF_AOI2_EN       (unsigned char)0x02 
#define  SL_SC7A21_HPF_AOI1_EN       (unsigned char)0x01 
//
#define  SL_SC7A21_CTRL_REG3         (unsigned char)0x22
#define  SL_SC7A21_INT1_CLICK        (unsigned char)0x80
#define  SL_SC7A21_INT1_AOI1         (unsigned char)0x40
#define  SL_SC7A21_INT1_AOI2         (unsigned char)0x20
#define  SL_SC7A21_INT1_DRDY1        (unsigned char)0x10
#define  SL_SC7A21_INT1_DRDY2        (unsigned char)0x08
#define  SL_SC7A21_INT1_WTM          (unsigned char)0x04
#define  SL_SC7A21_INT1_OVERRUN      (unsigned char)0x02
#define  SL_SC7A21_CLICK_LATCH_EN    (unsigned char)0x01

#define  SL_SC7A21_CTRL_REG4         (unsigned char)0x23
#define  SL_SC7A21_DATA_BDU_EN       (unsigned char)0x80 
#define  SL_SC7A21_DATA_BLE_EN       (unsigned char)0x40
#define  SL_SC7A21_DATA_FS_2G        (unsigned char)0x00		
#define  SL_SC7A21_DATA_FS_4G        (unsigned char)0x10
#define  SL_SC7A21_DATA_FS_8G        (unsigned char)0x20	
#define  SL_SC7A21_DATA_FS_16G       (unsigned char)0x30
#define  SL_SC7A21_DATA_DLPF_EN      (unsigned char)0x08
#define  SL_SC7A21_TEST_DISEN        (unsigned char)0x00   
#define  SL_SC7A21_SPI_MODE3         (unsigned char)0x01
#define  SL_SC7A21_SPI_MODE4         (unsigned char)0x00

#define  SL_SC7A21_CTRL_REG5         (unsigned char)0x24
#define  SL_SC7A21_BOOT_EN           (unsigned char)0x80
#define  SL_SC7A21_FIFO_8BITS        (unsigned char)0x40
#define  SL_SC7A21_FIFO_16BITS       (unsigned char)0x00
#define  SL_SC7A21_LATCH_MODE0       (unsigned char)0x00    
#define  SL_SC7A21_LATCH_MODE1       (unsigned char)0x10 
#define  SL_SC7A21_LATCH_MODE2       (unsigned char)0x20 
#define  SL_SC7A21_LATCH_MODE3       (unsigned char)0x30
#define  SL_SC7A21_LIR_AOI1_EN       (unsigned char)0x08
#define  SL_SC7A21_D4D_AOI1_EN       (unsigned char)0x08
#define  SL_SC7A21_LIR_AOI2_EN       (unsigned char)0x08
#define  SL_SC7A21_D4D_AOI2_EN       (unsigned char)0x08
#define  SL_SC7A21_FIFO_BITS_MSK     (unsigned char)0x40
    
#define  SL_SC7A21_CTRL_REG6         (unsigned char)0x25
#define  SL_SC7A21_INT2_CLICK        (unsigned char)0x80
#define  SL_SC7A21_INT2_AOI1         (unsigned char)0x40
#define  SL_SC7A21_INT2_AOI2         (unsigned char)0x20
#define  SL_SC7A21_INT2_BOOT         (unsigned char)0x10
#define  SL_SC7A21_INT2_ACT          (unsigned char)0x08
#define  SL_SC7A21_CS_PU_EN          (unsigned char)0x00
#define  SL_SC7A21_CS_PU_DISEN       (unsigned char)0x04
/***中断有效时的电平设置，高电平相当于上升沿，低电平相当于下降沿****/
#define  SL_SC7A21_INT_ACT_L_LEVEL   (unsigned char)0x02 //中断时INT脚输出 低电平
#define  SL_SC7A21_INT_ACT_H_LEVEL   (unsigned char)0x00 //中断时INT脚输出 高电平     
#define  SL_SC7A21_INT_PP_OUT        (unsigned char)0x00
#define  SL_SC7A21_INT_OD_OUT        (unsigned char)0x01

#define  SL_SC7A21_DRDY_REG          (unsigned char)0x27
#define  SL_SC7A21_XYZ_DRDY          (unsigned char)0x0F//所有数据就位  

#define  SL_SC7A21_OUT_X_L           (unsigned char)0x28
#define  SL_SC7A21_OUT_X_H           (unsigned char)0x29
#define  SL_SC7A21_OUT_Y_L           (unsigned char)0x2A
#define  SL_SC7A21_OUT_Y_H           (unsigned char)0x2B
#define  SL_SC7A21_OUT_Z_L           (unsigned char)0x2C
#define  SL_SC7A21_OUT_Z_H           (unsigned char)0x2D
/*连续读取数据时的数据寄存器地址*/
#define  SL_SC7A21_DATA_OUT          (unsigned char)(SL_SC7A21_OUT_X_L|0x80)    

#define  SL_SC7A21_FIFO_CTRL_REG     (unsigned char)0x2E
#define  SL_SC7A21_FIFO_FM_BYPASS    (unsigned char)0x00
#define  SL_SC7A21_FIFO_FM_FIFO      (unsigned char)0x40   
#define  SL_SC7A21_FIFO_FM_STREAM    (unsigned char)0x80
#define  SL_SC7A21_FIFO_FM_TRIGGER   (unsigned char)0xC0
#define  SL_SC7A21_FIFO_TR_AOI1      (unsigned char)0x00
#define  SL_SC7A21_FIFO_TR_AOI2      (unsigned char)0x20
#define  SL_SC7A21_FIFO_FTH_0        (unsigned char)0x00 
#define  SL_SC7A21_FIFO_FTH_15       (unsigned char)0x0F
#define  SL_SC7A21_FIFO_FTH_25       (unsigned char)0x19
#define  SL_SC7A21_FIFO_FTH_31       (unsigned char)0x1F
#define  SL_SC7A21_FIFO_FM_MSK       (unsigned char)0x3F 

#define  SL_SC7A21_FIFO_MODE_DIS     (unsigned char)0x00
#define  SL_SC7A21_FIFO_MODE_EN      (unsigned char)0x01
#define  SL_SC7A21_STREAM_MODE_EN    (unsigned char)0x02
#define  SL_SC7A21_FIFO_16BITS_MODE  (unsigned char)0x00
#define  SL_SC7A21_FIFO_8BITS_MODE   (unsigned char)0x01

#define  SL_SC7A21_FIFO_SRC_REG      (unsigned char)0x2F
#define  SL_SC7A21_FIFO_WTM_FLAG     (unsigned char)0x80
#define  SL_SC7A21_FIFO_OVER_FLAG    (unsigned char)0x40
#define  SL_SC7A21_FIFO_8FSS_FLAG    (unsigned char)0x3F
#define  SL_SC7A21_FIFO_16FSS_FLAG   (unsigned char)0x1F
    
#define  SL_SC7A21_AOI1_CFG    	     (unsigned char)0x30
#define  SL_SC7A21_AOI_OR    	     (unsigned char)0x00    
#define  SL_SC7A21_AOI_MOTION	     (unsigned char)0x40  
#define  SL_SC7A21_AOI_AND  	     (unsigned char)0x80  
#define  SL_SC7A21_AOI_POSITION      (unsigned char)0xC0 
#define  SL_SC7A21_AOI_ZHZU_EN       (unsigned char)0x20
#define  SL_SC7A21_AOI_ZLZD_EN       (unsigned char)0x10
#define  SL_SC7A21_AOI_YHYP_EN       (unsigned char)0x08
#define  SL_SC7A21_AOI_YLYD_EN       (unsigned char)0x04
#define  SL_SC7A21_AOI_XHXP_EN       (unsigned char)0x02
#define  SL_SC7A21_AOI_XLXD_EN       (unsigned char)0x01

#define  SL_SC7A21_AOI1_SRC          (unsigned char)0x31
#define  SL_SC7A21_IA_FLAG           (unsigned char)0x40
#define  SL_SC7A21_ZH_FLAG           (unsigned char)0x20
#define  SL_SC7A21_ZL_FLAG           (unsigned char)0x10
#define  SL_SC7A21_YH_FLAG           (unsigned char)0x08
#define  SL_SC7A21_YL_FLAG           (unsigned char)0x04
#define  SL_SC7A21_XH_FLAG           (unsigned char)0x02
#define  SL_SC7A21_XL_FLAG           (unsigned char)0x01
#define  SL_SC7A21_Z_FLAG            (unsigned char)0x30
#define  SL_SC7A21_Y_FLAG            (unsigned char)0x0C
#define  SL_SC7A21_X_FLAG            (unsigned char)0x03

#define  SL_SC7A21_AOI1_THS    	     (unsigned char)0x32
/***取值在0-127之间，此处仅举例****/
#define SL_SC7A21_AOI_THS_5PERCENT   (unsigned char)0x06
#define SL_SC7A21_AOI_THS_10PERCENT  (unsigned char)0x0C
#define SL_SC7A21_AOI_THS_20PERCENT  (unsigned char)0x18
#define SL_SC7A21_AOI_THS_40PERCENT  (unsigned char)0x30
#define SL_SC7A21_AOI_THS_80PERCENT  (unsigned char)0x60

#define  SL_SC7A21_AOI1_DURATION     (unsigned char)0x33
/***取值在0-127之间，此处仅举例 乘以ODR单位时间****/
#define SL_SC7A21_AOI_DURATION_2CLK  (unsigned char)0x02
#define SL_SC7A21_AOI_DURATION_5CLK  (unsigned char)0x05
#define SL_SC7A21_AOI_DURATION_10CLK (unsigned char)0x0A

#define  SL_SC7A21_AOI2_CFG    	     (unsigned char)0x34
#define  SL_SC7A21_AOI2_SRC          (unsigned char)0x35
#define  SL_SC7A21_AOI2_THS    	     (unsigned char)0x36
#define  SL_SC7A21_AOI2_DURATION     (unsigned char)0x37
//同AOI1

#define  SL_SC7A21_CLICK_CFG   	     (unsigned char)0x38
#define  SL_SC7A21_CLICK_ZD   	     (unsigned char)0x20
#define  SL_SC7A21_CLICK_ZS   	     (unsigned char)0x10
#define  SL_SC7A21_CLICK_YD   	     (unsigned char)0x08
#define  SL_SC7A21_CLICK_YS   	     (unsigned char)0x04
#define  SL_SC7A21_CLICK_XD   	     (unsigned char)0x02
#define  SL_SC7A21_CLICK_XS   	     (unsigned char)0x01
#define  SL_SC7A21_CLICK_XYZD 	     (unsigned char)(SL_SC7A21_CLICK_ZD|SL_SC7A21_CLICK_YD|SL_SC7A21_CLICK_XD)   
#define  SL_SC7A21_CLICK_XYZS 	     (unsigned char)(SL_SC7A21_CLICK_ZS|SL_SC7A21_CLICK_YS|SL_SC7A21_CLICK_XS)

#define  SL_SC7A21_CLICK_SRC   	     (unsigned char)0x39
#define  SL_SC7A21_TIP_IA_FLAG       (unsigned char)0x40
#define  SL_SC7A21_TIP_D_FLAG        (unsigned char)0x20
#define  SL_SC7A21_TIP_S_FLAG        (unsigned char)0x10
#define  SL_SC7A21_SIGN_FLAG         (unsigned char)0x08
#define  SL_SC7A21_TIP_Z_FLAG        (unsigned char)0x04
#define  SL_SC7A21_TIP_Y_FLAG        (unsigned char)0x02
#define  SL_SC7A21_TIP_X_FLAG        (unsigned char)0x01

#define  SL_SC7A21_CLICK_THS_REG     (unsigned char)0x3A
#define  SL_SC7A21_CLICK_THS_5       (unsigned char)0x06
#define  SL_SC7A21_CLICK_THS_10      (unsigned char)0x0C
#define  SL_SC7A21_CLICK_THS_20      (unsigned char)0x18
#define  SL_SC7A21_CLICK_THS_40      (unsigned char)0x30
#define  SL_SC7A21_CLICK_THS_80      (unsigned char)0x60

#define  SL_SC7A21_TIME_LIMIT_REG    (unsigned char)0x3B
#define  SL_SC7A21_CLICK_TIME_1      (unsigned char)0x01
#define  SL_SC7A21_CLICK_TIME_3      (unsigned char)0x03
#define  SL_SC7A21_CLICK_TIME_5      (unsigned char)0x05
#define  SL_SC7A21_CLICK_TIME_8      (unsigned char)0x08
#define  SL_SC7A21_CLICK_TIME_10     (unsigned char)0x0A

#define  SL_SC7A21_TIME_LATENCY_REG  (unsigned char)0x3C
#define  SL_SC7A21_TIME_LA_1         (unsigned char)0x01
#define  SL_SC7A21_TIME_LA_2         (unsigned char)0x02
#define  SL_SC7A21_TIME_LA_5         (unsigned char)0x05
#define  SL_SC7A21_TIME_LA_8         (unsigned char)0x08
#define  SL_SC7A21_TIME_LA_10        (unsigned char)0x0A
#define  SL_SC7A21_TIME_LA_20        (unsigned char)0x14

#define  SL_SC7A21_TIME_WINDOW_REG   (unsigned char)0x3D
#define  SL_SC7A21_TIME_WINDOW_10    (unsigned char)0x0A
#define  SL_SC7A21_TIME_WINDOW_20    (unsigned char)0x14 
#define  SL_SC7A21_TIME_WINDOW_30    (unsigned char)0x1E 
#define  SL_SC7A21_TIME_WINDOW_40    (unsigned char)0x28 
#define  SL_SC7A21_TIME_WINDOW_50    (unsigned char)0x32 
#define  SL_SC7A21_TIME_WINDOW_60    (unsigned char)0x3C 

#define  SL_SC7A21_ACT_THS_REG       (unsigned char)0x3E
#define  SL_SC7A21_ACT_THS_10        (unsigned char)0x0A 
#define  SL_SC7A21_ACT_THS_20        (unsigned char)0x14 
#define  SL_SC7A21_ACT_THS_30        (unsigned char)0x1E 
#define  SL_SC7A21_ACT_THS_40        (unsigned char)0x28 
#define  SL_SC7A21_ACT_THS_50        (unsigned char)0x32 
#define  SL_SC7A21_ACT_THS_60        (unsigned char)0x3C

#define  SL_SC7A21_ACT_DURATION      (unsigned char)0x3F
#define  SL_SC7A21_ACT_DUR_10        (unsigned char)0x0A 
#define  SL_SC7A21_ACT_DUR_20        (unsigned char)0x14 
#define  SL_SC7A21_ACT_DUR_30        (unsigned char)0x1E 
#define  SL_SC7A21_ACT_DUR_40        (unsigned char)0x28 
#define  SL_SC7A21_ACT_DUR_50        (unsigned char)0x32 
#define  SL_SC7A21_ACT_DUR_60        (unsigned char)0x3C  

/**SLEEP**/
#define  SL_SC7A21_SLEEP_CTRL_REG0   (unsigned char)0x6B
#define  SL_SC7A21_SLEEP_EN          (unsigned char)0x01 
#define  SL_SC7A21_SLEEP_INT_MODE0   (unsigned char)0x00
#define  SL_SC7A21_SLEEP_INT_MODE1   (unsigned char)0x10
#define  SL_SC7A21_SLEEP_INT_MODE2   (unsigned char)0x20
#define  SL_SC7A21_SLEEP_INT_MODE3   (unsigned char)0x30

#define  SL_SC7A21_SLEEP_CTRL_REG1   (unsigned char)0x6C
#define  SL_SC7A21_SLEEP_BIT0        (unsigned char)0x00
#define  SL_SC7A21_SLEEP_BIT1        (unsigned char)0x10
#define  SL_SC7A21_SLEEP_BIT2        (unsigned char)0x20
#define  SL_SC7A21_SLEEP_BIT3        (unsigned char)0x30
#define  SL_SC7A21_SLEEP_TH0         (unsigned char)0x00
#define  SL_SC7A21_SLEEP_TH1         (unsigned char)0x40
#define  SL_SC7A21_SLEEP_TH2         (unsigned char)0x80
#define  SL_SC7A21_SLEEP_TH3         (unsigned char)0xC0
#define  SL_SC7A21_SLEEP_TIME0       (unsigned char)0x00
#define  SL_SC7A21_SLEEP_TIME1       (unsigned char)0x01
#define  SL_SC7A21_SLEEP_TIME2       (unsigned char)0x02
#define  SL_SC7A21_SLEEP_TIME3       (unsigned char)0x03

#define  SL_SC7A21_SLEEP_SRC_REG     (unsigned char)0x6D
#define  SL_SC7A21_SLEEP_DRDYS       (unsigned char)0x01

#define  SL_SC7A21_SLP_ACT_SRC_REG   (unsigned char)0x6E
#define  SL_SC7A21_SLP_LEVEL_REG     (unsigned char)0x6F

//POR
#define  SL_SC7A21_SOFT_RESET_REG    (unsigned char)0x68
#define  SL_SC7A21_SOFT_RESET_VALUE  (unsigned char)0xA5

/**********特殊功能寄存器**********/
#define  SL_SC7A21_SDO_I2C_PU_CFG    (unsigned char)0x57
#define  SL_SC7A21_SDO_I2C_PU_EN     (unsigned char)0x00
#define  SL_SC7A21_I2C_PU_DIS        (unsigned char)0x04
#define  SL_SC7A21_SDO_PU_DIS        (unsigned char)0x08
#define  SL_SC7A21_SDO_I2C_DIS       (unsigned char)0x0C

    
/********客户需要进行的IIC接口封包函数****************/
extern unsigned char SL_SC7A21_I2c_Spi_Write(unsigned char sl_spi_iic,unsigned char reg, unsigned char Data);
extern unsigned char SL_SC7A21_I2c_Spi_Read(unsigned char sl_spi_iic,unsigned char reg, unsigned char len, unsigned char *buf);
/**SL_SC7A21_I2c_Spi_Write 函数中， sl_spi_iic:0=spi  1=i2c  Reg：寄存器地址   data：寄存器的配置值******************/
/**SL_SC7A21_I2c_Spi_Write 函数 是一个单次写的函数*******************************************************************/
/***SL_SC7A21_I2c_Spi_Read 函数中， sl_spi_iic:0=spi  1=i2c Reg 同上，len:读取数据长度，buf:存储数据首地址（指针）***/
/***SL_SC7A21_I2c_Spi_Read 函数 是可以进行单次读或多次连续读取的函数*************************************************/

/********客户需要封包Click 定时器启停函数************/
/********要求定时器50ms执行一次*********************/
extern void SL_Close_Sc7a21_Click_Timer(void);
extern void SL_Open_Sc7a21_Click_Timer(void);
/***举例如下：***/
//void SL_Close_Sc7a21_Click_Timer(void)
//{
//   SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
//}
//void SL_Open_Sc7a21_Click_Timer(void)
//{
//    SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
//}

/*** 客户IIC函数封装举例
unsigned char SL_MEMS_i2c_spi_Write(unsigned char reg, unsigned char data)
{
    i2cWrite(SC7A21_IIC_ADDRESS,  reg,  data);       //由客户的II函数接口决定
    return 1;
}

unsigned char SL_MEMS_i2c_spi_Read(unsigned char reg, unsigned char len, unsigned char *buf)
{
    i2cRead( SC7A21_IIC_ADDRESS,  reg,  len, buf);//由客户的II函数接口决定
    return 1;
}
***/

/**use this function can judge the sensor online status**/
signed char  SL_SC7A21_Online_Test(unsigned char Sl_pull_up_mode);
/***输入参数:Sl_pull_up_mode:0x00 0x08 0x04 0x0c*****************************************************/
/****Sl_pull_up_mode=0x00=SL_SC7A21_SDO_I2C_PU_EN: SDO  I2C  pull up*********************************/
/****Sl_pull_up_mode=0x04=SL_SC7A21_I2C_PU_DIS : SDO  pull up and  I2C  open drain*******************/
/****Sl_pull_up_mode=0x08=SL_SC7A21_SDO_PU_DIS : I2C  pull up and  SDO  open drain*******************/
/****Sl_pull_up_mode=0x0C=SL_SC7A21_SDO_I2C_DIS: SDO  I2C  open drain********************************/
/**return -1: sensor outline***********************************/
/**return  1: sensor  online***********************************/

/**use this function can boot efuse regiseter value and reset sensor**/
signed char  SL_SC7A21_BOOT(void);
/**return  1: always**/

/**use this function can set scale of sensor**/
signed char  SL_SC7A21_FS_Config(unsigned char SC7A21_FS_Reg);
//exp:#define  SL_SC7A21_DATA_FS_2G        (unsigned char)0x00	
//exp:#define  SL_SC7A21_DATA_FS_4G        (unsigned char)0x10
//exp:#define  SL_SC7A21_DATA_FS_8G        (unsigned char)0x20
//exp:#define  SL_SC7A21_DATA_FS_16G       (unsigned char)0x30
/**return -1: sensor set success**/
/**return  1: sensor set fail**/

/**use this function can set ODR of sensor**/
signed char  SL_SC7A21_Power_Config(unsigned char ODR_Config_Reg,unsigned char Power_Mode);
//exp:#define  SL_SC7A21_ODR_25HZ          (unsigned char)0x37
//exp:#define  SL_SC7A21_ODR_50HZ          (unsigned char)0x47
//exp:Power_Mode==0                        lower power mode
//exp:Power_Mode==1                        normal power mode
//exp:Power_Mode==2                        hi-pwr power mode

/**use this function can set FIFO MODE**/
signed char  SL_SC7A21_FIFO_Config(unsigned char Fifo_Mode,unsigned char Fifo_Bit);
//exp:Fifo_Mode==0                        fifo mode disable
//exp:Fifo_Mode==1                        fifo mode enable
//exp:Fifo_Mode==2                        stream mode enable
//exp:Fifo_Bit==0                         16bits fifo mode
//exp:Fifo_Bit==1                         8bits  fifo mode

/**use this function can set INT MODE**/
unsigned char SL_SC7A21_INT_Config(unsigned char Int_Para);
//exp:Int_Para==0x00                   int happen then output push-pull  high level
//exp:Int_Para==0x01                   int happen then output open-drain high level
//exp:Int_Para==0x02                   int happen then output push-pull  low level
//exp:Int_Para==0x03                   int happen then output open-drain low level
 

/**use this function can read sensor xyz data**/
#if   SL_SC7A21_16BIT_8BIT==0
signed char  SL_SC7A21_Read_XYZ_Data(signed char  *SL_SC7A21_Data_XYZ_Buf);
#elif SL_SC7A21_16BIT_8BIT==1
signed char  SL_SC7A21_Read_XYZ_Data(signed short *SL_SC7A21_Data_XYZ_Buf);
#endif
//must define a array SL_SC7A21_XYZ_Buf[3], type is signed char or signed short 
//&SL_SC7A21_XYZ_Buf[0]  is the function 's parameter

#if   SL_SC7A21_FIFO_16BIT_8BIT==0
signed char  SL_SC7A21_Read_XYZ_FIFO_Data(signed char *SL_SC7A21_Data_X_Buf,signed char *SL_SC7A21_Data_Y_Buf,signed char *SL_SC7A21_Data_Z_Buf);
#elif SL_SC7A21_16BIT_8BIT==1
signed char  SL_SC7A21_Read_XYZ_FIFO_Data(signed short *SL_SC7A21_Data_X_Buf,signed short *SL_SC7A21_Data_Y_Buf,signed short *SL_SC7A21_Data_Z_Buf);
#endif

/**use this function can reset pedo value**/
void SL_SC7A21_Pedo_Reset(void);

/**use this function can set pedo para**/
void SL_SC7A21_Pedo_Config(unsigned char *pedo_reg_value);
/**pedo_reg_value[0]:   ---> 10h**/
/**pedo_reg_value[1]:   ---> 18h**/
/**pedo_reg_value[2]:   ---> 19h**/
/**pedo_reg_value[3]:   ---> 1Ah**/
/**pedo_reg_value[4]:   ---> 11h**/
/**pedo_reg_value[5]:   ---> 12h**/
/**pedo_reg_value[6]:   ---> 13h**/

/**use this function can set wrist para**/
void SL_SC7A21_Wrist_Config(unsigned char *wrist_reg_value);
/**wrist_reg_value[0]:   ---> 08h**/
/**wrist_reg_value[1]:   ---> 09h**/
/**wrist_reg_value[2]:   ---> 0Ah**/
/**wrist_reg_value[3]:   ---> 0Bh**/

/**use this function can set sleep para**/
void SL_SC7A21_Sleep_Config(unsigned char *sleep_reg_value);
/**sleep_reg_value[0]:   ---> 6Bh**/
/**sleep_reg_value[1]:   ---> 6Ch**/

/**use this function can get pedo value in timer**/
unsigned int  SL_SC7A21_Get_Pedo_Count(void);

/**use this function can get wrist value in gpio interrupt**/
unsigned char  SL_SC7A21_Get_Wrist_Status(void);

/**use this function can get wrist value in timer**/
unsigned char  SL_SC7A21_Get_Sleep_Status(void);

/**use this function can Set click value in init***/
void SL_SC7A21_Single_Click_Config(unsigned char *click_para);
/**click_para[0]:0-> 200Hz  1->400Hz**/
/**click_para[1]:   ---> 21h**********/
/**click_para[2]:   ---> 25h**********/
/**click_para[3]:   ---> 38h**********/
/**click_para[4]:   ---> 3Ah**********/
/**click_para[5]:   ---> 3Bh**********/
/**click_para[6]:   ---> 3Ch**********/

/**use this function can Get click value in INT Service***/
unsigned char SL_SC7A21_Click_Algo(unsigned int Click_TH,unsigned char Click_E);//Service function in Int Function
/**Click_TH:三轴矢量化和的爬坡阈值******************/
/**Click_TH:default value=70************************/
/**Click_E:三轴矢量化和的上坡前噪声阈值************/
/**Click_E:default value=80****噪声阈值************/

unsigned char SL_Get_CLICK_PP_CNT(unsigned char fun_flag);
/**Get >Click_E NUM  AND RESET THIS VALUE***/
/**0:RESET THIS VALUE***/
/**1:Get >Click_E NUM***/

//步骤如下：
//0.signed char  SL_SC7A21_BOOT(void);
//1.signed char  SL_SC7A21_Online_Test(void);
//2.signed char  SL_SC7A21_FS_Config(unsigned char Sc7a20_FS_Reg);
//3.signed char  SL_SC7A21_Power_Config(unsigned char Power_Config_Reg);
//4.unsigned char SL_SC7A21_INT_Config(unsigned char Int_Para);
//5.void SL_SC7A21_Pedo_Config(unsigned char *pedo_reg_value);
//6.void SL_SC7A21_Wrist_Config(unsigned char *wrist_reg_value);
//7.void SL_SC7A21_Sleep_Config(unsigned char *sleep_reg_value);
//8.unsigned int  SL_SC7A21_Get_Pedo_Count(void);   //in timer
//9.unsigned char  SL_SC7A21_Get_Wrist_Status(void);//in int
//10.unsigned char  SL_SC7A21_Get_Sleep_Status(void);//in timer
//11.signed char  SL_SC7A21_Read_XYZ_FIFO_Data(signed char *SL_SC7A21_Data_X_Buf,signed char *SL_SC7A21_Data_Y_Buf,signed char *SL_SC7A21_Data_Z_Buf);
//11.signed char  SL_SC7A21_Read_XYZ_FIFO_Data(signed short *SL_SC7A21_Data_X_Buf,signed short *SL_SC7A21_Data_Y_Buf,signed short *SL_SC7A21_Data_Z_Buf);

//11.signed char  SL_SC7A21_Read_XYZ_Data(signed char  *SL_SC7A21_Data_XYZ_Buf);//in timer
//11.signed char  SL_SC7A21_Read_XYZ_Data(signed short *SL_SC7A21_Data_XYZ_Buf);//in timer


#endif /* __SL_SC7A21_DRIVER_H */

