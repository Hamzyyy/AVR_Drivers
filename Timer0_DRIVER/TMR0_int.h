/*
 * TMR_int.h
 *
 *  Created on: Jun 21, 2019
 *      Author: Hamzy
 */

#ifndef TMR0_INT_H_
#define TMR0_INT_H_


/*********************************/
/********PUBLIC MACROS************/
/*********************************/





/*********************************/
/********PUBLIC FUNCTION**********/
/*********************************/

/****Initialize the timer based on the MODE****/
void TMR0_voidInit_Normal(void);
void TMR0_voidInit_CTC(void);
void TMR0_voidInit_FAST_PWM(void);
void TMR0_voidInit_PHASE_CORRECT(void);


/****Assign Values to the TCNT & the Compare Register****/
void TMR0_voidSetTimerReg(u8 u8Val_cpy);
void TMR0_voidSetCompareReg(u8 u8Val_cpy);

/****Get the value of the timer register****/
u8 TMR0_u8GetCounterValue(void);

/****Overflow interrupt enable/disable functions****/
void TMR0_voidEnableOverflowInterrupt(void);
void TMR0_voidDisableOverflowInterrupt(void);


/****Compare match interrupt enable/disable functions****/
void TMR0_voidEnableCompareInterrupt(void);
void TMR0_voidDisableCompareInterrupt(void);


/****Global interrupt enable/disable functions****/
void TMR0_voidEnableGlobalInterrupt(void);
void TMR0_voidDisableGlobalInterrupt(void);



/****Callback functions****/
void TMR0_voidSetOverflowCallBack(void (*ptr_cpy)(void));
void TMR0_voidSetCompareCallBack(void (*ptr_cpy)(void));


#endif /* TMR0_INT_H_ */
