/*************************************************
//����        :main
//����        :������
//��ڲ���    :��
//���ڲ���    :��
//��ǰ�汾    :V0.0
//��д:       :����ΰ
//���        :����
//�������    :2021.5.13
//�޸ļ�¼    :2021.5.21  V0.0���淢��
************************************************/
//========================================================================
//�޸ļ�¼V0.1
//========================================================================
#include "GCE_General.h" //ϵͳ ͨ�õ����ļ�

GCE_XDATA  UI08 M_Power_Delay_Time=0;

void delay(UI16 i)
{
   while(i--);
}
//UI08 pwer_delay_time = 3;
void main(void)
{
	//P0_OE=_0011_1111;//������������Ϊ���
	MCU_Initial();//MCU��ʼ��
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
	{ //�޲���ʱ��10s���Զ�����͹���ģʽ�����������ж���鿴lp_mode����Ϊ1
		GCE_CLRWDT(); //��WDT, reset system
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
         
            GCE_CLRWDT(); //��WDT,
          
            MCU_Enter_Sleep();
           
            
            //_Sleep_status = 0;
            M_Sleep_Delay_Time=5;
           
        }       
        Sleep_deal();
	}
}


