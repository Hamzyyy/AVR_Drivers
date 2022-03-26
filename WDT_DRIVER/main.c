/*
 * main.c
 *
 *  Created on: Jun 8, 2019
 *      Author: Hamzy
 */
#define F_CPU 8000000


#include <avr/io.h>
#include <avr/delay.h>
#include"Lib/types.h"
#include "Lib/bitwise.h"
#include "DIO_int.h"
#include "WDT_int.h"


int main(void)
{

   DIO_VidSetPinDir( DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	for(u8 i=0;i<8;i++)
	{
		_delay_ms(10);
		 DIO_voidTogglePinVal( DIO_PORTA, DIO_PIN0);
		_delay_ms(10);
	}

    /******* THE SUPER LOOP *******/

    while (1)
    {
    	 WDT_voidStart(WDT_2048K_CYCLE);
		_delay_ms(1000);
		 WDT_voidStop();
    }


	return 0;
}
