
#include "GCE_General.h" //ϵͳ ͨ�õ����ļ�


GCE_XDATA UI08    Motor_POWER_ON_timer=0;
GCE_XDATA UI08    Motor_POWER_OFF_timer=0;
GCE_XDATA UI16    Fan_on_timer=0;//�������ʱ��
GCE_XDATA UI16    Fan_off_timer=0;
GCE_XDATA UI16    Fan_PWM_buf=0;
GCE_XDATA UI08    Fan_PWM=0;
/*************************************************
//����        :	Motor_PID_data_init
//����        : ������ʼ��
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE XXX
************************************************/
void Motor_Data_Init(void)
{
     Motor_POWER_ON_timer=0;
     Motor_POWER_OFF_timer=0;
     Fan_on_timer=0;//�������ʱ��
     Fan_off_timer=0;
     Fan_PWM_buf=0;
     Fan_PWM=0;
}
/*************************************************
//����        :	prg_s_motor
//����        : Sʱ��Ƭ
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE XXX
************************************************/
void prg_s_motor(void)
{
    if(!_1S_for_Motor)
    {return;}
    _1S_for_Motor=0;
    //
    if(Fan_PWM_buf>0)
    {
    	if(Fan_on_timer<0xffff)
        {Fan_on_timer++;}
	Fan_off_timer=0;
    }
    else
    {
    	if(Fan_off_timer<0xffff)
        {Fan_off_timer++;}
        Fan_on_timer=0;
    }


}




/*************************************************
//����        :	FAN_PWM_deal
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE XXX
************************************************/
void FAN_PWM_deal(void)
{
      UI32 pwm_buf=0;

      if(Motor_POWER_ON_timer<5)
      {
          return;
      }

      if((Fan_PWM_buf<=30)&&(0==Fan_PWM))//�رշ��ʱ
      {
          Fan_PWM_buf=0;
      }
      else if(Fan_PWM!=Fan_PWM_buf)
      {

          if(Fan_PWM_buf<=Fan_PWM)
          {
               if((Fan_PWM_buf+3)>=Fan_PWM)
               {
                  Fan_PWM_buf=Fan_PWM;
               }
               else
               {
                  Fan_PWM_buf=Fan_PWM_buf+3;
               }
          }
          else
          {
               if(Fan_PWM_buf<=(Fan_PWM+3))
               {
                  Fan_PWM_buf=Fan_PWM;
               }
               else
               {
                  Fan_PWM_buf-=3;
               }
          }
      }


     pwm_buf=PWM0_PERIOD_VALUE;
     pwm_buf=pwm_buf*Fan_PWM_buf/200;
     if(pwm_buf>PWM0_PERIOD_VALUE)
     {pwm_buf=PWM0_PERIOD_VALUE;}

     if(pwm_buf==0)
     {
        P33_FUN_IO;//����Ϊ��ͨIO
        P33_CLR;
     }
     else
     {
        P33_FUN_PWM01;//���ó�PWM�˿�
     }
     PWM_DUTY_Set(pwm_buf);
#if 0
  Motor_CW_EN;
  Motor_POWER_ON;
  PWM_DUTY_Set(100);
#endif

}
/*************************************************
//����        :	void Motor_15V_Deal(void)
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE XXX
************************************************/
void Motor_Power_Deal(void)
{

    if((0!=Fan_PWM_buf)||(0!=Fan_PWM))
    {
    	Motor_POWER_ON;
        Motor_CW_EN;
        Motor_POWER_OFF_timer=0;
        if(Motor_POWER_ON_timer<0xff)
        {
            Motor_POWER_ON_timer++;
        }
       //
    }
    else
    {
        Motor_POWER_ON_timer=0;
        if(Motor_POWER_OFF_timer<0xff)
        {
            Motor_POWER_OFF_timer++;
            if(Motor_POWER_OFF_timer == 50)//5s��رյ�Դ
            {
               Motor_POWER_OFF;
               Motor_CCW_EN;
            }
        }



    }
}

/*************************************************
//����        :	void Motor_deal(void)
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE XXX
************************************************/
void Motor_deal(void)
{
     prg_s_motor();
    if(!_100ms_for_Motor)
    {return;}
    _100ms_for_Motor=0;
    Motor_Power_Deal();
    FAN_PWM_deal();


}














