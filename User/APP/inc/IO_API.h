/**
  ******************************************************************************
  * @file IO_API.h
  *
  ******************************************************************************
  *改文件输入为DO_out[],将其输出到IO口,并返回DI_status,及每个输入输出的持续时间
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __IO_API_H
#define __IO_API_H


typedef struct IO_struct
{
  UI08 IO_Value_Buf; //
  UI08 IO_Cnt;       //
  PinStatus IO_Status;     //每一步的间隔时间
}Str_IO;

extern GCE_XDATA Str_IO  Water_Status;     //水满状态
extern GCE_XDATA Str_IO  Filt_Status;  //压缩机温度开关状态



//====================================================================================
extern void IO_operate(void);
extern void Sys_Off(void);
#endif /* __IO_API_H */

