
/*******************************************************************************
                                 Includes
*******************************************************************************/
#include "GCE_General.h"

/*******************************************************************************
                                 define definitions
*******************************************************************************/
#define DATA_PAGE0          0x8200 // data flash第1页

#define DATA_FLASH_ADRR_START   0x8200 // data flash第1页
#define DATA_FLASH_PAGE_NUM     1      // 共1页
#define DATA_FLASH_PAGE_LEN     128    // 128字节
#define DATA_FLASH_ADRR_END   (DATA_FLASH_START_ADRR + (DATA_FLASH_PAGE_LEN * DATA_FLASH_PAGE_NUM))

/*******************************************************************************
                                 Functions definitions
*******************************************************************************/

//******************************************************************************
// 函数名称 : Flash_PageErase
// 功能说明 : 按页擦除flash(2ms)
// 入口参数 : Addr - 页地址
// 出口参数 : 0-表示擦除成功,非0-表示擦除失败
// 当前版本 : V0.0
// 编写人员 : 曾海更
// 审核人员 : 刘磊
// 审核日期 : 2021.5.13
// 修改记录 : 2021.5.13  V0.0初版发布
//******************************************************************************
UI08 Flash_PageErase(UI16 Addr)
{
    UI16  i;
    UI08  pass = 0;
    UI08  rd_data;
    UI16  page_len;

    // 解锁flash
    IAP_PR = 0xAC;
    if(IAP_PR == 0x01)
        return 1;

    // flash区域
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

    // 擦除flash
    IAP_AH = (UI08)(Addr >> 8);
    IAP_AL = 0x00;
    IAP_C0 = 0x01; // IAP使能
    IAP_C1 = 0x12; // 启动擦除,CPU暂停
    IAP_C0 = 0x00; // IAP禁止
    for(i=0; i < page_len; i = i+1)
    {
        rd_data = *((UI08 code *)(Addr + i));
        if(rd_data != 0xFF)
            pass = 2;
    }

    // 锁定flash
    IAP_PR = 0x53;
    if(IAP_PR == 0x00)
        pass = 3;

    return  pass;
}

//******************************************************************************
// 函数名称 : Flash_Write
// 功能说明 : 按字节写flash(20us)
// 入口参数 : Addr - 地址, Dat - 数据
// 出口参数 : 0-表示写成功,非0-表示写失败
// 当前版本 : V0.0
// 编写人员 : 曾海更
// 审核人员 : 刘磊
// 审核日期 : 2021.5.13
// 修改记录 : 2021.5.13  V0.0初版发布
//******************************************************************************
UI08 Flash_Write(UI16 Addr, UI08 Dat)
{
    UI08  pass = 0;
    UI08  rd_data;

    // 解锁flash
    IAP_PR = 0xAC;
    if(IAP_PR == 0x01)
        return 1;

    // flash区域
    if((Addr & 0x8000) == 0x8000)
    {
        IAP_AS = 0x5A;  // data flash
    }
    else
    {
        IAP_AS = 0xA5; // main flash
    }

    // 写flash
    IAP_AL = (UI08)(Addr);
    IAP_AH = (UI08)(Addr >> 8);
    IAP_D = Dat;
    IAP_C0 = 0x01; // IAP使能
    IAP_C1 = 0x34; // 启动擦除,CPU暂停
    IAP_C0 = 0x00; // IAP禁止
    rd_data = *((UI08 code *)(Addr));
    if(rd_data != Dat)
        pass = 2;

    // 锁定flash
    IAP_PR = 0x53;
    if(IAP_PR == 0x00)
        pass = 3;

    return  pass;
}

//******************************************************************************
// 函数名称 : Flash_Read
// 功能说明 : 按字节读flash
// 入口参数 : Addr - 地址, Len - 长度
// 出口参数 : 无
// 当前版本 : V0.0
// 编写人员 : 曾海更
// 审核人员 : 刘磊
// 审核日期 : 2021.5.13
// 修改记录 : 2021.5.13  V0.0初版发布
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

