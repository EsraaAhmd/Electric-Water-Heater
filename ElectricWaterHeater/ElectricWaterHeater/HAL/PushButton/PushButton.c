/*
 * PushButton.c
 *
 * Created: 12/7/2021 7:45:25 PM
 *  Author: hp
 */ 
#include "STD_TYPES.h"
#include "PushButton.h"
#include "PushButtonCFG.h"
#include "DIO.h"
#include "ExInt.h"
#define F_CPU 16000000UL
#include "util/delay.h"

#define OFF 0
#define ON 1

void  P_B_INIT (u8 button)
{
	switch(button)
	{
		case OnOff:
		EXTERNAL_INT_0_INIT();
		break;
		case Up:
		EXTERNAL_INT_1_INIT();
		break;
		case Down:
		EXTERNAL_INT_2_INIT();
		break;
	}
}
u8 P_B_READ (u8 button)
{
	u8 value = 0;
	switch(button)
	{
		case 0:
		value = PIN_READ(ON_OFF_BUTTON);
		break;
		case 1:
		value = PIN_READ(UP_BUTTON);
		break;
		case 2:
		value = PIN_READ(DOWN_BUTTON);
		break;
	}
	return value;
}
u8 DOWN(void){
	// Check if on for the first time
	if(!(P_B_READ(DOWN_BUTTON))){
		// wait for 60 ms to make sure it's on (bouncing solution)
		_delay_ms(60);

		// check one more time
		if (!(P_B_READ(DOWN_BUTTON))){
			return ON;
		}
		else return OFF;
	}
	else return OFF;
}
u8 UP(void){
	// Check if on for the first time
	if(!(P_B_READ(UP_BUTTON))){
		// wait for 60 ms to make sure it's on (bouncing solution)
		_delay_ms(60);

		// check one more time
		if (!(P_B_READ(DOWN_BUTTON))){
			return ON;
		}
		else return OFF;
	}
	else return OFF;
}

