/*
 * UART_prog.c
 *
 *  Created on: Jul 23, 2019
 *      Author: Hamzy
 */
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "UART_priv.h"
#include "UART_cfg.h"
#include "UART_int.h"



/* Initialization Function*/
void UART_voidInit(void)
{

	/* Baud Rate Select (when URSEL == 0) */
	    u16 Baud = 51;
	    UBRRH=(Baud>>8);
		UBRRL = Baud;

	/** Enable the Receiving and Transmitting **/
	UCSRB =(1<<RXEN) | (1<<TXEN);

	/** Number of bits Received/Transmitted = 8 bits "Frame Format"**/
	UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);

}



/* Sending Data Function*/
void UART_voidSend(u8 u8_Data)
{
	/*UDRE is set to indicate the transmitter is ready*/
	while ((UCSRA & (1<<UDRE))==0);
	UDR = u8_Data;

}



/* Receiving Data Function*/
u8 UART_voidReceive(void)
{
	/* RXC == 1 when there is unread data*/
	/* RXC == 0 when the receive buffer is empty*/
	while ((UCSRA & (1<<RXC))==0);
	return UDR;
}
