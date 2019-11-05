#include "ALL_Includes.h"
#if CURVE_MOTION_ENABLED

// 输出变量
u8 motion_head;//头
u8 motion_tail;//尾
u32 motion_counter;//运动计数器
u32 motion_duration;//运动时区间;

motion_key keys[MOTION_BUFFER_SIZE];
 
static float int_to_float(int16 a)
// 16bit unsigned integer to float.
{
    return (float) a;
}


static int16 float_to_int(float a)
// Float to 6:10 signed fixed.
{
    return (int16) (a + 0.5);
//	return (int16) (a );
}


static float fixed_to_float(int16 a)
// 6:10 signed fixed point to float.
{
    return ((float) a) / 1024.0;
}


#if 0
static int16 float_to_fixed(float a)
// Float to 6:10 signed fixed.
{
    return (int16) (a * 1024.0);
}
#endif


void motion_init(void)
// Initialize the curve buffer.
{
    // Initialize the counter.
    motion_counter = 0;

    // Initialize the duration.
    motion_duration = 0;

    // Initialize the queue.
    motion_head = 0;
    motion_tail = 0;

    // Initialize the keypoint.
    keys[0].delta = 0;
    keys[0].position = 512.0;
    keys[0].in_velocity = 0.0;
    keys[0].out_velocity = 0.0;

	
	  keys[1].delta = 0;
    keys[1].position = 512.0;
    keys[1].in_velocity = 0.0;
    keys[1].out_velocity = 0.0;
		
			
	  keys[2].delta = 0;
    keys[2].position = 512.0;
    keys[2].in_velocity = 0.0;
    keys[2].out_velocity = 0.0;
					
	  keys[3].delta = 0;
    keys[3].position = 512.0;
    keys[3].in_velocity = 0.0;
    keys[3].out_velocity = 0.0;
							
	  keys[4].delta = 0;
    keys[4].position = 512.0;
    keys[4].in_velocity = 0.0;
    keys[4].out_velocity = 0.0;
							
	  keys[5].delta = 0;
    keys[5].position = 512.0;
    keys[5].in_velocity = 0.0;
    keys[5].out_velocity = 0.0;	
							
	  keys[6].delta = 0;
    keys[6].position = 512.0;
    keys[6].in_velocity = 0.0;
    keys[6].out_velocity = 0.0;		
							
	  keys[7].delta = 0;
    keys[7].position = 512.0;
    keys[7].in_velocity = 0.0;
    keys[7].out_velocity = 0.0;			
    // Initialize an empty hermite curve at the center servo position.
	//在中间伺服位置初始化一个空的埃尔米特曲线。
    curve_init(0, 0, 512.0, 512.0, 0.0, 0.0);
    // 重置寄存器。
    motion_registers_reset();
}


void motion_reset(int16 position)
// Reset the motion buffer to the specified position.  The enabled state is preserved.将运动缓冲区重置为指定位置。启用状态保存。
{
    // Reset the counter.重置计数器。
    motion_counter = 0;

    // Reset the duration.
    motion_duration = 0;

    // Reset the queue.
    motion_head = 0;
    motion_tail = 0;

    // Reset the keypoint.
    keys[0].delta = 0;
    keys[0].position = int_to_float(position);
    keys[0].in_velocity = 0.0;
    keys[0].out_velocity = 0.0;

    // Initialize an empty hermite curve.  This is a degenerate case for the hermite
    // curve that will always return the position of the curve without velocity.
//	初始化一个空的埃尔米特曲线。这是厄米特的退化情形。
//  曲线，总是返回曲线的位置，没有速度
    curve_init(0, 0, keys[0].position, keys[0].position, 0.0, 0.0);

    //Reset the registers.
    motion_registers_reset();
}


