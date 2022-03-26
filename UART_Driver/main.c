/*
 * main.c
 *
 *  Created on: Jul 23, 2019
 *      Author: Hamzy
 */

#define F_CPU 8000000

#include <avr/delay.h>
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "DIO_int.h"
#include "UART_cfg.h"
#include "UART_int.h"




int main(void)
{
	u8 data = 0;
	/* Turn on the UART */
	UART_voidInit();

    /* Initialization of PORTA for the LEDS*/
	 DIO_VidSetPortDir (DIO_PORTA, DIO_PORT_OUTPUT);




	/* The super loop*/
	while (1)
	{
		 data = UART_voidReceive();
		 UART_voidSend(data);
		 UART_voidSend(' ');
	}
	return 0;
}

