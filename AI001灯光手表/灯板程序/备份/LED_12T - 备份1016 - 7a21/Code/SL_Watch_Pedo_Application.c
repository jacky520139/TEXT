

#include "ALL_Includes.h"

#define SL_Sensor_Algo_Release_Enable 1
#if SL_Sensor_Algo_Release_Enable==0
extern signed short          SL_DEBUG_DATA[10][128];
extern unsigned char         SL_DEBUG_DATA_LEN;
#endif

#define SL_SC7A20_SPI_IIC_MODE  1
/***SL_SC7A20_SPI_IIC_MODE==0  :SPI*******/
/***SL_SC7A20_SPI_IIC_MODE==1  :IIC*******/

/**Please modify the following parameters according to the actual situation**/
signed char SL_SC7A20_PEDO_INIT(void)
{
    unsigned char  status=0;
/*****if use spi mode please config first******/    
#if SL_SC7A20_SPI_IIC_MODE == 0//spi
    status=SL_SC7A20_Driver_Init(1,0x04);//iic mode pull up config 
	//init sensor
	status=SL_SC7A20_Driver_Init(0,0x04);//spi or iic select
#else
 	status=SL_SC7A20_Driver_Init(1,0x00);//spi or iic select   
#endif
    /**********set pedo sensitivity**********/
    SL_PEDO_TH_SET(26,12,0);
    
	return status;
}
//unsigned char sl_pedo_flag=0;
//signed short  sl_pedo_data[32];
static unsigned int  SL_STEP      = 0;
unsigned int  SL_SC7A20_PEDO_ALGO(void)
{
#if SL_Sensor_Algo_Release_Enable==0
	unsigned char         sl_i;
#endif
	signed short          SC7A20_XYZ_Buf[3][16];
	unsigned char         SC7A20_FIFO_NUM;

    /*******read fifo data******/
	SC7A20_FIFO_NUM=SL_SC7A20_Read_FIFO();
    /*******get pedo value******/
    SL_STEP= SL_Watch_Pedo_Algo();
    /*******get accel orginal data and length*******/
    SC7A20_FIFO_NUM=SL_SC7A20_GET_FIFO_Buf(&SC7A20_XYZ_Buf[0][0],&SC7A20_XYZ_Buf[1][0],&SC7A20_XYZ_Buf[2][0]);

    if(SL_STEP>200)
    {
        /**reset pedo value**/
        SL_Pedo_ResetStepCount();
    }

#if SL_Sensor_Algo_Release_Enable==0
    for(sl_i=0;sl_i<SC7A20_FIFO_NUM;sl_i++)
    {       
        SL_DEBUG_DATA[0][sl_i]=SC7A20_XYZ_Buf[0][sl_i];
        SL_DEBUG_DATA[1][sl_i]=SC7A20_XYZ_Buf[1][sl_i];
        SL_DEBUG_DATA[2][sl_i]=SC7A20_XYZ_Buf[2][sl_i];
        SL_DEBUG_DATA[3][sl_i]=SL_STEP;
//        SL_DEBUG_DATA[4][sl_i]=sl_pedo_flag;
//        SL_DEBUG_DATA[5][sl_i]=sl_pedo_data[sl_i];	
    }
    SL_DEBUG_DATA_LEN=SC7A20_FIFO_NUM;
#endif
    
    return SL_STEP;
}



