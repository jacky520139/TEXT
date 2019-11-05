
#include "ALL_Includes.h"

#define MAX_POSITION  (4095)


// Determine the top value for timer/counter1 from the frequency divider.
//确定来自分频器定时器峰值
#define PWM_TOP_VALUE(div)      ((u16) div << 4) - 1
// Determines the compare value associated with the duty cycle for timer/counter1.确定与占空比相关联的比较值

#define PWM_OCRN_VALUE(div,pwm) (u16) (((u32) pwm * (((u32) div << 4) - 1)) / 255)
//#define PWM_OCRN_VALUE(div,pwm) (u16) ((u32) pwm * ((2500)) / 255)
// Flags that indicate PWM output in A and B direction.
 u8 pwm_a=0;
 u8 pwm_b=0;

// Pwm frequency divider value.PWM频率分频值
static u16 pwm_div;


#define DELAYLOOP 20 // TODO: This needs to be adjusted to account for the clock rate.
                     //       This value of 20 gives a 5 microsecond delay and was chosen
                     //       by experiment with an "MG995".
 static void delay_loop(int n)
{
    u8 i;
    for(i=0; i<n; i++)
    {
//        asm("nop");
			_nop_();
    }
}

 void pwm_dir_a(u8 pwm_duty)
// Send PWM signal for rotation with the indicated pwm ratio (0 - 255).
// This function is meant to be called only by pwm_update.
//发送PWM信号与指定的PWM占空比（0 - 255）旋转。
//这个功能只有通过pwm_update调用。
{
    // 确定定时器的占空比值
    u16 duty_cycle = PWM_OCRN_VALUE(pwm_div, pwm_duty);
//    EA=0;
//    // Do we need to reconfigure PWM output for direction A?
//	我们需要重新配置PWM输出方向A吗？
    if (!pwm_a)
    { // Yes...

//          PWM5_P03_OUTPUT_DISABLE;
//          PWM4_P01_OUTPUT_DISABLE;
//			    PWM5=0;
//          PWM4=0;
//          delay_loop(DELAYLOOP);
//          PWM5_P03_OUTPUT_ENABLE;
					PWM5=1;
          PWM4=1;
          pwm_b = 0;
    }

    // Update the A direction flag.  A non-zero value keeps us from
    // recofiguring the PWM output A when it is already configured.
    pwm_a = pwm_duty;

//set_SFRPAGE;
//		PWM5H = duty_cycle>>8;
//		PWM5L = duty_cycle;
//		PWM4H = 0X00;
//		PWM4L = 0X00;
//clr_SFRPAGE;
//    set_LOAD;
//		set_PWMRUN;

//     EA=1;

}


 void pwm_dir_b(u8 pwm_duty)
// Send PWM signal for rotation with the indicated pwm ratio (0 - 255).
// This function is meant to be called only by pwm_update.
{
    // Determine the duty cycle value for the timer.
    u16 duty_cycle = PWM_OCRN_VALUE(pwm_div, pwm_duty);
//    EA=0;
    // Do we need to reconfigure PWM output for direction B?
    if (!pwm_b)
    {
//          PWM5_P03_OUTPUT_DISABLE;
//          PWM4_P01_OUTPUT_DISABLE;
////			    PWM0_P12_OUTPUT_DISABLE;
//			    PWM5=0;
//          PWM4=0;
//          delay_loop(DELAYLOOP);
//			    PWM4_P01_OUTPUT_ENABLE;
					PWM5=1;
          PWM4=1;
          pwm_a = 0;
    }
    pwm_b = pwm_duty;
		
//		set_SFRPAGE;
//		PWM5H = 0x00;	
//		PWM5L = 0x00;
//		PWM4H = duty_cycle>>8;						
//		PWM4L = duty_cycle;
//clr_SFRPAGE;
//    set_LOAD;
//		set_PWMRUN;
//    EA=1;

}


//void pwm_init(void)
//// Initialize the PWM module for controlling a DC motor.
//{
//    pwm_div = DEFAULT_PWM_FREQ_DIVIDER;

//	  PWM_IMDEPENDENT_MODE;
//	
//	  PWM_GP_MODE_DISABLE;
//	  PWM_CLOCK_FSYS;
//	  PWM_CLOCK_DIV_64;
//	
//		PWMPH = PWM_TOP_VALUE(pwm_div)>>8;
//		PWMPL = PWM_TOP_VALUE(pwm_div);
//	
//    set_SFRPAGE;										// PWM4 and PWM5 duty value need set SFPPAGE 1
//		PWM5H = 0x00;						
//		PWM5L = 0x00;
//		PWM4H = 0x00;						
//		PWM4L = 0x00;
//	  clr_SFRPAGE;
//	  set_PNP4;//反向驱动
//		set_PNP5;//反向驱动
//	  PWM4_P01_OUTPUT_ENABLE;
//		PWM5_P03_OUTPUT_ENABLE;
////		pwm_dir_a(100);
////		pwm_dir_b(200);
//		

