/*
 * LCD_Priv.h
 *
 *  Created on: Oct 1, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef HAL_LCD_LCD_PRIV_H_
#define HAL_LCD_LCD_PRIV_H_


#define   _8_bit_mode_Command    0x38

#define   Clear_screen           0x01
#define   DisplayON_CursorOFF    0x0c
#define   Return_Home            0x02

#define _4_bit_mode_Command1     0x33
#define _4_bit_mode_Command2     0x32
#define _4_bit_mode_Command3     0x28

#define  SET_ROW0_COL0    0x80
#define  SET_ROW1_COL0    0xC0

#endif /* HAL_LCD_LCD_PRIV_H_ */
