/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
**********************************************************/

#ifndef __TMR2_H__
#define __TMR2_H__

#include "user.h"

void TMR2_WR(uint tmrn);
void TMR2_CYC_WR(uint tmrn_cyc);
uint TMR2_RD(void);
uint TMR2_CYC_RD(void);

#endif
