
#include "ALL_Includes.h"
// The minimum and maximum servo position as defined by 10-bit ADC values.
#define MIN_POSITION            (0)//最小位置值
#define MAX_POSITION            0x1000//最大位置值
// PID输出的最大最和最小值
#define MAX_OUTPUT              (255)//最大输出
#define MIN_OUTPUT              (-MAX_OUTPUT)//最小输出

// Values preserved across multiple PID iterations.
static int16 previous_seek=-1; // 注意:previous_seek = = 1表示初始化所需的
static int16 previous_position=0;//上一次位置变量

static int16 seek_delta=-1;//目标位置增量
static int16 position_at_start_of_new_seek=-1;//新搜寻的开始位置
static u8 previous_pwm_is_enabled=0;

     int16 seek_position;//目标位置
     int16 seek_velocity;//寻求速度
     int16 minimum_position;//最小位置
     int16 maximum_position;//最大位置
 u8 Reverse_Seek=0;
 PID_Dir PID;




//
// Digital Lowpass Filter Implementation
//
// See: A Simple Software Lowpass Filter Suits Embedded-system Applications
// http://www.edn.com/article/CA6335310.html
//
// k    Bandwidth (Normalized to 1Hz)   Rise Time (samples)
// 1    0.1197                          3
// 2    0.0466                          8
// 3    0.0217                          16
// 4    0.0104                          34
// 5    0.0051                          69
// 6    0.0026                          140
// 7    0.0012                          280
// 8    0.0007                          561
//

#define FILTER_SHIFT 1

static int32 filter_reg = 0;

static int16 filter_update(int16 input)//数字滤波
{
#if 0
    // Update the filter with the current input.用当前输入更新滤波器
#if FULL_ROTATION_ENABLED
    filter_reg += normalize_position_difference(input - (filter_reg >> FILTER_SHIFT));
#else
    filter_reg = filter_reg - (filter_reg >> FILTER_SHIFT) + input;
#endif

    // Scale output for unity gain.
    return (int16) (filter_reg >> FILTER_SHIFT);
#else
    return input;
#endif
}

void pid_init(void)
// Initialize the PID algorithm module.初始化pid算法模块
{
   previous_seek = -1;
}


void pid_registers_defaults(void)
{

	  PID.deadband=DEFAULT_PID_DEADBAND;
		PID.p_gain  =DEFAULT_PID_PGAIN;
		PID.i_gain  =DEFAULT_PID_IGAIN;
		PID.d_gain  =DEFAULT_PID_DGAIN;
	
    minimum_position=DEFAULT_MIN_SEEK;
	  maximum_position=DEFAULT_MAX_SEEK;
	  Reverse_Seek=0;//反反向标志
	
}


