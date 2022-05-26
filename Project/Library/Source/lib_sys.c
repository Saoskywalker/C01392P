/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_sys.h"

/*********************************************************
函数名:	HRC_OP
描  述:	选择内部HRC时钟
输入值: 无
输出值: 无
返回值: 无 
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
函数名:	XOSC_OP
描  述:	选择外部晶振时钟
输入值: 无
输出值: 无
返回值: 无 
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
函数名:	LRC_OP
描  述:	选择LRC低频时钟
输入值: 无
输出值: 无
返回值: 无 
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



