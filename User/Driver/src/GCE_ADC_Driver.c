#include "GCE_General.h" //ϵͳ ͨ�õ����ļ�
/* Private defines -----------------------------------------------------------*/

#if (GCE_ADC_EN)

UI08 ADC_Channel[ADC_USE_CHANNEL_TOTAL] = {ADC_USE_CHANNEL_TAB};
UI08 zero_val_count = 0;
////��������
void ADC_Init_Channel(UI08 _channel);
void ADC_Sample_Loop(UI08 _channel, UI08 _interval_time, UI08 _reject_count, UI08 _total_sample_count);
void ADC_Sample(void);
/*************************************************
//����        :ADC_init_ADC_channel
//����        :ADCͨ����ʼ��
//��ڲ���    :_channel
//���ڲ���    :��
//��ǰ�汾    :V0.0
//��д:       :����ΰ
//���        :����
//�������    :2021.5.12
//�޸ļ�¼    :2021.5.13  V0.0���淢��
************************************************/
void ADC_Init_Channel(UI08 _channel)
{
    ADC_C0 = bit7 | bit6 | (_channel); // ADCʹ�ܣ�ѡ���ʼͨ��,�������һ��
}
/*************************************************
//����        :ADC_sample_loop
//����        :ADC���ݲ���ѭ��
//��ڲ���    :UI08 _channel,UI08 _interval_time,UI08 _reject_count,UI08 _total_sample_count
//���ڲ���    :��
//��ǰ�汾    :V0.0
//��д:       :����ΰ
//���        :����
//�������    :2021.5.13
//�޸ļ�¼    :2021.5.14  V0.0���淢��
************************************************/
//==========================================================================================
GCE_XDATA UI08 _ADC_end = 0;
GCE_XDATA UI16 ADC_value_buf = 0;
GCE_XDATA UI08 sample_time = 0;
GCE_XDATA UI08 sample_cnt = 0;
GCE_XDATA UI32 ADC_sum = 0;
GCE_XDATA UI16 ADC_max = 0;
GCE_XDATA UI16 ADC_min = 0;
GCE_XDATA UI08 ADC_channel_ptr = 0;   //ͨ��ָ��
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
    _channel = 0; //����������
    //========================================================================
    // ADC_buf=ADC_DH;//ADCֵ�ĸ���λ
    // ADC_buf=ADC_buf&0x0f;
    // ADC_buf=ADC_buf<<8;
    // ADC_buf|=(UI16)(ADC_DH);//��4bit + ��8bit =12bit
    ADC_buf = GCE_GET_ADC_VALUE;
    // if(ADC_IF)
    //{ADC_INT_IF_CLR;}
    // ADC_buf=ADC_buf>>2;//ȡ10λ
    //========================================================================
    GCE_ADC_TRG; //��ʼADCת��
                 //========================================================================

    sample_cnt++;
    if (sample_cnt < _reject_count)
    {
        zero_val_count = 0;
        return;
    } //ȥ��ǰreject_count��

    ///////////////////////////////////////////////////////////////
    //����л�����F03оƬ����һ��������ADͨ��ż��������ֵΪ������
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
    ADC_sum -= ADC_max; //ȥ�����ֵ
    ADC_sum -= ADC_min; //ȥ����Сֵ
    ADC_value_buf = ADC_sum / (_total_sample_count - _reject_count - 3);
    //========================================================================
    ADC_sum = 0;
    _ADC_end = 1;
}

/*************************************************
//����        :ADC_sample
//����        :ADC���ݲ���
//��ڲ���    :��
//���ڲ���    :��
//��ǰ�汾    :V0.0
//��д:       :����ΰ
//���        :����
//�������    :2021.5.13
//�޸ļ�¼    :2021.5.14  V0.0���淢��
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
        // AD_value_lit[0]=(ADC_value_buf>>2);//ȡ�õ�AD
        AD_value_lit[ADC_channel_ptr] = (ADC_value_buf >> 2); //ȡ�õ�AD
        // ADC_channel_ptr = 0;
        ADC_channel_ptr++;
        if (ADC_channel_ptr >= ADC_USE_CHANNEL_TOTAL)
        {
            ADC_channel_ptr = 0;
        }
        //ͨ���л�
        ADC_Init_Channel(ADC_Channel[ADC_channel_ptr]);
        GCE_ADC_TRG; //��ʼADCת��
        sample_time = 0;
        _ADC_end = 0;
    }
    else
    {
        ADC_Sample_Loop(ADC_Channel[ADC_channel_ptr], 1, 3, 3 + 17); //ÿ10msִ��һ�β���,��(3+17)��,����ǰ3��,ȥ�����ֵ����Сֵ,��ƽ��
    }
}

#endif ////GCE_ADC_EN
