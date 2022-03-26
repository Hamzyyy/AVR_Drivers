/*
 * TMR_priv.h
 *
 *  Created on: Jul 13, 2019
 *      Author: Hamzy
 */

#ifndef TMR1_PRIV_H_
#define TMR1_PRIV_H_

/*********************************/
/********PRIVATE MACROS***********/
/*********************************/


/*** PRESCALLER / Clock Select Bits (CS) ***/
#define TMR1_DIV_BY_1           1
#define TMR1_DIV_BY_8           2
#define TMR1_DIV_BY_64          3
#define TMR1_DIV_BY_256         4
#define TMR1_DIV_BY_1024        5


/*** Waveform at Normal & CTC Mode / COM bits (COM1A1 & COM1B1) (COM1A0 & COM1B0)***/

#define TMR1_DISABLE_OC1        0
#define TMR1_TOGGLE_OC1         1
#define TMR1_CLEAR_OC1          2
#define TMR1_SET_OC1            3

/*** Waveform at Fast PWM & Phase Correct / COM bits (COM00 & COM01) ***/
#define TMR1_NON_INVERTED       2  // Clear OC1 on compare match & set OC0 at TOP
#define TMR1_INVERTED           3  // Set OC1 on compare match & Clear OC0 at TOP



/*** Timer1 Register ***/
#define TCNT1       *((volatile u16*) 0x4C)



/*** Timer1 Control Register A ***/
#define TCCR1A      *((volatile u8*) 0x4F)

#define COM1A1      7
#define COM1A0      6
#define COM1B1      5
#define COM1B0      4
#define FOC1A       3
#define FOC1B       2
#define WGM11       1
#define WGM10       0


/*** Timer1 Control Register B ***/
#define TCCR1B      *((volatile u8*) 0x4E)

#define ICNC1       7     //INPUT CAPTURE NOISE CANCELER
#define ICES1       6     //INPUT CAPTURE EDGE SELECT 0 (FALLING EDGE) & 1 (RISING EDGE)
/********************/
#define WGM13       4
#define WGM12       3
#define CS12        2
#define CS11        1
#define CS10        0




/*** Timer1 Output compare Register OCR1 ***/
#define OCR1A        *((volatile u16*) 0x4A)
#define OCR1B        *((volatile u16*) 0x48)



/*** Timer Interrupt Mask Register TMISK ***/
#define TIMSK        *((volatile u8*) 0x59)

#define TICIE1       5    //INPUT CAPTURE Interrupt Enable
#define OCIE1A       4    //OUTPUT COMPARE A Interrupt Enable
#define OCIE1B       3    //OUTPUT COMPARE B Interrupt Enable
#define TOIE1        2    //OVERFLOW Interrupt Enable




/*** Timer Interrupt Flag Register TIFR ***/
#define TIFR        *((volatile u8*) 0x58)

#define ICF1        5    //INPUT CAPTURE flag
#define OCF1A       4    //OUTPUT COMPARE A MATCH flag
#define OCF1B       3    //OUTPUT COMPARE B MATCH Flag
#define TOV1        2    //OVERFLOW flag




/*** Timer/Counter1 Input Capture Register ***/
#define ICR1        *((volatile u16*) 0x46)




/*** Status Register SREG ***/
#define SREG        *((volatile u8*)0x5F)
#define IBIT	    7

#endif /* TMR1_PRIV_H_ */
