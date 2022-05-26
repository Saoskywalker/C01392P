#include "GCE_General.h"

UUI16 flag_1ms_u16={0};/*1ms ʱ���־*/
UUI16 flag_10ms_u16={0};/*10ms ʱ���־*/
UUI16 flag_100ms_u16={0};/*100ms ʱ���־*/
UUI16 flag_1S_u16={0};/*1S ʱ���־*/

UI16 _100ms_delay_flag_=0;//100ms��ʱ��־
UI16 _10ms_delay_flag_=0;//10ms��ʱʱ��־
UI16 _1ms_delay_flag_=0;//1ms��ʱ��־

////��������
void SystemTimesGenerate(void);//���ж��е���
/*************************************************
//����        :SystemTimesGenerate
//����        :ϵͳ��׼ʱ������//�ж��е���
//��ڲ���    :��
//���ڲ���    :��
//��ǰ�汾    :V0.0
//��д:       :����ΰ
//���        :����
//�������    :2021.5.13
//�޸ļ�¼    :2021.5.14  V0.0���淢��
************************************************/
void SystemTimesGenerate(void)//���ж��е���
{
	static UI08 sysTime10msCnt=0;//10ms������
	static UI08 sysTime100msCnt=0;//100ms������
	static UI08 sysTime1000msCnt=0;//1000ms������
//========================================================================
	_TEST_1MS
//========================================================================
	_1ms_delay_flag_++;
	flag_1ms_u16.word = 0xffff;//1msʱ���־
	sysTime10msCnt++;
	if(sysTime10msCnt >= 10)
	{
		sysTime10msCnt = 0;
		_10ms_delay_flag_++;

		flag_10ms_u16.word = 0xffff;//10msʱ���־
		sysTime100msCnt++;
		if(sysTime100msCnt >= 10)
		{
			sysTime100msCnt = 0;
			_100ms_delay_flag_++;

			flag_100ms_u16.word = 0xffff;//100msʱ���־
			sysTime1000msCnt++;
			if(sysTime1000msCnt >= 10)
			{
				sysTime1000msCnt = 0;
				flag_1S_u16.word = 0xffff;//1Sʱ���־
//========================================================================
				_TEST_1S
//========================================================================
			}
		}
	}
}



