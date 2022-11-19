/*
 * TIME0_Int.h
 *
 *  Created on: Nov 16, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_TIMER0_TIME0_INT_H_
#define MCAL_TIMER0_TIME0_INT_H_

///***************** INCLUDES **********//
#include "TIME0_Cnfg.h"
#include "TIME0_Priv.h"
#include "GIE_Int.h"
#include "BIT_MATH.h"
#include "STD_TYPS.h"
#include "DIO_Int.h"
#include <avr/interrupt.h>

///***************** PROTOTYPES **********//
void M_TIMER0_void_Timer0Int(void);
void M_TIMER0_U8_Timer0SetTime(u32);
void M_TIMER0_void_Timer0Start(void);
void M_TIMER0_void_Timer0Stop(void);
void M_TIMER0_void_Timer0SetCallBack(void (*)(void));

////********************* TIMER0_PWM_MODE *************************///
void M_TIMER0_void_Pwm0Int(void);
void M_TIMER0_void_Pwm0SetDutyCycle(u8);
void M_TIMER0_void_Pwm0Start(void);
void M_TIMER0_void_Pwm0Stop(void);


#endif /* MCAL_TIMER0_TIME0_INT_H_ */
