/*
 * TMR_prog.c
 *
 *  Created on: Jun 21, 2019
 *      Author: Hamzy
 */

#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "TMR0_priv.h"
#include "TMR0_int.h"
#include "TMR0_cfg.h"


/** Global Variable (Pointer) to a function (Related to normal mode)***/
void (*TMR0_OverflowCallBack)(void);

/** Global Variable (Pointer) to a function (Related to CTC match mode)***/
void (*TMR0_CompareCallBack)(void);

/*** In Case Of NORMAL MODE ***/
#if TMR0_MODE == TMR0_NORMAL_MODE

void TMR0_voidInit_Normal(void)
{
	/** Set the TCNT at the initial value**/
	TCNT0 = 0;


	/** Enable the overflow interrupt**/
	TIMSK |= (1<<TOIE0);

	/*** Configure the timer control register
	 * 1. non-PWM mode FOC0 = 1
	 * 2. normal mode WFM00 = 0 & WGM01 = 0
	 * 3. normal mode COM01 = 0 & COM00 = 0
	 * clock = F_CPU/1024 CS02 = 1 CS01 = 0 CS00 = 1
	 *
	 */


	/** Choose the prescaler (clock = F_CPU/1024)**/
	/** CS02 = 1 CS01 = 0 CS00 =1**/
	TCCR0 = (1<<FOC0) | TMR0_PRESCALLER;


	/** SET OC0 mode to toggle on Compare**/
	/** SET bit NO.4 COM00 by 1**/
	TCCR0 |= (TMR0_TOGGLE_OC0<<COM00);
}


/*** In Case Of CTC MODE ***/
#elif TMR0_MODE == TMR0_CTC_MODE

void TMR0_voidInit_CTC(void)
{
	/** Set the TCNT at the initial value**/
	TCNT0 = 0;

	/*** Configure the timer control register
	 * 1. non-PWM mode FOC0 = 1
	 * 2. CTC mode WFM00 = 0 & WGM01 = 1
	 * 3. CTC mode (toggle) COM01 = 0 & COM00 = 1
	 * clock = F_CPU/1024 CS02 = 1 CS01 = 0 CS00 = 1
	 *
	 */

	/** Choose the prescaller (clock = F_CPU/1024)**/
	/** CS02 = 1 CS01 = 0 CS00 =1**/
	TCCR0 = (1<<FOC0) | TMR0_PRESCALLER;

	/** CTC mode**/
	TCCR0 |= (1<<WGM01);

	/** SET OC0 mode to toggle on Compare**/
	/** SET bit NO.4 COM00 by 1**/
	TCCR0 |= (TMR0_COMPARE_EVENT<<COM00);


	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<OCIE0);
}

/*** In Case Of FAST PWM MODE ***/
#elif TMR0_MODE == TMR0_FAST_PWM_MODE

void TMR0_voidInit_FAST_PWM(void)
{
	/** Set the TCNT at the initial value**/
	TCNT0 = 0;

	/*** Configure the timer control register
	 * 1. PWM mode FOC0 = 0
	 * 2. Fast PWM mode WFM00 = 1 & WGM01 = 1
	 * 3. CTC mode (toggle) COM01 = 0 & COM00 = 1
	 * clock = F_CPU/1024 CS02 = 1 CS01 = 0 CS00 = 1
	 *
	 */

	/** Choose the prescaller (clock = F_CPU/1024)**/
	/** CS02 = 1 CS01 = 0 CS00 =1**/
	TCCR0 = (0<<FOC0) | TMR0_PRESCALLER;

	/** Set the output compare register at the initial value**/
	OCR0 = 0;


	/** Fast PWM mode WFM00 = 1 & WGM01 = 1 **/
	TCCR0 |= (1<<WGM01) | (1<<WGM00);


	/** SET OC0 mode Non inverting**/
	/** SET COM00 = 1 & COM01 = 1**/
	TCCR0 |= (1<<COM00) | (1<<COM01);


	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<OCIE0);
}


/*** In Case Of Phase Correct MODE ***/
#elif TMR0_MODE == TMR0_PHASE_CORRECT_MODE

