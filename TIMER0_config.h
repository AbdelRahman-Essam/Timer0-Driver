#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/*Modes OF operation
 *
 *	TIMER0_NORMAL_MODE
 *	TIMER0_FAST_PWM_MODE
 *	TIMER0_CTC_MODE
 *	TIMER0_PHASE_CORRECT_PWM_MODE
 */
#define TIMER0_MODE		TIMER0_PHASE_CORRECT_PWM_MODE

/*
 * Output Compare Match Output Mode
  	TIMER0_NON_PWM_DISCONNECTED
	TIMER0_NON_PWM_TOGGLE
	TIMER0_NON_PWM_CLEAR
	TIMER0_NON_PWM_SET

    TIMER0_FAST_PWM_DISCONNECTED
    TIMER0_FAST_PWM_CLEAR
    TIMER0_FAST_PWM_SET

    TIMER0_PHASE_CORRECT_PWM_DISCONNECTED
  	TIMER0_PHASE_CORRECT_PWM_CLEAR
  	TIMER0_PHASE_CORRECT_PWM_SET
 */
#define OC0 	TIMER0_NON_PWM_DISCONNECTED


/*
 * Clock
TIMER0_NO_CLOCK
TIMER0_NO_PRESCALER
TIMER0_PRESCALER_8
TIMER0_PRESCALER_64
TIMER0_PRESCALER_256
TIMER0_PRESCALER_1024
TIMER0_EXTCLK_at_T0_FALLING
TIMER0_EXTCLK_at_T0_RISING
 */
#define CLOCK		TIMER0_NO_PRESCALER_8


/*************************************************************************/
/* Interrupts State
 * Options:		TIMER0_OVF_INTERRUPT_ENABLE
				TIMER0_OC_INTERRUPT_ENABLE
				TIMER0_OVF_INTERRUPT_DISABLE
				TIMER0_OC_INTERRUPT_DISABLE
 */
/*************************************************************************/
#define TIMER0_OVF_INTERRUPT_STATE	TIMER0_OVF_INTERRUPT_DISABLE
#define TIMER0_OC_INTERRUPT_STATE	TIMER0_OVF_INTERRUPT_DISABLE


/*
 * Preload Value
 *  0--->255
 */
#define PRELOAD 0

/*
 * Number of Over Flow Counts
 */
#define	OVF_COUNTS 3900


/*
 * OCR Value
 * Range 0----->255
 */
#define OCR 0

#endif /* TIMER0_CONFIG_H_ */
