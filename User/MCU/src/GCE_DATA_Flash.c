
/*******************************************************************************
                                 Includes
*******************************************************************************/
#include "GCE_General.h"

/*******************************************************************************
                                 define definitions
*******************************************************************************/
#define DATA_PAGE0          0x8200 // data flash��1ҳ

#define DATA_FLASH_ADRR_START   0x8200 // data flash��1ҳ
#define DATA_FLASH_PAGE_NUM     1      // ��1ҳ
#define DATA_FLASH_PAGE_LEN     128    // 128�ֽ�
#define DATA_FLASH_ADRR_END   (DATA_FLASH_START_ADRR + (DATA_FLASH_PAGE_LEN * DATA_FLASH_PAGE_NUM))

/*******************************************************************************
                                 Functions definitions
*******************************************************************************/

//******************************************************************************
// �������� : Flash_PageErase
// ����˵�� : ��ҳ����flash(2ms)
// ��ڲ��� : Addr - ҳ��ַ
// ���ڲ��� : 0-��ʾ�����ɹ�,��0-��ʾ����ʧ��
// ��ǰ�汾 : V0.0
// ��д��Ա : ������
// �����Ա : ����
// ������� : 2021.5.13
// �޸ļ�¼ : 2021.5.13  V0.0���淢��
//******************************************************************************
UI08 Flash_PageErase(UI16 Addr)
{
    UI16  i;
    UI08  pass = 0;
    UI08  rd_data;
    UI16  page_len;

    // ����flash
    IAP_PR = 0xAC;
    if(IAP_PR == 0x01)
        return 1;

    // flash����
    if((Addr & 0x8000) == 0x8000)
    {
        IAP_AS = 0x5A;  // data flash
        page_len = 0x100;
    }
    else
    {
        IAP_AS = 0xA5; // main flash
        page_len = 0x200;
    }

    // ����flash
    IAP_AH = (UI08)(Addr >> 8);
    IAP_AL = 0x00;
    IAP_C0 = 0x01; // IAPʹ��
    IAP_C1 = 0x12; // ��������,CPU��ͣ
    IAP_C0 = 0x00; // IAP��ֹ
    for(i=0; i < page_len; i = i+1)
    {
        rd_data = *((UI08 code *)(Addr + i));
        if(rd_data != 0xFF)
            pass = 2;
    }

    // ����flash
    IAP_PR = 0x53;
    if(IAP_PR == 0x00)
        pass = 3;

    return  pass;
}

//******************************************************************************
// �������� : Flash_Write
// ����˵�� : ���ֽ�дflash(20us)
// ��ڲ��� : Addr - ��ַ, Dat - ����
// ���ڲ��� : 0-��ʾд�ɹ�,��0-��ʾдʧ��
// ��ǰ�汾 : V0.0
// ��д��Ա : ������
// �����Ա : ����
// ������� : 2021.5.13
// �޸ļ�¼ : 2021.5.13  V0.0���淢��
//******************************************************************************
UI08 Flash_Write(UI16 Addr, UI08 Dat)
{
    UI08  pass = 0;
    UI08  rd_data;

    // ����flash
    IAP_PR = 0xAC;
    if(IAP_PR == 0x01)
        return 1;

    // flash����
    if((Addr & 0x8000) == 0x8000)
    {
        IAP_AS = 0x5A;  // data flash
    }
    else
    {
        IAP_AS = 0xA5; // main flash
    }

    // дflash
    IAP_AL = (UI08)(Addr);
    IAP_AH = (UI08)(Addr >> 8);
    IAP_D = Dat;
    IAP_C0 = 0x01; // IAPʹ��
    IAP_C1 = 0x34; // ��������,CPU��ͣ
    IAP_C0 = 0x00; // IAP��ֹ
    rd_data = *((UI08 code *)(Addr));
    if(rd_data != Dat)
        pass = 2;

    // ����flash
    IAP_PR = 0x53;
    if(IAP_PR == 0x00)
        pass = 3;

    return  pass;
}

//******************************************************************************
// �������� : Flash_Read
// ����˵�� : ���ֽڶ�flash
// ��ڲ��� : Addr - ��ַ, Len - ����
// ���ڲ��� : ��
// ��ǰ�汾 : V0.0
// ��д��Ա : ������
// �����Ա : ����
// ������� : 2021.5.13
// �޸ļ�¼ : 2021.5.13  V0.0���淢��
//******************************************************************************
void Flash_Read(UI16 Addr, UI08 *pBuf, UI16 Len)
{
    UI08 i;

    for(i = 0; i < Len; i++)
    {
        pBuf[i] = *((UI08 code *)(Addr + i));
    }
}

/******************************* End of File (C) ******************************/

