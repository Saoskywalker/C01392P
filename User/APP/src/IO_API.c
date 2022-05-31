#include "GCE_General.h"

GCE_XDATA Str_IO Water_Status; //水满开关状态
GCE_XDATA Str_IO Filt_Status;  //滤网开关状态

/*************************************************
//名称        :	void water_IO_read(void)
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/
void Water_IO_Read(UI08 _conut_sum)
{
    if (Water_Status.IO_Value_Buf != WATER_IO)
    {
        Water_Status.IO_Value_Buf = WATER_IO;
        Water_Status.IO_Cnt = 0;
    }
    else
    {
        Water_Status.IO_Cnt++;
        if (Water_Status.IO_Cnt >= _conut_sum)
        {
            Water_Status.IO_Cnt = 0;
            if (Water_Status.IO_Value_Buf)
            {
                Water_Status.IO_Status = SET;
            }
            else
            {
                Water_Status.IO_Status = RESET;
            }
        }
    }
}

/*************************************************
//名称        :	void Filt_IO_Read(void)
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/

void Filt_IO_Read(UI08 _conut_sum)
{
    if (Filt_Status.IO_Value_Buf != Filt_IO)
    {
        Filt_Status.IO_Value_Buf = Filt_IO;
        Filt_Status.IO_Cnt = 0;
    }
    else
    {
        Filt_Status.IO_Cnt++;
        if (Filt_Status.IO_Cnt >= _conut_sum)
        {
            Filt_Status.IO_Cnt = 0;
            if (Filt_Status.IO_Value_Buf)
            {
                Filt_Status.IO_Status = SET;
            }
            else
            {
                Filt_Status.IO_Status = RESET;
            }
        }
    }
}

/*************************************************
//名称        :	void prg_ms_IO(void)
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/
void prg_ms10_IO(void)
{
    if (!_10ms_for_IO)
    {
        return;
    }
    _10ms_for_IO = 0;

    Water_IO_Read(10);
    Filt_IO_Read(10);
}
/*************************************************
//名称        :	DI_read
//功能        :
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE XXX
//修	改: 	GCE XXX
**************************************************/
void DI_read(void)
{
    prg_ms10_IO();
}
/*************************************************
//名称        :	DO_output
//功能        : IO 负载输出
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE XXX
//修	改: 	GCE XXX
**************************************************/
void DO_output(void)
{
    if (_COMP_Status)
    {
        COMP_ON;
    }
    else
    {
        COMP_OFF;
    }
#if 1
    if (_UVC_Status)
    {
        UVC_ON;
    }
    else
    {
        UVC_OFF;
    }
#endif
}

/*************************************************
//名称        :	void sys_off(void)
//功能        : 关闭所有负载
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/
void Sys_Off(void)
{
    FAN_PWM_Set(0);
    Motor_POWER_OFF;
    Motor_CCW_EN;
    Txd_H;
    HUM1_L;
    HUM2_L;
    COMP_OFF;
    UVC_OFF;
    EXV_UD_Out(0X00);
    //  EXV_LR_Out(0X00);
}

/*************************************************
//名称        :	void IO_operate(void)
//功能        : IO口操作
//入口参数    :	无
//出口参数    :	无
//构	建: 	GCE
//修	改: 	GCE XXX
************************************************/
void IO_operate(void)
{
    DI_read();
    DO_output();
}
/******************* (C) COPYRIGHT 2010 GCE *****END OF FILE****/
