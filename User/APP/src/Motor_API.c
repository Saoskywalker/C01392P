
#include "GCE_General.h" //系统 通用调用文件


GCE_XDATA UI08    Motor_POWER_ON_timer=0;
GCE_XDATA UI08    Motor_POWER_OFF_timer=0;
GCE_XDATA UI16    Fan_on_timer=0;//风机运行时间
GCE_XDATA UI16    Fan_off_timer=0;
GCE_XDATA UI16    Fan_PWM_buf=0;
GCE_XDATA UI08    Fan_PWM=0;
/*************************************************
//名称        :	Motor_PID_data_init
//功能        : 变量初始化
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/
void Motor_Data_Init(void)
{
     Motor_POWER_ON_timer=0;
     Motor_POWER_OFF_timer=0;
     Fan_on_timer=0;//风机运行时间
     Fan_off_timer=0;
     Fan_PWM_buf=0;
     Fan_PWM=0;
}
/*************************************************
//名称        :	prg_s_motor
//功能        : S时间片
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
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
//名称        :	FAN_PWM_deal
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/
void FAN_PWM_deal(void)
{
      UI32 pwm_buf=0;

      if(Motor_POWER_ON_timer<5)
      {
          return;
      }

      if((Fan_PWM_buf<=30)&&(0==Fan_PWM))//关闭风机时
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
        P33_FUN_IO;//配置为普通IO
        P33_CLR;
     }
     else
     {
        P33_FUN_PWM01;//复用成PWM端口
     }
     PWM_DUTY_Set(pwm_buf);
#if 0
  Motor_CW_EN;
  Motor_POWER_ON;
  PWM_DUTY_Set(100);
#endif

}
/*************************************************
//名称        :	void Motor_15V_Deal(void)
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
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
            if(Motor_POWER_OFF_timer == 50)//5s后关闭电源
            {
               Motor_POWER_OFF;
               Motor_CCW_EN;
            }
        }



    }
}

/*************************************************
//名称        :	void Motor_deal(void)
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
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














