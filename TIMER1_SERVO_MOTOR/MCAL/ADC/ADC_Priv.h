/*
 * ADC_Priv.h
 *
 *  Created on: Nov 14, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

///***************** Macros **********////
///
/// ***************** ADC Registers **********////

#define  ADMUX_REG       (*(volatile u8*)0x27)
#define  REFS1           7
#define  REFS0           6
#define  ADLAR           5
#define  MUX0            0
#define  MUX1            1
#define  MUX2            2
#define  MUX3            3
#define  MUX4            4
#define  ADCSRA_REG      (*(volatile  u8*)0x26)
#define  ADEN            7
#define  ADSC            6
#define  ADIF            4
#define  ADPS0           0
#define  ADPS1           1
#define  ADPS2           2
#define  ADATE           5
#define  ADIE            3

#define  SFIOR_REG       (*(volatile  u8*)0x50)
#define  ADTS2           7
#define  ADTS1           6
#define  ADTS0           5

#define  ADCL_REG        (*(volatile  u8*)0x24)
#define  ADCH_REG        (*(volatile  u8*)0x25)
#define  ADC_REG         (*(volatile  u16*)0x24)



//// ***************** voltage reference  **********////

#define   AVCC                    1
#define   INTERNAL_2v_VREF        2
#define   AREF_PIN                3

//// ***************** ADC MODES  **********////
#define  ADC_INT                  1
#define  ADC_POL                  2


#endif /* MCAL_ADC_ADC_PRIV_H_ */
