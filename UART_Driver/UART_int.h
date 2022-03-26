/*
 * UART_int.h
 *
 *  Created on: Jul 23, 2019
 *      Author: Hamzy
 */

#ifndef UART_INT_H_
#define UART_INT_H_



/*********************************/
/********PUBLIC FUNCTION**********/
/*********************************/

/* Initialization Function*/
void UART_voidInit(void);

/* Sending Data Function*/
void UART_voidSend(u8 u8_Data);

/* Receiving Data Function*/
u8 UART_voidReceive(void);

#endif /* UART_INT_H_ */
