/*
 * SPI_prog.c
 *
 *  Created on: Jul 29, 2019
 *      Author: Hamzy
 */
#include "Lib/types.h"
#include "DIO_priv.h"
#include "DIO_int.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"
#include "SPI_int.h"

#if SPI_MODE == SPI_MASTER

/* Master Initialization Function */
void SPI_vidMasterInit(void)
{
  /*Set MOSI & CLK as output*/
	DDRB_REG = (1<<MOSI) | (1<<SCK) | (1<<SS);


  /* 1. Enable SPI SPE = 1
   * 2. Select MASTER MODE MSTR = 1
   * 3. Select CLK = FCPU/16 SPR0 = 1
   */
  SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


/* Send Data Function */
void SPI_send(u8 data)
{
	SPDR = data;
	/* Do not exit the loop while SPIF == 0 */
	while ((SPSR & (1<<SPIF)) ==0);

}

#elif SPI_MODE == SPI_SLAVE

/* Slave Initialization Function */
void SPI_vidSlaveInit(void)
{
	  /* Set MISO */
	  DIO_VidSetPinDir(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);

	  /* 1. Enable SPI SPE = 1 */
	  SPCR |= (1<<SPE);
}

/* Receive Data Function */
u8 SPI_u8receive(void)
{
	/* Do not exit the loop while SPIF == 0 */
	while ((SPSR & (1<<SPIF)) ==0);

	return SPDR;
}

/* Check Sent Function */
u8 SPI_u8dataCheck(void)
{
	return 0;
}

#else
#endif
