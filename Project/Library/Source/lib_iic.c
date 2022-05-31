/*********************************************************
*�ļ���:	main.c
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2019/08/08
**********************************************************/

#include "lib_iic.h"

/*********************************************************
������:	IIC_BRR_WR
��  ��:	IIC����������
����ֵ: 8λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void IIC_BRR_WR(uchar brr)
{
    IIC_BRR =  brr;
}

/*********************************************************
������:	IIC_S_ADDR_WR
��  ��:	IIC�ӻ���ַ����
����ֵ: 8λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void IIC_S_ADDR_WR(uchar addr)
{
    IIC_ADDR = addr;
}

/*********************************************************
������: IIC_DATA_WR
��  ��:	IIC������������
����ֵ: 8λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void IIC_DATA_WR(uchar wr_data)
{
    while((IIC_STA & 0x04)==0X00){};
    IIC_DATA = wr_data;
}

/*********************************************************
������: IIC_M_ADDR_WR
��  ��:	IIC������������
����ֵ: 8λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void IIC_M_ADDR_WR(uchar addr, uchar w_r)
{
    uchar  tmp_data;
    tmp_data = addr<<1;
    tmp_data = tmp_data + w_r;
    while((IIC_STA & 0x04)==0X00){};
    IIC_DATA = tmp_data;
}

/*********************************************************
������:	IIC_STA_RD
��  ��:	��ȡ��������
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
uchar IIC_STA_RD(void)
{
    uchar  tmp_data;	
    tmp_data = IIC_STA;
    return  tmp_data;
}

/*********************************************************
������:	IIC_DATA_RD
��  ��:	��ȡ��������
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
uchar IIC_DATA_RD(void)
{
    uchar  tmp_data;
    tmp_data = IIC_DATA;
    return  tmp_data;
}
/*********************************************************
������:	IIC_START_TG
��  ��:	����start�ź�
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
void IIC_START_TG(void) 
{
	uint TMP_CNT = 0;
    IIC_C1 |= 0X04;
	// TMP_CNT = 0;
	while((IIC_C1&0x04)==0x04)
    {
		TMP_CNT++;
		if(TMP_CNT > 60000) 
        {
			IIC_C0 &= 0XF7;
			IIC_C0 |= 0X08;
			break;
		}
    };
}
/*********************************************************
������:	IIC_STOP_TG
��  ��:	����Stop�ź�
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
void IIC_STOP_TG(void) 
{
	uint TMP_CNT;
    IIC_C1 |= 0X08;
	TMP_CNT = 0;
	while((IIC_C1&0x08)==0x08)
    {
		TMP_CNT++;
		if(TMP_CNT > 150) 
        {
			IIC_C0 &= 0XFE;
			IIC_C0 |= 0X01;
			break;
		}
    };
    IIC_C1 &= 0xF7;
}

#if 0
void IIC_START_TG(void) 
{
    uint TMP_CNT;
    IIC_C1 |= 0X04;
    TMP_CNT = 0;
    while((IIC_C1&0x04)==0x04)
    {
        TMP_CNT = TMP_CNT + 1;
        if(TMP_CNT>60000) 
        {
            IIC_C0 &= 0XFE;
            IIC_C0 |= 0X01;
            break;
        }
    };
	//IIC0_C1 &= 0Xfb;
}

void IIC_STOP_TG(void) 
{
    uint TMP_CNT;
    IIC_C1 |= 0X08;
    TMP_CNT = 0;
    while((IIC_STA&0x20)==0x00)
    {
        TMP_CNT = TMP_CNT + 1;
        if(TMP_CNT>150) 
        {
            IIC_C0 &= 0XFE;
            IIC_C0 |= 0X01;
            break;
        }
    };
    IIC_C1 &= 0XF7;
}
#endif
