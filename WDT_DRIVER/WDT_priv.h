/*
 * WDT_priv.h
 *
 *  Created on: Jul 20, 2019
 *      Author: Hamzy
 */

#ifndef WDT_PRIV_H_
#define WDT_PRIV_H_



/***********************************************/
/*************PRIVATE DIFINTIOS (MACROS)********/
/***********************************************/


#define WDTCR         *((volatile u8*) 0x41)

#define WDTOE         4   // Watch dog turn-off enable
#define WDE           3   // Watch dog enable
#define WDP2          2   // Watch dog prescaller
#define WDP1          1   // Watch dog prescaller
#define WDP0          0   // Watch dog prescaller

#endif /* WDT_PRIV_H_ */
