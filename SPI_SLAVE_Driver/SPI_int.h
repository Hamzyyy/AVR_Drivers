/*
 * SPI_int.h
 *
 *  Created on: Jul 29, 2019
 *      Author: Hamzy
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_


/*******************************************************/
/********************PUBLIC MACROS********************/
/*******************************************************/

#define SPI_SLAVE    0
#define SPI_MASTER   1

/*SPI PINS*/
/*SPI PINS*/
#define SS     4
#define MOSI   5
#define MISO   6
#define SCK    7






/*******************************************************/
/********************PUBLIC FUNCTION********************/
/*******************************************************/

/* Master Initialization Function */
void SPI_vidMasterInit(void);

/* Slave Initialization Function */
void SPI_vidSlaveInit(void);

/* Send Data Function */
void SPI_send(u8 data);

/* Receive Data Function */
u8 SPI_u8receive(void);

/* Check Sent Function */
u8 SPI_u8dataCheck(void);


#endif /* SPI_INT_H_ */
