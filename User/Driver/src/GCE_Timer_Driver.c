#include "GCE_General.h" //ϵͳ ͨ�õ����ļ�
/* Private defines -----------------------------------------------------------*/

UI08  mS_Count=0;
#if(GCE_TIMER0_IT_EN)
/*************************************************
//����        :GCE_Timer0_IT
//����        :��ʱ��0�жϴ�����
//��ڲ���    :��
//���ڲ���    :��
//��ǰ�汾    :V0.0
//��д:       :����ΰ
//���        :����
//�������    :2021.6.5
//�޸ļ�¼    :2021.6.5  V0.0���淢��
************************************************/
void GCE_Timer0_IT(void)//�жϵ���
{
	_TEST_TIMER0_IT

	if(!_txd_en)
	{ Communication_Rxd_IRQ_deal();}
	else
	{Communication_Txd_IRQ();}

    mS_Count++;
	if(mS_Count>=8)
	{
        mS_Count=0;
        if(Uart0_rxd_delay>0)
        {
            Uart0_rxd_delay--;
            if(Uart0_rxd_delay==0)
            {
                Uart0_Rxd_Ok=1;
            }
        }

	    EXV_UD_run();
	}

}
#endif///GCE_TIMER0_IT_EN///

