/*
 * EXTI_prog.c

 *
 *  Created on: May 22, 2019
 *      Author: Hazmy
 */
#define F_CPU 8000000
#include <avr/interrupt.h>
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "EXTI_cfg.h"
#include "EXTI_priv.h"
#include "EXTI_int.h"

void EXTI0_vidInit(void)
{
	/**Set INT0 pin as input pin**/
	CLR_BIT(DDRD_REG, EXTI_INT0_PIN);

	/**Set INT0 pin as high in order to activate the pull up resistor**/
	SET_BIT(PORTD_REG, EXTI_INT0_PIN);

	/**Enable the General Interrupt Flag "PSW"**/
	SET_BIT(SREG_REG, IBIT);

	/** Enable the GICR "PIE"**/
	SET_BIT(GICR_REG, INT0);

	/**Interrupt sense control select with ACTIVE LOW**/
    MCUCR_REG &= ~(1<<ISC00) | ~(1<<ISC01);

}



void EXTI1_vidInit(void)
{
	/**Set INT1 pin as input pin**/
		CLR_BIT(DDRD_REG, EXTI_INT1_PIN);

		/**Set INT1 pin as high in order to activate the pull up resistor**/
		SET_BIT(PORTD_REG, EXTI_INT1_PIN);

		/**Enable the General Interrupt Flag "PSW"**/
		SET_BIT(SREG_REG, IBIT);

		/** Enable the GICR "PIE"**/
		SET_BIT(GICR_REG, INT1);

		/**Interrupt sense control select with ACTIVE LOW**/
	    MCUCR_REG &= ~(1<<ISC10) | ~(1<<ISC11);

}


void EXTI2_vidInit(void)
{
	/**Set INT2 pin as input pin**/
		CLR_BIT(DDRB_REG, EXTI_INT2_PIN);

		/**Set INT2 pin as high in order to activate the pull up resistor**/
		SET_BIT(PORTB_REG, EXTI_INT2_PIN);

		/**Enable the General Interrupt Flag "PSW"**/
		SET_BIT(SREG_REG, IBIT);

		/** Enable the GICR "PIE"**/
		SET_BIT(GICR_REG, INT2);

		/**Interrupt sense control select with FALLING EDGE "Set to 0**/
		MCUCSR_REG &= ~(1<<ISC2);

}
