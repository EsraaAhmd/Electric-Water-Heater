/*
 * EEPROM.c
 *
 * Created: 12/15/2021 12:13:18 AM
 *  Author: hp
 */ 
#include "STD_TYPES.h"
#include "TWI.h"
#include "LED.h"
#define  F_CPU 16000000UL
#include "util/delay.h"

void EEPROM_24C16_INIT(void)
{
	TWI_MASTER_INIT();
	
}
void EEPROM_24C16_WRITE(u8 byte_address,u8 data)
{
	TWI_START_CONDETION();
	TWI_SEND_SLAVE_ADDRESS_WRITE(0x50);   // 0x50 = 0101 0000  ( It will be shifted left by 1 and become => 1010 0000 )
	TWI_SEND_DATA(byte_address);
	TWI_SEND_DATA(data);
	TWI_STOP_CONDETION();
	_delay_ms(10);
}
u8   EEPROM_24C16_READ(u8 byte_address)
{
	u8 data = 0;
	TWI_START_CONDETION();
	TWI_SEND_SLAVE_ADDRESS_WRITE(0x50);
	TWI_SEND_DATA(byte_address);
	TWI_REPEATED_START();
	TWI_SEND_SLAVE_ADDRESS_READ(0x50);
	data = TWI_READ_DATA();
	TWI_STOP_CONDETION();
	return data;
}