/*
 * WDT_int.h
 *
 *  Created on: Jul 20, 2019
 *      Author: Hamzy
 */

#ifndef WDT_INT_H_
#define WDT_INT_H_

/*********************************/
/********PUBLIC MACROS************/
/*********************************/

/*** NUMBER OF WATCH DOG OSCILATOR CYCLE ***/

#define WDT_16K_CYCLE		0  // Time out = 16.3 ms
#define WDT_32K_CYCLE		1  // Time out = 32.5 ms
#define WDT_64K_CYCLE		2  // Time out = 65 ms
#define WDT_128K_CYCLE		3  // Time out = 0.13 s
#define WDT_256K_CYCLE		4  // Time out = 0.26 s
#define WDT_502K_CYCLE		5  // Time out = 0.52 s
#define WDT_1024K_CYCLE		6  // Time out = 1 s
#define WDT_2048K_CYCLE		7  // Time out = 2.1 s




/*********************************/
/********PUBLIC FUNCTION**********/
/*********************************/


void WDT_voidStart(u8 u8_cycles_NO_cpy);
void WDT_voidStop(void);


#endif /* WDT_INT_H_ */
