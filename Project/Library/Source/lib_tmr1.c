/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_tmr1.h"

/*********************************************************
函数名:	TMR1_WR
描  述:	TMR1初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR1_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR1L =  (uchar)tmrn;
    TMR1H =  (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR1_RD
描  述:	读取TMR1
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR1_RD(void)
{
    uint tmp_data;
    tmp_data = TMR1H;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR1L;
    return  tmp_data;
}

/*********************************************************
函数名:	TMR1_CYC_WR
描  述:	TMR1周期初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR1_CYC_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR1_CYL = (uchar)tmrn;
    TMR1_CYH = (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR1_CYC_RD
描  述:	读取TMR1周期寄存器
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR1_CYC_RD(void)
{
    uint tmp_data;
    tmp_data = TMR1_CYH;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR1_CYL;
    return  tmp_data;
}
