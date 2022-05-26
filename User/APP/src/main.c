/*************************************************
//名称        :main
//功能        :主程序
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.13
//修改记录    :2021.5.21  V0.0初版发布
************************************************/
//========================================================================
//修改记录V0.1
//========================================================================
#include "GCE_General.h" //系统 通用调用文件

GCE_XDATA  UI08 M_Power_Delay_Time=0;

void delay(UI16 i)
{
   while(i--);
}
//UI08 pwer_delay_time = 3;
void main(void)
{
	//P0_OE=_0011_1111;//测试引脚配置为输出
	MCU_Initial();//MCU初始化
	//_TEST_INIT_TIME;

    Sys_Off();
	Comm_input_init;
   /* while(pwer_delay_time > 0)
    {
        if(_1S_for_TEST)
        {
          _1S_for_TEST = 0;
            pwer_delay_time--;
        }
    }*/

	while (1)
	{ //无操作时，10s后自动进入低功耗模式，程序处理在中断里，查看lp_mode设置为1
		GCE_CLRWDT(); //清WDT, reset system
		ADC_deal();
		Sht30_Deal();
		EXV_Control();
		Motor_deal();
		Communication_Deal();
		IO_operate();
		General_Func_Deal();

        if(_Sleep_status)
        {
      
            delay(20);
         
            GCE_CLRWDT(); //清WDT,
          
            MCU_Enter_Sleep();
           
            
            //_Sleep_status = 0;
            M_Sleep_Delay_Time=5;
           
        }       
        Sleep_deal();
	}
}


