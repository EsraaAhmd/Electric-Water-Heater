/*
 * ExInt.c
 *
 * Created: 12/15/2021 6:24:56 PM
 *  Author: hp
 */ 

#include "REG.h"
#include "BIT_MATH.h"

void EXTERNAL_INT_0_INIT(void)
{
	SET_BIT(SREG,7);         /*_TO_ENABLE_EXTERNAL_INT_*****************/
	SET_BIT(GICR,6);         /*_TO_ENABLE_TNTERRUPT_0_******************/
	CLR_BIT(MCUCR,0);        /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_FALLING_EDGE*/
	SET_BIT(MCUCR,1);        /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_FALLING_EDGE*/
}

void EXTERNAL_INT_1_INIT(void){
	SET_BIT(SREG,7);         /*_TO_ENABLE_EXTERNAL_INT_*****************/
	SET_BIT(GICR,7);         /*_TO_ENABLE_TNTERRUPT_1_******************/
	SET_BIT(MCUCR,2);        /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_RISSING_EDGE*/
	SET_BIT(MCUCR,3);        /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_RISSING_EDGE*/
}

void EXTERNAL_INT_2_INIT(void){
	SET_BIT(SREG,7);         /*_TO_ENABLE_EXTERNAL_INT_*****************/
	SET_BIT(GICR,5);         /*_TO_ENABLE_TNTERRUPT_2_******************/
	SET_BIT(MCUCSR,6);       /*_DETERMINE_ACTION_TRIGGER_THE_INTERRUPT_RISSING_EDGE*/
}