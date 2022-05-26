/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_tmr3.h"

/*********************************************************
函数名:	TMR3_WR
描  述:	TMR3初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR3_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR3L =  (uchar)tmrn;
    TMR3H =  (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR3_RD
描  述:	读取TMR3
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR3_RD(void)
{
    uint tmp_data;
    tmp_data = TMR3H;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR3L;
    return  tmp_data;
}

/*********************************************************
函数名:	TMR3_CYC_WR
描  述:	TMR3周期初始值设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void TMR3_CYC_WR(uint tmrn)
{
    uint tmp_data;
    tmp_data = tmrn>>8;
    TMR3_CYL = (uchar)tmrn;
    TMR3_CYH = (uchar)tmp_data;
}


/*********************************************************
函数名:	TMR3_CYC_RD
描  述:	读取TMR3周期寄存器
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint TMR3_CYC_RD(void)
{
    uint tmp_data;
    tmp_data = TMR3_CYH;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + TMR3_CYL;
    return  tmp_data;
}
