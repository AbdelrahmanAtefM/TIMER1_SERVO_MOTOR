/*
 * ADC_Prog.c
 *
 *  Created on: Nov 14, 2022
 *      Author: AbdelRahman Atef
 */
///*****************INCLUDES**********//
#include "ADC_Int.h"


u16 x =0;

void M_ADC_void_AdcInt(void)
{
#if V_REF == AVCC
	/// Selecting voltage reference to AVCC
	// set REFS0 bit in ADMUX_REG
	SetBit(ADMUX_REG, REFS0);
	// clear REFS0 bit in ADMUX_REG
	ClrBit(ADMUX_REG ,REFS1);
#elif V_REF == AREF_PIN
	/// Selecting voltage reference to AREF_PIN
	// clear REFS0 bit in ADMUX_REG
	ClrBit(ADMUX_REG,REFS0);
	// clear REFS0 bit in ADMUX_REG
	ClrBit(ADMUX_REG ,REFS1);
#elif V_REF ==  INTERNAL_2v_VREF
	/// Selecting voltage reference to INTERNAL_VREF
	// set REFS0 bit in ADMUX_REG
	SetBit(ADMUX_REG,REFS0);
	// set REFS0 bit in ADMUX_REG
	SetBit(ADMUX_REG ,REFS1);
#endif
	/// selecting Adjustment  Result
	// Clear ADLAR bit on ADMUX_REG to select right adjust result
	ClrBit(ADMUX_REG , ADLAR);
	/// selecting  channel
	// clear the four bit (MUX4 MUX3 MUX2 MUX1 MUX0 ) to select ADC0
	ClrBit(ADMUX_REG , MUX0);
	ClrBit(ADMUX_REG , MUX1);
	ClrBit(ADMUX_REG , MUX2);
	ClrBit(ADMUX_REG , MUX3);
	ClrBit(ADMUX_REG , MUX4);

	//// select  Prescaler
	// To select 128 as devision factor C the three bit (ADPS2 ADPS1 ADPS0 ) on  ADCSRA_REG to
	SetBit(ADCSRA_REG , ADPS0 );
	SetBit(ADCSRA_REG , ADPS1 );
	SetBit(ADCSRA_REG , ADPS1 );

	/// To Enable Auto Trigger mode -> free running mode
	// set ADATE bit in  ADCSRA_REG
	 SetBit(ADCSRA_REG , ADATE );
	 ClrBit(SFIOR_REG , ADTS2 );
	 ClrBit(SFIOR_REG , ADTS1 );
	 ClrBit(SFIOR_REG , ADTS0 );

	///Enable the ADC circuit
	//set bit ADEN on ADCSRA_REG
	SetBit(ADCSRA_REG , ADEN );

#if ADC_MODE ==  ADC_INT
	SetBit(ADCSRA_REG ,ADSC );     //// to start conversion
    M_GIE_void_GIE_EN();          //// to enable  general interrupt
	SetBit(ADCSRA_REG ,ADIE );   //// to enable  ADC interrupt

#endif
}
#if  ADC_MODE ==  ADC_POL
u16 M_ADC_u16_AdcRead(void)
{
	//u16 Local_u16_value = 0;
	////////to start conversion
	//set ADSC bit in  ADCSRA_REG
	SetBit(ADCSRA_REG ,ADSC );

   /// check  ADC Interrupt Flag to see if conversion completed or not
  	while(GetBit(ADCSRA_REG, ADIF) == 0);
	return ADC_REG ;
}
#elif  ADC_MODE ==  ADC_INT
ISR(ADC_vect)
{
   x = ADC_REG;
}
#endif

