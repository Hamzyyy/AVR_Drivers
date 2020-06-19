/*
 * main.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Hamdy
 */

#define F_CPU 8000000
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "DIO_int.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include "SPI_cfg.h"
#include "SPI_int.h"

int main(void)
{

    #if SPI_MODE == SPI_MASTER
	SPI_vidMasterInit();

    #elif SPI_MODE == SPI_SLAVE

	/*LCD Initialization*/
	DIO_VidSetPortDir (LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_VidSetPortDir (LCD_CTL_PORT, DIO_PORT_OUTPUT);

	LCD_vid_Initial();
	LCD_vidSend_word("Welcome");

	/*SPI Slave Initialization*/
     SPI_vidSlaveInit();

    #else
    #endif



     while(1)
     {
     #if SPI_MODE == SPI_MASTER
      SPI_send('A');

    #elif SPI_MODE == SPI_SLAVE
    	  _delay_ms(100);
   	       LCD_vidSend_char(SPI_u8receive());

    #else
    #endif

     }

	return 0;
}

