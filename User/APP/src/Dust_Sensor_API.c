
#include "GCE_General.h"

GCE_XDATA UI08 Dust_rxd_delay = 0;            // nms������յ�����
GCE_XDATA UI08 Dust_rxd_bytes = 0;            //���յ����ֽ�
GCE_XDATA UI08 Dust_rxd_buf[RXD_TOTAL] = {0}; //���յ�����
GCE_XDATA UI08 Dust_txd_buf[TXD_TOTAL] = {0}; //���͵�����
GCE_XDATA UI08 Dust_txd_length = 0;           //�������ݵĳ���
GCE_XDATA UI08 Dust_txd_bytes = 0;            //��ǰ���������ֽڳ���

GCE_XDATA UI16 Dust_Sensor_Value = 0;       //�ҳ�������ֵ
GCE_XDATA UI32 Dust_Sensor_Value_sum = 0;   //�ҳ�������ֵsum
GCE_XDATA UI08 Dust_Sensor_err_cont = 0;    //�ҳ������� ͨ�Ź��ϼ���
GCE_XDATA UI08 Dust_Sensor_sample_Cont = 0; //�ɼ���������������ֵ�Ĵ���

void Dust_Sensor_Data_Init(void)
{
}
/***********************************************
�������ƣ�sum_check
�������ܣ�ǰ�������ۼӺ�  ȡ����λ
��ڲ�������
���ڲ�������
��ע��
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
  check_sum = (check_sum & 0x7f); //ȡ����λ
  //
  return check_sum;
}
/***********************************************
�������ƣ�Dust_Uart_rxd
�������ܣ�
��ڲ�������
���ڲ�������
��ע��
************************************************/
void Dust_Uart_rxd(void)
{
  UI08 check_sum = 0;
  UI08 i;
  UI16 Sensor_Value = 0;

  //==========================================================
  if (!Dust_Uart_rxd_ok) //���յ�����
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
  //��ҳ����������ϼ���
  Dust_Sensor_err_cont = 0;
  // wifi_rxd_protocol();
  if (Dust_rxd_bytes == 4) //�ظ��ҳ�ֵ
  {
    Sensor_Value = (Dust_rxd_buf[2] & 0X7f);                 // �� 7bit
    Sensor_Value |= ((UI16)((Dust_rxd_buf[1] & 0X7f) << 7)); //�� 7bit
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
  if ((!_Power_Status) && (!_Self_Test)) //�ػ�״̬��������(�ػ��жϵ�Դ)
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
  if ((Dust_Sensor_err_cont >= 100) //����״̬��100ms*10=10S
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
�������ƣ�Dust_Uart_Txd
�������ܣ�
��ڲ�������
���ڲ�������
��ע��
************************************************/
void Dust_Uart_Txd(void)
{
  UI08 check_sum = 0;
  //�Լ���֤�Է�����
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
�������ƣ�Dust_sensor_Uart
�������ܣ�
��ڲ�������
���ڲ�������
��ע��
************************************************/
void Dust_sensor_Uart(void)
{
  Dust_Uart_rxd();
  Prg_Dust_Sensor_100mS();
}
