/*
 * SysState.h
 *
 * Created: 12/15/2021 8:02:29 PM
 *  Author: hp
 */ 


#ifndef SYSSTATE_H_
#define SYSSTATE_H_
#include "STD_TYPES.h"

#define OFF 0
#define ON 1
#define SETTING 2

u8 CurrentState;
#define INIT_DESIRED_TEMP 60
#define NUM_OF_TEMP_MEASURES 10

#define MIN_TEMP 35
#define MAX_TEMP 70



u16 temp_arr[NUM_OF_TEMP_MEASURES];
u16 desired_temp;
u16 actual_temp;
u16 avg_temp;

u8 temp_measure_f;
u8 temp_measure_counter;
u8 setting_counter;

u16 toggle_f;
u8 arr_counter;

void SysInit(void);
void ON_state(void);
void OFF_state(void);
void SET_state(void);

void change_temp(void);
void add_new_temp(u16 * arr , u16 new_val);
u16 calculate_avg_temp(u16 * arr);
void temp_arr_init(void);


#endif /* SYSSTATE_H_ */