
#ifndef _SC7A21_H_
#define _SC7A21_H_
////////////////////SC7A21地址定义///////////////
#define SC7A21_ADDR    0X18   //SDO脚接地为0x18,悬空或者接高为0x19
////////////////////寄存器地址定义///////////////
#define	The_OUT_TEMP_L	0X0C//温度低位
#define	The_OUT_TEMP_H	0X0D//温度高位

#define	WHO_AM_I	      0X0F
#define	STEP_CTRL	      0X10//计步控制寄存器

#define	STEP_DELTA	    0X11//计步差值控制寄存器

#define	STEP_WTM0	      0X12//计步阀值低位
#define	STEP_WTM	      0X13//计步阀值高位

#define	STEP_SRC	      0X14//计步状态

#define	STEP_COUNTER0	  0X15//计步值寄存器1
#define	STEP_COUNTER1	  0X16//计步值寄存器1
#define	STEP_COUNTER2	  0X17//计步值寄存器2

#define	STEP_CONFIG1	  0X18//计步值控制寄存器0
#define	STEP_CONFIG2	  0X19//计步值控制寄存器1 

#define	CTRL_REG0	      0X1F//控制寄存器0
#define	CTRL_REG1	      0X20//控制寄存器1
#define	CTRL_REG2	      0X21//控制寄存器2
#define	CTRL_REG3	      0X22//控制寄存器3
#define	CTRL_REG4	      0X23//控制寄存器4
#define	CTRL_REG5	      0X24//控制寄存器5
#define	CTRL_REG6	      0X25//控制寄存器6

#define	REFERENCE	      0X26//参考

#define	STATUS_REG	    0X27//数据状态寄存器
#define	OUT_X_L	        0X28//X 轴加速度计值。 这个值以 2 的补码的形式输出。
#define	OUT_X_H	        0X29
#define	OUT_Y_L	        0X2A//Y 轴加速度计值。 这个值以 2 的补码的形式输出。
#define	OUT_Y_H	        0X2B
#define	OUT_Z_L	        0X2C//Z 轴加速度计值。 这个值以 2 的补码的形式输出。
#define	OUT_Z_H	        0X2D

#define	FIFO_CTRL_REG	  0X2E//FIFO 控制寄存器
#define	FIFO_SRC_REG	  0X2F//FIFO 状态寄存器

#define	A0I1_CFG	      0X30//AOI1 配置寄存器
#define	AOI1_SOURCE	    0X31//AOI1 状态寄存器
#define	AOI_THS	        0X32//AOI1 阈值寄存器
#define	AOI1_DURATION	  0X33//AOI1 持续时间

#define	A012_CFG	      0X34//AOI2 配置寄存器
#define	A012_SOURCE	    0X35//AOI2 状态寄存器
#define	AO12_TSH	      0X36//AOI2 阈值寄存器
#define	AO12_DURATION	  0X37//AOI2 持续时间

#define	CLICK_CFG	      0X38
#define	CLICK_the_SRC	  0X39
#define	CLICK_TSH	      0X3A

#define	TIME_LIMIT	    0X3B
#define	TIME_LATENCY	  0X3C
#define	TIME_WINDOW	    0X3D



#define	ACT_THS	        0X3E
#define	ACT_DURATION	  0X3F


void INIT_SC7A21(void);
void Read_STEP_COUNTER(void);
void Clean_STEP_COUNTER(void);
#endif 
