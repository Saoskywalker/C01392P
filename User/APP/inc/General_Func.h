//**********************************************************
//文件名称: 	General_func.c
//文件描述: 	各模块都会调用到的通用子程序
//说	明:
//项目名称: 	COR748
//构	建: 	GCE 唐永强		2011/07/11
//修	改: 	GCE XXX 		2011/07/11
//*********************************************************/

#ifndef __General_func_H
#define __General_func_H

extern GCE_XDATA UI08 M_Sleep_Delay_Time;

extern GCE_XDATA UUI08 SYS_bit; //系统标志位
#define _Power_Status SYS_bit.bit_.b0
#define _Fan15V_Power_Status SYS_bit.bit_.b1
#define _UVC_Status SYS_bit.bit_.b2
#define _COMP_Status SYS_bit.bit_.b3
#define _Self_Test SYS_bit.bit_.b4
#define _SWING_Status SYS_bit.bit_.b7

extern GCE_XDATA UUI08 SYS_bit1; //系统标志位
#define _10ms_MOTER_CHECK_EN SYS_bit1.bit_.b0
#define _txd_tick_en SYS_bit1.bit_.b1
//#define  _ADC_end                 SYS_bit1.bit_.b2
#define _Sleep_status_buf SYS_bit1.bit_.b3
#define _Sleep_status SYS_bit1.bit_.b4
#define _water_full_Status_buf SYS_bit1.bit_.b5
#define _Test_rxd_ok SYS_bit1.bit_.b6
#define _Sleep_WakeUp_En SYS_bit1.bit_.b7

extern GCE_XDATA UUI08 SYS_bit2; //系统标志位
#define _Power_Status_Old SYS_bit2.bit_.b0

//#define  _ms100_for_motor       SYS_bit2.bit_.b2
//#define  _ms100_for_motor_err   SYS_bit2.bit_.b5

extern void General_Func_Deal(void);
extern void Sleep_deal(void);
#endif
