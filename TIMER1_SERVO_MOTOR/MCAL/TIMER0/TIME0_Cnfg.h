/*
 * TIME0_Cnfg.h
 *
 *  Created on: Nov 16, 2022
 *      Author: AbdelRahman Atef
 */

#ifndef MCAL_TIMER0_TIME0_CNFG_H_
#define MCAL_TIMER0_TIME0_CNFG_H_

/*
 * select TIMER0 MODE:
 *  NORMAL_MODE
 *  CTC_MODE
 */
#define  TIMER0_MODE   CTC_MODE

/*
 * select PRESCALER :
 *  1024
 *  256
 *  64
 *  8
 */
#define TIMER0_PRESCALER           1024

/*
 * select TIMER0_PWM_MODE :
 *  FAST_PWM_MODE
 *  PHASE_CORRECT
 */
#define  TIMER0_PWM_MODE            PHASE_CORRECT

/*
 * select TIMER0_FAST_PWM_MODE :
 *  INVERTED
 *  NON_INVERTED
 */
#define  TIMER0_FAST_PWM_MODE       NON_INVERTED
/*
 * select TIMER0_PWM_PHASE_CORRECT :
 *  NON_INVERTED
 *  INVERTED
 */
#define  TIMER0_PWM_PHASE_CORRECT   NON_INVERTED

/*
 * select FOSC
 */
#define  FOSC   16
#endif /* MCAL_TIMER0_TIME0_CNFG_H_ */
