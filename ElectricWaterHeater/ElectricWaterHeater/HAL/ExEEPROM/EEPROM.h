/*
 * EEPROM.h
 *
 * Created: 12/15/2021 12:13:36 AM
 *  Author: hp
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "STD_TYPES.h"

void EEPROM_24C16_INIT(void);
void EEPROM_24C16_WRITE(u8,u8);
u8   EEPROM_24C16_READ(u8);


#endif /* EEPROM_H_ */