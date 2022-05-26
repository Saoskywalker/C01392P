/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/

#ifndef __TMR3_H__
#define __TMR3_H__

#include "user.h"

void TMR3_WR(uint tmrn);
void TMR3_CYC_WR(uint tmrn_cyc);
uint TMR3_RD(void);
uint TMR3_CYC_RD(void);

#endif
