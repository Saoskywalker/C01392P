/**
  ******************************************************************************
  * @file GCE_adc.h
  * @brief This file contains all HW registers definitions and memory mapping.
  * @author STMicroelectronics - MCD Application Team
  * @version V1.1.1
  * @date 2021-6-1
  ******************************************************************************
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GCE_DATA_FLASH_H
#define __GCE_DATA_FLASH_H

#if(GCE_EEPROM_EN)

/*******************************************************************************
                                 define definitions
*******************************************************************************/
#define DATA_PAGE0          0x8200 // data flash第1页

#define DATA_FLASH_ADRR_START   0x8200 // data flash第1页
#define DATA_FLASH_PAGE_NUM     1      // 共1页
#define DATA_FLASH_PAGE_LEN     128    // 128字节
#define DATA_FLASH_ADRR_END   (DATA_FLASH_START_ADRR + (DATA_FLASH_PAGE_LEN * DATA_FLASH_PAGE_NUM))

extern UI08 Flash_PageErase(UI16 Addr);
extern UI08 Flash_Write(UI16 Addr, UI08 Dat);
extern void Flash_Read(UI16 Addr, UI08 *pBuf, UI16 Len);


#endif////GCE_EEPROM_EN

#endif /* __GCE_DATA_FLASH_H */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/

