/*
 * main.c
 *
 *  Created on: May 4, 2019
 *      Author: Hamzy
 */
#define F_CPU 8000000
#include <util/delay.h>
#include"KPD_priv.h"
#include"LIB/types.h"
#include "Lib/bitwise.h"
#include"DIO_int.h"
#include "SvnSeg_int.h"
#include"KPD_cfg.h"
#include"KPD_int.h"

int main(void)
{
	/* Initializing the Keypad by setting the rows OUTPUT to  and the columns to INPUT*/


	DIO_VidSetPortDir (DIO_PORTB, 0XFF);

	DIO_VidSetPortDir (KPD_PORT, 0X0F);
	DIO_VidSetPortVal (KPD_PORT, DIO_PORT_OUTPUT);

	while(1)
	{
		u8 key = 0;
		key = KPD_u8getPress();

		 if(key != 0xff)
		 {
			 u8Svn_Seg( SvnSeg_CommonAnode, key);
		 }
	}
	return 0;
}

