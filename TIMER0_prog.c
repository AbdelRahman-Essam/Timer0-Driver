#include "std_types.h"
#include "utils.h"
#include "DIO_int.h"
#include "TIMER0_int.h"
#include "TIMER0_priv.h"
#include "TIMER0_config.h"
void __vector_10 (void) __attribute__ ((signal,used, externally_visible));
void __vector_11 (void) __attribute__ ((signal,used, externally_visible));

void (*OVF_ISR)(void)='\0';
void (*OC_ISR)(void)='\0';
u8 counter10=0;
u8 counter11=0;

void TIMER0_voidInit(void)
{
    /*** SET OC0 MODE ***/
#if(OC0==TIMER0_NON_PWM_DISCONNECTED)
	{
		CLRBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_NON_PWM_TOGGLE)
	{
		SETBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_NON_PWM_CLEAR)
	{
		CLRBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_NON_PWM_SET)
	{
		SETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_FAST_PWM_DISCONNECTED)
	{
		CLRBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_FAST_PWM_CLEAR)
	{
		CLRBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_FAST_PWM_SET)
	{
		SETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_PHASE_CORRECT_PWM_DISCONNECTED)
	{
		CLRBIT(TCCR0,COM00);
		CLRBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_PHASE_CORRECT_PWM_CLEAR)
	{
		CLRBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#elif(OC0==TIMER0_PHASE_CORRECT_PWM_SET)
	{
		SETBIT(TCCR0,COM00);
		SETBIT(TCCR0,COM01);
	}
#endif

    /*** SET TIMER0 MODE ***/
#if(TIMER0_MODE==TIMER0_NORMAL_MODE)
	{
		CLRBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
	}
#elif(TIMER0_MODE==TIMER0_FAST_PWM_MODE)
	{
		SETBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
	}
#elif(TIMER0_MODE==TIMER0_CTC_MODE)
	{
		CLRBIT(TCCR0,WGM00);
		SETBIT(TCCR0,WGM01);
	}
#elif(TIMER0_MODE==TIMER0_PHASE_CORRECT_PWM_MODE)
	{
		SETBIT(TCCR0,WGM00);
		CLRBIT(TCCR0,WGM01);
	}
#endif

    /*** CLOCK SELECT ***/
#if(CLOCK==TIMER0_NO_CLOCK)
	{
		CLRBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_NO_PRESCALER)
	{
		SETBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_PRESCALER_8)
	{
		CLRBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_PRESCALER_64)
	{
		SETBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
		CLRBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_PRESCALER_256)
	{
		CLRBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		SETBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_PRESCALER_1024)
	{
		SETBIT(TCCR0,CS00);
		CLRBIT(TCCR0,CS01);
		SETBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_EXTCLK_at_T0_FALLING)
	{
		CLRBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
		SETBIT(TCCR0,CS02);
	}
#elif(CLOCK==TIMER0_EXTCLK_at_T0_RISING)
	{
		SETBIT(TCCR0,CS00);
		SETBIT(TCCR0,CS01);
		SETBIT(TCCR0,CS02);
	}
#endif
	//TCCR0|=MODE|OC0|CLOCK;  needed to be separated better

	TCNT0 = PRELOAD;
	OCR0 = OCR;

}

/*** Enable the interrupts ***/
void TIMER0_voidEnOVFInterreupt(void)
{
	SETBIT(TIMSK,TOIE);
	//TIMSK |=0x01;
}
void TIMER_voidEnOCInterrupt(void)
{
	SETBIT(TIMSK,OCIE);
	//TIMSK|=0x02;
}
void TIMER0_voidSetPreload(u8 Value)
{
	TCNT0= Value;
}
void TIMER0_voidSetOCR(u8 Value)
{
	OCR0 = Value;
}
void TIMER0_voidSetOVFISR(void(*ptr)(void))
{
	OVF_ISR=ptr;
}
void TIMER0_voidSetOCISR(void(*ptr)(void))
{
	OC_ISR=ptr;
}
void __vector_10 (void)
{
	counter10++;
	if(OVF_COUNTS == counter10)
	{
		OVF_ISR();
		counter10 =0;
	}

}
void __vector_11 (void)
{
	counter11++;
	if(OCR == counter11)
	{
		OC_ISR();
		counter11 =0;
	}

}
















