/*
 * TMR_int.h
 *
 *  Created on: Jul 13, 2019
 *      Author: Hamzy
 */

#ifndef TMR1_INT_H_
#define TMR1_INT_H_


/*****************************************************/
/**************** PUBLIC MACROS **********************/
/*****************************************************/


/******** TMR1 EDGE SELECT **********/
#define TMR1_FALLING_EDGE                  0
#define TMR1_RISING_EDGE                   1

/******** TMR1 CHANEL SELECT **********/
#define TMR1_CHA                           0
#define TMR1_CHB                           1


/******** TIMER MODES **********/
/******** TCCR1A **********/
/******** WAVE GENERATION BITS WGM10:WGM13 **********/

#define TMR1_NORMAL_MODE                    0
#define TMR1_CTC_MODE                       4
#define TMR1_PHASE_FREQ_CORRECT_MODE        8
#define TMR1_PHASE_CORRECT_MODE             10
#define TMR1_FAST_PWM_MODE                  14





/*******************************************************/
/********************PUBLIC FUNCTION********************/
/*******************************************************/

/****Initialize the timer based on the MODE****/
void TMR1_voidInit_Normal(void);
void TMR1_voidInit_CTC(u8 u8Ch_cpy);
void TMR1_voidInit_FAST_PWM(u8 u8Ch_cpy);
void TMR1_voidInit_PHASE_CORRECT(u8 u8Ch_cpy);
void TMR1_voidInit_PHASE_FREQ_CORRECT(u8 u8Ch_cpy);


/****Assign Values to the TCNT & the Compare Registers****/
void TMR1_voidSetTimerReg(u16 u16Val_cpy);
void TMR1_voidSetCompareRegA(u16 u16Val_cpy);
void TMR1_voidSetCompareRegB(u16 u16Val_cpy);
void TMR1_voidSetICU_Reg(u16 u16Val_cpy);

/****Get the value of the timer register****/
u16 TMR1_u16GetCounterValue(void);
u16 TMR1_u16GetICU_Value(void);

/****Overflow interrupt enable/disable functions****/
void TMR1_voidEnableOverflowInterrupt(void);
void TMR1_voidDisableOverflowInterrupt(void);


/****Compare match interrupt enable/disable functions****/
void TMR1_voidEnableCompareInterruptA(void);
void TMR1_voidDisableCompareInterruptA(void);

void TMR1_voidEnableCompareInterruptB(void);
void TMR1_voidDisableCompareInterruptB(void);

void TMR1_voidEnableICU_Interrupt(void);
void TMR1_voidDisableICU_Interrupt(void);

void TMR1_voidICU_EdgeSelect(u8 u8Edge_cpy);


/****Global interrupt enable/disable functions****/
void TMR1_voidEnableGlobalInterrupt(void);
void TMR1_voidDisableGlobalInterrupt(void);



/****Callback functions****/
void TMR1_voidSetOverflowCallBack(void (*ptr_cpy)(void));
void TMR1_voidSetCompareCallBackA(void (*ptr_cpy)(void));
void TMR1_voidSetCompareCallBackB(void (*ptr_cpy)(void));


#endif /* TMR1_INT_H_ */
