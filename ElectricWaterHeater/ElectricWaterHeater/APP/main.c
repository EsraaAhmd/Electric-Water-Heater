/*
 * ElectricWaterHeater.c
 *
 * Created: 12/7/2021 4:45:53 PM
 * Author : hp
 */ 

#define F_CPU 16000000UL
#include "util/delay.h"
#include "SysState.h"
#include "EEPROM.h"
#include "Led.h"
#include "PushButton.h"
#include "SevenSegment.h"
#include "LM35.h"

#include <avr/interrupt.h>

#define OFF 0
#define ON  1
u8 SysState;

extern u32 num_of_ov;
extern u32 initial_value;

u8 temp = 60;          //initial temperature value

u8 tempSens=0;
u8 tempSum=0;
u8 temAvg=0;

u8  TEMP=60;
u8  DEVICE_STATE;
u8  SETTING_MODE_STATE;
u8  HEATING_ELE_LED_STATE;
u8  SEVEN_SEG_STATE=OFF;

u8  SENSOR_TEMP_VALUE=0;
u16 SENSOR_TEMP_SUM=0;
u8  AVERAGE_SENSOR_TEMP_VALUE=0;

static  u32 counter=0;

int main(void)
{
	
    
    SysInit();

    while(1){
	    switch (CurrentState){
		    case ON:{
			    ON_state();
			    break;
		    }
		    case OFF:{
			    OFF_state();
			    break;
		    }
		    case SETTING:{
			    SET_state();
			    break;
		    }
	    }
    }
    return 0;
}

ISR(INT0_vect)   //OnOff
{  
	if(CurrentState ==OFF){
		CurrentState  = ON;
		desired_temp = EEPROM_24C16_READ(0x00);
	}
	else if (CurrentState ==ON || CurrentState ==SETTING){
		CurrentState  = OFF;
	}
}

ISR(INT1_vect)   //Up
{
	if(CurrentState==OFF){
		CurrentState=ON;
	}
	else if(CurrentState==ON){
		counter=0;
		TEMP+=5;
		if(TEMP>75){
			TEMP=75;
		}
		EEPROM_24C16_WRITE(0x00,TEMP);  
	}
}

ISR(INT2_vect)   //Down
{
	if(SysState==OFF){
		SysState=ON;
	}
	else if(SysState==ON){
		counter=0;
		TEMP-=5;
		if(TEMP<35){
			TEMP=35;
		}
		EEPROM_24C16_WRITE(0x00,TEMP);  
	}
}

ISR(TIMER0_OVF_vect)  
{
	temp_measure_f = 1;
}
