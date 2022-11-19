/*
 * BIT_MATH.h
 *
 *  Created on: Sep 15, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef APP_BIT_MATH_H_
#define APP_BIT_MATH_H_

#define SetBit(Reg,Bit)    Reg |=  (1 << Bit )  ///SetBit function to Set the value of bit to 1
#define ClrBit(Reg,Bit)    Reg &= ~(1 << Bit )  ///ClrBit function to Set the value of bit to 0
#define TogBit(Reg,Bit)    Reg ^=  (1 << Bit )  ///TogBit function to Reflect the value of a bit
#define GetBit(Reg,Bit)    ((Reg >> Bit ) & 1) ///SetBit function to Get the value of a bit


//#define SET_BIT(REG,BIT)          REG |=  (1 << (BIT))
//#define CLR_BIT(REG,BIT)          REG &= ~(1 << (BIT))
//#define TOG_BIT(REG,BIT)          REG ^=  (1 << (BIT))
//#define GET_BIT(REG,BIT)          ((REG >> BIT) & 1  )

#endif /* APP_BIT_MATH_H_ */
