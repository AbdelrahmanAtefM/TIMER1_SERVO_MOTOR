/*
 * LCD_Prog.c
 *
 *  Created on: Oct 1, 2022
 *      Author: AbdelRahman Atef
 */
///*****************INCLUDES**********//

#include "LCD_Int.h"
#include "STD_TYPS.h"

/// ***************MACROS************//
/// **************FUNCTIONS********//

void H_LCD_Void_LCDInt(void)
{
#if LCD_MODE == Activate_8_bit_mode    ///****8_bit_mode**********///
	///**SetPinDirection for LCD_DATA_PINS from LCD_DATA0 to LCD_DATA7 to OUTPUT////
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA0_PIN,OUTPUT ); ///LCD_DATA0_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA1_PIN,OUTPUT ); ///LCD_DATA1_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA2_PIN,OUTPUT ); ///LCD_DATA2_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA3_PIN,OUTPUT ); ///LCD_DATA3_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA4_PIN,OUTPUT ); ///LCD_DATA4_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA5_PIN,OUTPUT ); ///LCD_DATA5_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA6_PIN,OUTPUT ); ///LCD_DATA6_PIN
	M_DIO_void_SetPinDirection(LCD_DATA_PORT,LCD_DATA7_PIN,OUTPUT ); ///LCD_DATA7_PIN

	///**SetPinDirection for LCD_EN_PIN to OUTPUT////
	M_DIO_void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT );
	///**SetPinDirection for LCD_EN_PIN to OUTPUT////
	M_DIO_void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT );
	///****************  LCD Commands***********///
	H_LCD_Void_LCDWriteCommand(_8_bit_mode_Command);  /// set 8_bit_mode
	H_LCD_Void_LCDWriteCommand(DisplayON_CursorOFF);  /// set LCD DisplayON


#elif  LCD_MODE == Activate_4_bit_mode   ///****4_bit_mode**********///
	///**SetPinDirection for LCD_DATA_PINS from LCD_DATA4 to LCD_DATA7 to OUTPUT////
	M_DIO_void_SetPinDirection(PORTB_ID,LCD_DATA4_PIN,OUTPUT ); ///LCD_DATA4_PIN
	M_DIO_void_SetPinDirection(PORTB_ID,LCD_DATA5_PIN,OUTPUT ); ///LCD_DATA5_PIN
	M_DIO_void_SetPinDirection(PORTB_ID,LCD_DATA6_PIN,OUTPUT ); ///LCD_DATA6_PIN
	M_DIO_void_SetPinDirection(PORTB_ID,LCD_DATA7_PIN,OUTPUT ); ///LCD_DATA7_PIN
	///**SetPinDirection for LCD_EN_PIN to OUTPUT////
	M_DIO_void_SetPinDirection(LCD_EN_PORT,LCD_EN_PIN,OUTPUT );
	///**SetPinDirection for LCD_EN_PIN to OUTPUT////
	M_DIO_void_SetPinDirection(LCD_RS_PORT,LCD_RS_PIN,OUTPUT );
	_delay_ms(10000);   /// delay for 1 second to give LCD Microcontroller time to start
	///****************  LCD Commands***********///
	H_LCD_Void_LCDWriteCommand(_4_bit_mode_Command1);  ///
	H_LCD_Void_LCDWriteCommand(_4_bit_mode_Command2);  /// set 4_bit_mode
	H_LCD_Void_LCDWriteCommand(_4_bit_mode_Command3);  ///
	H_LCD_Void_LCDWriteCommand(DisplayON_CursorOFF);  /// set LCD DisplayON
	H_LCD_Void_LCDWriteCommand(Return_Home);         /// LCD start from home
	H_LCD_Void_LCDWriteCommand(Clear_screen);        /// Clear LCD screen

