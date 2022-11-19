/*
 * KeyPad_prog.c
 *
 *  Created on: Oct 7, 2022
 *       Author: AbdelRahman Atef
 */
///*****************INCLUDES**********//

#include "KeyPad_Int.h"

///*****************Functions**********//

void H_KEYPAD_void_KeyPadInt(void)
{

	///***************** _ Set Row Pins Direction as input**********//
	M_DIO_void_SetPinDirection(ROWS_PORT, Row1_PIN, OUTPUT);  ///Set_Row_1_Pin_Direction
	M_DIO_void_SetPinDirection(ROWS_PORT, Row2_PIN, OUTPUT);  ///Set_Row_2_Pin_Direction
	M_DIO_void_SetPinDirection(ROWS_PORT, Row3_PIN, OUTPUT);  ///Set_Row_3_Pin_Direction
	M_DIO_void_SetPinDirection(ROWS_PORT, Row4_PIN, OUTPUT);  ///Set_Row_4_Pin_Direction

	///***************** _ Set Columns Pins Direction as input**********//
	M_DIO_void_SetPinDirection(COLUMNS_PORT, Col1_PIN, INPUT);  ///Set_Column_1_Pin_Value
	M_DIO_void_SetPinDirection(COLUMNS_PORT, Col2_PIN, INPUT);  ///Set_Column_2_Pin_Value
	M_DIO_void_SetPinDirection(COLUMNS_PORT, Col3_PIN, INPUT);  ///Set_Column_3_Pin_Value
	M_DIO_void_SetPinDirection(COLUMNS_PORT, Col4_PIN, INPUT);  ///Set_Column_4_Pin_Value

	///***************** _ Set Row Pins Value to HIGH **********//
	M_DIO_void_SetPinValue(ROWS_PORT, Row1_PIN, HIGH);  ///Set_Row_1_Pin_Direction
	M_DIO_void_SetPinValue(ROWS_PORT, Row2_PIN, HIGH);  ///Set_Row_2_Pin_Direction
	M_DIO_void_SetPinValue(ROWS_PORT, Row3_PIN, HIGH);  ///Set_Row_3_Pin_Direction
	M_DIO_void_SetPinValue(ROWS_PORT, Row4_PIN, HIGH);  ///Set_Row_4_Pin_Direction



}
u8 H_KEYPAD_void_KeyPadRead(void)
{
#if KEYPAD_MODEDL == MODEL_A

	u8 Local_u8_Arr [4][4]= {{'1','2','3','A'},
			                 {'4','5','6','B'},
							 {'7','8','9','C'},
							 {'*','0','#','D'}};
#elif KEYPAD_MODEDL == MODEL_B
	u8 Local_u8_Arr [4][4]= {{'1','2','3','A'},
			                 {'4','5','6','B'},
							 {'7','8','9','C'},
							 {'*','0','#','D'}};
#endif
	u8 Local_u8_Col =0;            /// local columns counter
	u8 Local_u8_Row =0;            /// local Rows counter
    u8 Local_u8_Read = RELEASED;  /// local variable to read the button status

///NOTE: To use this code you have to connect columns & Rows sequential pins in the same port***//
	/////for loop to read the value of the four Rows ////////
	for (Local_u8_Row = Row1_PIN ; Local_u8_Row <= Row4_PIN ; Local_u8_Row++ ){
		///****set Local Row value to low***********/////
		M_DIO_void_SetPinValue(ROWS_PORT, Local_u8_Row, LOW);
	/////for loop to read the value of the four columns ////////
	for(Local_u8_Col = Col1_PIN ; Local_u8_Col <= Col4_PIN ; Local_u8_Col ++ )
		{

		   ///**************Read_Local Column Pin value**********
		   /// ************** check if button is pressed********
		   if (M_DIO_U8_PinRead(COLUMNS_PORT, Local_u8_Col) == PRESSED)
		   {   ////*******delay for DEBOUNCING
			   _delay_ms(KEYPAD_DEBOUNCING_TIME);
			   /// ************** check again if button is pressed********
			    if (M_DIO_U8_PinRead(COLUMNS_PORT, Local_u8_Col) == PRESSED)
		     	{
	            ///********if button is pressed set Local_u8_Read  ********
				  Local_u8_Read =Local_u8_Arr [Local_u8_Row][Local_u8_Col - 2] ;

			    }
		   }
		}
	            ///****set Local_u8_Row value to high ***********/////
			M_DIO_void_SetPinValue(ROWS_PORT, Local_u8_Row, HIGH);
	}
    return Local_u8_Read ;
}
