/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_tmr2.h"

/*********************************************************
函数名:	TMR2_WR
描  述:	TMR2初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR2_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR2L =  (uchar)tmrn;
    TMR2H =  (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR2_RD
描  述:	读取TMR2
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR2_RD(void)
{
    uint tmp_data;
    tmp_data = TMR2H;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR2L;
    return  tmp_data;
}

/*********************************************************
函数名:	TMR2_CYC_WR
描  述:	TMR2周期初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR2_CYC_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR2_CYL = (uchar)tmrn;
    TMR2_CYH = (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR2_CYC_RD
描  述:	读取TMR2周期寄存器
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR2_CYC_RD(void)
{
    uint tmp_data;
    tmp_data = TMR2_CYH;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR2_CYL;
    return  tmp_data;
}