int16 pid_position_to_pwm(int16 current_position, u8 tick)
// This is a modified pid algorithm by which the seek position and seek
// velocity are assumed to be a moving target.  The algorithm attempts to
// output a pwm value that will achieve a predicted position and velocity.
//这是一种改进的PID算法，通过它来查找位置和寻找。
//速度被假定为运动目标。该算法试图输出一个PWM值，以达到预测的位置和速度。
{
    // We declare these static to keep them off the stack.

    static int16 current_velocity;//现在速度
    static int16 filtered_position;//滤波后的位置

    static u8    pwm_is_enabled;//PWM使能标志
	
// Get flag indicating if PWM is enabled or not. This saves fetching it each time
// we want to know.
//获取指示是否启用了PWM的标志。这节省每次提取它。
//我们想知道
//    pwm_is_enabled=registers_read_byte(REG_FLAGS_LO)&(1<<FLAGS_LO_PWM_ENABLED);

    // 通过数字低通滤波器对当前位置进行滤波。
    filtered_position = filter_update(current_position);

    // 使用过滤位置确定速度
#if FULL_ROTATION_ENABLED
    current_velocity = normalize_position_difference(filtered_position - previous_position);
#else
    current_velocity = filtered_position - previous_position;//当前速度
#endif

    // 读取目标位置和速度
//    seek_position = (int16) registers_read_word(REG_SEEK_POSITION_HI, REG_SEEK_POSITION_LO);
//    seek_velocity = (int16) registers_read_word(REG_SEEK_VELOCITY_HI, REG_SEEK_VELOCITY_LO);
    // 读取最小和最大位置。
//    minimum_position = (int16) registers_read_word(REG_MIN_SEEK_HI, REG_MIN_SEEK_LO);
//    maximum_position = (int16) registers_read_word(REG_MAX_SEEK_HI, REG_MAX_SEEK_LO);

// Are we reversing the seek sense?我们是否颠倒了寻求意义？
// TODO: What is the point of this? Surely it is better to correct the wires to the motor than这是什么意思？当然，最好把电机的电线校正好。
//       risk accidents?/风险事故？
    if (Reverse_Seek!= 0)
    {
        // Yes. Update the position and velocity using reverse sense.利用反向感觉更新位置和速度
//        registers_write_word(REG_POSITION_HI, REG_POSITION_LO, (u16) (MAX_POSITION - current_position));
//        registers_write_word(REG_VELOCITY_HI, REG_VELOCITY_LO, (u16) -current_velocity);
        // Reverse sense the seek and other position values.反向寻找位置和其他位置值
           seek_position = MAX_POSITION - seek_position;
        minimum_position = MAX_POSITION - minimum_position;
        maximum_position = MAX_POSITION - maximum_position;
			
    }
    else
    {
        // No. Update the position and velocity registers without change.无变化地更新位置和速度寄存器
//        registers_write_word(REG_POSITION_HI, REG_POSITION_LO, (u16) current_position);
//        registers_write_word(REG_VELOCITY_HI, REG_VELOCITY_LO, (u16) current_velocity);
    }

    // 获取死区
//    PID.deadband = (int16) registers_read_byte(REG_PID_DEADBAND);

// Keep the seek position bound within the set minimum and maximum position and the hardware
// defined limits.
// NOTE: Even when full rotation is enabled, the limit of the set min and max
//       positions are still applied: these must be set appropriately to allow
//       full rotation to occur.
//
//       TODO: When full rotation is enabled, it may be that the user desires the
//             range to be exclusive rather than inclusive.

    if (seek_position < minimum_position) seek_position = minimum_position;
    if (seek_position > maximum_position) seek_position = maximum_position;
    if (seek_position < MIN_POSITION)     seek_position = MIN_POSITION;
    if (seek_position > MAX_POSITION)     seek_position = MAX_POSITION;

// Check for new seek target
    if(previous_seek != seek_position )    // PWM enable state has changed...PWM启用状态已改变
    { 
       if(previous_seek == -1)                       // Initialisation初始化
       {
          previous_position = current_position;
          PID.i_component = 0;
				  seek_delta = current_position;
       }
		  
     	 previous_seek = seek_position;  
			  seek_delta=previous_seek;
//     seek_delta = current_position;//???????
//		 seek_delta=seek_position;
       position_at_start_of_new_seek = current_position;//更新目标位置时的起点位置
       previous_pwm_is_enabled = pwm_is_enabled;
			 
    }
//Send_Word_To_UART0 (current_position);
//
// Update seek target
//
    if(tick && seek_delta!=seek_position && seek_velocity>0) // Tick is our time constant
    {
       if(position_at_start_of_new_seek<seek_position)
       {
             seek_delta+=seek_velocity;
          if(seek_delta>=seek_position)
          {
             seek_delta=seek_position;
          }
       } else
       {
          if(position_at_start_of_new_seek>seek_position)
          {
             seek_delta-=seek_velocity;
             if(seek_delta<=seek_position)
             {
                seek_delta=seek_position;
             }
          }
       }
    }

    if(seek_delta==seek_position)
    {
       current_position = filtered_position;
    }

// Calculate PWM
#if FULL_ROTATION_ENABLED
    p_component = normalize_position_difference(seek_delta - current_position);
#else
    // The proportional component to the PID is the position error.PID的比例分量是位置误差
    PID.p_component = seek_delta - current_position;
#endif

    // The integral component
    if(tick) // Tick is our time constant
    {
       PID.i_component += PID.p_component;
		
       if(PID.i_component<PID_I_MIN) // Somewhat arbitrary anti integral wind-up; we're experimenting有点武断的反积分；我们正在试验
       {
          PID.i_component=PID_I_MIN;
       } else
       {
          if(PID.i_component>PID_I_MAX)
          {
             PID.i_component=PID_I_MAX;
          }
       }
    }

    // The derivative component to the PID is the change in position.PID的导数分量是位置的变化
    PID.d_component = previous_position - current_position;
    previous_position = current_position;

    // Get the proportional, derivative and integral gains.
//    PID.p_gain = registers_read_word(REG_PID_PGAIN_HI, REG_PID_PGAIN_LO);
//    PID.i_gain = registers_read_word(REG_PID_IGAIN_HI, REG_PID_IGAIN_LO);
//    PID.d_gain = registers_read_word(REG_PID_DGAIN_HI, REG_PID_DGAIN_LO);

    // Start with zero PWM output.
    PID.pwm_output = 0;

    // Apply proportional component to the PWM output if outside the deadband.
    if ((PID.p_component > PID.deadband) || (PID.p_component < -PID.deadband))
    {
        // Apply the proportional component of the PWM output.
        PID.pwm_output += (int32) PID.p_component * (int32) PID.p_gain;

    // Apply the integral component of the PWM output.
        PID.pwm_output += (int32) PID.i_component * (int32) PID.i_gain;

    // Apply the derivative component of the PWM output.
        PID.pwm_output += (int32) PID.d_component * (int32) PID.d_gain;
    } else
    {
       PID.i_component = 0;
    }

    // Shift by 8 to account for the multiply by the 8:8 fixed point gain values.
    // NOTE: When OpenEncoder is enabled an extra 1 place of shift is applied
    //       to account for the increased precision (which is approximately a
    //       factor of 2) so that the magnitude of the gain values are similar
    //       across the two different platforms.
    //
    //       Factor of 2: pot measurements are typically approaching 180 degrees
    //       across the 0 to 1023 ADC range. OpenEncoder is 360 degrees across the
    //       0 to 4096 range.
    //
//移8占乘8点增益值。
//注意：当OpenEncoder启用额外的1位移位的应用
//考虑到精度的提高（大约是
//因子2）使增益值的大小类似。
//跨越两个不同的平台。

//2因素：罐测量通常接近180度。
//跨越0至1023 ADC范围。openencoder是360度在0至4096的范围内。
#if ENCODER_ENABLED
    PID.pwm_output >>= 9;
#else
    PID.pwm_output >>= 8;//pwm_output/256
#endif

    // Check for output saturation.
    if (PID.pwm_output > MAX_OUTPUT)
    {
        // Can't go higher than the maximum output value.
        PID.pwm_output = MAX_OUTPUT;
    }
    else if (PID.pwm_output < MIN_OUTPUT)
    {
        // Can't go lower than the minimum output value.
        PID.pwm_output = MIN_OUTPUT;
    }

    return (int16) PID.pwm_output;
		
		
}

