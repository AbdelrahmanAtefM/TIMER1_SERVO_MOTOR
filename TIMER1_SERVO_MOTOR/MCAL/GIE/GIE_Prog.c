/*
 * GIE_Prog.c
 *
 *  Created on: Nov 14, 2022
 *      Author:  AbdelRahman Atef
 */

/// *************** Includes ************//
#include "GIE_Int.h"

/// *************** Functions  ************//
/// M_GIE_void_GIEEn function to Enable general interrupt
void M_GIE_void_GIE_EN (void)
{
	///set I_BIT in SREG_REG
	SetBit(SREG_REG,I_BIT);
}
/// M_GIE_void_GIEDIS function to Disable general interrupt
void M_GIE_void_GIE_DIS (void)
{
	///clear I_BIT in SREG_REG
	ClrBit(SREG_REG,I_BIT);
}
