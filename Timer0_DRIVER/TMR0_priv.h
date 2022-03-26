/*
 * TMR_priv.h
 *
 *  Created on: Jun 21, 2019
 *      Author: Hamzy
 */

#ifndef TMR0_PRIV_H_
#define TMR0_PRIV_H_

/*********************************/
/********PRIVATE MACROS***********/
/*********************************/


/***Timer Modes / Waveform Generation Mode Bits (WGM)***/

#define TMR0_NORMAL_MODE                   0
#define TMR0_CTC_MODE                      1
#define TMR0_FAST_PWM_MODE                 2
#define TMR0_PHASE_CORRECT_MODE            3

/***PRESCALLER / Clock Select Bits (CS)***/
#define TMR0_DIV_BY_1           1
#define TMR0_DIV_BY_8           2
#define TMR0_DIV_BY_64          3
#define TMR0_DIV_BY_256         4
#define TMR0_DIV_BY_1024        5


/*** Waveform at Normal & CTC Mode / COM bits (COM00 & COM01) ***/

#define TMR0_DISABLE_OC0    0
#define TMR0_TOGGLE_OC0     1
#define TMR0_CLEAR_OC0      2
#define TMR0_SET_OC0        3

/*** Waveform at Fast PWM & Phase Correct / COM bits (COM00 & COM01) ***/
#define TMR0_NON_INVERTED   2  // Clear OC0 on compare match & set OC0 at TOP
#define TMR0_INVERTED       3  // Set OC0 on compare match & Clear OC0 at TOP



/***Timer0 Register***/
#define TCNT0   *((volatile u8*) 0x52)



/***Timer0 Control Register***/
#define TCCR0   *((volatile u8*) 0x53)

#define FOC0     7
#define WGM00    6
#define COM01    5
#define COM00    4
#define WGM01    3
#define CS02     2
#define CS01     1
#define CS00     0


/***Timer0 Output compare Register OCR0***/
#define OCR0   *((volatile u8*) 0x5C)


/***Timer0 Interrupt Mask Register TMISK***/
#define TIMSK   *((volatile u8*) 0x59)

#define OCIE0     1    //Output compare match interrupt enable bit
#define TOIE0     0    //Overflow interrupt enable bit


/***Timer0 Interrupt Flag Register TIFR***/
#define TIFR   *((volatile u8*) 0x58)

#define OCF0     1    //Output compare flag bit
#define TOV0     0    //Overflow flag bit


/***Status Register SREG***/
#define SREG     *((volatile u8*)0x5F)
#define IBIT	 7

#endif /* TMR0_PRIV_H_ */
