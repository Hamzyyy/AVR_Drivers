/*
 * EXTI_priv.h
 *
 *  Created on: May 22, 2019
 *      Author: FUTURE
 */

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

/****************************************/
/************Private Macros**************/
/****************************************/

#define MCUCR_REG    *((volatile u8*)0x55)
#define MCUCSR_REG   *((volatile u8*)0x54)
#define GICR_REG     *((volatile u8*)0x5B)
#define GIFR_REG     *((volatile u8*)0x5A)
#define SREG_REG     *((volatile u8*)0x5F)


/*** PORT B ***/
#define PORTB_REG	*((volatile u8*)0X38)
#define DDRB_REG	*((volatile u8*)0X37)
#define PINB_REG	*((volatile u8*)0X36)

/*** PORT D ***/
#define PORTD_REG	*((volatile u8*)0X32)
#define DDRD_REG	*((volatile u8*)0X31)
#define PIND_REG	*((volatile u8*)0X30)



/*** MCU Control Register –MCUCR BITS **/
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

/*** MCU Control and Status Register – MCUCSR BITS ***/
#define	ISC2	6

/*** General Interrupt Control Register – GICR BITS ***/
#define INT1	7
#define INT0	6
#define INT2	5

/*** General Interrupt Flag Register – GIFR BITS ***/
#define INTF1	7
#define INTF0	6
#define INTF2	5


/*** The AVR Status Register – SREG BITS ***/
#define IBIT	7

#endif /* EXTI_PRIV_H_ */
