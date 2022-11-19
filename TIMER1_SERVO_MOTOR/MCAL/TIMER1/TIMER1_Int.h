/*
 * TIMER1_Int.h
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_TIMER1_TIMER1_INT_H_
#define MCAL_TIMER1_TIMER1_INT_H_

///***************** INCLUDES **********//
#include "TIMER1_Cnfg.h"
#include "TIMER1_Prive.h"
#include "DIO_Int.h"
#include "STD_TYPS.h"
#include "BIT_MATH.h"


///***************** PROTOTYPES **********//
void M_TIMER1_void_Pwm1Int(void);
void M_TIMER1_void_Pwm1SetFrequancy(u32);
void M_TIMER1_void_Pwm1SetDutycycle(f32);
void M_TIMER1_void_Pwm1Start(void);
void M_TIMER1_void_Pwm1Stop(void);
#endif /* MCAL_TIMER1_TIMER1_INT_H_ */
