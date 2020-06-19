/*
 * TWI_int.h
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamzy
 */

#ifndef TWI_INT_H_
#define TWI_INT_H_

/*********************************/
/********PUBLIC FUNCTION**********/
/*********************************/

/* Initialization function*/
void TWI_voidInit(void);

void TWI_voidSendStart(void);

void TWI_voidSendStop(void);

void TWI_voidSendSlaveAdress_W(u8 u8Address_cpy);

void TWI_voidSendSlaveAdress_R(u8 u8Address_cpy);

u8 TWI_u8CheckStatus(u8 u8Status_cpy);

void TWI_voidSendData(u8 u8Data_cpy);

u8 TWI_u8ReceiveData(void);


#endif /* TWI_INT_H_ */
