/*
 * Timer.c
 *
 * Created: 12/14/2021 11:11:12 PM
 *  Author: hp
 */ 
#include "TimerCFG.h"
#include "Timer.h"
#include "BIT_MATH.h"
#include "REG.h"

u32 num_of_ov;
u32 initial_value;

void TIMER_0_INIT(void)
{
	#if TIMER_0_MODE   ==  NORMAL
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#elif TIMER_0_MODE  == CTC
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#endif
	SET_BIT(SREG,7);    // to enable global int
	SET_BIT(TIMSK,0);   // to enable timer0 int
}
void TIMER_0_SET_TIME(u32 desired_time)
{
	u32 tick_time   = 1024 / 16;   // result in micro second
	u32 total_ticks = ( desired_time * 1000 ) / tick_time;
	num_of_ov       = total_ticks / 256;
	initial_value   = 255 - ( total_ticks % 256 );
	if( (total_ticks % 256) != 0 )
	{
		TCNT0       = initial_value;
		num_of_ov++;
	}
}

void TIMER_0_START(void)
{
	#if TIMER_0_PRESCALER     ==   _64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	#elif TIMER_0_PRESCALER   ==   _256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif TIMER_0_PRESCALER   ==   _1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif
}

void TIMER_0_STOP(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}

