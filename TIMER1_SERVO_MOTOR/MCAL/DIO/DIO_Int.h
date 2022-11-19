/*
 * DIO_Int.h
 *
 *  Created on: Sep 15, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
#include "DIO_Cnfg.h"
#include "DIO_Priv.h"
#include "BIT_MATH.h"
#include "STD_TYPS.h"



/************Macros**********/

#define   INPUT      0
#define   OUTPUT     1

#define   LOW      0
#define   HIGH     1

/***************PORTS IDS**********/
#define PORTA_ID    1
#define PORTB_ID    2
#define PORTC_ID    3
#define PORTD_ID    4

/******************define Pins ID*/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7


/***********Prototypes*************/

/// Function to set pin Direction //
void M_DIO_void_SetPinDirection (u8 port , u8 pin , u8 dirction);
/// Function to set pin Value //
void M_DIO_void_SetPinValue(u8 , u8, u8);
/// Function to Toggle pin Value //
void M_DIO_void_PinTog(u8 port , u8 pin);
/// Function to Read pin Value //
u8 M_DIO_U8_PinRead(u8 port , u8 pin);

#endif /* MCAL_DIO_DIO_INT_H_ */
