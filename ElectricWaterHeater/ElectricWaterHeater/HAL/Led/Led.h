/*
 * Led.h
 *
 * Created: 12/7/2021 8:01:42 PM
 *  Author: hp
 */ 


#ifndef LED_H_
#define LED_H_


#include "STD_TYPES.h"

/***** PROTOTYPES *****/
void LED_INIT   (u8);
void LED_ON     (u8);
void LED_OFF    (u8);
void LED_TOGGLE (u8);

/******* MACROS *******/
#define HeatingLed       0
#define HeatingElement   1
#define CoolingElement   2


#endif /* LED_H_ */