/*********************************************************
*�ļ���:	main.c
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2019/08/08
**********************************************************/

#include "lib_iap.h"

/*********************************************************
������:	IAP_UNLOCK
��  ��:	flash ��������
����ֵ: 
���ֵ: ��
����ֵ: 8λֵ�����1��ʾ�ɹ������0��ʾʧ�� 
**********************************************************/
uchar IAP_UNLOCK()
{
    uchar  pass;
    pass = 0;
    IAP_PR = 0xac;
    if(IAP_PR == 0X1) 
    {
        pass = 1;
    }
    else
    {
        pass = 0;
    }
    return  pass;
}

/*********************************************************
������:	IAP_LOCK
��  ��:	flash ��������
����ֵ: 
���ֵ: ��
����ֵ: 8λֵ�����1��ʾ�ɹ������0��ʾʧ�� 
**********************************************************/
uchar IAP_LOCK()
{
    uchar  pass;
    pass = 0;
    IAP_PR = 0x53;
    if(IAP_PR == 0X0)
    {
        pass = 1;
    }
    else 
    {
        pass = 0;
    }
    return  pass;
}

/*********************************************************
������:	IAP_ERASR
��  ��:	flash ����
����ֵ: ҳ������ַ
���ֵ: ��
����ֵ: 8λֵ�����1��ʾ�����ɹ������0��ʾ����ʧ�� 
**********************************************************/
uchar IAP_ERASE(uint addr)
{
    uchar  pass;
    uchar  rd_data;
    uint   IAP_tmp_addr;
    uint   i;
    uint   max_addr;
    pass = 1;
    if((addr&0x8000)==0x8000) 
    {
        IAP_AS = 0X5A;  //data flash
        max_addr = 0x100;
    }
    else 
    {
        IAP_AS = 0XA5;
        max_addr = 0x200;
    }

    IAP_AH = addr>>8;
    IAP_AL = 0X00;
    IAP_C0 = 0X01;
    IAP_C1 = 0X12;
    IAP_C0 = 0X00;
    for(i=0; i < max_addr; i = i+1) 
    {
        IAP_tmp_addr = addr + i;
        rd_data = *((uchar code *)(addr));
        if(rd_data != 0xff) 
        {
            pass = 0;
        }
    }
    return  pass;
}

/*********************************************************
������:	IAP_PROG
��  ��:	flash ���
����ֵ: ��̵�ַ16λ���������8λ
���ֵ: ��
����ֵ: 8λֵ�����1��ʾ�ɹ������0��ʾʧ�� 
**********************************************************/
uchar IAP_PROG(uint addr, uchar din)
{
    uchar  pass;
    uchar  PROG_tmp_data;
    pass = 0;
    if((addr&0x8000)==0x8000) 
    {
        IAP_AS = 0X5A;  //data flash
    }
    else 
    {
       IAP_AS = 0XA5;
    }

    IAP_AL = addr;
    IAP_AH = addr>>8;
    IAP_D = din;
    IAP_C0 = 0X01;
    IAP_C1 = 0X34;
    IAP_C0 = 0X00;
    PROG_tmp_data = *((uchar code *)(addr));
    if(PROG_tmp_data == din) 
    {
        pass = 1;
    }
    else
    {
        pass = 0;
    }
    IAP_D = 0xff;
    IAP_AH = 0xff;
    return  pass;
}


/*********************************************************
������:	IAP_DATA_RD
��  ��:	flash ����
����ֵ: ��ַ16λ
���ֵ: flash 8λ���� 
����ֵ: 
**********************************************************/
uchar IAP_DATA_RD(uint addr)
{
    uchar RD_tmp_data;
    RD_tmp_data = *((uchar code *)(addr));
    return  RD_tmp_data;
}
