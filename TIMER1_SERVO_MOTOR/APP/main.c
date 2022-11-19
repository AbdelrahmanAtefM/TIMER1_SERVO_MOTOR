/*
 * main.c
 *
 *  Created on: Sep 15, 2022
 *      Author: AbdelRahman Atef
 */


///********************* Application on TIMER1 using SERVO_MOTOR ********************//


///*****************INCLUDES**********//
#include "main.h"      ///*** this is a header file to contain all includes of Application



int main ()
{

	    //// initialize Servo_motor
        H_SERVOMOTOR_void_ServoMotorInt();
        /// function to set desired  Angel
        H_SERVOMOTOR_void_ServoMotorSetAngel(180);    ///  desired angel

        //// function to start  Servo_motor
        H_SERVOMOTOR_void_ServoMotorStart();

    while (1)
       {


       }


}

