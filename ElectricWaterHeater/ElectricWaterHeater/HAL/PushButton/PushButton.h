/*
 * PushButton.h
 *
 * Created: 12/7/2021 7:44:19 PM
 *  Author: hp
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

#include "STD_TYPES.h"

void  P_B_INIT (u8);
u8 P_B_READ (u8 );

#define OnOff   0
#define Up   1
#define Down   2

unsigned char UP(void);
unsigned char DOWN(void);

#endif /* PUSHBUTTON_H_ */