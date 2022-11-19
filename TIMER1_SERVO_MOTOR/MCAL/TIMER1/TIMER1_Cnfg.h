/*
 * TIMER1_Cnfg.h
 *
 *  Created on: Nov 19, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_TIMER1_TIMER1_CNFG_H_
#define MCAL_TIMER1_TIMER1_CNFG_H_

/*
 * select TIMER1_FAST_PWM1_MODE MODE:
 *  NON_Inverted
 *  Inverted
 */
#define  TIMER1_FAST_PWM1_MODE   NON_Inverted

/*
 * select PRESCALER :
 *  1024
 *  256
 */
#define TIMER1_PRESCALER           256

/*
 * select FOSC
 */
#define  F_OSC   16

#endif /* MCAL_TIMER1_TIMER1_CNFG_H_ */
