/*
 * main.c
 *
 *  Created on: May 11, 2019
 *      Author: Hamzy
 */
#define F_CPU 8000000
#include "Lib/types.h"
#include "DIO_int.h"
#include <util/delay.h>


/**A code to operate a motor in both direction***/

int main (void)
{
	/*Set the port direction of the Motor as output*/
	DIO_VidSetPortDir(DIO_PORTA, DIO_PORT_OUTPUT);

	/*Set the port direction of the switch as input*/
	DIO_VidSetPortDir(DIO_PORTB, DIO_PORT_INPUT);

	/*Set the port value of the switch as high to activate the pull up switch*/
	DIO_VidSetPortVal(DIO_PORTB, DIO_PORT_HIGH);

	while(1)
	{
		/*If the first switch is pressed then wait for a small delay to overcome the bouncing*/
		if(DIO_u8GetPinVal(DIO_PORTB, DIO_PIN0)== 0)
		{
			_delay_ms(500);
			if(DIO_u8GetPinVal(DIO_PORTB, DIO_PIN0)== 0)
			{
				/*Set the motor pin high to operate the motor CCW and turn on the right LED */
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN2, DIO_HIGH);
			}
			/*If the first switch is released*/
			else if(DIO_u8GetPinVal(DIO_PORTB, DIO_PIN0)== 1)
			{
				/*Set the motor pin low to turn off the motor and the right LED */
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN0, DIO_LOW);
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN2, DIO_LOW);

			}
			else
			{

			}

		}
		/*If the second switch is pressed then wait for a small delay to overcome the bouncing*/
		else if((DIO_u8GetPinVal(DIO_PORTB, DIO_PIN1)== 0))
		{
			_delay_ms(500);
			if(DIO_u8GetPinVal(DIO_PORTB, DIO_PIN1)== 0)
			{
				/*Set the motor pin high to operate the motor CW and turn on the left LED */
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN1, DIO_HIGH);
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN3, DIO_HIGH);
			}
			/*If the first switch is released*/
			else if(DIO_u8GetPinVal(DIO_PORTB, DIO_PIN1)== 1)
			{
				/*Set the motor pin low to turn off the motor and the left LED */
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN1, DIO_LOW);
				DIO_VidSetPinVal(DIO_PORTA, DIO_PIN3, DIO_LOW);
			}
			else
			{

			}
		}

	}
	return 0;
}
