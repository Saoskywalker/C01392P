/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_tmr0.h"

/*********************************************************
函数名:	TMR0_WR
描  述:	TMR0初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR0_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data =tmrn>>8;
    TMR0L =  (uchar)tmrn;
    TMR0H =  (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR0_RD
描  述:	读取TMR0
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR0_RD(void)
{
    uint tmp_data;
    tmp_data = TMR0H;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR0L;
    return  tmp_data;
}

/*********************************************************
函数名:	TMR0_CYC_WR
描  述:	TMR0周期初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR0_CYC_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR0_CYL = (uchar)tmrn;
    TMR0_CYH = (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR0_CYC_RD
描  述:	读取TMR0周期寄存器
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR0_CYC_RD(void)
{
    uint tmp_data;
    tmp_data = TMR0_CYH;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR0_CYL;
    return  tmp_data;
}
