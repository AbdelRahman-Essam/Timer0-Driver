#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_
#include "utils.h"
#include "TIMER0_priv.h"

void TIMER0_voidInit(void);
void TIMER0_voidEnOVFInterreupt(void);
void TIMER_voidEnOCInterrupt(void);
void TIMER0_voidSetPreload(u8 value);
void TIMER0_voidSetOCR(u8 value);
void TIMER0_voidSetOVFISR(void(*ptr)(void));
void TIMER0_voidSetOCISR(void(*ptr)(void));
/*************************************************************************/
/* Timer0 Initialization
 * Description: Initialize timer0 registers and global variables
 * Input:       Void
 * Output:      Void
 */
/*************************************************************************/
void TIMER0_vidInit(void);


/*************************************************************************/
/* Timer0 Set Interrupt State
 * Description: Set the state (enable/disable) of timer0 interrupts, either
 *              the overflow interrupt or the output compare match interrupt.
 * Input:       Copy_u8IntpId		TIMER0_OVF_INTERRUPT
 *                          		TIMER0_OC_INTERRUPT
 *              Copy_u8IntpSt		TIMER0_ENABLE
 *              					TIMER0_DISABLE
 * Output:		Void
 */
/*************************************************************************/
void TIMER0_vidSetIntpSt(u8 Copy_u8IntpId, u8 Copy_u8IntpSt);


/*************************************************************************/
/* Timer0 Set Preload
 * Description: Set the TCNT0 with a preload value defined in config.
 * Input:		Copy_u8Preload		0-255
 * Output:      Void
 */
/*************************************************************************/
void TIMER0_vidSetPrealod(u8 Copy_u8Preload);


/*************************************************************************/
/* Timer0 Set OCR0 Register
 * Description: Set the OCR0 with the value to be compared with.
 * Input:		Copy_u8Compare		0-255
 * Output:      Void
 */
/*************************************************************************/
void TIMER0_vidSetOcr(u8 Copy_u8Compare);


/*************************************************************************/
/* Timer0 Set Overflow Interrupt Callback
 * Description: Set the pointer to function of the overflow interrupt
 * Input:		Copy_ptrOvfTask		Pointer to function whose input and
 *                                  output are void
 * Output:      Void
 */
/*************************************************************************/
void TIMER0_vidSetOvfCallBack(void (*Copy_ptrOvfTask)(void));


/*************************************************************************/
/* Timer0 Set Output Compare Interrupt Callback
 * Description: Set the pointer to function of the output compare interrupt
 * Input:		Copy_ptrOcTask		Pointer to function whose input and
 *                                  output are void
 * Output:      Void
 */
/*************************************************************************/
void TIMER0_vidSetOcCallBack(void (*Copy_ptrOcTask)(void));




















#endif /* TIMER0_INT_H_ */
