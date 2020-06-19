/*
 * KPD_int.h
 *
 *  Created on: May 4, 2019
 *      Author: FUTURE
 */

#ifndef KPD_INT_H_
#define KPD_INT_H_

/*********************************/
/********PUBLIC MACROS***********/
/*********************************/

#define KPD_COL_START   0
#define KPD_COL_END     4
#define KPD_ROW_START   4
#define KPD_ROW_END     8
#define KPD_LOW         0
#define KPD_HIGH        1


/***********************************/
/********PUBLIC FUNCTION***********/
/*********************************/

u8 KPD_u8getPress(void);

#endif /* KPD_INT_H_ */
