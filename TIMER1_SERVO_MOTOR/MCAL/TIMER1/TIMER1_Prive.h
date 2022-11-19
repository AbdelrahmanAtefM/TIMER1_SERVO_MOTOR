/*
 * TIMER1_Prive.h
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_TIMER1_TIMER1_PRIVE_H_
#define MCAL_TIMER1_TIMER1_PRIVE_H_

///***************** Macros **********//

///***************** TIMER1 Registers  **********//
#define  TCCR1A_REG    *((volatile u8 *)0X4F)
#define  WGM10         0
#define  WGM11         1
#define  COM1A0        6
#define  COM1A1        7

#define  TCCR1B_REG    *((volatile u8 *)0X4E)
#define  CS10          0
#define  CS11          1
#define  CS12          2
#define  WGM12         3
#define  WGM13         4



#define OCR1A_REG      *((volatile u16 *)0X4A)

#define ICR1_REG       *((volatile u16 *)0X46)


////********* Select FAST PWM1 MODE
#define  NON_Inverted  1
#define  Inverted      2

#endif /* MCAL_TIMER1_TIMER1_PRIVE_H_ */
