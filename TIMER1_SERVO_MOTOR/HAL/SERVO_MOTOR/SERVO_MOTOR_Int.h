/*
 * SERVO_MOTOR_Int.h
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef HAL_SERVO_MOTOR_SERVO_MOTOR_INT_H_
#define HAL_SERVO_MOTOR_SERVO_MOTOR_INT_H_

///***************** INCLUDES **********//
#include "TIMER1_Int.h"
#include "STD_TYPS.h"


///***************** PROTOTYPES **********//
void H_SERVOMOTOR_void_ServoMotorInt(void);
void H_SERVOMOTOR_void_ServoMotorSetAngel(u8);
void H_SERVOMOTOR_void_ServoMotorStart(void);
void H_SERVOMOTOR_void_ServoMotorStop(void);


#endif /* HAL_SERVO_MOTOR_SERVO_MOTOR_INT_H_ */
