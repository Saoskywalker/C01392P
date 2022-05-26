/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/

#ifndef __PWM1_H__
#define __PWM1_H__

#include "user.h"

void   PWM1_R0_WR(uint  pwm_r0);  //设置PWM10输出占空比寄存器
void   PWM1_R1_WR(uint  pwm_r1);  //设置PWM11输出占空比寄存器

uint   PWM1_R0_RD(void);  //读取PWM_R0值
uint   PWM1_R1_RD(void);  //读取PWM_R1值

void   PWM1_DT_WR(uchar  pwm_dt);  //设置PWM死区时间
uchar  PWM1_DT_RD(void);  //读取PWM1_DT值，16位

#endif
