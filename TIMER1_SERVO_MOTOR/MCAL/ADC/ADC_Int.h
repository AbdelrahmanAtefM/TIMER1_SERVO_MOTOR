/*
 * ADC_Int.h
 *
 *  Created on: Nov 14, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

///*****************INCLUDES**********//
#include "ADC_Cnfg.h"
#include "ADC_Priv.h"
#include "GIE_Int.h"
#include "STD_TYPS.h"
#include "BIT_MATH.h"
#include <AVR/interrupt.h>
///********** ADC resolution is 10 bit ************//
/// ***************Prototypes************//
void M_ADC_void_AdcInt(void);
u16 M_ADC_u16_AdcRead(void);

#endif /* MCAL_ADC_ADC_INT_H_ */
