/*
 * EEPROM_int.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Hamzy
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_


/*********************************/
/*********PUBLIC MACROS***********/
/*********************************/

#define EEP_ADDRESS         0b01010000
/* Status at TWSR when Start Condition */
#define TWI_START           0x08
/* Status at TWSR when Repeated Start Condition */
#define TWI_RPT_START       0x10
/* Status at TWSR when Slave address sent and ACK received*/
#define TWI_MT_SLA_ACK      0x18
/* Status at TWSR when Slave address sent and not ACK received*/
#define TWI_MT_SLA_NACK     0x20
/* Status at TWSR when data sent and ACK received*/
#define TWI_MT_DATA_ACK     0x28
/* Status at TWSR when data sent and not ACK received*/
#define TWI_MT_DATA_NACK    0x30
/* Status at TWSR when Master lose arbitration "write mode" */
#define TWI_MT_ARB_LOST     0x38
/* Status at TWSR when Master lose arbitration "read mode" */
#define TWI_MR_ARB_LOST     0x38
/* Status at TWSR when Slave address sent and ACK received "read mode"*/
#define TWI_MR_SLA_ACK      0x40
/* Status at TWSR when Slave address sent and not ACK received "read mode"*/
#define TWI_MR_SLA_NACK     0x48
/* Status at TWSR when data sent and ACK received "read mode"*/
#define TWI_MR_DATA_ACK     0x50
/* Status at TWSR when data sent and not ACK received "read mode"*/
#define TWI_MR_DATA_NACK    0x58






/*********************************/
/********PUBLIC FUNCTION**********/
/*********************************/

void EEPROM_Init(void);

u8 EEPROM_WriteByte(u8 data, u8 block, u8 location);

u8 EEPROM_ReadByte(u8 block, u8 location, u8* byte);



#endif /* EEPROM_INT_H_ */
