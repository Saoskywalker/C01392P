/*********************************************************
*�ļ���:	main.c
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2019/08/08
**********************************************************/

#include "lib_adc.h"

/*********************************************************
������:	ADC_DATA_RD
��  ��:	��ȡ��������
����ֵ: ��
���ֵ: 16λֵ
����ֵ: �� 
**********************************************************/
uint ADC_DATA_RD(void)
{
    uint  tmp_data;
    tmp_data = ADC_DH;
    tmp_data = tmp_data <<8;
    tmp_data = tmp_data + ADC_DL;

    return  tmp_data;
}