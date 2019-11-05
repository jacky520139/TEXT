/*
    Copyright (c) 2006 Michael P. Thompson <mpthompson@gmail.com>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use, copy,
    modify, merge, publish, distribute, sublicense, and/or sell copies
    of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.

    $Id$
*/

#ifndef _OS_PID_H_
#define _OS_PID_H_ 1

#define PID_I_MAX    300
#define PID_I_MIN    -300



typedef struct  
{
  u16   p_gain;//P增益
  u16   i_gain;//I增益
  u16   d_gain;//D增益
	
	int16 deadband;//死区
  int16 p_component;//P部分
	int16 i_component;//I部分
  int16 d_component;//D部分

  int32 pwm_output;//PWM输出
	
}PID_Dir;

    extern PID_Dir PID;
    extern int16 seek_position;//目标位置
    extern int16 seek_velocity;//寻求速度
    extern int16 minimum_position;//最小位置
    extern int16 maximum_position;//最大位置
    extern u8    Reverse_Seek;

// Initialize the PID algorithm module.
void pid_init(void);

// Initialize the PID related register values.
void pid_registers_defaults(void);

// Take the 10-bit position as input and output a signed PWM to be
// applied to the servo motors.
int16 pid_position_to_pwm(int16 position, u8 tick);

#endif // _OS_PID_H_
