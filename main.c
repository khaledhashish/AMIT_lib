/*
* GccApplication11.c
*
* Created: 9/26/2020 1:33:17 PM
* Author : khaled
*/
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "key_pad.h"
#include "LCD_4.h"
#include "shortcuts.h"

void up();
void down();

int main(void)
{
	LCD_init();
	DDRC=0x07;
	
	while (1)
	{	
		//LCD_Clear();
		LCD_num(keypad());
		_delay_ms(500);
	}
}

void up(){
	for(int i=0;i<8;i++){
		setPinC(i);
		_delay_ms(2000);
		resetPinC(i);
	}
}
void down(){
	for(int i=7;i>=0;i--){
		setPinC(i);
		_delay_ms(2000);
		resetPinC(i);
	}
}
