/*
 * ADCCFG.h
 *
 * Created: 12/14/2021 10:48:52 PM
 *  Author: hp
 */ 


#ifndef ADCCFG_H_
#define ADCCFG_H_


/********_SELECT_VREF_*********/
/*_OPTIONS_1_-> [AVCC] ********/
/*_OPTIONS_2_-> [AREF] ********/
/*_OPTIONS_3_-> [_2V] *********/
#define ADC_VREF               AVCC
/*******************************************/
/********_SELECT_ADJUSTMENT_****/
/*_OPTIONS_1_-> [RIGHT] ********/
/*_OPTIONS_2_-> [LEFT] *********/
#define ADC_ADJUSTMENT          RIGHT
/*******************************************/
/*******_AUTO_TRIGERING_MODE_****/
/*_OPTIONS_1_-> [DISABLE] ********/
/*_OPTIONS_2_-> [ENABLE] *********/
#define AUTO_TRIGERING_MODE     ENABLE
/*******************************************/
/**********_ADC_PRESCALER_********/
/*_OPTIONS_1_-> [_64] ************/
/*_OPTIONS_2_-> [_128] ***********/
#define ADC_PRESCALER          _128
/*******************************************/


#endif /* ADCCFG_H_ */