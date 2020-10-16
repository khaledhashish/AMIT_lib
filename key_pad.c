/*
 * key_pad.c
 *
 * Created: 1out1/14/out3out1out3out1 in4:out3out3:out1out3 PM
 *  Author: khaled
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "shortcuts.h"
#include "key_pad.h"
int k;
#define data_pins PORTC
#define data_in PINC
#define out1 0
#define out2 1
#define out3 2
#define in1 3
#define in2 4
#define in3 5
#define in4 6

int keypad(){
	
	data_pins |= (1<<out1);data_pins |= (1<<out2);data_pins |= (1<<out3);
	if (data_in & (1<<in1))k=first_three();
	if (data_in & (1<<in2))k=second_three();
	if (data_in & (1<<in3))k=third_three();
	if (data_in & (1<<in4))k=last_three();
	data_pins |= (1<<out1);data_pins |= (1<<out2);data_pins |= (1<<out3);
	return k;
}

int first_three(){
	data_pins &= ~(1<<out1);data_pins |= (1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in1)))return 1;
	data_pins |= (1<<out1);data_pins &= ~(1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in1)))return 2;
	data_pins |= (1<<out1);data_pins |= (1<<out2);data_pins &= ~(1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in1)))return 3;
	return k;

}

int second_three(){
	data_pins &= ~(1<<out1);data_pins |= (1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in2)))return 4;
	data_pins |= (1<<out1);data_pins &= ~(1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in2)))return 5;
	data_pins |= (1<<out1);data_pins |= (1<<out2);data_pins &= ~(1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in2)))return 6;
	return k;

}

int third_three(){
	data_pins &= ~(1<<out1);data_pins |= (1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in3)))return 7;
	data_pins |= (1<<out1);data_pins &= ~(1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in3)))return 8;
	data_pins |= (1<<out1);data_pins |= (1<<out2);data_pins &= ~(1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in3)))return 9;
	return k;
}

int last_three(){
	data_pins &= ~(1<<out1);data_pins |= (1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in4)))return 10;
	data_pins |= (1<<out1);data_pins &= ~(1<<out2);data_pins |= (1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in4)))return 0;
	data_pins |= (1<<out1);data_pins |= (1<<out2);data_pins &= ~(1<<out3);
	_delay_ms(40);
	if (!(data_in & (1<<in4)))return 11;
	return k;
}

