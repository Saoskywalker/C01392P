#include "GCE_General.h" //系统 通用调用文件
/* Private defines -----------------------------------------------------------*/

UI08 mS_Count = 0;
#if (GCE_TIMER0_IT_EN)
/*************************************************
//名称        :GCE_Timer0_Enable
//功能        :关定时器定时器0
************************************************/
void GCE_Timer0_Enable(void)
{
    TMR0_EN;
}

/*************************************************
//名称        :GCE_Timer0_Disable
//功能        :关定时器定时器0
************************************************/
void GCE_Timer0_Disable(void)
{
    TMR0_DIS;
}

/*************************************************
//名称        :GCE_Timer0_IT
//功能        :定时器0中断处理函数
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.6.5
//修改记录    :2021.6.5  V0.0初版发布
************************************************/
void GCE_Timer0_IT(void) //中断调用
{
    _TEST_TIMER0_IT

    if (!_txd_en)
    {
        Communication_Rxd_IRQ_deal();
    }
    else
    {
        Communication_Txd_IRQ();
    }

    Hum_driver();

    mS_Count++;
    if (mS_Count >= 8)
    {
        mS_Count = 0;


        EXV_UD_run();
    }
}
#endif /// GCE_TIMER0_IT_EN///
