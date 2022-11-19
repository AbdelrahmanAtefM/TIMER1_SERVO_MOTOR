/*
 * KeyPad_Int.h
 *
 *  Created on: Oct 7, 2022
 *       Author: AbdelRahman Atef
 */

#ifndef HAL_KEYPAD_KEYPAD_INT_H_
#define HAL_KEYPAD_KEYPAD_INT_H_

///*****************INCLUDES**********//
#include "KeyPad_confg.h"
#include "DIO_Int.h"
#include "STD_TYPS.h"
#include <util/delay.h>
/// ***************MACROS************//

/// *************** _ Keypad models ************//
#define  MODEL_A      1
#define  MODEL_B      2

/// *************** _Select Columns PORT************//
#define COLUMNS_PORT   PORTD_ID
/// *************** _Select Columns pins************//
#define Col1_PIN     PIN2
#define Col2_PIN     PIN3
#define Col3_PIN     PIN4
#define Col4_PIN     PIN5

/// *************** _Select Rows PORT************//
#define ROWS_PORT   PORTB_ID
/// *************** _Select Rows pins************//
#define Row1_PIN    PIN0
#define Row2_PIN    PIN1
#define Row3_PIN    PIN2
#define Row4_PIN    PIN3
/// **************PROTOTYPES********//
void H_KEYPAD_void_KeyPadInt(void);
u8   H_KEYPAD_void_KeyPadRead(void);

#endif /* HAL_KEYPAD_KEYPAD_INT_H_ */
