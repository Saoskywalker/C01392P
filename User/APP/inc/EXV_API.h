/********************************************************************************
  // 文件名称:   EXV_device.h
  // 功能描述:   驱动程序功能设计
  //            (管理硬件设备层面上数据读写的协议实现，驱动程序的封装、接口设计)
*********************************************************************************/
#ifndef _EXV_API_H
#define _EXV_APIE_H

//==========================================================================================
//      2) 变量声明(需要配置变量\寄存器定义)
//==========================================================================================

#define UD_degree00 0
#define UD_degree45 550
#define UD_degree90 1100
#define UD_degree_Closs 100  //关闭多走步数


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
  AUTO_SWING=0,        //自动摆
  LEFT_RIGHT_SWING=1,  //左右摆
  UP_DOWN_SWING=2,     //上下摆
  STOP_SWING=3         //停止摆
}Swing_Mode;

extern GCE_XDATA Swing_Mode  EXV_SWING_Mode;
extern GCE_XDATA Swing_Mode  EXV_SWING_Mode_old;
//==============================================================================
//      3) 函数声明(对外接口)
//==============================================================================
extern void EXV_Control(void);
extern void EXV_Data_Init(void);


#endif



