/*
 * SERVO_MOTOR_Prog.c
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

///***************** INCLUDES **********//
#include "SERVO_MOTOR_Int.h"

////***************** FUNCTIONS **********//

////***************** Function to initialize the servo motor **********//
void H_SERVOMOTOR_void_ServoMotorInt(void)
{
	M_TIMER1_void_Pwm1Int();
	M_TIMER1_void_Pwm1SetFrequancy(50);
}
////***************** Function to set angel of the servo motor **********//
void H_SERVOMOTOR_void_ServoMotorSetAngel(u8 Local_u8Angel)
{
	f32 Local_f32DutyCycleValue = ((5.0 * Local_u8Angel) / 180.0) + 5.0;
	M_TIMER1_void_Pwm1SetDutycycle(Local_f32DutyCycleValue);
}
////***************** Function to start servo motor **********//
void H_SERVOMOTOR_void_ServoMotorStart(void)
{
	M_TIMER1_void_Pwm1Start();
}
////***************** Function to stop servo motor **********//
void H_SERVOMOTOR_void_ServoMotorStop(void)
{
	M_TIMER1_void_Pwm1Stop();
}
