/*
 * key_pad.c
 *
 * Created: 10/14/2020 6:22:02 PM
 *  Author: khaled
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "shortcuts.h"
#include "key_pad.h"
int k;


int keypad(){
	
	setPinC(0);setPinC(1);setPinC(2);
	if (isPressedC(3))k=first_three();
	if (isPressedC(4))k=second_three();
	if (isPressedC(5))k=third_three();
	if (isPressedC(6))k=last_three();
	return k;
}

int first_three(){
	resetPinC(0);setPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(3))return 1;
	setPinC(0);resetPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(3))return 2;
	setPinC(0);setPinC(1);resetPinC(2);
	_delay_ms(40);
	if (!isPressedC(3))return 3;
	return k;

}

int second_three(){
	resetPinC(0);setPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(4))return 4;
	setPinC(0);resetPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(4))return 5;
	setPinC(0);setPinC(1);resetPinC(2);
	_delay_ms(40);
	if (!isPressedC(4))return 6;
	return k;

}

int third_three(){
	resetPinC(0);setPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(5))return 7;
	setPinC(0);resetPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(5))return 8;
	setPinC(0);setPinC(1);resetPinC(2);
	_delay_ms(40);
	if (!isPressedC(5))return 9;
	return k;
}

int last_three(){
	resetPinC(0);setPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(6))return 10;
	setPinC(0);resetPinC(1);setPinC(2);
	_delay_ms(40);
	if (!isPressedC(6))return 0;
	setPinC(0);setPinC(1);resetPinC(2);
	_delay_ms(40);
	if (!isPressedC(6))return 11;
	return k;
}

