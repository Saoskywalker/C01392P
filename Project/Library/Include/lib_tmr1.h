/*********************************************************
*��  ��:	sinomicon
*��  ��:	V1.00
*��  ע:    
**********************************************************/

#ifndef __TMR1_H__
#define __TMR1_H__

#include "user.h"

void TMR1_WR(uint tmrn);
void TMR1_CYC_WR(uint tmrn_cyc);
uint TMR1_RD(void);
uint TMR1_CYC_RD(void);

#endif
