/**
  ******************************************************************************
  * @file interrupt.c
  *
  ******************************************************************************
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "GCE_General.h" //系统 通用调用文件
/*************************************************
全局变量
************************************************/

/****************************************
 * 中断入口
 * ************************************/
 /*************************************************
//名称        :interrupt_INT0_VECTOR
//功能        :中断向量0服务函数//外中断0中断服务函数
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.12
//修改记录    :2021.5.13  V0.0初版发布
************************************************/
void Interrupt_INT0_VECTOR(void) interrupt 0
{
 	EINT0n_IF=_0000_0000;
#if(GCE_EXT0_EN)
	GCE_EXT0_IT();
#endif
	_TEST_INT0_IT
	//INT0_IF = 0;硬件清零
}

void Interrupt_INT1_VECTOR(void) interrupt 2
{
	EINT1n_IF=_0000_0000;
#if(GCE_EXT1_EN)
	GCE_EXT1_IT();
#endif
	_TEST_INT1_IT
	//INT1_IF = 0;硬件清零
}

/*************************************************
//名称        :interrupt_INT2_VECTOR
//功能        :中断向量2服务函数//定时器0中断服务函数
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.12
//修改记录    :2021.5.13  V0.0初版发布
************************************************/
void Interrupt_INT2_VECTOR(void) interrupt 7
{
#if(!SYSCLK_EN)
	static UI08 Timer0_Cnt=0;
#endif

	if (TMR0_IF) //定时器0//1ms中断
	{
	    TMR0_IF = 0;
#if(GCE_TIMER0_IT_EN)
	    GCE_Timer0_IT();
#endif


#if(SYSCLK_EN)
    SystemTimesGenerate();
#else
    Timer0_Cnt++;
    if(Timer0_Cnt>= SYSCLK_CNT)// (SYS_TIME_1MS/SYS_TIME_VALUE))//
    {
		Timer0_Cnt=0;
    	SystemTimesGenerate();
    }
#endif


	}
	//TMR1_IF = 0;
	//TMR2_IF = 0;
	//TMR3_IF = 0;
	TMRn_IF = 0;
	//INT2_IF = 0;硬件清零
}

/*************************************************
//名称        :interrupt_INT3_VECTOR
//功能        :中断向量3服务函数//UART1中断服务函数
//入口参数    :无
//出口参数    :无
//当前版本    :V0.0
//编写:       :周智伟
//审核        :刘磊
//审核日期    :2021.5.12
//修改记录    :2021.5.13  V0.0初版发布
************************************************/
void Interrupt_INT3_VECTOR(void) interrupt 8
{
	UI08 rxdata=0;

	if (RX0_IF)
	{
		rxdata=UART0_RXB;//UART1_RXB为接收字节寄存器
		RX0_IF = 0;
		_TEST_UART0_RX0_IT
#if(GCE_UART0_EN)
		if (UART_IE & bit0)
		{
			if (!(UART1_RXC & 0xc0))
			{
			#if(GCE_UART0_EN)
				UART0_RX_IT(rxdata);
			#endif
			}
			else
			{
				UART0_RXC &= 0xfc;
				UART0_RXC |= 0x01;
			}
		}
#endif
	}

	if (RX1_IF)
	{
		rxdata=UART1_RXB;//UART1_RXB为接收字节寄存器
		RX1_IF = 0;
		_TEST_UART1_RX1_IT
#if(GCE_UART1_EN)
		if (UART_IE & bit2)
		{
			if (!(UART1_RXC & 0xc0))
			{
			#if(GCE_UART1_EN)
				UART1_RX_IT(rxdata);
			#endif
			}
			else
			{
				UART1_RXC &= 0xfc;
				UART1_RXC |= 0x01;
			}
		}
#endif
	}

	if (TX0_IF)
	{
#if(GCE_UART0_EN)
		if (UART_IE & bit1)
		{
			if (!(UART0_TXC & 0xc0))
			{   //UART1_TXB为发送字节寄存器
			#if(GCE_UART0_EN)
				UART0_TXB = *GCE_Uart0.pTxBuf;
			        GCE_Uart0.pTxBuf++;
			        GCE_Uart0.Len--;
			        if(GCE_Uart0.Len == 0)
			        {
			        	UART_IE &= ~bit1;
			        }
			//#elif
			//	UART_IE &= ~bit1;
			#endif

			}
		}
#endif
		_TEST_UART0_TX0_IT
		TX1_IF = 0;
	}

	if (TX1_IF)
	{
#if(GCE_UART1_EN)
		if (UART_IE & bit3)
		{
			if (!(UART1_TXC & 0xc0))
			{   //UART1_TXB为发送字节寄存器
			#if(GCE_UART1_EN)
				UART1_TXB = *GCE_Uart1.pTxBuf;
			        GCE_Uart1.pTxBuf++;
			        GCE_Uart1.Len--;
			        if(GCE_Uart1.Len == 0)
			        {
			        	UART_IE &= ~bit3;
			        }
			#else
				UART_IE &= ~bit3;
			#endif
			}
		}
#endif
		_TEST_UART1_TX1_IT
		TX1_IF = 0;
	}
	//INT3_IF = 0;硬件清零
}

void Interrupt_INT4_VECTOR(void) interrupt 9
{

	if (TK_IF == 1)
	{
/*		tk_data_store(); //SensorCounted = SensorCounted + 1;由于第一次进中断为手动置气标准位，故该值被去除
		if (SensorCounted >= AllSensorNums)
		{																				 //所有按键均完成一轮扫描
			TKThreshold_ini();															 //再次确认阈值是否正确
			tk_key = TK_key_out(AllSensorNums, 5, HP_MOOD, MAX_KEY_MUL, MKEY_LIMIT_CNT); //计算按键值
			SensorCounted = 0;
		}*/
		TK_IF = 0;
		////TK_scan(); //启动下一次扫描
	}
}

void Interrupt_INT5_VECTOR(void) interrupt 10
{

}

void Interrupt_INT6_VECTOR(void) interrupt 11
{
    if(LVD_IF)
    {
        LVD_IF = 0;
        // LVD中断处理
    }
}


/******************* (C) COPYRIGHT 2010 GCE *****END OF FILE****/
