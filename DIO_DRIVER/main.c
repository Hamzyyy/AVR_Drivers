/*
 * main.c
 *
 *  Created on: Feb 16, 2019
 *      Author: FUTURE
 */
#define F_CPU 8000000
#include "Lib/types.h"
#include "DIO_int.h"
#include <util/delay.h>

int main (void)
{
	// Initialization and Declaration

	DIO_VidSetPortDir (DIO_PORTB, 0xff); // Takes PORT_NAME & OUTPUT/INPUT
	DIO_VidSetPortVal (DIO_PORTB,0xff);            // Takes PORT_NAME & HIGH/LOW
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN1, DIO_OUTPUT); // Takes PORT_NAME, PIN_NAME & OUTPUT/INPUT
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
	DIO_VidSetPinDir(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);


	// Application
while(1)
{
	u8 i;

	for(i = 0; i < 8; i++)
	{
		DIO_VidSetPinVal(DIO_PORTB, i, DIO_HIGH);
	    _delay_ms(500);
		DIO_VidSetPinVal(DIO_PORTB, i, DIO_LOW);
	    _delay_ms(500);
	}


/*
	DIO_VidSetPinVal(DIO_PORTB, DIO_PIN0, DIO_HIGH);
    _delay_ms(100);
	DIO_VidSetPinVal(DIO_PORTB, DIO_PIN0, DIO_LOW);
    _delay_ms(100);
*/


}
return 0;
}

