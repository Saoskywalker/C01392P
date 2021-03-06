/*********************************************************
*文件名:	main.c
*作  者:	sinomicon
*版  本:	V1.00
*日  期:	2019/08/08
**********************************************************/

#include "lib_pwm2.h"

/*********************************************************
函数名:	PWM2_R0_WR
描  述:	PWM20占空比设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void PWM2_R0_WR(uint pwm_r0)
{
    uint tmp_data;
    tmp_data = pwm_r0>>8;
    PWM2_R0L = (uchar)pwm_r0;
    PWM2_R0H = (uchar)tmp_data;
}

/*********************************************************
函数名:	PWM2_R1_WR
描  述:	PWM21占空比设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void PWM2_R1_WR(uint pwm_r1)
{
    uint tmp_data;
    tmp_data = pwm_r1>>8;
    PWM2_R1L = (uchar)pwm_r1;
    PWM2_R1H = (uchar)tmp_data;
}

/*********************************************************
函数名:	PWM2_R0_RD
描  述:	读取PWM2_R0
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint PWM2_R0_RD(void)
{
    uint tmp_data;
    tmp_data = PWM2_R0H;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + PWM2_R0L;
    return  tmp_data;
}

/*********************************************************
函数名:	PWM2_R1_RD
描  述:	读取PWM2_R1
输入值: 无
输出值: 16位值
返回值: 无 
**********************************************************/
uint PWM2_R1_RD(void)
{
    uint tmp_data;
    tmp_data = PWM2_R1H;
    tmp_data = tmp_data<<8;
    tmp_data = tmp_data + PWM2_R1L;
    return  tmp_data;
}

/*********************************************************
函数名:	PWM2_DT_WR
描  述:	PWM21占空比设定
输入值: 16位值
输出值: 无
返回值: 无 
**********************************************************/
void PWM2_DT_WR(uchar pwm_dt)
{
    PWM2_DT = pwm_dt;
}

/*********************************************************
函数名:	PWM2_DT_RD
描  述:	读取PWM2_DT
输入值: 无
输出值: 8位值
返回值: 无 
**********************************************************/
uchar PWM2_DT_RD(void)
{
    uint tmp_data;
    tmp_data = PWM2_DT;
    return  tmp_data;
}


