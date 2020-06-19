/*
 * main.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Hamzy
 */


#define F_CPU  8000000

#include <util/delay.h>
#include"Lib/types.h"
#include "Lib/bitwise.h"
#include "DIO_int.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include "TWI_int.h"
#include "EEPROM_int.h"



int main(void)
{

	/** LCD ports output **/
	DIO_VidSetPortDir (LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_VidSetPortDir (LCD_CTL_PORT, DIO_PORT_OUTPUT);

	/*Port C input pull up*/
	DIO_VidSetPortDir (DIO_PORTC, DIO_INPUT);
	DIO_VidSetPortVal (DIO_PORTC, DIO_PORT_OUTPUT);

	/* Initialize LCD */
	LCD_vid_Initial();

	/* Initialize I2C */
		TWI_voidInit();

		u8 one, two, three, four, five;

		/* Data*/
		u8 data;

		/* Data array (buffer) */
		u8 array [5] = {'H', 'A', 'M', 'Z', 'Y'};




		/* Store in one = array [0] = 'H', block = 1, location = 0x01 */
		one = EEPROM_WriteByte(array[0], 0x01, 0x01);
		/* print ASCII 0 + 4 = 4 */
		LCD_vidSend_char(48+one);

        /*********************IT STOPS HERE********************/


		/* Store in two = array [1] = 'A', block = 1, location = 0x02 */
		two = EEPROM_WriteByte(array[1], 0x01, 0x02);
		/* print ASCII 0 + 4 = 4 */
		LCD_vidSend_char(48+two);


		/* Store in three = array [2] = 'M', block = 1, location = 0x03 */
		three = EEPROM_WriteByte(array[2], 0x01, 0x03);
		/* print ASCII 0 + 4 = 4 */
		LCD_vidSend_char(48+three);


		/* Store in four = array [3] = 'Z', block = 1, location = 0x04 */
		four = EEPROM_WriteByte(array[3], 0x01, 0x04);
		/* print ASCII 0 + 4 = 4 */
		LCD_vidSend_char(48+four);


		/* Store in five = array [4] = 'Y', block = 1, location = 0x05 */
		four = EEPROM_WriteByte(array[4], 0x01, 0x05);
		/* print ASCII 0 + 4 = 4 */
		LCD_vidSend_char(48+four);


		/* a little bit of delay */
		_delay_ms(100);


		/************ Display the Data ************/

        one = EEPROM_ReadByte(0x01, 0x01, &data);
		LCD_vidSend_char(48+one);
		LCD_vidSend_char(data);



        two = EEPROM_ReadByte(0x01, 0x02, &data);
		LCD_vidSend_char(48+one);
		LCD_vidSend_char(data);


        three = EEPROM_ReadByte(0x01, 0x03, &data);
		LCD_vidSend_char(48+one);
		LCD_vidSend_char(data);


        three = EEPROM_ReadByte(0x01, 0x04, &data);
		LCD_vidSend_char(48+one);
		LCD_vidSend_char(data);


        three = EEPROM_ReadByte(0x01, 0x05, &data);
		LCD_vidSend_char(48+one);
		LCD_vidSend_char(data);


while(1)
{


}

	return 0;

}
