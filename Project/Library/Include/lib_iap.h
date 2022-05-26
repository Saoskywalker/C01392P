/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
**********************************************************/
#ifndef __IAP_H__
#define __IAP_H__

#include "user.h"

uchar IAP_UNLOCK(void);
uchar IAP_LOCK(void);

uchar IAP_ERASE(uint addr);
uchar IAP_PROG(uint addr, uchar din);

uchar IAP_DATA_RD(uint addr);


#endif
