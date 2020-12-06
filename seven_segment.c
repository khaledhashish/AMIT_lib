/*
 * _7_segment.c
 *
 * Created: 12/6/2020 6:14:10 PM
 *  Author: khaled
 */ 
# define F_CPU 16000000UL
#include <avr/io.h>
#include "seven_segment.h"

void write_7_segment(int data){
	int digit_1= data%10;
	int digit_2= data/10;
	PORTA = (digit_1<<4);
	PORTB |= (1<<1);
	PORTB &= ~(1<<1);
	PORTA = (digit_2<<4);
	PORTB |= (1<<2);
	PORTB &= ~(1<<2);
}