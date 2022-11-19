/*
 * LCD_Cnfg.h
 *
 *  Created on: Oct 1, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef HAL_LCD_LCD_CNFG_H_
#define HAL_LCD_LCD_CNFG_H_

///*****************INCLUDES**********//
#include "LCD_Int.h"

/// ***************MACROS************//
/// ************SELECT LCD DATA PORT *******///
#define LCD_DATA_PORT   PORTB
/// ************SELECT LCD DATA PINS *******///
#define LCD_DATA_PORT_PIN  PORTB_ID
#define LCD_DATA0_PIN   PIN0
#define LCD_DATA1_PIN   PIN1
#define LCD_DATA2_PIN   PIN2
#define LCD_DATA3_PIN   PIN3
#define LCD_DATA4_PIN   PIN4
#define LCD_DATA5_PIN   PIN5
#define LCD_DATA6_PIN   PIN6
#define LCD_DATA7_PIN   PIN7
#define LCD_DATA8_PIN   PIN8

///************SELECT LCD EN & RS PORT *******///
#define LCD_EN_PORT      PORTD_ID
#define LCD_RS_PORT      PORTD_ID
///************SELECT LCD EN & RS PINS *******///
#define LCD_EN_PIN      PIN7
#define LCD_RS_PIN      PIN6

///************SELECT LCD_MODE *******///
#define   Activate_8_bit_mode  8
#define   Activate_4_bit_mode  4

/// Activate_8_bit_mode
///      OR
/// Activate_4_bit_mode
#define LCD_MODE Activate_4_bit_mode






#endif /* HAL_LCD_LCD_CNFG_H_ */
