/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_uart1.h"

/*********************************************************
函数名:	UART_BRR_WR
描  述:	UART波特率设置
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void UART1_BRR_WR(uint brr)
{
    uint tmp_data;
    tmp_data =brr>>8;
    UART1_BRL =  (uchar)brr;
    UART1_BRH =  (uchar)tmp_data;
}


/*********************************************************
函数名:	UART_BRR_RD
描  述:	读取BRR值
输入值: 无
输出值: 16位值
返回值: 无 
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
函数名:	UART_TX_DAT
描  述: UART发送数据
输入值: 8位值
输出值: 无
返回值: 无 
**********************************************************/
void UART1_TX_DAT(uchar tx_data)
{
    UART1_TXB = tx_data;
}


/*********************************************************
函数名:	UART_RX8_DAT
描  述:	读取接收数据
输入值: 无
输出值: 8位值
返回值: 无 
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
函数名:	UART_RX9_DAT
描  述:	读取接收数据
输入值: 无
输出值: 8位值
返回值: 无 
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
