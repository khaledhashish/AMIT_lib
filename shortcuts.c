/*
 * shortcuts.c
 *
 * Created: 10/14/2020 6:38:20 PM
 *  Author: khaled
 */ 

#include "shortcuts.h"
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define pb0 0
#define pb1 4
#define pb2 2
#define LED0 2
#define LED1 7
#define LED2 3
void setPinA(int pinNumber)
{
	PORTA |= (1<<pinNumber);
}
void setPinB(int pinNumber)
{
	PORTB |= (1<<pinNumber);
}
void setPinC(int pinNumber)
{
	PORTC |= (1<<pinNumber);
}
void setPinD(int pinNumber)
{
	PORTD |= (1<<pinNumber);
}

void setPin(char data,int pinNumber){
	data |= (1<<pinNumber);
}


void resetPinA(int pinNumber)
{
	PORTA &= ~(1<<pinNumber);
}
void resetPinB(int pinNumber)
{
	PORTB &= ~(1<<pinNumber);
}
void resetPinC(int pinNumber)
{
	PORTC &= ~(1<<pinNumber);
}
void resetPinD(int pinNumber)
{
	PORTD &= ~(1<<pinNumber);
}

void resetPin(char data,int pinNumber)
{
	data &= ~(1<<pinNumber);
}

void togglepinA(int pinNumber)
{
	PORTA ^= (1<<pinNumber);
}
void togglepinB(int pinNumber)
{
	PORTB ^= (1<<pinNumber);
}
void togglepinC(int pinNumber)
{
	PORTC ^= (1<<pinNumber);
}
void togglepinD(int pinNumber)
{
	PORTD ^= (1<<pinNumber);
}

void togglepin(char data,int pinNumber)
{
	data ^= (1<<pinNumber);
}

int isPressedA(int pinNumber){
	if(PINA & (1<<pinNumber))return 1;
	else return 0;
}
int isPressedB(int pinNumber){
	if(PINB & (1<<pinNumber))return 1;
	else return 0;
}
int isPressedC(int pinNumber){
	if(PINC & (1<<pinNumber))return 1;
	else return 0;
}
int isPressedD(int pinNumber){
	if(PIND & (1<<pinNumber))return 1;
	else return 0;
}

int isPressed(char data,int pinNumber)
{
	if(PIND & (1<<pinNumber))return 1;
	else return 0;
}
