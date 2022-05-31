
#ifndef __MOTOR_H
#define __MOTOR_H

extern GCE_XDATA UI08 Fan_PWM;

extern void Motor_Data_Init(void);
extern void Motor_deal(void);
extern void Speed_deal(void);
void FAN_PWM_Set(UI16 i);

#endif
