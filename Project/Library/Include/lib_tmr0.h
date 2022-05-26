/*********************************************************
*作  者:	sinomicon
*版  本:	V1.00
*备  注:    
**********************************************************/
#ifndef __TMR0_H__
#define __TMR0_H__

#include "user.h"

void TMR0_WR(uint tmrn);
void TMR0_CYC_WR(uint tmrn_cyc);
uint TMR0_RD(void);
uint TMR0_CYC_RD(void);

#endif
