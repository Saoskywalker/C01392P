#include "GCE_General.h" //系统 通用调用文件
/* Private defines -----------------------------------------------------------*/

#if (GCE_ADC_EN)

UI08 ADC_Channel[ADC_USE_CHANNEL_TOTAL] = {ADC_USE_CHANNEL_TAB};
UI08 zero_val_count = 0;
////函数声明
void ADC_Init_Channel(UI08 _channel);
void ADC_Sample_Loop(UI08 _channel, UI08 _interval_time, UI08 _reject_count, UI08 _total_sample_count);
void ADC_Sample(void);
/*************************************************
//名称        :ADC_init_ADC_channel
//功能        :ADC通道初始化
//入口参数    :_channel
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.12
//修改记录    :2021.5.13  V0.0初版发布
************************************************/
void ADC_Init_Channel(UI08 _channel)
{
    ADC_C0 = bit7 | bit6 | (_channel); // ADC使能，选择初始通道,软件触发一次
}
/*************************************************
//名称        :ADC_sample_loop
//功能        :ADC数据采样循环
//入口参数    :UI08 _channel,UI08 _interval_time,UI08 _reject_count,UI08 _total_sample_count
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.13
//修改记录    :2021.5.14  V0.0初版发布
************************************************/
//==========================================================================================
GCE_XDATA UI08 _ADC_end = 0;
GCE_XDATA UI16 ADC_value_buf = 0;
GCE_XDATA UI08 sample_time = 0;
GCE_XDATA UI08 sample_cnt = 0;
GCE_XDATA UI32 ADC_sum = 0;
GCE_XDATA UI16 ADC_max = 0;
GCE_XDATA UI16 ADC_min = 0;
GCE_XDATA UI08 ADC_channel_ptr = 0;   //通道指针
GCE_XDATA UI16 AD_value_lit[2] = {0}; // 12bit
//==========================================================================================
//==========================================================================================
void ADC_Sample_Loop(UI08 _channel, UI08 _interval_time, UI08 _reject_count, UI08 _total_sample_count)
{
    UI16 ADC_buf;
    UI16 temp_x;

    if (_ADC_end)
    {
        return;
    }
    //========================================================================
    sample_time++;
    if (sample_time < _interval_time)
    {
        return;
    }
    sample_time = 0;
    _channel = 0; //编译器警报
    //========================================================================
    // ADC_buf=ADC_DH;//ADC值的高四位
    // ADC_buf=ADC_buf&0x0f;
    // ADC_buf=ADC_buf<<8;
    // ADC_buf|=(UI16)(ADC_DH);//高4bit + 低8bit =12bit
    ADC_buf = GCE_GET_ADC_VALUE;
    // if(ADC_IF)
    //{ADC_INT_IF_CLR;}
    // ADC_buf=ADC_buf>>2;//取10位
    //========================================================================
    GCE_ADC_TRG; //开始ADC转换
                 //========================================================================

    sample_cnt++;
    if (sample_cnt < _reject_count)
    {
        zero_val_count = 0;
        return;
    } //去掉前reject_count次

    ///////////////////////////////////////////////////////////////
    //针对中基国威F03芯片做的一个补丁，AD通道偶尔出现数值为零的情况
    if (0 == ADC_buf)
    {
        zero_val_count++;
        if (zero_val_count < 5)
        {
            sample_cnt--;
            return;
        }
    }
    else
    {
        zero_val_count = 0;
    }
    /////////////////////////////////////////////////////////////

    //========================================================================
    if (sample_cnt == _reject_count)
    {
        ADC_max = ADC_buf;
        return;
    }
    if (sample_cnt == _reject_count + 1)
    {
        ADC_min = ADC_buf;
        return;
    }
    if (ADC_buf > ADC_max)
    {
        temp_x = ADC_max;
        ADC_max = ADC_buf;
        ADC_buf = temp_x;
    }
    if (ADC_buf < ADC_min)
    {
        temp_x = ADC_min;
        ADC_min = ADC_buf;
        ADC_buf = temp_x;
    }
    ADC_sum += ADC_buf;
    //========================================================================
    if (sample_cnt < _total_sample_count)
    {
        return;
    }
    sample_cnt = 0;
    ADC_sum -= ADC_max; //去掉最大值
    ADC_sum -= ADC_min; //去掉最小值
    ADC_value_buf = ADC_sum / (_total_sample_count - _reject_count - 3);
    //========================================================================
    ADC_sum = 0;
    _ADC_end = 1;
}

/*************************************************
//名称        :ADC_sample
//功能        :ADC数据采样
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.13
//修改记录    :2021.5.14  V0.0初版发布
************************************************/
void ADC_Sample(void)
{
    if (!_10ms_for_ADC)
    {
        return;
    }
    _10ms_for_ADC = 0;
    if (_ADC_end)
    {
        // AD_value_lit[0]=(ADC_value_buf>>2);//取得的AD
        AD_value_lit[ADC_channel_ptr] = (ADC_value_buf >> 2); //取得的AD
        // ADC_channel_ptr = 0;
        ADC_channel_ptr++;
        if (ADC_channel_ptr >= ADC_USE_CHANNEL_TOTAL)
        {
            ADC_channel_ptr = 0;
        }
        //通道切换
        ADC_Init_Channel(ADC_Channel[ADC_channel_ptr]);
        GCE_ADC_TRG; //开始ADC转换
        sample_time = 0;
        _ADC_end = 0;
    }
    else
    {
        ADC_Sample_Loop(ADC_Channel[ADC_channel_ptr], 1, 3, 3 + 17); //每10ms执行一次采样,采(3+17)次,丢掉前3次,去掉最大值和最小值,再平均
    }
}

#endif ////GCE_ADC_EN
