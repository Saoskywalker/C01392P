/********************************************************************************
  // �ļ�����:   EXV_device.h
  // ��������:   �������������
  //            (����Ӳ���豸���������ݶ�д��Э��ʵ�֣���������ķ�װ���ӿ����)
*********************************************************************************/
#ifndef _EXV_DEVICE_H
#define _EXV_DEVICE_H

//==========================================================================================
//      2) ��������(��Ҫ���ñ���\�Ĵ�������)
//==========================================================================================
#define EXV_UD_step_short_time  2//ms
#define EXV_UD_step_long_time  15//ms

//#define EXV_LR_step_short_time  2//ms
//#define EXV_LR_step_long_time  15//ms

typedef struct EXV
{
  UI08 EXV_Step_Time_Cnt; //
  UI08 EXV_Step_Cnt;       //
  UI08 EXV_Step_Time;     //ÿһ���ļ��ʱ��
  UI16 EXV_Excit_Time;    //����ʱ��
  UI16 EXV_Step_Target;    //Ŀ�경��
  UI16 EXV_Step_Now;       //��ǰ����
}sEXVPARA;


extern GCE_XDATA  sEXVPARA  EXV_UD;
//extern GCE_XDATA  sEXVPARA  EXV_LR;

extern void EXV_UD_Out(UI08 _io_data);
//extern void EXV_LR_Out(UI08 _io_data);


extern void EXV_UD_run(void);
//extern void EXV_LR_run(void);

#endif



