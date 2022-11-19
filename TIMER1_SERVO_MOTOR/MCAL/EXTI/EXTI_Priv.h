/*
 * EXTI_Priv.h
 *
 *  Created on: Oct 7, 2022
 *       Author: AbdelRahman Atef
 */
#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

///*****************INCLUDES**********//
#include "EXTI_Int.h"
/// ***************MACROS************//

#define MCUCR_REG      *((volatile u8*)0x55)    /// MCU control Register
#define ISC00          0
#define ISC01          1
#define MCUCSR_REG     *((volatile u8*)0x54)    /// MCU control status Register
#define GICR_REG       *((volatile u8*)0x5B)    /// General interrupt control Register
#define INT0           6
#define SREG_REG       *((volatile u8*)0x5F)    /// status Register EG Register
#define I_BIT          7

#define GIFR_REG       *((volatile u8*)0x5A)    /// General interrupt flag Register



/// INT0 MOdes

#define  Falling_Edge        0
#define  Rising_Edge         1
#define  Low_Level           2
#define  AnyLogical_change   3


#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
