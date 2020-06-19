/*
 * EXTI_int.h
 *
 *  Created on: May 22, 2019
 *      Author: FUTURE
 */

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

/************************************/
/***********Public Macros************/
/************************************/
#define EXTI_INT0	0
#define EXTI_INT1	1
#define EXTI_INT2	2

#define EXTI_INT0_PIN	2
#define EXTI_INT1_PIN	3
#define EXTI_INT2_PIN	2



/************************************/
/***********Public Functions*********/
/************************************/

/*** Interrupt Initializing ***/

void EXTI0_vidInit(void);
void EXTI1_vidInit(void);
void EXTI2_vidInit(void);

#endif /* EXTI_INT_H_ */
