#include "ALL_Includes.h"
u8 KEY_Trg = 0;
_KEY_Dev   *KEY_Dev;
_KEY_Dev 	 KEY1_Dev = {1, 0, 0, 0, 0, 0};
_KEY_Dev 	 KEY2_Dev = {1, 0, 0, 0, 0, 0};

_KEY_Dev* code Key_Dev_Add[2] = {&KEY1_Dev, &KEY2_Dev};


/*****************************************************************
* 函数名称：void cankey(void)
* 函数功能：按键扫描
* 输入参数：无
* 输出参数：无
***************************************************************/
#define keyshotTime 2
#define keylongTime 250
#define keyhitTime 1

void Key_Scan(void)                                //按键扫描函数
{
    bit KEY_Pro;
    u8 xdata i = 0;

    for(i = 0; i < 2; i++)
    {
        switch(i)
        {
        case 0:
            KEY_Pro = Up_Key;
            KEY_Dev = Key_Dev_Add[i];
            break;
        case 1:

            KEY_Pro = Down_Key;
            KEY_Dev = Key_Dev_Add[i];
            break;
        }
        if(KEY_Pro == 0)  //IO是高电平，说明按键没有被按下，这时要及时清零一些标志位
        {
            KEY_Dev->Down_Time++;
            KEY_Dev->Up_Time = 0;
            if(KEY_Dev->Down_Time > keyshotTime)
            {   if(KEY_Dev->Lock == 0)
                {   KEY_Dev->Trg++;
                    KEY_Dev->Lock = 1;
                    if(KEY_Dev->Mode == Single)
                    {   KEY_Dev->Value = KEY_Dev->Trg;
                        KEY_Dev->Trg = 0;
                    }
                }
            }
            if(KEY_Dev->Mode == Variety && KEY_Dev->Down_Time == keylongTime)
            {   KEY_Dev->Value = Long_Trg_Value;
                KEY_Dev->Trg = 0;
            }
        }
        else
        {   KEY_Dev->Down_Time = 0;
            KEY_Dev->Lock = 0;
            if(KEY_Dev->Mode == Variety)
            {   if(KEY_Dev->Trg != 0)
                {   KEY_Dev->Up_Time++;
                    if(KEY_Dev->Up_Time > keyhitTime)
                    {   KEY_Dev->Value = KEY_Dev->Trg;
                        KEY_Dev->Trg = 0;
                    }
                }
            }
        }
    }

}