void TMR0_voidInit_PHASE_CORRECT(void)
{

	/** Set the TCNT at the initial value**/
	TCNT0 = 0;

	/*** Configure the timer control register
	 * 1. PWM mode FOC0 = 0
	 * 2. Fast PWM mode WFM00 = 1 & WGM01 = 1
	 * 3. CTC mode (toggle) COM01 = 0 & COM00 = 1
	 * clock = F_CPU/1024 CS02 = 1 CS01 = 0 CS00 = 1
	 *
	 */


	/** Choose the prescaller (clock = F_CPU/1024)**/
	/** CS02 = 1 CS01 = 0 CS00 =1**/
	TCCR0 = (0<<FOC0) | TMR0_PRESCALLER;


	/** Set the output compare register at the initial value**/
	OCR0 = 0;


	/** Phase Correct PWM mode WFM00 = 1 & WGM01 = 0 **/
	TCCR0 |= (1<<WGM00);


	/** SET OC0 mode Non inverting**/
	/** SET COM00 = 1 & COM01 = 1**/
	TCCR0 |= (1<<COM00) | (1<<COM01);


	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<OCIE0);
}

#endif

/*
 * Description:      Timer0 set TIMER_REG function
 * Input argument:   u8
 * Return argument:  void
 */

void TMR0_voidSetTimerReg(u8 u8Val_cpy)
{
	TCNT0 = u8Val_cpy;
}


/*
 * Description:      set OUTPUT COMPARE_REG function
 * Input argument:   u8
 * Return argument:  void
 */

void TMR0_voidSetCompareReg(u8 u8Val_cpy)
{
	OCR0 = u8Val_cpy;
}

/*
 * Description:      Get timer value
 * Input argument:   void
 * Return argument:  u8
 */

u8 TMR0_u8GetCounterValue(void)
{
	return TCNT0;
}


/*
 * Description:      TMR0 enable overflow interrupt
 * Input argument:   void
 * Return argument:  void
 */

void TMR0_voidEnableOverflowInterrupt(void)
{
	/** Enable the overflow interrupt**/
	TIMSK |= (1<<TOIE0);
}


/*
 * Description:      TMR0 disable overflow interrupt
 * Input argument:   void
 * Return argument:  void
 */

void TMR0_voidDisableOverflowInterrupt(void)
{
	/** Disable the overflow interrupt**/
	TIMSK &= ~(1<<TOIE0);
}


/*
 * Description:      TMR0 enable compare match interrupt
 * Input argument:   void
 * Return argument:  void
 */

void TMR0_voidEnableCompareInterrupt(void)
{
	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<OCIE0);
}


/*
 * Description:      TMR0 disable compare match interrupt
 * Input argument:   void
 * Return argument:  void
 */

void TMR0_voidDisableCompareInterrupt(void)
{
	/** Enable the output compare match interrupt**/
	TIMSK &= ~(1<<OCIE0);
}


/*
 * Description:      TMR0 enable global interrupt
 * Input argument:   void
 * Return argument:  void
 */

void TMR0_voidEnableGlobalInterrupt(void)
{
	/** Enable the global interrupt**/
	SREG  |= (1<<IBIT);
}

/*
* Description:      TMR0 disable global interrupt
* Input argument:   void
* Return argument:  void
*/

void TMR0_voidDisableGlobalInterrupt(void)
{
	/** Enable the global interrupt**/
	SREG  &= ~(1<<IBIT);
}



/** Description:       Overflow call back function
 * Input argument:     void
 * Return argument:    void
 */

void TMR0_voidSetOverflowCallBack(void (*ptr_cpy)(void))
{
	/**the pointer to function is assigned to the *ptr to another function(of the application)**/
	TMR0_OverflowCallBack = ptr_cpy;
}


/** Description:       Compare call back function
 * Input argument:     void
 * Return argument:    void
 */

void TMR0_voidSetCompareCallBack(void (*ptr_cpy)(void))
{
	/**the pointer to function is assigned to the *ptr to another function(of the application)**/
	TMR0_CompareCallBack = ptr_cpy;
}

/** The prototype and implementation of the ISR **/
/** plus the #pragma to tell the linker it's a signal = ISR used = no call**/
   void __vector_11(void)__attribute__((signal, used));
   void __vector_11(void)
   {
	   TMR0_OverflowCallBack();
   }

/** The prototype and implementation of the ISR **/
/** The prototype and implementation of the ISR **/
   /** plus the #pragma to tell the linker it's a signal = ISR used = no call**/
      void __vector_10(void)__attribute__((signal, used));
      void __vector_10(void)
      {
    	  TMR0_CompareCallBack();
      }


