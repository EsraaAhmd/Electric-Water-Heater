/*
 * SysState.c
 *
 * Created: 12/15/2021 8:03:03 PM
 *  Author: hp
 */ 
#include "SysState.h"
#include "Led.h"
#include "PushButton.h"
#include "SevenSegment.h"
#include "EEPROM.h"
#include "LM35.h"
void SysInit(void)
{
	S_SEG_INIT();
	
	LED_INIT(HeatingLed);
	LED_INIT(HeatingElement);
	LED_INIT(CoolingElement);
	
	P_B_INIT(OnOff);
	P_B_INIT(Up);
	P_B_INIT(Down);
	CurrentState=OFF;
	
	EEPROM_24C16_INIT();
	if(EEPROM_24C16_READ(0x00) != 0xFF)   // check if there are no data in EEPROM (first time to use it)
	{  
		desired_temp = EEPROM_24C16_READ(0x00);       // read data from byte number 0 in external EEPROM IC
	}
	else{
		desired_temp = INIT_DESIRED_TEMP;
	}
	
	temp_arr_init();
	EEPROM_24C16_WRITE(0x00,(u8) desired_temp);
}
void ON_state(void)
{
	if (temp_measure_f == 1){
		actual_temp = (TEMP_S_READ()*0.5);
		add_new_temp(temp_arr , actual_temp);
		avg_temp = calculate_avg_temp(temp_arr);
		temp_measure_f = 0;
	}
	
	S_SEG_DISPLAY(actual_temp);

	
	change_temp();
	

	
	if(UP()==ON || DOWN()==ON){

		S_SEG_OFF();
		setting_counter = 0;
		CurrentState = SETTING;
		
	}
}
void OFF_state(void)
{
	 S_SEG_OFF();
	 LED_OFF(HeatingLed);
	 LED_OFF(HeatingElement);
	 LED_OFF(CoolingElement);
}
void SET_state(void)
{
	LED_OFF(HeatingLed    );
	LED_OFF(HeatingElement);
	LED_OFF(CoolingElement);
	
	

	
	if(toggle_f == 1){
		S_SEG_DISPLAY(desired_temp);
	}
	else{
		S_SEG_OFF();
	}
	

	
	if((UP() == ON) && (desired_temp < MAX_TEMP)){
		desired_temp = desired_temp + 5;
		setting_counter = 0;
		S_SEG_DISPLAY(desired_temp);
	}
	else if ((DOWN() == ON) && (desired_temp > MIN_TEMP)){
		desired_temp = desired_temp - 5;
		setting_counter = 0;
		S_SEG_DISPLAY(desired_temp);
	}
	
	EEPROM_24C16_WRITE(0x00,desired_temp);
	
}


void change_temp(void)
{
	if( (desired_temp < avg_temp + 5) && (desired_temp > avg_temp - 5) ){

		LED_OFF(HeatingLed    );
		LED_OFF(HeatingElement);
		LED_OFF(CoolingElement);
	}
	else if(desired_temp < avg_temp + 5){

		
		LED_OFF(HeatingElement);
		LED_ON(HeatingLed    );
			 
		LED_ON(CoolingElement);
	}
	else if (desired_temp > avg_temp - 5){

		
		LED_ON(HeatingElement);
		LED_OFF(CoolingElement);
		if (toggle_f == 1)
		{
			LED_ON(HeatingLed    );
		}
		else {
			LED_OFF(HeatingLed    );
		}
	}
}

u16 calculate_avg_temp(u16 * arr)
{
	u16 sum = 0;
	u16 avg;

	for(u8 i=0; i<NUM_OF_TEMP_MEASURES; i++){
		sum = sum + arr[i];
	}
	avg = (u16) sum / NUM_OF_TEMP_MEASURES;
	return avg;
}

void temp_arr_init(void)
{
	u16 first_temp = TEMP_S_READ()*0.5;
	
	for (u8 i = 0; i<NUM_OF_TEMP_MEASURES; i++){
		temp_arr[i]= first_temp;
	}
	
	avg_temp = calculate_avg_temp(temp_arr);
	arr_counter = 0;
}


void add_new_temp(u16 * arr , u16 new_val)
{
	arr[arr_counter] = new_val;
	arr_counter ++;
	
	if (arr_counter == 10){
		arr_counter = 0;
	}
}