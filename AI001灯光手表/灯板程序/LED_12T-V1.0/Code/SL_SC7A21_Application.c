

#include "ALL_Includes.h"

#define SL_Sensor_Algo_Release_Enable 1
#if SL_Sensor_Algo_Release_Enable==0
extern signed short          SL_DEBUG_DATA[9][128];
extern unsigned char         SL_DEBUG_DATA_LEN;
#endif

static unsigned char   SL_SLEEP             = 0;
static unsigned short  sl_sleep_cnt         = 0;
static unsigned short  sl_sleep_flag        = 0;
static unsigned char   SL_DEBUG_SLEEP       = 0;

static unsigned char   SL_WRIST      = 0;

/**请根据实际情况修改以下参数**/
signed char SL_SC7A21_INIT(void)
{
    unsigned char  status=0;
 
    unsigned char pedo_para[7] ={0x05,0xA4,0x1F,0x37,0x0F,0xFF,0x00};
    unsigned char wrist_para[4]={0x31,0x31,0x00,0x93};
    unsigned char sleep_para[2]={0x11,0x09}; 
    unsigned char int_para     =0x02;//default int level set high,int output mode set pushpull  
    
/*****if use spi mode please config first******/    
#if SL_SC7A21_SPI_IIC_MODE == 0//spi
    //disable SDO & SDA & SCL PULL-UP Resistance
    status=SL_SC7A21_Online_Test(SL_SC7A21_SDO_I2C_DIS);//pull up config
#else
    status=SL_SC7A21_Online_Test(SL_SC7A21_SDO_PU_DIS);//pull up config
#endif
    /**********set sc7a21 full-scale**********/
    status=SL_SC7A21_FS_Config(SL_SC7A21_DATA_FS_4G);
    /**********set sc7a21 odr and power mode**********/
    status=SL_SC7A21_Power_Config(SL_SC7A21_ODR_50HZ,SL_SC7A21_LOWER_POWER);
    /**********set sc7a21 FIFO MODE and 8BITS FIFO MODE**********/ 
    status=SL_SC7A21_FIFO_Config(SL_SC7A21_FIFO_MODE_EN,SL_SC7A21_FIFO_8BITS_MODE);
    /**********set sc7a21 INT LEVEL AND INT MODE**********/ 
    status=SL_SC7A21_INT_Config(int_para);   
    /**********10h 18h 19h 1Ah 11h 12h 13h  Total:7**********/
    SL_SC7A21_Pedo_Config(&pedo_para[0]);
    /**********08h 09h 0Ah 0Bh  Total:4**********/
    SL_SC7A21_Wrist_Config(&wrist_para[0]);
    /**********6Bh 6Ch   Total:2****************/
    //must open this function an hour early
    SL_SC7A21_Sleep_Config(&sleep_para[0]);
    sl_sleep_flag = 0;

	return status;
}

//定时1min 调用一次
#define SL_SC7A21_SLEEP_WAKE_TH    2//0-1-2
#define SL_SC7A21_SLEEP_LIGHT_TH   5//3-4-5
#define SL_SC7A21_SLEEP_DEEP_TH    7//6-7 

unsigned char  SL_SC7A21_GET_SLEEP_VALUE(void)
{
    unsigned char   sl_sleep_status      = 0;
    
    sl_sleep_status =  SL_SC7A21_Get_Sleep_Status();
    SL_DEBUG_SLEEP  =  sl_sleep_status;
    if(sl_sleep_flag==0)//pre-judge
    {
        if(sl_sleep_status>1)
        {
            sl_sleep_cnt++;
            if(sl_sleep_cnt>20)//already 20min
            {
                sl_sleep_cnt=0;
                sl_sleep_flag=1;
                return  sl_sleep_status/2;           
            }
            else
                return 0;//wake status
        }
        else
        {
            sl_sleep_cnt =0;
            sl_sleep_flag=1;
        }
    }

    if(sl_sleep_status<=SL_SC7A21_SLEEP_WAKE_TH)
    {
        return 0;//wake status
    }
    else if(sl_sleep_status<=SL_SC7A21_SLEEP_LIGHT_TH)
    {
        return 1;//light status
    }
    else
    {
        return 2;//deep status
    }

    return sl_sleep_status;
}

