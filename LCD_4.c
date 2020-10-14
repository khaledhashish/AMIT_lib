/*
 * LCD_4.c
 *
 * Created: 10/14/2020 6:45:53 PM
 *  Author: khaled
 */ 

#include "LCD_4.h"
#include "shortcuts.h"
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA PORTB
#define ctrl PORTB
#define LCD_Data_Pins DDRB
#define LCD_ctrl_Pins DDRB
#define en 3
#define RS 1
#define Rw 2

void LCD_cmd(char comm){
	resetPinB(RS);
	LCD_DATA = (LCD_DATA & 0x0F) | (comm & 0xF0);
	setPinB(en);
	_delay_ms(100);
	resetPinB(en);
	_delay_ms(100);
	LCD_DATA = (LCD_DATA & 0x0F) | (comm << 4);
	setPinB(en);
	_delay_ms(100);
	resetPinB(en);
}

void LCD_init(){
	LCD_Data_Pins=0xff;
	LCD_cmd(0x02);
	_delay_ms(100);
	LCD_cmd(0x28); //4-bit mode
	_delay_ms(100);
	LCD_cmd(0x01); //Clear
	_delay_ms(100);
	//LCD_cmd(0x02); //return home
	_delay_ms(100);
	LCD_cmd(0x06); //increment auto
	_delay_ms(100);
	LCD_cmd(0x0C);
	_delay_ms(100);
	LCD_cmd(0x80);
}

void LCD_Write(char data){
	setPinB(RS);
	LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);
	setPinB(en);
	_delay_ms(100);
	resetPinB(en);
	_delay_ms(200);
	LCD_DATA = (LCD_DATA & 0x0F) | (data << 4);
	setPinB(en);
	_delay_ms(100);
	resetPinB(en);
	
}
void LCD_Write_Str(char* data){
	while (*data != '\0'){
		LCD_Write(*data);
		data++;
	}
}

void LCD_num(int data){
	char temp[8];
	itoa(data,temp,10);
	LCD_Write_Str(temp);
}

void LCD_Clear(){
	LCD_cmd(0x01);
}

void LCD_GoTo_xy(int x,int y){
	LCD_cmd(0x02);
	if (y==2)LCD_cmd(0XC0);
	while(x != 1 ){
		LCD_cmd(0x14);
		x--;
	}
}