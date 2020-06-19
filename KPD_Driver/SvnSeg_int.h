/*
 * DIO_int.h
 *
 *  Created on: Feb 15, 2019
 *      Author: FUTURE
 */

#ifndef SVNSEG_INT_H_
#define SVNSEG_INT_H_

/*********************************/
/********PUBLIC MACROS***********/
/*********************************/


/* Seven Segment modes*/

#define SvnSeg_CommonCathode 0
#define SvnSeg_CommonAnode   1

/*********************************/
/********PUBLIC FUNCTION***********/
/*********************************/

u8 u8Svn_Seg( u8 u8_modeCPY, u8 u8_numberCPY);


#endif /* SVNSEG_INT_H_ */
