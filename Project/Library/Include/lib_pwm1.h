/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
**********************************************************/

#ifndef __PWM1_H__
#define __PWM1_H__

#include "user.h"

void   PWM1_R0_WR(uint  pwm_r0);  //����PWM10���ռ�ձȼĴ���
void   PWM1_R1_WR(uint  pwm_r1);  //����PWM11���ռ�ձȼĴ���

uint   PWM1_R0_RD(void);  //��ȡPWM_R0ֵ
uint   PWM1_R1_RD(void);  //��ȡPWM_R1ֵ

void   PWM1_DT_WR(uchar  pwm_dt);  //����PWM����ʱ��
uchar  PWM1_DT_RD(void);  //��ȡPWM1_DTֵ��16λ

#endif
