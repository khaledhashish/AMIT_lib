/*
 * External_interrupt.c
 *
 * Created: 11/20/2020 9:05:03 PM
 *  Author: khaled
 */ 

#include "External_interrupt.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define low_level 00
#define any_logical 01
#define rising_edge 11
#define falling_edge 10
#define falling_inter2 0
#define rising_inter2 1

#define interrupt0 0
#define interrupt1 1
#define interrupt2 2

void external_intter_inti(int num,int mode){
		switch(num){
			case 0: {
				GICR |= (1<<6);
				MCUCR |= mode;	
			}
			case 1: {
				GICR |= (1<<7);
				switch(mode){
					case 00:{
						MCUCR &= ~(1<<ISC10); 
						MCUCR &= ~(1<<ISC11);
					}
					case 01:{
						MCUCR |= (1<<ISC10);
						MCUCR &= ~(1<<ISC11);
					}
					case 10:{
						MCUCR |= (1<<ISC11);
						MCUCR &= ~(1<<ISC10);
					}
					case 11:{
						MCUCR |= (1<<ISC10);
						MCUCR |= (1<<ISC11);
					}
				}
			}
			case 2: {
				GICR |= (1<<5);
				MCUCSR |= (mode<<6);
			}
		}
		sei();
}