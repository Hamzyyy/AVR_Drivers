/*
 * DIO_int.h
 *
 *  Created on: Feb 15, 2019
 *      Author: FUTURE
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

/*********************************/
/********PUBLIC MACROS************/
/*********************************/

// PORT DEFINITION
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3



// PIN DEFINITION
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

// IO DIRECTION
#define DIO_OUTPUT 1
#define DIO_INPUT  0

#define DIO_PORT_OUTPUT 255
#define DIO_PORT_INPUT   0


// IO STATE (PIN/PORT VALUE)
#define DIO_HIGH 1
#define DIO_LOW  0

#define DIO_PORT_HIGH  255
#define DIO_PORT_LOW   0

/***********************************/
/********PUBLIC FUNCTION***********/
/*********************************/


/* IO Pins Functions */

void DIO_VidSetPinDir(u8 u8PortID_Cpy, u8 u8PinID_Cpy, u8 u8PinDir_Cpy); // return void because it's setter not getter

void DIO_VidSetPinVal(u8 u8PortID_Cpy, u8 u8PinID_Cpy, u8 u8PinVal_Cpy);

u8 DIO_u8GetPinVal (u8 u8PortID_Cpy, u8 u8PinID_Cpy);

/* IO Port Functions */

void DIO_VidSetPortDir (u8 u8PortID_Cpy, u8 u8PortDir_Cpy);
void DIO_VidSetPortVal (u8 u8PortID_Cpy, u8 u8PortVal_Cpy);
u8 DIO_u8GetPortVal(u8 u8PortID_Cpy);

#endif /* DIO_INT_H_ */
