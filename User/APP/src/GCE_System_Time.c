#include "GCE_General.h"

UUI16 flag_1ms_u16={0};/*1ms 时间标志*/
UUI16 flag_10ms_u16={0};/*10ms 时间标志*/
UUI16 flag_100ms_u16={0};/*100ms 时间标志*/
UUI16 flag_1S_u16={0};/*1S 时间标志*/

UI16 _100ms_delay_flag_=0;//100ms延时标志
UI16 _10ms_delay_flag_=0;//10ms延时时标志
UI16 _1ms_delay_flag_=0;//1ms延时标志

////函数声明
void SystemTimesGenerate(void);//在中断中调用
/*************************************************
//名称        :SystemTimesGenerate
//功能        :系统标准时间生成//中断中调用
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.13
//修改记录    :2021.5.14  V0.0初版发布
************************************************/
void SystemTimesGenerate(void)//在中断中调用
{
	static UI08 sysTime10msCnt=0;//10ms计数器
	static UI08 sysTime100msCnt=0;//100ms计数器
	static UI08 sysTime1000msCnt=0;//1000ms计数器
//========================================================================
	_TEST_1MS
//========================================================================
	_1ms_delay_flag_++;
	flag_1ms_u16.word = 0xffff;//1ms时间标志
	sysTime10msCnt++;
	if(sysTime10msCnt >= 10)
	{
		sysTime10msCnt = 0;
		_10ms_delay_flag_++;

		flag_10ms_u16.word = 0xffff;//10ms时间标志
		sysTime100msCnt++;
		if(sysTime100msCnt >= 10)
		{
			sysTime100msCnt = 0;
			_100ms_delay_flag_++;

			flag_100ms_u16.word = 0xffff;//100ms时间标志
			sysTime1000msCnt++;
			if(sysTime1000msCnt >= 10)
			{
				sysTime1000msCnt = 0;
				flag_1S_u16.word = 0xffff;//1S时间标志
//========================================================================
				_TEST_1S
//========================================================================
			}
		}
	}
}



