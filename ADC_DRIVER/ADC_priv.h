/*
 * ADC_priv.h
 *
 *  Created on: Jun 5, 2019
 *      Author: FUTURE
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


/***********************************************/
/*************PRIVATE DIFINTIOS (MACROS)********/
/***********************************************/


/*************ADC REGISTERS********/

#define ADC_REG      *((volatile u16*)0X24)
#define ADMUX_REG    *((volatile u8*)0X27)
#define ADCSRA_REG   *((volatile u8*)0X26)


/*************ADC MULTIPLEXER SELECTION REGISTER ADMUX********/

#define REFS1    7
#define REFS0    6
#define ADLAR    5
#define MUX4     4
#define MUX3     3
#define MUX2     2
#define MUX1     1
#define MUX0     0



/*************ADC STATUS & CONTROL REGISTER ADCSRA********/

#define ADEN     7
#define ADSC     6
#define ADATE    5
#define ADIF     4
#define ADIE     3
#define ADPS2    2
#define ADPS1    1
#define ADPS0    0

#endif /* ADC_PRIV_H_ */
