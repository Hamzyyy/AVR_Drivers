/*
 * main.c
 *
 *  Created on: May 22, 2019
 *      Author: Hamzy
 */
#define F_CPU 8000000
#include <avr/interrupt.h>
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "EXTI_cfg.h"
#include "EXTI_int.h"
#include "DIO_int.h"
#include <util/delay.h>


/**External Interrupt #1 service routine**/

ISR(INT0_vect)
{

	_delay_ms(500);
	for(u8 i = 0; i<8; i++)
	{
	DIO_VidSetPortVal(DIO_PORTC, 1<<i);  /*LED Blinking Pattern 1*/
	_delay_ms(500);
	}


	for(u8 i = 0; i<8; i++)
	{
	DIO_VidSetPortVal(DIO_PORTC, 0x80>>i);  /*LED Blinking Pattern 1*/
	_delay_ms(500);
	}



}


/**External Interrupt #1 service routine**/
ISR(INT1_vect)
{
	_delay_ms(500);
	DIO_PORTC = ~DIO_PORTC;  /*toggle led state*/
}


/**External Interrupt #2 service routine**/
ISR(INT2_vect)
{
	_delay_ms(500);
	DIO_PORTC = ~DIO_PORTC;   /*toggle led state*/
}




int main(void)
{

	/**Set Port C as output & high to connect a LED**/
	DIO_VidSetPortDir(DIO_PORTC, DIO_PORT_OUTPUT);
	DIO_VidSetPortVal(DIO_PORTC, DIO_PORT_HIGH);

	/**Initialization of External Interrupt #1**/
	EXTI1_vidInit();

	/**Initialization of External Interrupt #2**/
	EXTI2_vidInit();

	/**Initialization of External Interrupt #0**/
	EXTI0_vidInit();


	while(1)
	{

	}
}
