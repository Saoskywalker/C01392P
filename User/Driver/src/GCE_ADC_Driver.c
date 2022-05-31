#include "GCE_General.h" //系统 通用调用文件
/* Private defines -----------------------------------------------------------*/

#if (GCE_ADC_EN)

UI08 ADC_Channel[ADC_USE_CHANNEL_TOTAL] = {ADC_USE_CHANNEL_TAB};
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
static GCE_XDATA UI08 _ADC_end = 0;
static GCE_XDATA UI16 ADC_value_buf = 0;
static GCE_XDATA UI08 ADC_channel_ptr = 0;   //通道指针
GCE_XDATA UI16 AD_value_lit[ADC_USE_CHANNEL_TOTAL] = {512}; // 12bit

/*************************************************
 // 函数名称    : HUM_sample_loop
 // 功能描述    : ADC采集
 // 入口参数    : data
 // 出口参数    : 无
 // 当前版本    :V1.0
***************************************************/
static void ADC_Sample_Loop(UI08 _channel, UI08 _interval_time, UI08 _reject_count, UI08 _total_sample_count)
{
    static GCE_XDATA UI32 ADC_sum = 0;
    static GCE_XDATA UI08 ADC_sample_cnt = 0;
    static GCE_XDATA UI16 ADC_max = 0;
    static GCE_XDATA UI16 ADC_min = 0;
    static GCE_XDATA UI08 zero_val_count = 0;
    static GCE_XDATA UI08 sample_time = 0;
    UI16 ADC_buf = 0;
    UI16 buf = 0;

    _channel = 0; //编译器警报

    if (_ADC_end)
    {
        return;
    }

    sample_time++;
    if (sample_time <= _interval_time)
    {
        return;
    }
    sample_time = 0;

    ADC_buf = GCE_GET_ADC_VALUE;
    GCE_ADC_TRG; // start AD

    ADC_sample_cnt++;
    if (ADC_sample_cnt <= _reject_count)
    {
        return; //去掉前reject_count次
    }

    // if (ADC_SAMPLE_COMPLETE() == 0)
    //     return;

    ///////////////////////////////////////////////////////////////
    //针对中基国威F03芯片做的一个补丁，AD通道偶尔出现数值为零的情况
    if (0 == ADC_buf)
    {
        zero_val_count++;
        if (zero_val_count < 5)
        {
            ADC_sample_cnt--;
            return;
        }
    }
    else
    {
        zero_val_count = 0;
    }
    /////////////////////////////////////////////////////////////

    if (ADC_sample_cnt >= _reject_count + 3)
    {
        if (ADC_buf > ADC_max)
        {
            buf = ADC_max;
            ADC_max = ADC_buf;
            ADC_buf = buf;
        }
        else if (ADC_buf < ADC_min)
        {
            buf = ADC_min;
            ADC_min = ADC_buf;
            ADC_buf = buf;
        }

        ADC_sum = ADC_sum + ADC_buf; //已去掉最大和最小值
        if (ADC_sample_cnt < _total_sample_count)
        {
            return;
        }
        ADC_value_buf = ADC_sum / (_total_sample_count - _reject_count - 2);
        ADC_sum = 0;
        ADC_sample_cnt = 0;
        zero_val_count = 0;
        _ADC_end = 1;
    }
    else if (ADC_sample_cnt == _reject_count + 1)
    {
        ADC_max = ADC_buf;
    }
    else if (ADC_sample_cnt == _reject_count + 2)
    {
        ADC_min = ADC_buf;

        if (ADC_max < ADC_min)
        {
            buf = ADC_max;
            ADC_max = ADC_min;
            ADC_min = buf;
        }
    }
}

