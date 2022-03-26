/*
 * TMR_prog.c
 *
 *  Created on: Jul 13, 2019
 *      Author: Hamzy
 */

#include "Lib/types.h"
#include "Lib/bitwise.h"
#include "TMR1_priv.h"
#include "TMR1_int.h"
#include "TMR1_cfg.h"



/** Global Variable (Pointer) to a function (Related to normal mode)***/
void (*TMR1_OverflowCallBack)(void);

/** Global Variable (Pointer) to a function (Related to CTC A match mode)***/
void (*TMR1_CompareCallBackA)(void);

/** Global Variable (Pointer) to a function (Related to CTC B match mode)***/
void (*TMR1_CompareCallBackB)(void);

/*** In Case Of NORMAL MODE ***/
#if TMR1_MODE == TMR1_NORMAL_MODE

void TMR1_voidInit_Normal(void)
{
	/** Set the TCNT at the initial value**/
	TCNT1 = 0;


	/** Enable the overflow interrupt**/
	TIMSK |= (1<<TOIE1);

	/*** Configure the timer control register
	 * 1. non-PWM mode FOC1A = 1 & FOC1B = 1
	 * 2. normal mode COM1A0 = 1 & COM1B0 = 1 TOGGLE OC1A & OC1B
	 * 3. clock = F_CPU/8 CS12 = 0 CS11 = 1 CS10 = 0
	 */

	/** For a NON-PWM mode**/
	/** FOC1A = 1 & FOC1B = 1**/
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);

	/** Choose the prescaler (clock = F_CPU/8)**/
	/** CS12 = 0 CS11 = 1 CS00 =0**/
	TCCR1B |=  TMR1_PRESCALLER;


	/** SET OC1 mode to toggle on Compare**/
	/** SET COM1A0 & COM1B0 by 1**/

	/** OC1A OUTPUT WAVE**/
	TCCR1A |= (TMR1_TOGGLE_OC1<<COM1A0);

	/** OC1B OUTPUT WAVE**/
	TCCR1A |= (TMR1_TOGGLE_OC1<<COM1B0);
}


/*** In Case Of CTC MODE ***/
#elif TMR1_MODE == TMR1_CTC_MODE

void TMR1_voidInit_CTC(u8 u8Ch_cpy)
{
	/** Set the TCNT at the initial value**/
	TCNT1 = 0;

	/** Choose the prescaler (clock = F_CPU/8)**/
	/** CS12 = 0 CS11 = 1 CS00 =0**/
	TCCR1B |=  TMR1_PRESCALLER;

	/*** Configure the timer control register
	 * 1. non-PWM mode FOC1A = 1 & FOC1B = 1
	 * 2. CTC mode WFM13 = 0, WFM12 = 1, WGM11 = 0  & WGM10 = 0
	 * 3. CTC mode (toggle) COM1A0 = 1 OR COM1B0 = 1
	 * 4. Clock = F_CPU/8 CS12 = 0 CS11 = 1 CS10 = 0
	 */

	switch (u8Ch_cpy)
	{
	     /** Output wave on OC1A**/
	     case TMR1_CHA:
	     TMR1_voidEnableCompareInterruptA();
	     TCCR1A |= (1<<FOC1A);
	     /** Toggle OC1A on compare match**/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1A0);
		 break;


		  /** Output wave on OC1A**/
	     case TMR1_CHB:
	     TMR1_voidEnableCompareInterruptB();
	     TCCR1A |= (1<<FOC1B);
	     /** Toggle OC1B on compare match**/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1B0);
		 break;
	}

	/** CTC mode**/
	/** WGM12 = 1**/
	TCCR1B |= (1<<WGM12);
}

/*** In Case Of FAST PWM MODE ***/
#elif TMR1_MODE == TMR1_FAST_PWM_MODE

void TMR1_voidInit_FAST_PWM(u8 u8Ch_cpy);
{
	/** Set the TCNT at the initial value**/
	TCNT1 = 0;

	/*** Configure the timer control register
	 * 1. PWM mode FOC1A = 0 & FOC1B = 0
	 * 2. FAST PWM mode WFM13 = 1, WFM12 = 1, WGM11 = 1  & WGM10 = 0
	 * 3. FAST PWM mode (non-inverting) Clear COM1A1 = 1 OR COM1B1 = 1 on compare match
	 * 4. Clock = F_CPU/8 CS12 = 0 CS11 = 1 CS10 = 0
	 */

	/** Choose the prescaler (clock = F_CPU/8)**/
	/** CS12 = 0, CS11 = 1 & CS00 =0**/
	TCCR1B |=  TMR1_PRESCALLER;

	switch (u8Ch_cpy)
	{
	     /** Output wave on OC1A**/
	     case TMR1_CHA:
	     TMR1_voidEnableCompareInterruptA();
	     /** Non-inverting mode **/
	     /** Clear OC1A on compare match and set on top **/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1A1);
		 break;


		  /** Output wave on OC1A**/
	     case TMR1_CHB:
	     TMR1_voidEnableCompareInterruptB();
	     /** Non-inverting mode **/
	     /** Clear OC1B on compare match and set on top **/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1B1);
		 break;
	}

	/** Fast PWM mode **/
	/** WGM10 = 0, WGM11 = 1, WGM12 = 1 & WGM13 = 1 **/
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<WGM13);

}


