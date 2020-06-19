/*
 * prog.c
 *
 *  Created on: Apr 27, 2019
 *      Author: FUTURE
 */
#include "Lib/types.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_cfg.h"
#include <util/delay.h>

#if LCD_MODE==LCD_4BIT_MODE


#elif LCD_MODE==LCD_8BIT_MODE

/*
 *description 	  	: initialization function
 *Input argument 	: void
 *return argument	: void
 */
void LCD_vid_Initial(void)
{
	/** WAIT until LCD powered **/
	_delay_ms(30);


	/**  FUNCTION SET  **/
	LCD_vidSend_CMD(LCD_FUNSET_8BIT);
	_delay_ms(10);


	/**  DISPLAY CONTROL  **/
	LCD_vidSend_CMD(LCD_DISPON_CURON_BLKON);
	_delay_ms(10);

	/**  Return Home  **/
	LCD_vidSend_CMD(LCD_HOME);
	_delay_ms(15);


	/**  DISPLAY CLEAR  **/
	LCD_vidSend_CMD(LCD_CLR_DIS);
	_delay_ms(15);


	/**  ENTRY MODE SET  **/
	LCD_vidSend_CMD(LCD_EntryMode_CURIN_SHDIS);
	_delay_ms(10);

}

/*
 *description 	  	: send command function
 *Input argument 	: the command want to be sent
 *return argument	: void
 */

void LCD_vidSend_CMD(u8 u8CMD)
{
	/*Set the R/S "off" so Mr.LCD understands it is a command*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RS, DIO_LOW);
	_delay_ms(15);


	/*Set the R/W "off" so that Mr.LCD Listen*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RW, DIO_LOW);
	_delay_ms(15);


	/*Light the enable light for Mr.LCD*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, DIO_HIGH);
	_delay_ms(15);


	/*Send the command*/
	DIO_VidSetPortVal (LCD_DATA_PORT, u8CMD);
	_delay_ms(15);

	/*Turn the Light OFF so that Mr.LCD can work in Dark */
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, DIO_LOW);
	_delay_ms(15);

	/*Light the enable light for Mr.LCD*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, DIO_HIGH);
	_delay_ms(10);

}


/*
 *description 	  	: send character function
 *Input argument 	: the command want to be sent
 *return argument	: void
 */

void LCD_vidSend_char(u8 u8char)
{

	/*Set the R/S "off" so Mr.LCD Listen understands it is a command*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RS, DIO_HIGH);
	_delay_ms(15);


	/*Set the R/W "off" so that Mr.LCD Listen*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_RW, DIO_LOW);
	_delay_ms(15);


	/*Light the enable light for Mr.LCD*/
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, DIO_HIGH);
	_delay_ms(15);

	/*Send the character*/
	DIO_VidSetPortVal (LCD_DATA_PORT, u8char);
	_delay_ms(15);


	/*Turn the Light OFF so that Mr.LCD can work in Dark */
	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, DIO_LOW);
	_delay_ms(15);


	DIO_VidSetPinVal(LCD_CTL_PORT, LCD_EN, DIO_HIGH);
	_delay_ms(10);
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
			_delay_ms(15);
			break;

		case 1:
			u8x = u8x + 0x40 ;
			u8x = 0x80 | u8x;
			LCD_vidSend_CMD(u8x);
			_delay_ms(15);
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
	_delay_ms(15);
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
	u8 i = 0;
	while(str[i] != '\0')
	{
		LCD_vidSend_char(str[i]);
		i++;
	}
}


#else
#endif


