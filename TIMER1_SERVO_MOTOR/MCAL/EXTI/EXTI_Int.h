/*
 * EXTI_Int.h
 *
 *  Created on: Oct 7, 2022
 *       Author: AbdelRahman Atef
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

///*****************INCLUDES**********//
#include "EXTI_Cnfg.h"
#include "EXTI_Priv.h"
#include "DIO_Int.h"
#include "STD_TYPS.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
/// ***************Prototypes************//

void M_EXTI_IN0_void_EXTI_INT0EN(void);
void M_EXTI_IN0_void_EXTI_INT0DIS(void);
void M_EXTI_INT0_void_Set_CallBack (void (*)(void));

#endif /* MCAL_EXTI_EXTI_INT_H_ */
