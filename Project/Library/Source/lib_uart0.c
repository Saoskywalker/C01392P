/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_uart0.h"

/*********************************************************
函数名:	UART_BRR_WR
描  述:	UART波特率设置
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void UART0_BRR_WR(uint brr)
{
    uint tmp_data;
    tmp_data =brr>>8;
    UART0_BRL =  (uchar)brr;
    UART0_BRH =  (uchar)tmp_data;
}


/*********************************************************
函数名:	UART_BRR_RD
描  述:	读取BRR值
输入值: 无
输出值: 16位值
返回值: 无 
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
函数名:	UART_TX_DAT
描  述: UART发送数据
输入值: 8位值
输出值: 无
返回值: 无 
**********************************************************/
void UART0_TX_DAT(uchar tx_data)
{
	while(TX0_IF==0){};
    UART0_TXB = tx_data;
}


/*********************************************************
函数名:	UART_RX8_DAT
描  述:	读取接收数据
输入值: 无
输出值: 8位值
返回值: 无 
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
函数名:	UART_RX9_DAT
描  述:	读取接收数据
输入值: 无
输出值: 8位值
返回值: 无 
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
