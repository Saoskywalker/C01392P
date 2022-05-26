
#include "GCE_General.h"

GCE_XDATA UI08 Dust_rxd_delay = 0;            // nms后处理接收的数据
GCE_XDATA UI08 Dust_rxd_bytes = 0;            //接收到的字节
GCE_XDATA UI08 Dust_rxd_buf[RXD_TOTAL] = {0}; //接收的数据
GCE_XDATA UI08 Dust_txd_buf[TXD_TOTAL] = {0}; //发送的数据
GCE_XDATA UI08 Dust_txd_length = 0;           //发送数据的长度
GCE_XDATA UI08 Dust_txd_bytes = 0;            //当前发送数据字节长度

GCE_XDATA UI16 Dust_Sensor_Value = 0;       //灰尘传感器值
GCE_XDATA UI32 Dust_Sensor_Value_sum = 0;   //灰尘传感器值sum
GCE_XDATA UI08 Dust_Sensor_err_cont = 0;    //灰尘传感器 通信故障计数
GCE_XDATA UI08 Dust_Sensor_sample_Cont = 0; //采集空气质量传感器值的次数

void Dust_Sensor_Data_Init(void)
{
}
/***********************************************
函数名称：sum_check
函数功能：前面数据累加和  取低七位
入口参数：无
出口参数：无
备注：
************************************************/
UI08 sum_check(UI08 *buffer, UI08 length)
{
  UI08 check_sum = 0;
  UI08 i = 0;
  for (i = 0; i < length; i++)
  {
    check_sum += buffer[i];
  }
  //
  check_sum = (check_sum & 0x7f); //取低七位
  //
  return check_sum;
}
/***********************************************
函数名称：Dust_Uart_rxd
函数功能：
入口参数：无
出口参数：无
备注：
************************************************/
void Dust_Uart_rxd(void)
{
  UI08 check_sum = 0;
  UI08 i;
  UI16 Sensor_Value = 0;

  //==========================================================
  if (!Dust_Uart_rxd_ok) //接收到数据
  {
    return;
  }
  Dust_Uart_rxd_ok = 0;

  check_sum = sum_check(Dust_rxd_buf, Dust_rxd_bytes - 1);
  if (Dust_rxd_buf[Dust_rxd_bytes - 1] != check_sum)
  {
    Dust_rxd_bytes = 0; //
    return;
  }
  //清灰尘传感器故障计数
  Dust_Sensor_err_cont = 0;
  // wifi_rxd_protocol();
  if (Dust_rxd_bytes == 4) //回复灰尘值
  {
    Sensor_Value = (Dust_rxd_buf[2] & 0X7f);                 // 低 7bit
    Sensor_Value |= ((UI16)((Dust_rxd_buf[1] & 0X7f) << 7)); //高 7bit
    // Sensor_Value=999;
    if (((Dust_Sensor_Value_sum + Sensor_Value) <= 0xffffffff) && (Dust_Sensor_sample_Cont < 0xff))
    {
      Dust_Sensor_Value_sum += Sensor_Value;
      Dust_Sensor_sample_Cont++;
    }
  }
  /////
  Dust_rxd_bytes = 0;
  for (i = 0; i < RXD_TOTAL; i++)
  {
    Dust_rxd_buf[i] = 0;
  }
}

void Dust_Sensor_Err_Chack(void)
{
  if ((!_Power_Status) && (!_Self_Test)) //关机状态不检测故障(关机切断电源)
  {
    Dust_Sensor_err_cont = 0;
    _Dust_Sensor_err = 0;
  }
  //
  if (Dust_Sensor_err_cont < 0xff)
  {
    Dust_Sensor_err_cont++;
  }
  //
  if ((Dust_Sensor_err_cont >= 100) //开机状态下100ms*10=10S
      || ((_Self_Test) && (Dust_Sensor_err_cont >= 3)))
  {
    _Dust_Sensor_err = 1;
  }
  else
  {
    _Dust_Sensor_err = 0;
  }
}
/***********************************************
函数名称：Dust_Uart_Txd
函数功能：
入口参数：无
出口参数：无
备注：
************************************************/
void Dust_Uart_Txd(void)
{
  UI08 check_sum = 0;
  //自检验证自发自收
  if (!_Self_Test)
  {
    return;
  }
  //
  Dust_txd_length = 7;
  Dust_txd_bytes = 0;
  Dust_txd_buf[0] = 0xAA;
  Dust_txd_buf[1] = 0x55;
  Dust_txd_buf[2] = 0x84;
  Dust_txd_buf[3] = 0x21;
  Dust_txd_buf[4] = 0x7B;
  Dust_txd_buf[5] = 0xDE;
  check_sum = sum_check(Dust_txd_buf, Dust_txd_length - 1);
  Dust_txd_buf[6] = check_sum;

  Uart0Send_IT(Dust_txd_buf, Dust_txd_length);
}

void Prg_Dust_Sensor_100mS(void)
{
  if (!_100ms_for_Dust_Uart)
  {
    return;
  }
  _100ms_for_Dust_Uart = 0;
  Dust_Uart_Txd();
  Dust_Sensor_Err_Chack();
}
/***********************************************
函数名称：Dust_sensor_Uart
函数功能：
入口参数：无
出口参数：无
备注：
************************************************/
void Dust_sensor_Uart(void)
{
  Dust_Uart_rxd();
  Prg_Dust_Sensor_100mS();
}
