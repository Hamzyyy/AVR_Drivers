/*
 * TWI_prog.c
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamzy
 */

#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "TWI_priv.h"
#include "TWI_int.h"


/* Initialization function*/
void TWI_voidInit(void)
{
	/*Enable I2C*/
	TWCR |= (1<<TWEN);

	/*SCL = F_CPU/ 16 + 2*TWBR * 4^TWPS*/
	/*SCL = 8,000,000/ 16 + 2*8 * 4^0 = 250,000*/
	TWBR = 8;

	/*TWPS1 = 0 TWPS0 = 0*/
	TWSR = 0;

	TWAR = 2;

}



/* Sending Start Condition */
void TWI_voidSendStart(void)
{
	/* Clear interrupt flag
	 * Enable TWI
	 * Set Start bit
	 */
   TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);

   /*As long as the flag is down keep checking */
   while((TWCR & (1<<TWINT))==0);
}



/* Sending Stop Condition */
void TWI_voidSendStop(void)
{
	/* Clear interrupt flag
	 * Enable TWI
	 * Set Stop bit
	 */
   TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}



/* Sending the Slave address with Write command */
void TWI_voidSendSlaveAdress_W(u8 u8Address_cpy)
{
	/* 7 bit address shifted lift by one bit
	 * Then added 0 to "read" |0x00
	 */
	TWDR = (u8Address_cpy<<1);

	/* Clear interrupt flag
	 * Enable TWI
	 */
   TWCR |= (1<<TWINT) | (1<<TWEN);

   /*As long as the flag is down keep checking */
   while((TWCR & (1<<TWINT))==0);
}



/* Sending the Slave address with Read command */
void TWI_voidSendSlaveAdress_R(u8 u8Address_cpy)
{
	/* 7 bit address shifted lift by one bit
	 * Then added 1 to "read" |0x01
	 */
	TWDR = (u8Address_cpy<<1) | 0x01;

	/* Clear interrupt flag
	 * Enable TWI
	 */
   TWCR |= (1<<TWINT) | (1<<TWEN);

   /*As long as the flag is down keep checking */
   while((TWCR & (1<<TWINT))==0);
}


/* Status checking function */
u8 TWI_u8CheckStatus(u8 u8Status_cpy)
{
	/*masking the first 3 bits*/
	if ((TWSR & 0xF8) == u8Status_cpy)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0xFF;
}


/* Send data Byte function */
void TWI_voidSendData(u8 u8Data_cpy)
{
	TWDR = u8Data_cpy;

	/* Clear interrupt flag
	 * Enable TWI
	 */
   TWCR |= (1<<TWINT) | (1<<TWEN);

   /*As long as the flag is down keep checking */
   while((TWCR & (1<<TWINT))==0);
}


/* Receiving data Byte function */
u8 TWI_u8ReceiveData(void)
{
	/* Clear interrupt flag
	 * Enable TWI
	 */
   TWCR |= (1<<TWINT) | (1<<TWEN);

   /*As long as the flag is down keep checking */
   while((TWCR & (1<<TWINT))==0);

   return TWDR;
}
