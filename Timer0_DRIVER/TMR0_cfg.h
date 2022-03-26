/*
 * TMR_cfg.h
 *
 *  Created on: Jun 21, 2019
 *      Author: FUTURE
 */

#ifndef TMR0_CFG_H_
#define TMR0_CFG_H_

/*** Choose Mode
 *  TMR0_NORMAL_MODE
 *  TMR0_CTC_MODE
 *  TMR0_FAST_PWM_MODE
 *  TMR0_PHASE_CORRECT_MODE
 */
#define TMR0_MODE                TMR0_NORMAL_MODE




/*** Prescalling
 * TMR0_DIV_BY_1
 * TMR0_DIV_BY_8
 * TMR0_DIV_BY_64
 * TMR0_DIV_BY_256
 * TMR0_DIV_BY_1024
 */
#define TMR0_PRESCALLER         TMR0_DIV_BY_1024



/*** Waveform for Normal mode, CTC, Phase Correct & Fast PWM
 * TMR0_DISABLE_OC0
 * TMR0_TOGGLE_OC0
 * TMR0_CLEAR_OC0
 * TMR0_SET_OC0
 * TMR0_NON_INVERTED
 * TMR0_INVERTED
 */

#define TMR0_COMPARE_EVENT         TMR0_TOGGLE_OC0








#endif /* TMR0_CFG_H_ */
