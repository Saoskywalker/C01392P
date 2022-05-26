#include "GCE_General.h"

GCE_XDATA UUI08       SYS_bit={0};//系统标志位
GCE_XDATA UUI08       SYS_bit1={0};//系统标志位
GCE_XDATA UUI08       SYS_bit2={0};//系统标志位
GCE_XDATA UI08        M_Sleep_Delay_Time=10;//电源板进入睡眠倒计时

/*************************************************
//名称        :	Sleep_deal
//功能        :	睡眠处理
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE 张远泽		2011/07/11
//修	改: 	GCE XXX 		2011/07/11
************************************************/
void Sleep_deal(void)
{
    if((!_Sleep_status_buf)
        ||(Water_Status.IO_Status)
        ||(_Power_Status))
    {
        M_Sleep_Delay_Time=10;
    }

    if((_Sleep_status_buf)&&(0==M_Sleep_Delay_Time))
    {
       _Sleep_status=1;
    }
}

void prg_General_Func_1S(void)
{
  if(!_1S_for_General_Func)
  {return;}
  _1S_for_General_Func=0;
//系统进入睡眠倒计时
  if(M_Sleep_Delay_Time>0)
  {
      M_Sleep_Delay_Time--;
  }

}

void  General_Func_Deal(void)
{
    prg_General_Func_1S();
    
}

