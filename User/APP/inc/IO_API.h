/**
  ******************************************************************************
  * @file IO_API.h
  *
  ******************************************************************************
  *���ļ�����ΪDO_out[],���������IO��,������DI_status,��ÿ����������ĳ���ʱ��
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
  PinStatus IO_Status;     //ÿһ���ļ��ʱ��
}Str_IO;

extern GCE_XDATA Str_IO  Water_Status;     //ˮ��״̬
extern GCE_XDATA Str_IO  Filt_Status;  //ѹ�����¶ȿ���״̬



//====================================================================================
extern void IO_operate(void);
extern void Sys_Off(void);
#endif /* __IO_API_H */

