/*
 * ADC_int.h
 *
 *  Created on: Jun 5, 2019
 *      Author: Hamzy
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_


/*********************************/
/********PUBLIC MACROS**********/
/*********************************/
#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4 	4
#define ADC_CH5 	5
#define ADC_CH6 	6
#define ADC_CH7 	7


/*********************************/
/********PUBLIC FUNCTION**********/
/*********************************/

void ADC_Initial(void);
u16 ADC_GetReading(u8 u8ADC_CH_cpy);

#endif /* ADC_INT_H_ */
