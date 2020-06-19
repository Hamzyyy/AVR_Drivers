/*
 * main.c
 *
 *  Created on: Jun 8, 2019
 *      Author: Hamzy
 */
#define F_CPU 8000000
#include"Lib/types.h"
#include "Lib/bitwise.h"
#include "ADC_cfg.h"
#include "LCD_cfg.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "LCD_int.h"

int main(void)
{

    /**LCD PORTS INITIALIZATION**/
	DIO_VidSetPortDir (LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_VidSetPortDir (LCD_CTL_PORT, DIO_PORT_HIGH);


	/**SET THE PIN0 of PORTA as input Channel for ADC**/
	DIO_VidSetPinDir(DIO_PORTA, DIO_PIN0, DIO_INPUT);

	/**LCD INTITIALIZATION**/
    LCD_vid_Initial();

	/**ADC INTITIALIZATION**/
    ADC_Initial();


    /**The Result variable which receive get reading returned value*/
    u16 ADC0_read = 0;

    /** The Digital Volt**/
    u16 volt = 0;


    /******* THE SUPER LOOP *******/

    while (1)
    {
    	ADC0_read = ADC_GetReading(0);
    	volt = (u32)(ADC0_read * 5000) / (u16) 1024;

    	/**Print the output digital voltage on the LCD**/

    	LCD_vidPrint_int(volt);
    }


	return 0;
}
