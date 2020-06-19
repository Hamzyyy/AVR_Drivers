/*
 * SPI_priv.h
 *
 *  Created on: Jul 29, 2019
 *      Author: Hamzy
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_



/*********************************/
/********PRIVATE MACROS***********/
/*********************************/

/* SPI Control Register SPCR */
#define SPCR          *((volatile u8*) 0x2D)


#define SPIE          7
#define SPE           6
#define DORD          5
#define MSTR          4
#define CPOL          3
#define CPHA          2
#define SPR1          1
#define SPR0          0



/* SPI Status Register SPSR */
#define SPSR          *((volatile u8*) 0x2E)


#define SPIF          7
#define WCOL          6
#define SPI2X         0


/* SPI Data SPSR */
#define SPDR         *((volatile u8*) 0x2F)

#define MSB          7
#define LSB          0





#endif /* SPI_PRIV_H_ */
