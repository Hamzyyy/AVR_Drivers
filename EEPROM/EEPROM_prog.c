/*
 * EEPROM_prog.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Hamzy
 */
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "TWI_priv.h"
#include "TWI_int.h"
#include "EEPROM_int.h"

u8 EEPROM_WriteByte(u8 data, u8 block, u8 location)
{
	/* Send Start*/
	TWI_voidSendStart();
	/* Check Status if equal 0 exit */
	if (TWI_u8CheckStatus(TWI_START)!= 1)
	return 0;

	/* Master sends Slave address (1010 + block + write) */
	TWI_voidSendSlaveAdress_W((EEP_ADDRESS) | (block));
	/* Slave sends ACK */
	if (TWI_u8CheckStatus(TWI_MT_SLA_ACK)!= 1)
	return 1;

	/* Master sends byte address (location from 0:255) */
	TWI_voidSendData(location);
	/* Slave sends ACK */
	if (TWI_u8CheckStatus(TWI_MT_DATA_ACK)!= 1)
	return 2;

	/* Master sends data byte*/
	TWI_voidSendData(data);
	/* Slave sends ACK */
	if (TWI_u8CheckStatus(TWI_MT_DATA_ACK)!= 1)
	return 3;

	/* Send Stop*/
	TWI_voidSendStop();
	return 9;
}


u8 EEPROM_ReadByte(u8 block, u8 location, u8* byte)
{
	/* Send Start*/
	TWI_voidSendStart();
	/* Check Status if equal 0 exit */
	if (TWI_u8CheckStatus(TWI_START)!= 1)
	return 0;


	/* Master sends Slave address (1010 + block + write) */
	TWI_voidSendSlaveAdress_W((EEP_ADDRESS) | (block));
	/* Slave sends ACK */
	if (TWI_u8CheckStatus(TWI_MT_SLA_ACK)!= 1)
	return 1;


	/* Master sends byte address (location from 0:255) */
	TWI_voidSendData(location);
	/* Slave sends ACK */
	if (TWI_u8CheckStatus(TWI_MT_DATA_ACK)!= 1)
	return 2;


	/* Repeated Send Start*/
	TWI_voidSendStart();
	/* Check Status if equal 0 exit */
	if (TWI_u8CheckStatus(TWI_RPT_START)!= 1)
	return 3;


	/* Master sends Slave address (1010 + block + read) */
	TWI_voidSendSlaveAdress_R((EEP_ADDRESS) | (block));
	/* Slave sends ACK */
	if (TWI_u8CheckStatus(TWI_MR_SLA_ACK)!= 1)
	return 4;

	/* store the received byte in the pointer to array */
	*byte = TWI_u8ReceiveData();


	/* Send Stop*/
	TWI_voidSendStop();
	return 5;

}
