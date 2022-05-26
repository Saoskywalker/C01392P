/*********************************************************
*�ļ���:	main.c
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2019/08/08
**********************************************************/

#include "lib_uart1.h"

/*********************************************************
������:	UART_BRR_WR
��  ��:	UART����������
����ֵ: 16λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void UART1_BRR_WR(uint brr)
{
    uint tmp_data;
    tmp_data =brr>>8;
    UART1_BRL =  (uchar)brr;
    UART1_BRH =  (uchar)tmp_data;
}


/*********************************************************
������:	UART_BRR_RD
��  ��:	��ȡBRRֵ
����ֵ: ��
���ֵ: 16λֵ
����ֵ: �� 
**********************************************************/
uint UART1_BRR_RD(void)
{
    uint tmp_data;
    tmp_data = UART1_BRH;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + UART1_BRL;
    return  tmp_data;
}

/*********************************************************
������:	UART_TX_DAT
��  ��: UART��������
����ֵ: 8λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void UART1_TX_DAT(uchar tx_data)
{
    UART1_TXB = tx_data;
}


/*********************************************************
������:	UART_RX8_DAT
��  ��:	��ȡ��������
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
uchar UART1_RX8_DAT(void)
{
    uchar tmp_data;
    if((UART1_RXC & 0xc0)==0x00) 
    {
        tmp_data = UART1_RXB;
    }
    else 
    {
        tmp_data = 0xff;
        UART1_RXC &=0xfc;
        UART1_RXC |=0x01;
    }
    return  tmp_data;
}

/*********************************************************
������:	UART_RX9_DAT
��  ��:	��ȡ��������
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
uchar UART1_RX9_DAT(void)
{
    uchar tmp_data;
    tmp_data = UART1_RXC & 0xe0;
    if(tmp_data==0x00) 
    {
        tmp_data = UART1_RXB;
    }
    else 
    {
        tmp_data = 0xff;
        UART1_RXC &=0xfc;
        UART1_RXC |=0x02;
    }
    return  tmp_data;
}
