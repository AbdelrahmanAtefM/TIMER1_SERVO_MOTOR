/*
 * TIMER1_Prog.c
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

///***************** INCLUDES **********//
#include "TIMER1_Int.h"
///***************** Functions **********//

void M_TIMER1_void_Pwm1Int(void)
{
   //// ***** To enable  pin OC1A(PD5) direction to output
   M_DIO_void_SetPinDirection(PORTD_ID, PIN5, OUTPUT);
   ////TO enable TIMER1 FAST PWM(ICR1)
	// Clear WGM10 in TCCR1A_REG
	ClrBit(TCCR1A_REG ,WGM10);
	// Set   WGM11 in TCCR1A_REG
	SetBit(TCCR1A_REG ,WGM11);
	// Set   WGM12 in TCCR1B_REG
	SetBit(TCCR1B_REG ,WGM12);
	// Set   WGM13 in TCCR1B_REG
	SetBit(TCCR1B_REG ,WGM13);

#if   TIMER1_FAST_PWM1_MODE  == NON_Inverted
	////TO enable TIMER1 FAST PWM(ICR1) NON INVERTED MODE
	// Set   COM1A1 in TCCR1A_REG
	SetBit(TCCR1A_REG ,COM1A1);
	// Clear COM1A0 in TCCR1A_REG
	ClrBit(TCCR1A_REG ,COM1A0);

#elif TIMER1_FAST_PWM1_MODE  == NON_INVERTED
	////TO enable TIMER1 FAST PWM(ICR1)  INVERTED MODE
	// Set   COM1A1 in TCCR1A_REG
	SetBit(TCCR1B_REG ,COM1A1);
	// Set COM1A0 in TCCR1A_REG
	SetBit(TCCR1A_REG ,COM1A0);
#endif

}
void M_TIMER1_void_Pwm1SetFrequancy(u32 Local_u32Frequancy)
{
    ICR1_REG = ((F_OSC * 1000000)/TIMER1_PRESCALER)/Local_u32Frequancy;
}
void M_TIMER1_void_Pwm1SetDutycycle(f32 Local_u8DutySycle)
{
#if    TIMER1_FAST_PWM1_MODE  == NON_Inverted
		OCR1A_REG = (((Local_u8DutySycle * ICR1_REG)/100)-1);

#elif  TIMER1_FAST_PWM1_MODE  == Inverted

#endif
}
void M_TIMER1_void_Pwm1Start(void)
{
#if   TIMER1_PRESCALER == 1024
   ////******To select clock in 1024  Set (CS12 ,CS10) and clear (CS11) in TCCR1B_REG
	    SetBit(TCCR1B_REG , CS10);
	    ClrBit(TCCR1B_REG , CS11);
	    SetBit(TCCR1B_REG , CS12);

#elif TIMER1_PRESCALER == 256
  ////******To select clock in 256 clear (CS11 ,CS10) and Set (CS12) in TCCR1B_REG
	    ClrBit(TCCR1B_REG , CS10);
		ClrBit(TCCR1B_REG , CS11);
		SetBit(TCCR1B_REG , CS12);

#endif

}
void M_TIMER1_void_Pwm1Stop(void)
{
	////*** To stop timer clear  three bits ( CS12 ,CS11 ,CS10) in TCCR1B_REG
	 ClrBit(TCCR1B_REG , CS10);
	 ClrBit(TCCR1B_REG , CS11);
	 ClrBit(TCCR1B_REG , CS12);

}
