/*
 * WDT_prog.c
 *
 *  Created on: Jul 20, 2019
 *      Author: Hamzy
 */

#include <avr/io.h>
#include <avr/delay.h>
#include"Lib/types.h"
#include "Lib/bitwise.h"
#include "DIO_int.h"
#include "WDT_priv.h"
#include "WDT_int.h"


void WDT_voidStart(u8 u8_cycles_NO_cpy)
{
	WDTCR |= u8_cycles_NO_cpy; //TIME =2.2 SEC

	/*** EN WDT **/
	WDTCR |= (1<<WDE);
}


void WDT_voidStop(void)
{
	WDTCR |= (1<<WDE)|(1<<WDTOE);
	_delay_ms(4);
	// waiting for 4 cycles
	WDTCR &= ~(1<<WDE);
}