#endif
}
///***********Function to DisplayCharacter on the LCD*****8///
void H_LCD_Void_LCDDisplayCharacter(u8 Local_u8_character)
{
#if LCD_MODE == Activate_8_bit_mode  ///****8_bit_mode**********///
	///*******Set LCD_RS_PIN value to HIGH *********///
	M_DIO_void_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);
	LCD_DATA_PORT = Local_u8_character;  /// Set LCD_DATA_PORT to equal Local_u8_character
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);  /// Set LCD_EN_PIN value to HIGH
	_delay_ms(1);     /// delay for 1 millisecond
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);  /// Set LCD_EN_PIN value to LOW

#elif LCD_MODE == Activate_4_bit_mode  ///****4_bit_mode**********///
	///*******Set LCD_RS_PIN value to HIGH *********///
	M_DIO_void_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);
	///Set LCD_DATA_PORT equal Local_u8_character Shifted to left by 1 to send left part of the character
	LCD_DATA_PORT = (Local_u8_character& 0b11110000)|(LCD_DATA_PORT & 0b00001111)  ;
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);  /// Set LCD_EN_PIN value to HIGH
	_delay_ms(1);     /// delay for 1 millisecond
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);  /// Set LCD_EN_PIN value to LOW

	_delay_ms(1); ////delay for 1 millisecond to let LCD read the first part

//	///*******Set LCD_RS_PIN value to HIGH *********///
//	M_DIO_void_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);
	///Set LCD_DATA_PORT equal Local_u8_character Shifted to Right  by 3 to send Right part of the character
	LCD_DATA_PORT = ((Local_u8_character << 4 ) & 0b11110000)|(LCD_DATA_PORT & 0b00001111) ;
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);  /// Set LCD_EN_PIN value to HIGH
	_delay_ms(1);     /// delay for 1 millisecond
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);  /// Set LCD_EN_PIN value to LOW

#endif
	_delay_ms(5); /// to give time to LCD Microcontroller to process the repeated request
}
///***********Function to write a command to LCD*****8///
void H_LCD_Void_LCDWriteCommand(u8 Local_u8_Command)
{
#if LCD_MODE == Activate_8_bit_mode  ///****8_bit_mode**********///
	///*******Set LCD_RS_PIN value to LOW*********///
	M_DIO_void_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	LCD_DATA_PORT = Local_u8_Command ;  /// Set LCD_DATA_PORT to equal Local_u8_Command
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);  /// Set LCD_EN_PIN value to HIGH
	_delay_ms(1);     /// delay for 1 millisecond
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);  /// Set LCD_EN_PIN value to LOW

#elif LCD_MODE == Activate_4_bit_mode  ///****4_bit_mode**********///
	///*******Set LCD_RS_PIN value to HIGH *********///
	M_DIO_void_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	///Set LCD_DATA_PORT equal Local_u8_Command Shifted to left by 1 to send left part of the character
	LCD_DATA_PORT = (Local_u8_Command & 0b11110000)|(LCD_DATA_PORT & 0b00001111) ;
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);  /// Set LCD_EN_PIN value to HIGH
	_delay_ms(1);     /// delay for 1 millisecond
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);  /// Set LCD_EN_PIN value to LOW

	_delay_ms(1); ////delay for 1 millisecond to let LCD read the first part

//	///*******Set LCD_RS_PIN value to HIGH *********///
//	M_DIO_void_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);
	///Set LCD_DATA_PORT equal Local_u8_Command Shifted to Right  by 3 to send Right part of the character
	LCD_DATA_PORT = ((Local_u8_Command << 4)& 0b11110000)|(LCD_DATA_PORT & 0b00001111)  ;
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);  /// Set LCD_EN_PIN value to HIGH
	_delay_ms(1);     /// delay for 1 millisecond
	M_DIO_void_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);  /// Set LCD_EN_PIN value to LOW
