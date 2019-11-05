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

#ifndef _OS_CONFIG_H_
#define _OS_CONFIG_H_ 1

// Enable (1) or disable (0) checksum verification within the
// twi.c module.  When enabled the TWI_CMD_CHECKED_TXN command
// is enabled and basic checksum validation of reads and writes
// of registers can be made for more robust communication with
// the OpenServo.  The checksum code consumes about 280 bytes
// of Flash code space when enabled.
//（1）启用或禁用（0）校验和验证在TWI模块。
//当启用时，twi_cmd_checked_txn命令启用基本验证和校验读取和写入寄存器可以具有更强大的通信openservo。
//校验和代码在启用时消耗大约280字节的闪存代码空间
#define TWI_CHECKED_ENABLED         1 

// Enable (1) or disable (0) cubic Hermite curve following motion
// functions.  These functions allow the OpenServo to be controlled
// by keypoints along a cubic Hermite curve with each keypoint
// indicating servo position and velocity at a particular time.
//使（1）或禁用（0）三次Hermite曲线跟随运动函数。这些功能允许openservo是由每个点表示在一个特定的时间位置和速度沿一条三次Hermite曲线的关键点控制。
#define CURVE_MOTION_ENABLED        1

// Enable (1) or disable (0) some test motion code within the
// main.c module.  This test code can be enabled to test basic
// positioning of the OpenServo without a TWI master controlling
// the OpenServo.  It should normally be disabled.
//启用（1）或禁用（0）主模块中的一些测试运动代码。这个测试代码可以使测试的openservo基本定位没有TWI主控制openservo。通常应该禁用它
#define MAIN_MOTION_TEST_ENABLED    1

// Enable (1) or disable (0) standard servo pulse control signaling
// of the seek position.  As of 2/2/07 this feature is still under
// active development.  Please visit the OpenServo forums for the
// current status of this feature.
//启用（1）或禁用（0）标准伺服脉冲控制信号
//寻找位置。截至2/2／07，此功能仍在积极开发中。请访问这个功能的现状openservo论坛。
#define PULSE_CONTROL_ENABLED       0

// Enable (1) or disable (0) the swapping of PWM output A and B.
// This swapping must sometimes enabled depending on whether the
// positive lead to the motor is attached to MOSFET/PWM output A
// or MOSFET/PWM output B.  This option makes this easy to control
// within software.
//启用（1）或禁用（0）PWM输出A和B的交换。
//这种交换有时必须启用，这取决于是否对电机的正面引线连接到MOSFET / PWM输出A或MOSFET的PWM输出B。
#define SWAP_PWM_DIRECTION_ENABLED  1

// Enable (1) or disable (0) support for I2C connected encoder.
//启用（1）或禁用（0）支持I2C连接编码器。
#define ENCODER_ENABLED             0

// Enable (1) or disable (0) support for full rotation
//启用（1）或禁用（0）支持完全旋转
#define FULL_ROTATION_ENABLED       0

// The known OpenServo hardware types are listed below.
#define HARDWARE_TYPE_UNKNOWN           0
#define HARDWARE_TYPE_FUTABA_S3003      1
#define HARDWARE_TYPE_HITEC_HS_311      2
#define HARDWARE_TYPE_HITEC_HS_475HB    3
#define HARDWARE_TYPE_MG995             4

// By default the hardware type is unknown.  This value should be
// changed to reflect the hardware type that the code is actually
// being compiled for.
#define HARDWARE_TYPE                   HARDWARE_TYPE_UNKNOWN

// Set configuration values based on HARDWARE_TYPE.
#if (HARDWARE_TYPE == HARDWARE_TYPE_UNKNOWN)

// By default the PID gains are set to zero because they are the
// safest default when implementing an OpenServo on a new hardware.
// These defaults should be overriden by specifying the HARDWARE_TYPE
// above for actual known servo hardware.
#define DEFAULT_PID_PGAIN               0x0000//默认PID的P值
#define DEFAULT_PID_DGAIN               0x0000//默认PID的D值
#define DEFAULT_PID_IGAIN               0x0000//默认PID的I值
#define DEFAULT_PID_DEADBAND            32  //默认PID的死区

// Specify default mininimum and maximum seek positions.  The OpenServo will 指定默认的最小和最大寻求位置。开发伺服算法将不要试图超越这些位置
// not attempt to seek beyond these positions.
#define DEFAULT_MIN_SEEK_STD                0x0000
#define DEFAULT_MAX_SEEK_STD                0x1000

#define Rudder_MAX      2500//最大的舵机信号
#define Rudder_MIN      500
// Default pwm frequency divider.
#define DEFAULT_PWM_FREQ_DIVIDER        0x0040//默认PWM分频器频率16~64


#endif

//
// Update minimum and maximum seek positions depending on whether the encoder is
// used and/or full rotation is enabled.
//
#if FULL_ROTATION_ENABLED
//#if ENCODER_ENABLED
//#define DEFAULT_MIN_SEEK                0
//#define DEFAULT_MAX_SEEK                4095
//#else
#define DEFAULT_MIN_SEEK                0
#define DEFAULT_MAX_SEEK                1023
//#endif
#else
//#if ENCODER_ENABLED
//#define DEFAULT_MIN_SEEK                (DEFAULT_MIN_SEEK_STD<<1)
//#define DEFAULT_MAX_SEEK                (DEFAULT_MAX_SEEK_STD<<1)
//#else
#define DEFAULT_MIN_SEEK                DEFAULT_MIN_SEEK_STD
#define DEFAULT_MAX_SEEK                DEFAULT_MAX_SEEK_STD
//#endif
#endif

#endif // _OS_ADC_H_
