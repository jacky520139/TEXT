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

#ifndef _OS_EEPROM_H_
#define _OS_EEPROM_H_ 1

// The following defines the EEPROM version.  This value should
// be changed in code whenever changes to the OpenServo registers
// would cause the data stored in EEPROM to be incompatible from
// one version of the OpenServo firmware to the next version of
// the OpenServo firmware.
//以下定义了EEPROM版本。这个值应该改变代码时的openservo寄存器的变化会导致存储在EEPROM是水火不容的
//从一个版本的openservo固件的openservo固件的下一个版本的数据
#define EEPROM_VERSION      0x02

u8 eeprom_erase(void);
u8 eeprom_restore_registers(void);
u8 eeprom_save_registers(void);
void writerom(unsigned int *Data_Buf,unsigned char n );
void readrom(unsigned int *Data_Buf,unsigned char n);
#endif // _OS_EEPROM_H_
