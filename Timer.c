/*
 * Timer.c
 *
 * Created: 11/16/2020 3:12:10 PM
 *  Author: khaled
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

#include "Timer.h"

#define Timer_Off								0

#define OC0_off									0
#define OC0_CTC_Toogle							1
#define OC0_CTC_SET								3
#define OC0_CTC_RESET							2

#define OC0_Fast_PWM_SET_on_compare				3
#define OC0_Fast_PWM_RESET_on_compare			2

#define OC0_Phase_Correct_SET_on_compare		3
#define OC0_Phase_Correct_RESET_on_compare		2

#define Internal_No_prescaling					1
#define Internal_8_prescaling					2
#define Internal_64_prescaling					3
#define Internal_256_prescaling					4
#define Internal_1024_prescaling				5

#define External_falling						6
#define External_rising							7

#define Normal_mode								0x00
#define CTC_mode								0x08
#define Fast_PWM_Mode							0x48
#define PWM_Phase_correction_Mode				0x40

#define Timer0_Interrpt_overflow				0
#define Timer0_Interrpt_compare					1
#define Timer0_Interrpt_off						3

void Timer0_clock_source(int clk){
	TCCR0 |= clk;
}

void Timer0_Mode(int mode){
	TCCR0 |= mode<<3;
}

void Timer0_Oc0(int mode){
	TCCR0 |= mode<<4;
}

void Timer0_Intterrpt(int mode){
	if (mode==Timer0_Interrpt_off)
	{
		TIMSK &= ~ ((1<<0)|(1<<1));
	}
	else
	TIMSK |= 1<<mode;
}

void Timer0_init(int Timer_Mode,int clk,int Oc0,int Intterrpt_mode){
		Timer0_Mode(Timer_Mode);
		Timer0_Oc0(Oc0);
		Timer0_Intterrpt(Intterrpt_mode);
		Timer0_clock_source(clk);
		sei();
}

