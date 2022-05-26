/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/

#ifndef __PWM2_H__
#define __PWM2_H__

#include "user.h"

void   PWM2_R0_WR(uint  pwm_r0);  //设置PWM20输出占空比寄存器
void   PWM2_R1_WR(uint  pwm_r1);  //设置PWM21输出占空比寄存器

uint   PWM2_R0_RD(void);  //读取PWM_R0值
uint   PWM2_R1_RD(void);  //读取PWM_R1值

void   PWM2_DT_WR(uchar  pwm_dt);  //设置PWM死区时间
uchar  PWM2_DT_RD(void);  //读取PWM2_DT值，16位

#endif
