/*
 * LCD_Int.h
 *
 *  Created on: Oct 1, 2022
 *     Author: AbdelRahman Atef
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

///*****************INCLUDES**********//
#include "LCD_Cnfg.h"
#include "LCD_Priv.h"
#include "DIO_Int.h"
#include "STD_TYPS.h"
#include <util/delay.h>
/// ***************MACROS************//
#define  NUL '\0'
/// **************PROTOTYPES********//
/// ********function To initialize the LCD as output component *****///
void H_LCD_Void_LCDInt(void);
/// ********function To Write a command to  LCD  *****///
void H_LCD_Void_LCDWriteCommand(u8);
/// ********function To Display a character on LCD   *****///
void H_LCD_Void_LCDDisplayCharacter(u8);
/// ********function To Display a String on LCD   *****///
void H_Lcd_void_LCDWriteString(u8*);
/// ********function To Display a String on LCD   *****///
void H_Lcd_void_LCDWriteNum(s32);
/// ********function To Select Row and Column	 on LCD   *****///
void H_Lcd_void_LCDGoToXY(u8,u8);
/// ********function To Display a clock format on LCD  *****///
void H_Lcd_void_LCDClockDisplay(u8,u8,u8);
/// ********function To screen LCD screen *****///
void H_Lcd_void_LCDClear(void);
#endif /* HAL_LCD_LCD_INT_H_ */
