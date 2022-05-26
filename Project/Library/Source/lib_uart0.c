/*********************************************************
*�ļ���:	main.c
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ��:	2019/08/08
**********************************************************/

#include "lib_uart0.h"

/*********************************************************
������:	UART_BRR_WR
��  ��:	UART����������
����ֵ: 16λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void UART0_BRR_WR(uint brr)
{
    uint tmp_data;
    tmp_data =brr>>8;
    UART0_BRL =  (uchar)brr;
    UART0_BRH =  (uchar)tmp_data;
}


/*********************************************************
������:	UART_BRR_RD
��  ��:	��ȡBRRֵ
����ֵ: ��
���ֵ: 16λֵ
����ֵ: �� 
**********************************************************/
uint UART0_BRR_RD(void)
{
    uint tmp_data;
    tmp_data = UART0_BRH;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + UART0_BRL;
    return  tmp_data;
}

/*********************************************************
������:	UART_TX_DAT
��  ��: UART��������
����ֵ: 8λֵ
���ֵ: ��
����ֵ: �� 
**********************************************************/
void UART0_TX_DAT(uchar tx_data)
{
	while(TX0_IF==0){};
    UART0_TXB = tx_data;
}


/*********************************************************
������:	UART_RX8_DAT
��  ��:	��ȡ��������
����ֵ: ��
���ֵ: 8λֵ
����ֵ: �� 
**********************************************************/
uchar UART0_RX8_DAT(void)
{
    uchar tmp_data;
    while (RX0_IF==0){};
    if((UART0_RXC & 0xc0)==0x00) 
    {
        tmp_data = UART0_RXB;
    }
    else 
    {
        tmp_data = 0xff;
        UART0_RXC &=0xfc;
        UART0_RXC |=0x01;
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
uchar UART0_RX9_DAT(void)
{
    uchar tmp_data;
    while (RX0_IF==0){};
    tmp_data = UART0_RXC & 0xe0;
    if(tmp_data==0x00) 
    {
        tmp_data = UART0_RXB;
    }
    else 
    {
        tmp_data = 0xff;
        UART0_RXC &=0xfc;
        UART0_RXC |=0x02;
    }
    return  tmp_data;
}