/*** In Case Of Phase Correct MODE ***/
#elif TMR1_MODE == TMR1_PHASE_CORRECT_MODE

void TMR1_voidInit_PHASE_CORRECT(u8 u8Ch_cpy)
{

	/** Set the TCNT at the initial value**/
	TCNT1 = 0;

	/*** Configure the timer control register
	 * 1. PWM mode FOC1A = 0 & FOC1B = 0
	 * 2. Phase Correct PWM mode WFM13 = 1, WFM12 = 0, WGM11 = 1  & WGM10 = 0
	 * 3. Phase Correct PWM mode (non-inverting) Clear COM1A1 = 1 OR COM1B1 = 1 on compare match
	 * 4. Clock = F_CPU/8 CS12 = 0 CS11 = 1 CS10 = 0
	 */


	/** Choose the prescaler (clock = F_CPU/8)**/
	/** CS12 = 0, CS11 = 1 & CS00 =0**/
	TCCR1B |=  TMR1_PRESCALLER;


	switch (u8Ch_cpy)
	{
	     /** Output wave on OC1A**/
	     case TMR1_CHA:
	     TMR1_voidEnableCompareInterruptA();
	     /** Non-inverting mode **/
	     /** Clear OC1A on compare match and set on top **/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1A1);
		 break;


		  /** Output wave on OC1A**/
	     case TMR1_CHB:
	     TMR1_voidEnableCompareInterruptB();
	     /** Non-inverting mode **/
	     /** Clear OC1B on compare match and set on top **/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1B1);
		 break;
	}

	/** Phase Correct PWM mode **/
	/** WGM10 = 0, WGM11 = 1, WGM12 = 0 & WGM13 = 1 **/
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM13);
}

/*** In Case Of Phase And Frequency Correct MODE ***/
#elif TMR1_MODE == TMR1_PHASE_FREQ_CORRECT_MODE

void TMR1_voidInit_PHASE_FREQ_CORRECT(u8 u8Ch_cpy)
{
	/** Set the TCNT at the initial value**/
	TCNT1 = 0;

	/*** Configure the timer control register
	 * 1. PWM mode FOC1A = 0 & FOC1B = 0
	 * 2. Phase Correct and Frequency PWM mode WFM13 = 1, WFM12 = 0, WGM11 = 0  & WGM10 = 0
	 * 3. Phase Correct and Frequency PWM mode (non-inverting) Clear COM1A1 = 1 OR COM1B1 = 1 on compare match
	 * 4. Clock = F_CPU/8 CS12 = 0 CS11 = 1 CS10 = 0
	 */


	/** Choose the prescaler (clock = F_CPU/8)**/
	/** CS12 = 0, CS11 = 1 & CS00 =0**/
	TCCR1B |=  TMR1_PRESCALLER;


	switch (u8Ch_cpy)
	{
	     /** Output wave on OC1A**/
	     case TMR1_CHA:
	     TMR1_voidEnableCompareInterruptA();
	     /** Non-inverting mode **/
	     /** Clear OC1A on compare match and set on top **/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1A1);
		 break;


		  /** Output wave on OC1A**/
	     case TMR1_CHB:
	     TMR1_voidEnableCompareInterruptB();
	     /** Non-inverting mode **/
	     /** Clear OC1B on compare match and set on top **/
		 TCCR1A |= (TMR1_TOGGLE_OC1<<COM1B1);
		 break;
	}

	/** Phase & Frequency PWM mode **/
	/** WGM10 = 0, WGM11 = 0, WGM12 = 0 & WGM13 = 1 **/
	TCCR1B |= (1<<WGM13);

}

#endif



/*
 * Description:      Timer1 set TIMER_REG
 * Input argument:   u16
 * Return argument:  Void
 */
void TMR1_voidSetTimerReg(u16 u16Val_cpy)
{
	TCNT1 = u16Val_cpy;
}



/*
 * Description:      Set OUTPUT COMPAREA_REG A
 * Input argument:   u16
 * Return argument:  Void
 */
void TMR1_voidSetCompareRegA(u16 u16Val_cpy)
{
	OCR1A = u16Val_cpy;
}



/*
 * Description:      Set OUTPUT COMPAREA_REG B
 * Input argument:   u16
 * Return argument:  Void
 */
