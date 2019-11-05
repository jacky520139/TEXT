#include "ALL_Includes.h"
#define MAX_PACKET_LEN  32// max value is 32
u8 Rx_buf[MAX_PACKET_LEN];//接收缓存
u8 TX_buf[MAX_PACKET_LEN];//接收缓存
code unsigned char  Reg[][2] = {
	  {STEP_CTRL,    Bin(00000001)},		//B7~B6,计步中断2，B5~B4,计步中断1，B2:清除计步，B1:ODR频率，B0:计步功能开关
    {STEP_DELTA,   Bin(00000000)},		//
    {STEP_WTMO,    Bin(00000000)},		//
    {STEP_WTM,     Bin(00000000)},		//
    {STEP_CONFIG1, Bin(00000000)},		//
    {STEP_CONFIG2, Bin(00000000)},		//
    {CTRL_REG0,    Bin(00000000)},		//计步控制器，b6:温度传感器，B4:滤波数据,B3:高性能,B2:低通滤波，B1~B0:滤波频率
    {CTRL_REG1,    Bin(00000000)},		//
    {CTRL_REG2,    Bin(00000000)},		//
    {CTRL_REG3,    Bin(00000000)},		//
    {CTRL_REG4,    Bin(00000000)},		//
    {CTRL_REG5,    Bin(00000000)},   //
    {CTRL_REG6,    Bin(00000000)},   //
    {REFERENCE,    Bin(00000000)},   //
    {STATUS_REG,   Bin(00000000)},		//
    {FIFO_CTRL_REG,Bin(00000000)},		//
    {A0I1_CFG,     Bin(00000000)},   //
    {AOI_THS,      Bin(00000000)},   //
    {AOI1_DURATION,Bin(00000000)},   //
    {A012_CFG,     Bin(00000000)},   //
    {AO12_TSH,     Bin(00000000)},   //
    {AO12_DURATION,Bin(00000000)},	  //
    {CLICK_CFG,    Bin(00000000)},		//
		{CLICK_TSH,    Bin(00000000)},		//
    {TIME_LIMIT,   Bin(00000000)},		//
    {TIME_LATENCY, Bin(00000000)},   //
    {TIME_WINDOW,  Bin(00000000)},   //
    {ACT_THS,      Bin(00000000)},   //
    {ACT_DURATION, Bin(00000000)},   //
};
 /***************************************************************
* 函数功能：初始化SC7A21
* 输入参数：
* 输出参数：
***************************************************************/
void INIT_SC7A21(void)
{
u8 i,j=sizeof(Reg)/2;
for(i=0;i<j;i++)
{	
i2cs_tx_data(SC7A21_ADDR,Reg[i][0],&(Reg[i][1]),1);
}
}
 /***************************************************************
* 函数功能：读计步值
* 输入参数：
* 输出参数：
***************************************************************/
void Read_STEP_COUNTER(void)
{
i2cs_rx_data(SC7A21_ADDR,STEP_COUNTER0,Rx_buf,3);
}
 /***************************************************************
* 函数功能：清除计步值
* 输入参数：
* 输出参数：
***************************************************************/
void Clean_STEP_COUNTER(void)
{u8 temp;
i2cs_rx_data(SC7A21_ADDR,STEP_CTRL,&temp,1);
temp=temp&(~0x04);
i2cs_tx_data(SC7A21_ADDR,STEP_CTRL,&temp,1);
}

//void INIT_SC7A21(void)
//{
//i2cs_tx_data(uint8_t devAddr7,STEP_CTRL,uint8_t*buf,uint8_t Size);



//}
//清除计步值寄存器数据
