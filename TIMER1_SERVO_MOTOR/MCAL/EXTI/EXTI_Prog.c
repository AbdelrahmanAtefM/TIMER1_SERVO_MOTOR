/*
 * EXTI_Prog.c
 *
 *  Created on: Oct 7, 2022
 *       Author: AbdelRahman Atef
 */
///*****************INCLUDES**********//
#include "EXTI_Int.h"


void (*EXTI_INT0_CallBack)(void);
/// **************Functions********//
///************** M_EXTI_IN0_void_EXTI_INT0EN Function to Enable INT0 ********//
void M_EXTI_IN0_void_EXTI_INT0EN(void)
{
    ///Enable internal interrupt for INT0
        SetBit(GICR_REG,INT0);
////  Interrupt 0 (INT0) Sense Control
/// Interrupt Request on Falling_Edge
#if SENSE_CONTROL   == Falling_Edge
	/// Set bit ISC01  on MCUCR_REG
	SetBit(MCUCR_REG ,ISC01);
	/// Clear bit ISC00  on MCUCR_REG
	ClrBit(MCUCR_REG ,ISC00);

#elif SENSE_CONTROL   == Rising_Edge
	/// Set bit ISC01  on MCUCR_REG
	SetBit(MCUCR_REG ,ISC01);
	/// Clear bit ISC00  on MCUCR_REG
	SetBit(MCUCR_REG ,ISC00);

#elif SENSE_CONTROL   == AnyLogical_change
	/// Set bit ISC01  on MCUCR_REG
	ClrBit(MCUCR_REG ,ISC01);
	/// Clear bit ISC00  on MCUCR_REG
	SetBit(MCUCR_REG ,ISC00);

#elif SENSE_CONTROL   == Low_Level
	/// Set bit ISC01  on MCUCR_REG
	ClrBit(MCUCR_REG ,ISC01);
	/// Clear bit ISC00  on MCUCR_REG
	ClrBit(MCUCR_REG ,ISC00);
#endif
}
///************** M_EXTI_IN0_void_EXTI_INT0EN Function to Disable INT0 ********//
void M_EXTI_IN0_void_EXTI_INT0DIS()
{
	///Disable internal interrupt
	    ClrBit(GICR_REG,INT0);
}
///************** M_EXTI_INT0_void_Set_CallBack Function ********//
void M_EXTI_INT0_void_Set_CallBack (void (*local_ptr)(void))
{
	EXTI_INT0_CallBack = local_ptr;

}

ISR(INT0_vect)
{
	EXTI_INT0_CallBack();
}
