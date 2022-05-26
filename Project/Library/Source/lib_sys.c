/*********************************************************
*�ļ���:	main.c
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2019/08/08
**********************************************************/

#include "lib_sys.h"

/*********************************************************
������:	HRC_OP
��  ��:	ѡ���ڲ�HRCʱ��
����ֵ: ��
���ֵ: ��
����ֵ: �� 
**********************************************************/
void HRC_OP(void)
{
    uchar tmp_data;
    CLK_PR = 0xa5;
    CLK_C1 |= 0X01;
    tmp_data = CLK_C1;
    tmp_data = tmp_data & 0x10;
    while (CLK_C1==0x00) 
    {
        tmp_data = CLK_C1;
        tmp_data = tmp_data & 0x10;
    }
    CLK_C0 &= 0xcf; 
    while ((CLK_C1&0XC0) != 0X00) 
    {
        CLK_C0 &= 0xcf; 
    }
    CLK_PR = 0x5a;
}

/*********************************************************
������:	XOSC_OP
��  ��:	ѡ���ⲿ����ʱ��
����ֵ: ��
���ֵ: ��
����ֵ: �� 
**********************************************************/
void XOSC_OP(void)
{
    uchar tmp_data;
    CLK_PR = 0xa5;
    CLK_C1 |= 0X02;
    tmp_data = CLK_C1;
    tmp_data = tmp_data & 0x20;
    while (CLK_C1==0x00) 
    {
        tmp_data = CLK_C1;
        tmp_data = tmp_data & 0x20;
    }
    tmp_data = CLK_C0;
    tmp_data = tmp_data & 0x0f;
    tmp_data = tmp_data | 0x10;
    while ((CLK_C1&0XC0) != 0X40) 
    {
        CLK_C0 = tmp_data; 
    }
    CLK_PR = 0x5a;
}

/*********************************************************
������:	LRC_OP
��  ��:	ѡ��LRC��Ƶʱ��
����ֵ: ��
���ֵ: ��
����ֵ: �� 
**********************************************************/
void LRC_OP(void)
{
    uchar tmp_data;
    CLK_PR = 0xa5;
    tmp_data = CLK_C0;
    tmp_data = tmp_data & 0x0f;
    tmp_data = tmp_data | 0x20;
    while ((CLK_C1&0XC0) != 0X80) 
    {
        CLK_C0 = tmp_data; 
    }
    CLK_PR = 0x5a;
}



