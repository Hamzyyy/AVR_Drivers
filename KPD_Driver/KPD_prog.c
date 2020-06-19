/*
 * KPD_prog.c
 *
 *  Created on: May 4, 2019
 *      Author: Hamzy
 */
#include <util/delay.h>
#include"KPD_priv.h"
#include"LIB/types.h"
#include "Lib/bitwise.h"
#include"DIO_int.h"
#include"KPD_cfg.h"
#include"KPD_int.h"




/*description 	  	: get the pressed key from user
 *Input argument 	: void
 *return argument	: char variable which contain pressed key
 */



u8 KPD_u8getPress(void)
{

	 u8 KPD_arr[4][4] = {{'1','2','3','0'},
						{'5','6','7','8'},
						{'9','0','+','-'},
						{'*','/','=','.'}};

	/* Initializing the variable of rows, columns & the return value */
	u8 col_loc, row_loc, Key_pressed_loc = 0xff; //to ensure at the beginning that no key is pressed

	/* The bigger loop of Columns */
	for(col_loc = KPD_COL_START ; col_loc < KPD_COL_END; col_loc++)
	{
		/* Put zero at column by column */
		DIO_VidSetPinVal( KPD_PORT, col_loc, DIO_LOW);

		/* Get the value of each row and see if any one has zero */
		for(row_loc = KPD_ROW_START; row_loc < KPD_ROW_END; row_loc++)
		{
			if(DIO_u8GetPinVal (KPD_PORT, row_loc) == KPD_LOW)
			{
				/* rows start from 4 so KPD[rows-4][column] */
				Key_pressed_loc = KPD_arr[row_loc-4][col_loc];

				/* To overcome the bouncing effect, looping as long as the key pressed AKA row_loc ==0 */
				while(DIO_u8GetPinVal (KPD_PORT, row_loc) == KPD_LOW)
				{

				}
					_delay_ms(10);
			}
		}

		/* Set the column again to 1 in order to set another column with 1 */
		DIO_VidSetPinVal( KPD_PORT, col_loc, KPD_HIGH);
	}
return Key_pressed_loc;
}
