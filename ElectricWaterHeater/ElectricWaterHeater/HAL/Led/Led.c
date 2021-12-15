/*
 * Led.c
 *
 * Created: 12/7/2021 8:02:14 PM
 *  Author: hp
 */ 

#include "LedCFGh.h"
#include "DIO.h"

void LED_INIT   (u8 led)
{
	switch(led)
	{
		case 0:
		PIN_MODE(HEATING_LED,OUTPUT);
		break;
		case 1:
		PIN_MODE(HEATING_ELEMENT,OUTPUT);
		break;
		case 2:
		PIN_MODE(COOLING_ELEMENT,OUTPUT);
		break;
	}
}
void LED_ON     (u8 led)
{
	switch(led)
	{
		case 0:
		PIN_WRITE(HEATING_LED,HIGH);
		break;
		case 1:
		PIN_WRITE(HEATING_ELEMENT,HIGH);
		break;
		case 2:
		PIN_WRITE(COOLING_ELEMENT,HIGH);
		break;
	}
}
void LED_OFF    (u8 led)
{
	switch(led)
	{
		case 0:
		PIN_WRITE(HEATING_LED,LOW);
		break;
		case 1:
		PIN_WRITE(HEATING_ELEMENT,LOW);
		break;
		case 2:
		PIN_WRITE(COOLING_ELEMENT,LOW);
		break;
	}
}
void LED_TOGGLE (u8 led)
{
	switch(led)
	{
		case 0:
		PIN_TOGGLE(HEATING_LED);
		break;
		case 1:
		PIN_TOGGLE(HEATING_ELEMENT);
		break;
		case 2:
		PIN_TOGGLE(COOLING_ELEMENT);
		break;
	}
}
