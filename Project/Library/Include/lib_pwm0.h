/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
**********************************************************/

#ifndef __PWM0_H__
#define __PWM0_H__

#include "user.h"

void PWM0_R0_WR(uint pwm_r0);  //����PWM00���ռ�ձȼĴ���
void PWM0_R1_WR(uint pwm_r1);  //����PWM01���ռ�ձȼĴ���

uint  PWM0_R0_RD(void);  //��ȡPWM_R0ֵ
uint  PWM0_R1_RD(void);  //��ȡPWM_R1ֵ

void  PWM0_DT_WR(uchar  pwm_dt);  //����PWM����ʱ��
uchar PWM0_DT_RD(void);  //��ȡPWM0_DTֵ��8λ

#endif