void motion_registers_reset(void)
// Reset the motion registers to zero values.
{
    // Set the default position, velocity and delta data.设置默认位置、速度和delta数据
//    registers_write_word(REG_CURVE_POSITION_HI, REG_CURVE_POSITION_LO, 0);
//    registers_write_word(REG_CURVE_IN_VELOCITY_HI, REG_CURVE_IN_VELOCITY_LO, 0);
//    registers_write_word(REG_CURVE_OUT_VELOCITY_HI, REG_CURVE_OUT_VELOCITY_LO, 0);
    Curve_Position=0;
    Curve_In_Velocity=0;
    Curve_Out_Velocity=0;
    Curve_Delta=0;
    // 更新缓冲区状态。
//    registers_write_byte(REG_CURVE_RESERVED, 0);
	  Curve_Reserved=0;
//    registers_write_byte(REG_CURVE_BUFFER, motion_buffer_left());
}

u8 next;
u8 motion_append(void)
// Append a new curve keypoint from data stored in the curve registers.  The keypoint
// is offset from the previous curve by the specified delta.  An error is returned if
// there is no more room to store the new keypoint in the buffer or if the delta is
// less than one (a zero delta is not allowed).
//从存储在寄存器数据曲线添加一个新的曲线关键点。关键点由指定的增量从前面的曲线偏移。如果返回错误，则
//没有更多的空间来存储新的关键点在缓冲或者三角洲小于1（不允许零增量）
{
    int16 position;
    int16 in_velocity;
    int16 out_velocity;
//    u8 next;
    u16 delta;

    // Get the next index in the buffer.
    next = (motion_head + 1) & MOTION_BUFFER_MASK;//在缓冲区中获取下一个索引

    // Return error if we have looped the head to the tail and the buffer is filled.
    if (next == motion_tail) return 0;//如果我们的头循环到尾部，缓冲区被填满，则返回错误。

    // Get the position, velocity and time delta values from the registers.
//    position = (int16) registers_read_word(REG_CURVE_POSITION_HI, REG_CURVE_POSITION_LO);
	  
//    in_velocity = (int16) registers_read_word(REG_CURVE_IN_VELOCITY_HI, REG_CURVE_IN_VELOCITY_LO);
//    out_velocity = (int16) registers_read_word(REG_CURVE_OUT_VELOCITY_HI, REG_CURVE_OUT_VELOCITY_LO);
//    delta = (u16) registers_read_word(REG_CURVE_DELTA_HI, REG_CURVE_DELTA_LO);
	  position =Curve_Position;
	  in_velocity = (int16)Curve_In_Velocity;
    out_velocity = (int16)Curve_Out_Velocity;
    delta = Curve_Delta;
    // Keypoint delta must be greater than zero.
    if (delta < 1) return 0;

    // Fill in the next keypoint.
    keys[next].delta = delta;
    keys[next].position = int_to_float(position);
    keys[next].in_velocity = fixed_to_float(in_velocity);
    keys[next].out_velocity = fixed_to_float(out_velocity);

    // Is this keypoint being added to an empty buffer?
//		关键点被添加到一个空缓冲区？
    if (motion_tail == motion_head)
    {
        // Initialize a new hermite curve that gets us from the current position to the new position.
        // We use a velocity of zero at each end to smoothly transition from one to the other.
//			 初始化一个新的厄米曲线，使我们从当前位置到新位置。
//       我们用每一端的零速度平稳地从一个过渡到另一个
        curve_init(0, delta, curve_get_p1(), keys[next].position, 0.0, 0.0);
    }

    // Increase the duration of the buffer.增加缓冲区的持续时间
    motion_duration += delta;

    // Set the new head index.设置新的头索引。
    motion_head = next;

    // Reset the motion registers and update the buffer status.
   //		重置运动寄存器并更新缓冲区状态。
    motion_registers_reset();

    return 1;
}

    float fposition;//位置
    float fvelocity;//速度
