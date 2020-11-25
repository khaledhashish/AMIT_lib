/*
 * Timer.h
 *
 * Created: 11/20/2020 10:36:18 PM
 *  Author: khaled
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void Timer0_clock_source(int clk);
void Timer0_Mode(int mode);
void Timer0_Oc0(int mode);
void Timer0_Intterrpt(int mode);
void Timer0_init(int Timer_Mode,int clk,int Oc0,int Intterrpt_mode);

#endif /* TIMER_H_ */