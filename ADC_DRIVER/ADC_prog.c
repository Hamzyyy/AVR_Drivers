/*
 * ADC_prog.c
 *
 *  Created on: Jun 5, 2019
 *      Author: Hamzy
 */
#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "ADC_priv.h"
#include "ADC_cfg.h"
#include "ADC_int.h"


#if ADLAR_ADJ == LEFT_ADJ


#elif ADLAR_ADJ == RIGHT_ADJ
	/****ADC INITIALIZATION FUNCTION****/
void ADC_Initial(void)
{
	/****SELECT REFERENCE VOLATAGE: Select the AVCC 5v****/
	ADMUX_REG |= (1<<REFS0);

	/****SELECT PRESCALER DIVISION FACTOR: Select Division by / 64 to Get 8,000,000/64 = 125,000****/
	ADCSRA_REG |= (1<<ADPS2) | (1<<ADPS1);

	/****ADC ENABLE "TURN ON"****/
	ADCSRA_REG |= (1<<ADEN);
}


    /****ADC FUNCTION TO GET THE RESULTS****/
u16 ADC_GetReading(u8 u8ADC_CH_cpy)
{

	/****The number from user is ANDED with 111 = 7 to make sure it is not > 7****/
	/***mask by clearing all other bits except for the needed bits***/
	u8ADC_CH_cpy &= 0b00000111;

	/****Select the conversion Channel on ADMUX_REG****/
	/****Be SETTING the first three bits****/
	/****Also ANDing the ADMUX with 0b11111000 to make sure if any bit from 3:7 == 1 kept == 1****/
	ADMUX_REG = (ADMUX_REG & 0xF8) | u8ADC_CH_cpy;

	/****Start Conversion by SETTING ADSC****/
	ADCSRA_REG |= (1<<ADSC);

	/****Wait until the Conversion is Completed ADIF == 1 "POLLING"****/
	while ((ADCSRA_REG &(1<<ADIF)) == 0);


	/*** Return the content of the Registers "ADCL & ADCH" == Counts***/
	return ADC_REG;

}


#else
#endif

