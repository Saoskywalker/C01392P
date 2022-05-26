/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/

#ifndef __PWM0_H__
#define __PWM0_H__

#include "user.h"

void PWM0_R0_WR(uint pwm_r0);  //设置PWM00输出占空比寄存器
void PWM0_R1_WR(uint pwm_r1);  //设置PWM01输出占空比寄存器

uint  PWM0_R0_RD(void);  //读取PWM_R0值
uint  PWM0_R1_RD(void);  //读取PWM_R1值

void  PWM0_DT_WR(uchar  pwm_dt);  //设置PWM死区时间
uchar PWM0_DT_RD(void);  //读取PWM0_DT值，8位

#endif