/*************************************************
 // 函数名称    : HUM_sample_loop_for_int
 // 功能描述    : ADC采集
 // 入口参数    : data
 // 出口参数    : 无
 // 当前版本    :V1.0
***************************************************/
static void HUM_sample_loop_for_int(UI08 _channel, UI08 _interval_time, UI08 _reject_count, UI08 _total_sample_count)
{
    static GCE_XDATA UI32 ADC_sum = 0;
    static GCE_XDATA UI08 ADC_sample_cnt = 0;
    static GCE_XDATA UI16 ADC_max = 0;
    static GCE_XDATA UI16 ADC_min = 0;
    static GCE_XDATA UI08 zero_val_count = 0;
    static GCE_XDATA UI08 sample_time = 0;
    UI16 ADC_buf = 0;
    UI16 buf = 0;

    _channel = 0; //编译器警报

    if (_ADC_end)
    {
        return;
    }

    sample_time++;
    if (sample_time <= _interval_time)
    {
        return;
    }
    sample_time = 0;

    ADC_buf = GCE_GET_ADC_VALUE;
    GCE_ADC_TRG; // start AD

    ADC_sample_cnt++;
    if (ADC_sample_cnt <= _reject_count)
    {
        return; //去掉前reject_count次
    }

    // if (ADC_SAMPLE_COMPLETE() == 0)
    //     return;

    ///////////////////////////////////////////////////////////////
    //针对中基国威F03芯片做的一个补丁，AD通道偶尔出现数值为零的情况
    if (0 == ADC_buf)
    {
        zero_val_count++;
        if (zero_val_count < 5)
        {
            ADC_sample_cnt--;
            return;
        }
    }
    else
    {
        zero_val_count = 0;
    }
    /////////////////////////////////////////////////////////////

    if (ADC_sample_cnt >= _reject_count + 3)
    {
        if (ADC_buf > ADC_max)
        {
            buf = ADC_max;
            ADC_max = ADC_buf;
            ADC_buf = buf;
        }
        else if (ADC_buf < ADC_min)
        {
            buf = ADC_min;
            ADC_min = ADC_buf;
            ADC_buf = buf;
        }

        ADC_sum = ADC_sum + ADC_buf; //已去掉最大和最小值
        if (ADC_sample_cnt < _total_sample_count)
        {
            return;
        }
        ADC_value_buf = ADC_sum / (_total_sample_count - _reject_count - 2);
        ADC_sum = 0;
        ADC_sample_cnt = 0;
        zero_val_count = 0;
        _ADC_end = 1;
    }
    else if (ADC_sample_cnt == _reject_count + 1)
    {
        ADC_max = ADC_buf;
    }
    else if (ADC_sample_cnt == _reject_count + 2)
    {
        ADC_min = ADC_buf;

        if (ADC_max < ADC_min)
        {
            buf = ADC_max;
            ADC_max = ADC_min;
            ADC_min = buf;
        }
    }
}

/*************************************************
 // 函数名称    : Hum_driver
 // 功能描述    : 湿度驱动和采集
 // 入口参数    : data
 // 出口参数    : 无
 // 当前版本    :V1.0
***************************************************/
void Hum_driver(void)
{
    static GCE_XDATA UI08 hum_cont5 = 0;
    static GCE_XDATA UI08 hum_drive_period = 0;

    hum_cont5++;
    if (hum_cont5 >= 4)
    {
        hum_cont5 = 0;
        if (hum_drive_period <= 4) //1KHz互补50%方波
        {
            HUM1_L;
            HUM2_H;
        }
        else
        {
            HUM2_L;
            HUM1_H;
        }
    }
    hum_drive_period++;
    if (hum_drive_period >= 8)
    {
        hum_drive_period = 0;
        hum_cont5 = 0;
    }

    if (hum_drive_period == 3) // 3/10
    {
        if (ADC_Channel[ADC_channel_ptr] == HUM_ADC_channel)
        {
            //采68次,丢掉前2次,并去掉最大值和最小值(共64次),再平均
            HUM_sample_loop_for_int(ADC_Channel[ADC_channel_ptr], 0, 2, 64 + 2 + 2);
        }
    }
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
        // if (ADC_SAMPLE_COMPLETE() == 0)
        //     return;

        AD_value_lit[ADC_channel_ptr] = (ADC_value_buf >> 2); //取得的AD
        // ADC_channel_ptr = 0;
        ADC_channel_ptr++;
        if (ADC_channel_ptr >= ADC_USE_CHANNEL_TOTAL)
        {
            room_temp_deal();
            hum_deal();
            ADC_channel_ptr = 0;
        }
        //通道切换
        ADC_Init_Channel(ADC_Channel[ADC_channel_ptr]);
        GCE_ADC_TRG; //开始ADC转换
        _ADC_end = 0;
    }
    else
    {
        if (ADC_Channel[ADC_channel_ptr] != HUM_ADC_channel)
            //每10ms执行一次采样,采(2+18)次,丢掉前2次,并去掉最大值和最小值(共16次),再平均
            ADC_Sample_Loop(ADC_Channel[ADC_channel_ptr], 1, 2, 16 + 2 + 2);
    }
}

#endif ////GCE_ADC_EN
