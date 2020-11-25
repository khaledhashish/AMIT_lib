/*
 * UART.c
 *
 * Created: 11/22/2020 5:39:14 PM
 *  Author: khaled
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include "UART.h"
#include <stdlib.h>

#define Asynchronous 0
#define Synchronous  1

#define size_5_bit 0
#define size_6_bit 1
#define size_7_bit 2
#define size_8_bit 3
#define size_9_bit 7

void UART_inti(){
	//UCSRA 
	UCSRB |= (1<<TXEN) | (1<<RXEN);
	UBRRL=103; //rate 9600
}


void UART_SEND(char data){
	while (!(UCSRA & (1<<UDRE)));
	UDR=data;
}

void UART_SEND_str(char* str){
	for(int i=0;str[i]!='\0';i++){
		UART_SEND(str[i]);
	}
}

void UART_SEND_num(int data){
	char str[10];
	itoa(data,str,10);
	UART_SEND_str(str);
}

char UART_READ(){
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

int UART_READ_int(){
	while(!(UCSRA & (1<<RXC)));
	return (int)UDR;
}