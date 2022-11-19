/*
 * main.h
 *
 *  Created on: Sep 26, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_

/// *************** Includes ************//
#include "BIT_MATH.h"          ///**********_ Bit Math operation   _*************///
#include "STD_TYPS.h"          ///**********_ Standard Types file  _*************///
#include <util/delay.h>        ///**********_     delay library    _*************///
#include "DIO_Int.h"           ///**********_     DIO              _*************///
#include "LCD_Int.h"           ///**********_     LCD              _*************///
#include "KeyPad_Int.h"        ///**********_     KeyPad           _*************///
#include "EXTI_Int.h"          ///**********_     EXT_INT0         _*************///
#include <avr/interrupt.h>
#include "GIE_Int.h"           ///**********_  General interrupt   _*************///
#include "ADC_Int.h"           ///**********_     ADC              _*************///
#include "TEMPSENSOR_Int.h"    ///**********_     TEMPSENSOR       _*************///
#include "TIME0_Int.h"         ///**********_     TIMER0           _*************///
#include "TIMER1_Int.h"        ///**********_     TIMER1           _*************///
#include "SERVO_MOTOR_Int.h"   ///**********_     SERVO_MOTOR      _*************///

/// *************** MACROS ************//



/// ************** PROTOTYPES ********//
void A_EXTI_INT0Exc(void);
void A_TIMER0_void_Timer0Exc(void);

#endif /* APP_MAIN_H_ */
