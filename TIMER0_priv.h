/*
 * TIMER_priv.h
 *
 *  Created on: Nov 29, 2019
 *      Author: Abdelrahman Essam
 */

#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_

//Adresses of registers
#define TCCR0 (*(volatile u8 *)(0x53))
#define TCNT0 (*(volatile u8 *)(0x52))
#define TIMSK (*(volatile u8 *)(0x59))
#define SREG  (*(volatile u8 *)(0x5F))
#define OCR0  (*(volatile u8 *)(0x5C))

#define WGM00 6
#define WGM01 3
#define COM00 4
#define COM01 5
#define CS00  0
#define CS01  1
#define CS02  2
#define TOIE  0
#define OCIE  1




/* Modes of Operations */
#define TIMER0_NORMAL_MODE					1	//(u8)0x00
#define TIMER0_FAST_PWM_MODE				2	//(u8)0x48
#define TIMER0_CTC_MODE						3	//(u8)0x08
#define TIMER0_PHASE_CORRECT_PWM_MODE		4	//(u8)0x40

//Output Compare Match Output Mode (OC0)

/*For Non PWM Modes; Normal or CTC*/
/* Normal Port Operation */
#define TIMER0_NON_PWM_DISCONNECTED			1	//(u8)0x00
#define TIMER0_NON_PWM_TOGGLE				2	//(u8)0x10
#define TIMER0_NON_PWM_CLEAR				3	//(u8)0x20
#define TIMER0_NON_PWM_SET					4	//(u8)0x30

/*For Fast PWM  Mode Only*/
/* Normal Port Operation */
#define TIMER0_FAST_PWM_DISCONNECTED		5
#define TIMER0_FAST_PWM_CLEAR				6
#define TIMER0_FAST_PWM_SET					7

/********************For PHASE CORRECT PWM  Mode Only*********************/
/* Normal Port Operation */
#define TIMER0_PHASE_CORRECT_PWM_DISCONNECTED  8
#define TIMER0_PHASE_CORRECT_PWM_CLEAR		9
#define TIMER0_PHASE_CORRECT_PWM_SET		10

//Clock/prescaler
#define TIMER0_NO_CLOCK					1			//(u8)0x00
#define TIMER0_NO_PRESCALER				2			//(u8)0x01
#define TIMER0_NO_PRESCALER_8			3			//(u8)0x02
#define TIMER0_PRESCALER_64				4
#define TIMER0_PRESCALER_256			5
#define TIMER0_PRESCALER_1024			6
#define TIMER0_EXTCLK_at_T0_FALLING		7
#define TIMER0_EXTCLK_at_T0_RISING		8

/* Enable OVF Interrupt */
#define TIMER0_OVF_INTERRUPT_ENABLE				1
/* Enable OC Interrupt */
#define TIMER0_OC_INTERRUPT_ENABLE				2

/* Disable OVF Interrupt */
#define TIMER0_OVF_INTERRUPT_DISABLE			3
/* Disable OC Interrupt */
#define TIMER0_OC_INTERRUPT_DISABLE				4


/* Enable Interrupt */
#define TIMER0_ENABLE				(u8)5
/* Disable Interrupt */
#define TIMER0_DISABLE				(u8)40

/* Overflow Interrupt ID */
#define TIMER0_OVF_INTERRUPT		(u8)0
/* Output Compare Interrupt ID */
#define TIMER0_OC_INTERRUPT			(u8)1







#endif /* TIMER0_PRIV_H_ */
