/*
 * TWI_priv.h
 *
 *  Created on: Aug 14, 2019
 *      Author: Hamzy
 */

#ifndef TWI_PRIV_H_
#define TWI_PRIV_H_


/* TWI Bit Rate Register TWBR */
#define TWBR     *((volatile u8*)0x20)

/* TWI Control Register TWCR */
#define TWCR     *((volatile u8*)0x56)

#define TWINT    7 // TWI Interrupt Flag **
#define TWEA     6 // TWI Enable Acknowledge bit
#define TWSTA    5 // TWI Start Condition bit
#define TWSTO    4 // TWI Stop Condition bit
#define TWWC     3 // TWI Write Collision
#define TWEN     2 // TWI Enable

#define TWIE     0 // TWI Interrupt Enable


/* TWI Status Register TWSR */
#define TWSR     *((volatile u8*)0x21)

#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3

#define TWPS1   1 // TWI Prescaller bit 1
#define TWPS0   0 // TWI Prescaller bit 0


/* TWI Data Register TWDR */
#define TWDR     *((volatile u8*)0x23)


/* TWI Slave Address Register TWAR */
#define TWAR     *((volatile u8*)0x22)

#define TWGCE    0



#endif /* TWI_PRIV_H_ */
