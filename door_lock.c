/*
* door_lock.c
*
* Created: 10/16/2020 6:45:42 PM
*  Author: khaled
*/

#include "LCD_4.h"
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "door_lock.h"

int i=0;
int password;
int real_pass=1234;

void door_bin(){
	password=0;
	_delay_ms(200);
	if (i==0){
		LCD_init();
		keypad();
		LCD_Write_Str("Enter Pin:");
		LCD_GoTo_xy(1,2);
		write_pass();
		if (password==real_pass)
		{
			LCD_Clear();
			LCD_Home();
			LCD_Write_Str("Welcome! :)");
		}
		else{
			i++;
			door_bin();
		}
	}
	else if (i<3){
		LCD_Clear();
		LCD_Home();
		LCD_Write_Str("Wrong Pin!!");
		_delay_ms(200);
		LCD_Clear();
		LCD_Write_Str("Enter Pin again:");
		LCD_GoTo_xy(1,2);
		write_pass();
		if (password==real_pass)
		{
			LCD_Clear();
			LCD_Home();
			LCD_Write_Str("Welcome! :)");
		}
		else{
			i++;
			door_bin();
		}
	}
	else{
		LCD_Clear();
		LCD_Home();
		LCD_Write_Str("System Locked :(");
		return;
	}
}

void write_pass(){
	_delay_ms(70);
	if (PINC & (1<<3) || PINC & (1<<4) || PINC & (1<<5) || PINC & (1<<6)){
		int temp =keypad();
		if(temp<10){
			password *= 10;
			password += temp;
			LCD_Write('*');
			write_pass();
		}
		else if(temp==10){
			LCD_cmd(0x10);
			password /= 10;
			LCD_Write(' ');
			LCD_cmd(0x10);
			write_pass();
		}
		else{
		}
	}
	else{
		write_pass();
	}
}