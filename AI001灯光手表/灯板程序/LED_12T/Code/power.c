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

// Minimal module to support power reporting.  In the future this module
// may be expanded for the servo to monitor it's own power usage and take
// action when action when too much power is being consumed.


#include "ALL_Includes.h"
// Static structure for averaging power values.
//平均功率值的静态结构
static u8 power_index;
static u16 power_array[8];

void power_init(void)
// Initialize the power module.
{
    u8 i;

    // Initialize the power index.
    power_index = 0;

    // Initialize the power array.
    for (i = 0; i < 8; ++i) power_array[i] = 0;

    // 初始化系统寄存器中的电源值.
    registers_write_word(REG_POWER_HI, REG_POWER_LO, 0);
}


void power_update(u16 power)
//更新伺服电机功率值.报告的实际值是用前七个功率值平均计算的
{
    u8 i;

    // Insert the power value into the power array.
    power_array[power_index] = power;

    // Keep the index within the array bounds.
	//保持指数在数组界限
    power_index = (power_index + 1) & 7;

    // Reset the power value.
    power = 0;

    // Determine the power values across the power array.
    for (i = 0; i < 8; ++i) power += power_array[i];

    // Shift the sum of power values to find the average.
    power >>= 3;

    // Update the power values within the system registers.
    registers_write_word(REG_POWER_HI, REG_POWER_LO, power);
}