void TMR1_voidSetCompareRegB(u16 u16Val_cpy)
{
	OCR1B = u16Val_cpy;
}



/*
 * Description:      Set ICU_Reg
 * Input argument:   u16
 * Return argument:  Void
 */
void TMR1_voidSetICU_Reg(u16 u16Val_cpy)
{
	ICR1 = u16Val_cpy;
}




/*
 * Description:      Get timer value
 * Input argument:   void
 * Return argument:  u16
 */
u16 TMR1_u16GetCounterValue(void)
{
	return TCNT1;
}



/*
 * Description:      Get ICU value
 * Input argument:   void
 * Return argument:  u16
 */

u16 TMR1_u16GetICU_Value(void)
{
	return ICR1;
}


/*
 * Description:      TMR1 enable overflow interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidEnableOverflowInterrupt(void)
{
	/** Enable the overflow interrupt**/
	TIMSK |= (1<<TOIE1);
}




/*
 * Description:      TMR1 disable overflow interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidDisableOverflowInterrupt(void)
{
	/** Disable the overflow interrupt**/
	TIMSK &= ~(1<<TOIE1);
}





/*
 * Description:      TMR1 enable compare match A interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidEnableCompareInterruptA(void)
{
	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<OCIE1A);
}




/*
 * Description:      TMR1 disable compare match A interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidDisableCompareInterruptA(void)
{
	/** Disable the output compare match interrupt**/
	TIMSK &= ~(1<<OCIE1A);
}




/*
 * Description:      TMR1 enable compare match B interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidEnableCompareInterruptB(void)
{
	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<OCIE1B);
}



/*
 * Description:      TMR1 disable compare match B interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidDisableCompareInterruptB(void)
{
	/** Disable the output compare match interrupt**/
	TIMSK &= ~(1<<OCIE1B);
}

/*********************************************************/

/*
 * Description:      TMR1 enable ICU interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidEnableICU_Interrupt(void)
{
	/** Enable the output compare match interrupt**/
	TIMSK |= (1<<TICIE1 );
}



/*
 * Description:      TMR1 disable ICU interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidDisableICU_Interrupt(void)
{
	/** Disable the ICU interrupt**/
	TIMSK &= ~(1<<TICIE1);
}



/*********************************************************/

/*
 * Description:      TMR1 select ICU Edge
 * Input argument:   u8 (TMR1_FALLING_EDGE) or (TMR1_RISING_EDGE)
 * Return argument:  void
 */
void TMR1_voidICU_EdgeSelect(u8 u8Edge_cpy)
{
	TCCR1B |= (u8Edge_cpy<<ICES1);
}





/*
 * Description:      TMR1 enable global interrupt
 * Input argument:   void
 * Return argument:  void
 */
void TMR1_voidEnableGlobalInterrupt(void)
{
	/** Enable the global interrupt**/
	SREG  |= (1<<IBIT);
}





/*
* Description:      TMR1 disable global interrupt
* Input argument:   void
* Return argument:  void
*/
void TMR1_voidDisableGlobalInterrupt(void)
{
	/** Enable the global interrupt**/
	SREG  &= ~(1<<IBIT);
}





/** Description:       Overflow call back function
 * Input argument:     void
 * Return argument:    void
 */

void TMR1_voidSetOverflowCallBack(void (*ptr_cpy)(void))
{
	/**the pointer to function is assigned to the *ptr to another function(of the application)**/
	TMR1_OverflowCallBack = ptr_cpy;
}


/** Description:       Compare A call back function
 * Input argument:     void
 * Return argument:    void
 */

void TMR1_voidSetCompareCallBackA(void (*ptr_cpy)(void))
{
	/**the pointer to function is assigned to the *ptr to another function(of the application)**/
	TMR1_CompareCallBackA = ptr_cpy;
}






/********************************************/
/** Description:       Compare B call back function
 * Input argument:     void
 * Return argument:    void
 */

void TMR1_voidSetCompareCallBackB(void (*ptr_cpy)(void))
{
	/**the pointer to function is assigned to the *ptr to another function(of the application)**/
	TMR1_CompareCallBackB = ptr_cpy;
}



/********************************************/

/** The prototype and implementation of the ISR **/
/** plus the #pragma to tell the linker it's a signal = ISR used = no call**/
   void __vector_9(void)__attribute__((signal, used));
   void __vector_9(void)
   {
	   TMR1_OverflowCallBack();
   }

/** The prototype and implementation of the ISR **/
/** The prototype and implementation of the ISR **/
   /** plus the #pragma to tell the linker it's a signal = ISR used = no call**/
      void __vector_7(void)__attribute__((signal, used));
      void __vector_7(void)
      {
    	  TMR1_CompareCallBackA();
      }


      void __vector_8(void)__attribute__((signal, used));
      void __vector_8(void)
      {
    	  TMR1_CompareCallBackB();
      }

