#include "GCE_General.h"

GCE_XDATA UI08 Communication_Count_Timer = 160;   //ͨ�Ź��ϱ���
GCE_XDATA UI08 Communication_Delay_Txd_Timer = 0; //���յ����ݺ���ʱһ��ʱ����ٷ�������
/*****************************************************************************
//����        : prg_ms10_Comm
//����        : 1msʱ��Ƭ
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Prg_Communication_10mS(void)
{
    if (!_10ms_for_Com)
    {
        return;
    }
    _10ms_for_Com = 0;
    //
    if (Communication_Delay_Txd_Timer > 0)
    {
        Communication_Delay_Txd_Timer--;
        if (0 == Communication_Delay_Txd_Timer)
        {
            _txd_tick_en = 1;
        }
    }
}
/*****************************************************************************
//����        : prg_ms1_Comm
//����        : 1msʱ��Ƭ
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Prg_Communication_1S(void)
{
    if (!_1S_for_Com)
    {
        return;
    }
    _1S_for_Com = 0;
    //
    if (Communication_Count_Timer > 0)
    {
        Communication_Count_Timer--;
        if (0 == Communication_Count_Timer)
        {
            _Power_Status = 0;
        }
    }
}
/*************************************************
//����        :	void  crc_check(void)
//����        : ����У��
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE XXX
//��	��: 	GCE XXX
**************************************************/
UI08 crc_check(UI08 *buffer, UI08 length)
{
    UI08 crc = 0;
    UI08 loop = 0;
    UI08 loop_1 = 0;
    for (loop = 0; loop < length; loop++)
    {
        crc ^= buffer[loop];
        for (loop_1 = 0; loop_1 < 8; loop_1++)
        {
            if ((crc & 1) == 1)
            {
                crc = crc >> 1;
                crc ^= 0x8C;
            }
            else
            {
                crc = crc >> 1;
            }
        }
    }
    return crc;
}
/*****************************************************************************
//����        : rxd_data_protocl
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Rxd_Data_Protocl(void)
{
    UUI08 buf_bit;
    UI08 buf = 0;
    //
    buf_bit.byte = rxd_buf[1];
    _Power_Status = buf_bit.bit_.b0;
    _COMP_Status = buf_bit.bit_.b1;
    _Sleep_status_buf = buf_bit.bit_.b2;
    _Self_Test = buf_bit.bit_.b3;
    _SWING_Status = buf_bit.bit_.b6;
    _UVC_Status = buf_bit.bit_.b7;

    //��Ҷ
    buf = ((buf_bit.byte >> 4) & 0x03); //ȡbit4 bit5����
    EXV_SWING_Mode = (Swing_Mode)(buf);
    //
    Fan_PWM = rxd_buf[3]; // ��8bit

    if (rxd_buf[2] & bit7)
    {
        _Fan15V_Power_Status = 1;
    }
    else
    {
        _Fan15V_Power_Status = 0;
    }
}
/*****************************************************************************
//����        : txd_data_protocol
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Txd_Data_Protocol(void)
{
    UI08 buf = {0};
    UUI08 buf_bit = {0};
    //==============================================================
    //==================  �ظ�����װ��
    //==============================================================
    //
    txd_buf[0] = 0xaa;

    buf_bit.byte = 0;
    //��ˮ״̬
    if (Water_Status.IO_Status)
    {
        buf_bit.bit_.b0 = 1;
    }

    //˯��״̬
    if (Water_Status.IO_Status)
    {
        buf_bit.bit_.b1 = 0;
    }
    else
    {
        buf_bit.bit_.b1 = _Sleep_status_buf;
    }

    buf_bit.byte |= ((Version << 4) & 0xf0);
    //
    txd_buf[1] = buf_bit.byte;

    buf_bit.byte = 0;
    //����AD
    buf = ((Tcoil_AD_value >> 8) & 0x03);
    buf_bit.byte |= buf;

    txd_buf[3] = (UI08)(Tcoil_AD_value);

    //ѹ�����¶�AD
    buf = (((Comp_AD_value >> 8) & 0x03) << 2);
    buf_bit.byte |= buf;
    txd_buf[4] = (UI08)(Comp_AD_value);
    txd_buf[2] = buf_bit.byte; //

    //���²���ֵ
    txd_buf[5] = (UI08)(data_process.SHT30_temperature >> 8); //
    txd_buf[6] = (UI08)(data_process.SHT30_temperature);      //
    //ʪ��ֵ
    txd_buf[7] = (data_process.SHT30_humidity) & 0X7F; //
    //��ʪ�ȴ���������
    if (SHT30_err_Status)
    {
        txd_buf[7] |= bit7;
    }
    //
    txd_buf[8] = 0; //�߰�λ
    txd_buf[9] = 0; //�Ͱ�λ
    txd_buf[txd_length - 1] = crc_check(txd_buf, txd_length - 1);
}
/*****************************************************************************
//����        : communication_rxd
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Communication_Rxd(void)
{
    UI08 sum = 0;
    if (!_Rxd_OK)
    {
        return;
    }
    _Rxd_OK = 0;
    //
    if (rxd_buf[0] != 0xaa)
    {
        return;
    }
    //
    sum = crc_check(rxd_buf, rece_data_lenth - 1);
    if (rxd_buf[rece_data_lenth - 1] != sum)
    {
        return;
    }
    //
    Rxd_Data_Protocl();
    //
    Communication_Count_Timer = 160;

    Communication_Delay_Txd_Timer = 2;
}
/*****************************************************************************
//����        : communication_txd
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Communication_Txd(void)
{
    //˯��״̬��  ����ˮ����������˯�� ���200ms
    if ((Water_Status.IO_Status) && (_Sleep_status_buf) && (_1S_TXD_delay))
    {
        _txd_tick_en = 1;
        _1S_TXD_delay = 0;
    }

    //

    if (!_txd_tick_en)
    {
        return;
    }
    _txd_tick_en = 0;
    //

    //==============================================================
    //==================  �ظ�����װ��
    //==============================================================
    Txd_Data_Protocol();
    //==============================================================

    _txd_data = 0;
    _txd_end = 0;
    pulse_cnt = 0;
    _txd_start = 1;
    _txd_en = 1;
}
/*****************************************************************************
//����        : communication_Deal
//����        :
//��ڲ���    :	��
//���ڲ���    :	��
//��	��: 	GCE
//��	��: 	GCE
*****************************************************************************/
void Communication_Deal(void)
{
    Prg_Communication_10mS();
    Prg_Communication_1S();
    Communication_Rxd();
    Communication_Txd();
}