//		
////Please always setting Dead time before PWM run.		
//    set_LOAD;
//    set_PWMRUN;
//// pwm_stop();	

//}


void pwm_update(u16 position, int16 pwm)
// Update the PWM signal being sent to the motor.  The PWM value should be
// a signed integer in the range of -255 to -1 for clockwise movement,
// 1 to 255 for counter-clockwise movement or zero to stop all movement.
// This function provides a sanity check against the servo position and
// will prevent the servo from being driven past a minimum and maximum
// position.
//更新发送给电机的PWM信号。
//PWM值应该是按顺时针方向移动的-255到-1范围内的带符号整数，
//逆时针方向移动1到255，或零停止所有运动。
//此函数提供了针对伺服位置的健全检查将防止伺服被驱动过一个最小值和最大值位置
{
    u16 pwm_width;
    u16 min_position;
    u16 max_position;


    // Are we reversing the seek sense?我们是否颠倒了寻找的意义？
    if (Reverse_Seek != 0)
    {
        // Yes. Swap the minimum and maximum position.交换最小和最大位置

        // Get the minimum and maximum seek position.获取最小和最大查找位置
//        min_position = registers_read_word(REG_MAX_SEEK_HI, REG_MAX_SEEK_LO);
//        max_position = registers_read_word(REG_MIN_SEEK_HI, REG_MIN_SEEK_LO);
    min_position=minimum_position;
	  max_position=maximum_position;
        // Make sure these values are sane 10-bit values.
        if (min_position > MAX_POSITION)
					  min_position = MAX_POSITION;
        if (max_position > MAX_POSITION)
					  max_position = MAX_POSITION;

        // Adjust the values because of the reverse sense.
        min_position = MAX_POSITION - min_position;
        max_position = MAX_POSITION - max_position;
    }
    else
    {
        // No. Use the minimum and maximum position as is.
        // Get the minimum and maximum seek position.
//        min_position = registers_read_word(REG_MIN_SEEK_HI, REG_MIN_SEEK_LO);
//        max_position = registers_read_word(REG_MAX_SEEK_HI, REG_MAX_SEEK_LO);
						min_position=minimum_position;
						max_position=maximum_position;
        // Make sure these values are sane 10-bit values.
        if (min_position > MAX_POSITION)
					  min_position = MAX_POSITION;
        if (max_position > MAX_POSITION)
					  max_position = MAX_POSITION;
    }

    // Disable clockwise movements when position is below the minimum position.
    if ((position < min_position) && (pwm < 0)) pwm = 0;

    // Disable counter-clockwise movements when position is above the maximum position.
    if ((position > max_position) && (pwm > 0)) pwm = 0;

    if (pwm < 0)
    {
        // Less than zero. Turn clockwise.
        // Get the PWM width from the PWM value.
        pwm_width = (u16) -pwm;

        // Turn clockwise.
#if SWAP_PWM_DIRECTION_ENABLED
        pwm_dir_b(pwm_width);
#else
        pwm_dir_a(pwm_width);
#endif
    }
    else if (pwm > 0)
    {
        // More than zero. Turn counter-clockwise.

        // Get the PWM width from the PWM value.
        pwm_width = (u16) pwm;

        // Turn counter-clockwise.
#if SWAP_PWM_DIRECTION_ENABLED
        pwm_dir_a(pwm_width);
#else
        pwm_dir_b(pwm_width);
#endif

    }
    else
    {
        // Stop all PWM activity to the motor.
        pwm_stop();
    }
}


void pwm_stop(void)
// Stop all PWM signals to the motor.
{
//    // Disable interrupts.
//      EA=0;
//    // Are we moving in the A or B direction?
    if (pwm_a || pwm_b)
    {
//	  PWM5_P03_OUTPUT_DISABLE;
//		PWM4_P01_OUTPUT_DISABLE;	

           PWM5=1;
			     PWM4=1;
           pwm_a = 0;
           pwm_b = 0;
    }

//    // Set the PWM duty cycle to zero.
//		set_SFRPAGE;		
//		PWM4H = 0x00;	
//		PWM4L = 0x00;
//		PWM5H = 0x00;						
//		PWM5L = 0x00;
//		clr_SFRPAGE;		
//		clr_PWMRUN;
//    // Restore interrupts.
//     EA=1;
    // Save the pwm A and B duty values.
//    registers_write_byte(REG_PWM_DIRA, pwm_a);
//    registers_write_byte(REG_PWM_DIRB, pwm_b);
}
