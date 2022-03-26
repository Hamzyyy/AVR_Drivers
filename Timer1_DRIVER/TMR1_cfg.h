/*
 * TMR_cfg.h
 *
 *  Created on: Jul 13, 2019
 *      Author: Hamzy
 */

#ifndef TMR1_CFG_H_
#define TMR1_CFG_H_

/*** Choose Mode
 *  TMR1_NORMAL_MODE
 *  TMR1_CTC_MODE
 *  TMR1_FAST_PWM_MODE
 *  TMR1_PHASE_CORRECT_MODE
 *  TMR1_PHASE_FREQ_CORRECT_MODE
 */
#define TMR1_MODE                TMR1_NORMAL_MODE




/*** Prescalling
 * TMR1_DIV_BY_1
 * TMR1_DIV_BY_8
 * TMR1_DIV_BY_64
 * TMR1_DIV_BY_256
 * TMR1_DIV_BY_1024
 */
#define TMR1_PRESCALLER         TMR1_DIV_BY_8



/*** Waveform for Normal mode, CTC, Phase Correct & Fast PWM
 * TMR1_DISABLE_OC1
 * TMR1_TOGGLE_OC1
 * TMR1_CLEAR_OC1
 * TMR1_SET_OC1
 * TMR1_NON_INVERTED
 * TMR1_INVERTED
 */

#define TMR1_COMPARE_EVENT         TMR1_NON_INVERTED








#endif /* TMR1_CFG_H_ */
