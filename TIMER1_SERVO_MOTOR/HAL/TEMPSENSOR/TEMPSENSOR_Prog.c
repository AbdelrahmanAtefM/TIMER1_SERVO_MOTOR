/*
 * TEMPSENSOR_Prog.c
 *
 *  Created on: Nov 15, 2022
 *      Author: AbdelRahman Atef
 */
#include "DIO_Int.h"
#include "TEMPSENSOR_Int.h"
void H_TEMPSENSOR_void_TempSensorInt(void)
{
     M_DIO_void_SetPinDirection(PORTA_ID, PIN0, INPUT);
}
u8 H_TEMPSENSOR_void_TempSensorRead(void)
{
  u8 local_u8_AdcReading=0;
  local_u8_AdcReading = M_ADC_u16_AdcRead();
  u8 Temp =	  (((u32)local_u8_AdcReading * 500 )/1023);
  return Temp;
}
