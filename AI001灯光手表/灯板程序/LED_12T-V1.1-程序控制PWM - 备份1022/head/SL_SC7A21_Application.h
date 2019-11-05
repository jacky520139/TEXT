#ifndef SL_SC7A21_Application__H__
#define SL_SC7A21_Application__H__

extern signed char    SL_SC7A21_INIT(void);
extern unsigned int   SL_SC7A21_GET_PEDO_VALUE(void);//include sleep status
extern unsigned char  SL_SC7A21_WRIST_INT12_SERVICE_FUNCTION(void);

extern unsigned char  SL_SC7A21_CLICK_SERVICE(void);
extern unsigned char  SL_SC7A21_Click_Timer_Cnt(void);
extern void SL_Open_Sc7a21_Click_Timer(void);
extern void SL_Close_Sc7a21_Click_Timer(void);

#endif
