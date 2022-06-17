#include "GCE_General.h" //ϵͳ ͨ�õ����ļ�
#include "T_3450_10K.h"
#include "HIS-06_100K.h"

ADC_PARA Hum_para, Temp_room_para, Temp_comp_para, Temp_coil_para;
UI16 Temp_C_room_digit_value = 26215;//77�H

static UI08 F_C(UI08 cfdata)
{
    UI08 a;
    if (cfdata > 32)
        a = ((cfdata - 32) * 10 + 9) / 18;
    else
        a = ((32 - cfdata) * 10 + 9) / 18;
    return a;
}

/******************************************
 * ���ַ����
 * ***************************************/
/* static UI16 ADC_lookup(UI16 value, const UI16 *ptr, UI16 tab_leng)
{
    UI16 low, high, mid;

    if (tab_leng <= 1)
        return 0;

    low = 1;
    high = tab_leng;
    if (value <= *ptr)
    {
        return 0;
    }
    if (value >= *(ptr + tab_leng - 1))
    {
        return tab_leng - 1;
    }

    while (1)
    {
        tab_leng = high - low + 1;
        if (tab_leng & 0X01)
        {
            mid = (tab_leng >> 1) + low;
            if (value == *(ptr + mid - 1)) //��������
            {
                return mid - 1;
            }
            else if (mid + 1 == high && mid - 1 == low)
            {
                if (value > *(ptr + mid - 1))
                {
                    return mid;
                }
                else
                {
                    return mid - 2;
                }
            }
            else if (value > *(ptr + mid - 1))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            mid = (tab_leng >> 1) + low - 1;

            if (value >= *(ptr + mid - 1) && value <= *(ptr + mid)) //��������
            {
                if (value == *(ptr + mid - 1))
                {
                    return mid - 1;
                }
                else if (value == *(ptr + mid))
                {
                    return mid;
                }
                else
                {
                    if (value - *(ptr + mid - 1) >= *(ptr + mid) - value)
                    {
                        return mid;
                    }
                    else
                    {
                        return mid - 1;
                    }
                }
            }
            else if (value > *(ptr + mid))
            {
                low = mid + 2;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
} */

static UI16 ADC_lookup(UI16 value, const UI16 *ptr, UI16 tab_leng)
{
    UI16 low, high, mid, x1, y1;
    low = 0;
    high = tab_leng - 1;
    if (value <= *ptr)
    {
        return low;
    }
    if (value >= *(ptr + high))
    {
        return high;
    }
    //
    while (low <= high)
    {
        // mid=(low+high)/2;
        mid = (low + high) >> 1;
        if (*(ptr + mid) == value)
        {
            return mid;
        }
        else if (*(ptr + mid) > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (value < *(ptr + mid))
    {
        x1 = *(ptr + mid) - value;
        y1 = value - *(ptr + mid - 1);
        if (x1 <= y1)
        {
            return mid;
        }
        else
        {
            return mid - 1;
        }
    }
    else
    {
        x1 = *(ptr + mid + 1) - value;
        y1 = value - *(ptr + mid);
        if (x1 <= y1)
        {
            return mid + 1;
        }
        else
        {
            return mid;
        }
    }
}

/******************************************
 * ʹ��CORA0-1392H������ʹ�õĹ�ʽ��ֵ, ��C
 * ***************************************/
static UI16 adc_tran_temp_st(UI08 temp)
{
    UI32 tmp;
    UI16 s_t;
    tmp = ((((UI32)(temp + 49)) << 16) - (UI32)(temp + 49)); //(temp+49)*65535
    tmp = (tmp * 10) / 315;
    // if (tmp % 10 >= 5)
    {
        s_t = tmp / 10 + 1;
    }
    // else
    // {
    //     s_t = tmp / 10;
    // }
    return s_t;
}

void room_temp_deal(void)
{
    Temp_room_para.AD_value = (Troom_AD_value >> 1);

    if (Temp_room_para.AD_value < 30)
    {
        Temp_room_para.status = AI_CUT;
        Temp_room_para.value_F = 0;
        Temp_room_para.value = 0;
        Temp_C_room_digit_value = 0;
    }
    else if (Temp_room_para.AD_value > 500)
    {
        Temp_room_para.status = AI_SHORT;
        Temp_room_para.value_F = 0;
        Temp_room_para.value = 0;
        Temp_C_room_digit_value = 0;
    }
    else
    {
        Temp_room_para.status = AI_NORMAL;
        Temp_room_para.value_F = 5 + ADC_lookup(Temp_room_para.AD_value, Temp_tabF_10k_3450, 154); //��5F��ʼ
        if (Temp_room_para.value_F < 32)
        {
            Temp_room_para.value = 15 - F_C(Temp_room_para.value_F);
        }
        else
        {
            Temp_room_para.value = F_C(Temp_room_para.value_F) + 15;
        }
        Temp_C_room_digit_value = adc_tran_temp_st(Temp_room_para.value_F);
    }
}

void hum_deal(void)
{
    UI08 temp_room_buf = 0;
    static UI08 count = 0;

    Hum_para.AD_value = Hum_AD_value;
    if (Hum_para.AD_value > 1006) //ֻ�ж�·
    {
        if (++count >= 3)
        {
            count = 3;
            Hum_para.status = AI_SHORT;
            Hum_para.value = 99;
        }
    }
    else if (Hum_para.AD_value < 8 && Temp_room_para.value >= 15 + 15) //ֻ�п�·, ��AD��·�ɼ�����, ��AD��4��Ϊ5
    {
        if (++count >= 3)
        {
            count = 3;
            Hum_para.status = AI_CUT;
            Hum_para.value = 0;
        }
    }
    else
    {
        if (count > 0)
        {
            count--;
        }
        else
        {
            Hum_para.status = AI_NORMAL;
            // hum_tab���¶ȴ�5~45C, ��41���¶�
            if (Temp_room_para.value <= 5 + 15)
            {
                temp_room_buf = 0;
            }
            else if (Temp_room_para.value >= 45 + 15)
            {
                temp_room_buf = 40;
            }
            else
            {
                temp_room_buf = Temp_room_para.value - 15 - 5;
            }
            Hum_para.value = (UI08)(ADC_lookup(Hum_para.AD_value, hum_tab[temp_room_buf], 71) + 20);
        }
    }
}

/*************************************************
 // ��������    : void ADC_deal(void)
 // ��������    : �¶ȴ�����
 // ��ڲ���    : ��
 // ���ڲ���    : ��
***************************************************/
void ADC_deal(void)
{
    ADC_Sample();
}
