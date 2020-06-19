/*
 * main.c
 *
 *  Created on: Apr 27, 2019
 *      Author: Hamzy
 */

#define F_CPU 8000000
#include "Lib/types.h"
#include "DIO_int.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include <util/delay.h>

int main(void)
{
	/** Initialization part**/

	/*** Set port C "Data Port" as output in order to LCD Data pins ***/
	DIO_VidSetPortDir (LCD_DATA_PORT, 0xff);


	/*** Set port D "Control Port" as output in order to LCD Control pins ***/
	DIO_VidSetPortDir (LCD_CTL_PORT, 0xff);



	/*** LCD Initialization Process ***/
	LCD_vid_Initial();


	/***Send the Character to be displayed on the LCD ***/
	LCD_vidSend_char('K');

	while(1)
	{


		LCD_vidShift_R();
	    _delay_ms(500);



	}

	return 0;
}
