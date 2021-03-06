#include "GCE_General.h" //系统 通用调用文件
/* Private defines -----------------------------------------------------------*/

#if (GCE_EXT0_EN)
/*************************************************
//名称        :GCE_INT0_IT
//功能        :外中断0处理函数
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.6.5
//修改记录    :2021.6.5  V0.0初版发布
************************************************/
void GCE_EXT0_IT(void) //中断调用
{
     _Sleep_status = 0;
     M_Sleep_Delay_Time = 5;
}
#endif /// GCE_EXT0_EN///
////////////////////////////////////////////////////////////
#if (GCE_EXT1_EN)
/*************************************************
//名称        :GCE_INT1_IT
//功能        :外中断1处理函数
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.6.5
//修改记录    :2021.6.5  V0.0初版发布
************************************************/
void GCE_EXT1_IT(void) //中断调用
{
     _Sleep_status = 0;
     M_Sleep_Delay_Time = 5;
}
#endif /// GCE_EXT1_EN///