void motion_next(u16 delta)
// Increment the buffer counter by the indicated delta and return the position
// and velocity from the buffered curves.  If the delta is zero the current
// position and velocity is returned.
//通过指定的增量增量缓冲计数器并返回位置。
//和缓冲曲线的速度。如果三角洲是零电流
//返回位置和速度。
{


    // 确定在寄存器中是否禁用曲线运动
//    if (!(registers_read_byte(REG_FLAGS_LO) & (1<<FLAGS_LO_MOTION_ENABLED))) return;
    // 我们处理的是空曲线吗？
    if (motion_tail == motion_head)
    {
        // Yes. 保持计数器和持续时间为0。
        motion_counter = 0;
        motion_duration = 0;
    }
    else
    {
        // Increment the counter.增加计数器
        motion_counter += delta;

        // Have we exceeded the duration of the currently buffered curve?
        while (motion_counter > curve_get_duration())
        {
            // Reduce the buffer counter by the currently buffered curve duration.
//					通过当前缓冲的曲线持续时间来减少缓冲计数器
            motion_counter -= curve_get_duration();

            // Reduce the buffer duration by the currently buffered curve duration.
//					   通过当前缓冲的曲线持续时间来减少缓冲区持续时间
            motion_duration -= curve_get_duration();

            // Increment the tail to process the next buffered curve.
//					增加尾部来处理下一个缓冲曲线。motion_tail++;
            motion_tail = (motion_tail + 1) & MOTION_BUFFER_MASK;

            // Has the tail caught up with the head?
            if (motion_tail == motion_head)
            {
                // Initialize an empty hermite curve with a zero duration.  This is a degenerate case for
                // the hermite cuve that will always return the position of the curve without velocity.
//							初始化一个零时间的空埃尔米特曲线。这是Hermite曲线总是曲线的位置没有速度返回一个退化的情况。
                curve_init(0, 0, keys[motion_head].position, keys[motion_head].position, 0.0, 0.0);
                // Reset the buffer counter and duration to zero.
                motion_counter = 0;
                motion_duration = 0;
            }
            else
            {
                u8 curr_point;
                u8 next_point;
							//获取曲线的当前点和下一点
                curr_point = motion_tail;
                next_point = (curr_point + 1) & MOTION_BUFFER_MASK;

                // 从当前和下一个点初始化厄米曲线。
                curve_init(0,                             keys[next_point].delta,
                           keys[curr_point].position,     keys[next_point].position,
                           keys[curr_point].out_velocity, keys[next_point].in_velocity);
            }

            // Update the space available in the buffer.
//            registers_write_byte(REG_CURVE_BUFFER, motion_buffer_left());
        }
				
    }


		//从Hermite曲线得到位置和速度
    curve_solve(motion_counter, &fposition, &fvelocity);

    // The velocity is in position units a millisecond, but we really need the
    // velocity to be measured in position units every 10 milliseconds to match
    // the sample period of the ADC.
    fvelocity *=10.0;
   if(fvelocity<0)
	 { fvelocity=-fvelocity;}
    // Update the seek position register.
//    registers_write_word(REG_SEEK_POSITION_HI, REG_SEEK_POSITION_LO, );

//    // Update the seek velocity register.
//    registers_write_word(REG_SEEK_VELOCITY_HI, REG_SEEK_VELOCITY_LO, float_to_int(fvelocity));
		
	  seek_position=float_to_int(fposition);//目标位置
    seek_velocity=float_to_int(fvelocity);//寻求速度
	 
}


u8 motion_buffer_left(void)
// The motion buffer can contain up to MOTION_BUFFER_SIZE keypoints.  The function
// returns how many keypoints remain free in the buffer for use.
//运动的缓冲区可以包含多达motion_buffer_size要点。函数返回多少要点保持自由使用的缓冲区
{
    u8 space_left;

    // Determine the points left to store curve data.
   //	确定保存曲线数据的点
    if (motion_head < motion_tail)
    {
        space_left = (MOTION_BUFFER_SIZE - 1) - (MOTION_BUFFER_SIZE + motion_head - motion_tail);
    }
    else
    {
        space_left = (MOTION_BUFFER_SIZE - 1) - (motion_head - motion_tail);
    }

    return space_left;
}


#endif // CURVE_MOTION_ENABLED

