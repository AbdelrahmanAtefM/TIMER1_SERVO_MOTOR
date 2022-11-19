/*
 * DIO_Prog.c
 *
 *  Created on: Sep 15, 2022
 *      Author: AbdelRahman Atef
 */
#include "DIO_Int.h"

///  M_DIO_void_SetPinDirection takes 3 arguments PORT , PIN & DIRECTION
void M_DIO_void_SetPinDirection (u8 port , u8 pin , u8 direction)
{
	//// SWITCH too determine the Direction of Pin
	switch (direction)
		{
	 /// case  INPUT means that the Direction of Pin  = 0
		 case INPUT :
			 //// SWITCH too determine the Port of the Pin
			 switch (port)
			 	{
			 	case PORTA_ID :                        /// Port A
			 		ClrBit(DDRA,pin);                  /// clear pin value set it to 0
				break ;
			 	case PORTB_ID :                        /// Port B
			 		ClrBit(DDRB,pin);                 /// clear pin value set it to 0
			 	break ;
			 	case PORTC_ID :                       /// Port C
			 		ClrBit(DDRC,pin);                /// clear pin value set it to 0
			 	break ;
			 	case PORTD_ID :                       /// Port D
			 		ClrBit(DDRD,pin);                /// clear pin value set it to 0
			 	break ;

			 	default :     /*  Do nothing */       break;
			 	///* end of case INPUT  switch (port) */
			 	}
		break;        /////// break case INPUT

		/// case  INPUT means that the Direction of Pin = 1
		 case OUTPUT :
			 //// SWITCH too determine the Port of the Pin
			 switch (port)
			 	{
			 	case PORTA_ID :                   /// Port A
			 		SetBit(DDRA,pin);             /// SET pin value set it to 1
			 	break ;       /////// break case PORTA_ID

			 	case PORTB_ID :                  /// Port B
			 		SetBit(DDRB,pin);           /// SET pin value set it to 1
			 	break ;       /////// break case PORTB_ID

			 	case PORTC_ID :                  /// Port C
			 		SetBit(DDRC,pin);            /// SET pin value set it to 1
			 	break ;        /////// break case PORTC_ID

			 	case PORTD_ID :                  /// Port D
			 		SetBit(DDRD,pin);           /// SET pin value set it to 1
			 	break ;       /////// break case PORTD_ID

			 	default :    /*  Do nothing */                   break;
			 	         ///***** end of case OUTPUT  switch (port)  *******/
			 	}

		 break;          /////// break case OUTPUT


		 default:       /*  Do nothing */        break;
		       ///* default of switch (direction) */
		}

}



void M_DIO_void_SetPinValue(u8 port , u8 pin , u8 value)
{
	  /// SWITCH too determine the Value of the Pin
		switch (value)
		{
		   /// case  LOW means that the Value of Pin = 0
          case LOW :
        	  //// SWITCH too determine the Port of the Pin
			       switch (port)
			       	{
			       	case PORTA_ID :                  /// Port A
			       		ClrBit(PORTA,pin);          ///  clear pin value set it to 0
			       	break ;             /////// break case PORTA_ID

			       	case PORTB_ID :                 /// Port B
			       		ClrBit(PORTB,pin);          /// clear pin value set it to 0
			       	break ;          /////// break case PORTB_ID

			       	case PORTC_ID :                 /// Port C
			       		ClrBit(PORTC,pin);          /// clear pin value set it to 0
			       	break ;         /////// break case PORTC_ID

			       	case PORTD_ID :                 /// Port D
			       		ClrBit(PORTD,pin);         /// clear pin value set it to 0
			       	break ;       /////// break case PORTD_ID

			        default :   /*  Do nothing */              break;
			        ///* default of switch (port) */
			     	}
		 break;   /////// break case LOW

		 /// case  HIGH means that the Value of Pin = 1
		 case HIGH :
			 //// SWITCH too determine the Port of the Pin
			        switch (port)
			        	{
			        	case PORTA_ID :                /// Port A
			        		SetBit(PORTA,pin);         /// SET pin value set it to 1
			        	break ;             /////// break case PORTA_ID

			        	case PORTB_ID :                 /// Port B
			        		SetBit(PORTB,pin);         /// SET pin value set it to 1
			        	break ;          /////// break case PORTB_ID

			        	case PORTC_ID :                /// Port C
			        		SetBit(PORTC,pin);        /// SET pin value set it to 1
			        	break ;        /////// break case PORTC_ID

			        	case PORTD_ID :               /// Port D
			        		SetBit(PORTD,pin);        /// SET pin value set it to 1
			        	break ;      /////// break case PORTD_ID

			        	default :   /*  Do nothing */     break;
			        	///* default of switch (port) */
			        	}
		break;         /////// break case HIGH

		default:   /*  Do nothing */       break;
		///* default of switch (value) */
		}
}
    //// Toggle Pin function //////
void M_DIO_void_PinTog(u8 port , u8 pin)
{
	//// SWITCH too determine the Port of the Pin
	switch (port)
		{

		  case PORTA_ID :                           /// Port A
			  TogBit(PORTA,pin);                    /// Toggle pin value
		  break ;                       //// break case PORTA_ID

		  case PORTB_ID :                            /// Port B
			  TogBit(PORTB,pin);                     /// Toggle pin value
		  break ;                      /// / break case PORTB_ID

		  case PORTC_ID :                           /// Port C
			  TogBit(PORTC,pin);                   /// Toggle pin value
		  break ;                       ///break case PORTC_ID

		  case PORTD_ID :                          /// Port D
			  TogBit(PORTD,pin);                    /// Toggle pin value
		  break ;                       ///break case PORTD_ID

		  default :       /*  Do nothing */      break;
		  ///* default of switch (port) */
		}
}
u8 M_DIO_U8_PinRead(u8 port , u8 pin)
{
	/// local variable
	u8 local_u8_PinValue = 0;
	//// SWITCH too determine the Port of the Pin
		switch (port)
			{

			  case PORTA_ID :                           /// Port A
				  local_u8_PinValue = GetBit(PINA,pin);                    /// Read pin value
			  break ;                       //// break case PORTA_ID

			  case PORTB_ID :                            /// Port B
				  local_u8_PinValue = GetBit(PINB,pin);                     /// Read pin value
			  break ;                      /// / break case PORTB_ID

			  case PORTC_ID :                           /// Port C
				  local_u8_PinValue = GetBit(PINC,pin);                   /// Read pin value
			  break ;                       ///break case PORTC_ID

			  case PORTD_ID :                          /// Port D
				  local_u8_PinValue = GetBit(PIND,pin);                    /// Read pin value
			  break ;                       ///break case PORTD_ID

			  default :       /*  Do nothing */      break;
			  ///* default of switch (port) */
			}
   return local_u8_PinValue;
}
