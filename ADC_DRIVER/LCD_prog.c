/*
 * prog.c
 *
 *  Created on: Apr 27, 2019
 *      Author: FUTURE
 */
#include "Lib/types.h"
#include "DIO_int.h"
#include "LCD_cfg.h"
#include "LCD_int.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#if LCD_MODE==LCD_4BIT_MODE


#elif LCD_MODE == LCD_8BIT_MODE

/*
 *description 	  	: initialization function
 *Input argument 	: void
 *return argument	: void
 */
void LCD_vid_Initial(void)
{
	/** WAIT until LCD powered **/
	_delay_ms(50);


	/**  FUNCTION SET  **/
	LCD_vidSend_CMD(LCD_FUNSET_8BIT);
	_delay_ms(1);


	/**  DISPLAY CONTROL  **/
	LCD_vidSend_CMD(LCD_DISPON_CUROFF_BLKOFF);
	_delay_ms(1);

	/**  Return Home
	LCD_vidSend_CMD(LCD_HOME);
	_delay_ms(50); **/


	/**  DISPLAY CLEAR  **/
	LCD_vidSend_CMD(LCD_CLR_DIS);
	_delay_ms(2);


	/**  ENTRY MODE SET  **/
	LCD_vidSend_CMD(LCD_EntryMode_CURIN_SHDIS);
	_delay_ms(1);

}

/*
 *description 	  	: send command function
 *Input argument 	: the command want to be sent
 *return argument	: void
 */

void LCD_vidSend_CMD(u8 u8CMD)
{
	/*Set the R/S "off" so Mr.LCD understands it is a command*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RS, LCD_LOW);
//	_delay_ms(3);


	/*Set the R/W "off" so that Mr.LCD Listen*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RW, LCD_LOW);
//	_delay_ms(3);


	/*Light the enable light for Mr.LCD*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, LCD_HIGH);
//	_delay_ms(3);


	/*Send the command*/
	DIO_VidSetPortVal (LCD_DATA_PORT, u8CMD);
	_delay_ms(3);

	/*Turn the Light OFF so that Mr.LCD can work in Dark */
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(3);

}


/*
 *description 	  	: send character function
 *Input argument 	: the command want to be sent
 *return argument	: void
 */

void LCD_vidSend_char(u8 u8char)
{

	/*Set the R/S "off" so Mr.LCD Listen understands it is data*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RS, LCD_HIGH);
//	_delay_ms(3);


	/*Set the R/W "off" so that Mr.LCD Listen*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RW, LCD_LOW);
//	_delay_ms(3);


	/*Light the enable light for Mr.LCD*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, LCD_HIGH);
//	_delay_ms(3);

	/*Send the character*/
	DIO_VidSetPortVal (LCD_DATA_PORT, u8char);
	_delay_ms(3);


	/*Turn the Light OFF so that Mr.LCD can work in Dark */
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, LCD_LOW);
	_delay_ms(3);

}

/*
 *description 	  	: set cursor to postion x and y it use for
 *description 	  	write any where and edit the display data
 *Input argument 	: the postion x and y
 *return argument	: void
 */

void LCD_vidGoto(u8 u8x, u8 u8y)
{
	if (u8x < 16 && u8y < 2)
	{
		switch(u8y)
		{
		case 0:
			u8x = 0x80 | u8x;
			LCD_vidSend_CMD(u8x);
			_delay_ms(3);
			break;

		case 1:
			u8x = u8x + 0x40 ;
			u8x = 0x80 | u8x;
			LCD_vidSend_CMD(u8x);
			_delay_ms(3);
			break;

		default:
		break;
		}
	}

	else
	{
		/* out of range*/
	}
}


/*description 	  	: shift the display from right to left by shift data
*description 	  	on DDRAM
*Input argument 	: void
*return argument	: void
*/

void LCD_vidShift_L(void)
{
	LCD_vidSend_CMD(LCD_SHDIS_LFT);
	_delay_ms(3);
}

/*description 	  	: shift the display from left to right by shift data
*description 	  	on DDRAM
*Input argument 	: void
*return argument	: void
*/

void LCD_vidShift_R(void)
{
	LCD_vidSend_CMD(LCD_SHDIS_RT);
	_delay_ms(3);
}


/*
 *description 	  	: Send word at one function by pass pointer to string
 *description 	  	then will send char by char until reach NULL at
 *description 	  	the end of string
 *Input argument 	: pointer to string
 *return argument	: void
 */
void LCD_vidSend_word(u8 *str)
{
	u16 i = 0;
	while(str[i] != '\0')
	{
		LCD_vidSend_char(str[i]);
		i++;
	}
}

void LCD_vidPrint_int(u16 u16int_cpy)
{
	u8 arr[4] = {0};
	u8 i = 3;
	u8 temp = 0;

	while(u16int_cpy)
	{
		temp = u16int_cpy % 10;
		arr[i] = temp;
		i--;
		u16int_cpy = u16int_cpy / 10;
	}

	for(i = 0; i < 4; i++)
	{
		LCD_vidSend_char((arr[i] + '0'));
	}

}


#else
#endif


