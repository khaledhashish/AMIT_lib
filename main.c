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



int main(void)
{
	LCD_init();
	DDRC=0x07;
	keypad();
	LCD_Write_Str("hi");
	LCD_GoTo_xy(1,2);
	
	while (1)
	{	
		if(isPressedC(3) || isPressedC(4) || isPressedC(5) || isPressedC(6))
			LCD_num(keypad());
		_delay_ms(50);
	}
}



