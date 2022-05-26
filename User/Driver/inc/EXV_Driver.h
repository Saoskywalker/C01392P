/********************************************************************************
  // 文件名称:   EXV_device.h
  // 功能描述:   驱动程序功能设计
  //            (管理硬件设备层面上数据读写的协议实现，驱动程序的封装、接口设计)
*********************************************************************************/
#ifndef _EXV_DEVICE_H
#define _EXV_DEVICE_H

//==========================================================================================
//      2) 变量声明(需要配置变量\寄存器定义)
//==========================================================================================
#define EXV_UD_step_short_time  2//ms
#define EXV_UD_step_long_time  15//ms

//#define EXV_LR_step_short_time  2//ms
//#define EXV_LR_step_long_time  15//ms

typedef struct EXV
{
  UI08 EXV_Step_Time_Cnt; //
  UI08 EXV_Step_Cnt;       //
  UI08 EXV_Step_Time;     //每一步的间隔时间
  UI16 EXV_Excit_Time;    //励磁时间
  UI16 EXV_Step_Target;    //目标步数
  UI16 EXV_Step_Now;       //当前步数
}sEXVPARA;


extern GCE_XDATA  sEXVPARA  EXV_UD;
//extern GCE_XDATA  sEXVPARA  EXV_LR;

extern void EXV_UD_Out(UI08 _io_data);
//extern void EXV_LR_Out(UI08 _io_data);


extern void EXV_UD_run(void);
//extern void EXV_LR_run(void);

#endif