#endif
	_delay_ms(5); /// to give time to LCD Microcontroller to process the repeated request
}
/// ********function To Display a String on LCD   *****///
void H_Lcd_void_LCDWriteString(u8* Local_u8_PTR)
{
	u8 Local_u8_Counter = 0; /// loacal counter to count string character
	while (Local_u8_PTR[Local_u8_Counter] != NUL) /// while to loop until the end of the string
	{
//// call  H_LCD_Void_LCDDisplayCharacter and give it the location of the character on the string
		H_LCD_Void_LCDDisplayCharacter(Local_u8_PTR[Local_u8_Counter]);
		/// increment the Local_u8_Counter
		Local_u8_Counter++;
	}


}
/// ********function To Display a String on LCD   *****///
void H_Lcd_void_LCDWriteNum(s32 Local_s2_Number )
{
    u8 Local_u8_arr[12]={0};   /// loacal array to store the number of column of the lcd
    s8 Local_s8_Counter =0;    /// local counter for for loop
    if (Local_s2_Number < 0 )   /// check if the number is less than 0 to add sighn (-)
    {
     H_LCD_Void_LCDDisplayCharacter('-');
     Local_s2_Number = Local_s2_Number * -1 ;
    }
    while(Local_s2_Number !=0)
    {
    	Local_u8_arr [Local_s8_Counter] = Local_s2_Number %10;;
    	Local_s2_Number /=10;
    	Local_s8_Counter ++;
    }
    Local_s8_Counter--;
   do
    {
    	H_LCD_Void_LCDDisplayCharacter(Local_u8_arr [Local_s8_Counter] + 48);
    	Local_s8_Counter--;
    } while(Local_s8_Counter >= 0);

}
/// ********function To Select Row and Column	 on LCD   *****///
void H_Lcd_void_LCDGoToXY(u8 Local_u8_Row,u8 Local_u8_Column)
{
 if(Local_u8_Row >= 0 && Local_u8_Row <= 1 && Local_u8_Column >= 0 && Local_u8_Column <= 15)
		{

			u8 Arr[2]={SET_ROW0_COL0, SET_ROW1_COL0};
			H_LCD_Void_LCDWriteCommand(Arr[Local_u8_Row]+ Local_u8_Column);
		}
 else
 {
	 H_Lcd_void_LCDWriteString("wrong input!!");
 }

}
/// ********function To Display a clock format on LCD  *****///
void H_Lcd_void_LCDClockDisplay(u8 Local_u8_Hours,u8 Local_u8_Minutes,u8 Local_u8_Seconds)
{
	H_Lcd_void_LCDWriteString("Clock");
	if((Local_u8_Hours > 9) | (Local_u8_Minutes >9) | (Local_u8_Seconds > 9))
	{
		H_Lcd_void_LCDGoToXY(0, 7);
	    H_Lcd_void_LCDWriteString("H :M :S");
		H_Lcd_void_LCDGoToXY(1, 7);
		H_Lcd_void_LCDWriteNum(Local_u8_Hours);
		if(Local_u8_Hours <= 9)
			{
				H_LCD_Void_LCDDisplayCharacter(' ');
			}
		H_LCD_Void_LCDDisplayCharacter(':');
		H_Lcd_void_LCDWriteNum(Local_u8_Minutes);
		if(Local_u8_Minutes <= 9)
			{
				H_LCD_Void_LCDDisplayCharacter(' ');
			}
		H_LCD_Void_LCDDisplayCharacter(':');
		H_Lcd_void_LCDWriteNum(Local_u8_Seconds);

	}
	else
	{
		H_Lcd_void_LCDGoToXY(0, 7);
		H_Lcd_void_LCDWriteString("H:M:S");
		H_Lcd_void_LCDGoToXY(1, 7);
		H_Lcd_void_LCDWriteNum(Local_u8_Hours);
		H_LCD_Void_LCDDisplayCharacter(':');
		H_Lcd_void_LCDWriteNum(Local_u8_Minutes);
		H_LCD_Void_LCDDisplayCharacter(':');
		H_Lcd_void_LCDWriteNum(Local_u8_Seconds);
	}


}
/// ********function To screen LCD screen *****///
void H_Lcd_void_LCDClear(void)
{
	H_LCD_Void_LCDWriteCommand(Clear_screen);
}
