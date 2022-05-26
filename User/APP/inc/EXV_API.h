/********************************************************************************
  // �ļ�����:   EXV_device.h
  // ��������:   �������������
  //            (����Ӳ���豸���������ݶ�д��Э��ʵ�֣���������ķ�װ���ӿ����)
*********************************************************************************/
#ifndef _EXV_API_H
#define _EXV_APIE_H

//==========================================================================================
//      2) ��������(��Ҫ���ñ���\�Ĵ�������)
//==========================================================================================

#define UD_degree00 0
#define UD_degree45 550
#define UD_degree90 1100
#define UD_degree_Closs 100  //�رն��߲���


#define LR_degree00 0
#define LR_degree60 000
#define LR_degree90 500
#define LR_degree120 500



typedef enum
{
  STATUS1=0,
  STATUS2=1,
  STATUS3=2,
  STATUS4=3,
  STATUS5=4,
  STATUS_NO=5,
}
EXV_STATUS;

//
typedef enum
{
  AUTO_SWING=0,        //�Զ���
  LEFT_RIGHT_SWING=1,  //���Ұ�
  UP_DOWN_SWING=2,     //���°�
  STOP_SWING=3         //ֹͣ��
}Swing_Mode;

extern GCE_XDATA Swing_Mode  EXV_SWING_Mode;
extern GCE_XDATA Swing_Mode  EXV_SWING_Mode_old;
//==============================================================================
//      3) ��������(����ӿ�)
//==============================================================================
extern void EXV_Control(void);
extern void EXV_Data_Init(void);


#endif



