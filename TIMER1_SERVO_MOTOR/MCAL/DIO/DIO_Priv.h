/*
 * DIO_Priv.h
 *
 *  Created on: Sep 15, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_

/**********************includes*********************/
#include "STD_TYPS.h"
/************************************Macros***********************************/

            /**********define registers $ Ports addresses********/

/****************PORTA Registers**************/
#define  DDRA   *((volatile  u8*)0x3A)
#define  PORTA  *((volatile  u8*)0x3B)
#define  PINA   *((volatile  u8*)0x39)

/****************PORTB Registers**************/
#define  DDRB   *((volatile  u8*)0x37)
#define  PORTB  *((volatile  u8*)0x38)
#define  PINB   *((volatile  u8*)0x36)

/****************PORTC Registers**************/
#define  DDRC   *((volatile  u8*)0x34)
#define  PORTC  *((volatile  u8*)0x35)
#define  PINC   *((volatile  u8*)0x33)

/****************PORTD Registers**************/
#define  DDRD   *((volatile  u8*)0x31)
#define  PORTD  *((volatile  u8*)0x32)
#define  PIND   *((volatile  u8*)0x30)





#endif /* MCAL_DIO_DIO_PRIV_H_ */