//GPIO中断中调用
/***SC7A21 INT1 INT2中断服务函数中，读取抬手状态***/
//return 0: no action
//return 1: turn on   success
//return 2: turn down success
unsigned char  SL_SC7A21_WRIST_INT12_SERVICE_FUNCTION(void)
{
    SL_WRIST=SL_SC7A21_Get_Wrist_Status();
    return   SL_WRIST;
}

//定时1s或0.5s调用一次
//#define SL_SC7A21_TIMER_INTERVAL   1000
#define SL_SC7A21_TIMER_INTERVAL   500
static unsigned char sc7a21_timer_counter=0;   
static unsigned int  SL_STEP            = 0;
unsigned int  SL_SC7A21_GET_PEDO_VALUE(void)
{
#if SL_Sensor_Algo_Release_Enable==0
	unsigned char         sl_i;
#endif
  
#if   SL_SC7A21_FIFO_16BIT_8BIT==0
	signed char  SC7A21_XYZ_Buf[3][64];
#elif SL_SC7A21_16BIT_8BIT==1
	signed short SC7A21_XYZ_Buf[3][32];
#endif
	unsigned char         SC7A21_FIFO_NUM;
    
    /*******get accel orginal fifo data and length*******/
#if   SL_SC7A21_FIFO_16BIT_8BIT==0
    SC7A21_FIFO_NUM=SL_SC7A21_Read_XYZ_FIFO_Data(&SC7A21_XYZ_Buf[0][0],&SC7A21_XYZ_Buf[1][0],&SC7A21_XYZ_Buf[2][0]);
#elif SL_SC7A21_16BIT_8BIT==1
    SC7A21_FIFO_NUM=SL_SC7A21_Read_XYZ_FIFO_Data(&SC7A21_XYZ_Buf[0][0],&SC7A21_XYZ_Buf[1][0],&SC7A21_XYZ_Buf[2][0]);
#endif

    /*******get pedo value******/
    SL_STEP= SL_SC7A21_Get_Pedo_Count();//读计步值

    if(SL_STEP>200)
    {
        /**reset pedo value,just for example**/
        SL_SC7A21_Pedo_Reset();
    }
    
    sc7a21_timer_counter++; 
#if   SL_SC7A21_TIMER_INTERVAL==500
    if(sc7a21_timer_counter>=120)
    {
        SL_SLEEP=SL_SC7A21_GET_SLEEP_VALUE();
        sc7a21_timer_counter=0;
    } 
#elif SL_SC7A21_TIMER_INTERVAL==1000
    if(sc7a21_timer_counter>=60)
    {
        SL_SLEEP=SL_SC7A21_GET_SLEEP_VALUE();
        sc7a21_timer_counter=0;
    } 
#endif
    
#if SL_Sensor_Algo_Release_Enable==0
    for(sl_i=0;sl_i<SC7A21_FIFO_NUM;sl_i++)
    {       
        SL_DEBUG_DATA[0][sl_i]=SC7A21_XYZ_Buf[0][sl_i];
        SL_DEBUG_DATA[1][sl_i]=SC7A21_XYZ_Buf[1][sl_i];
        SL_DEBUG_DATA[2][sl_i]=SC7A21_XYZ_Buf[2][sl_i];
        SL_DEBUG_DATA[3][sl_i]=SL_SLEEP;
        SL_DEBUG_DATA[4][sl_i]=SL_DEBUG_SLEEP;
        SL_DEBUG_DATA[5][sl_i]=SL_STEP;
        SL_DEBUG_DATA[6][sl_i]=SL_WRIST;   
    }
    SL_DEBUG_DATA_LEN=SC7A21_FIFO_NUM;
    SL_WRIST = 0;//Clear this para
#endif
    
    return SL_STEP;
}



