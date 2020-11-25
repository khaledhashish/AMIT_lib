/*
 * SPI.c
 *
 * Created: 11/23/2020 10:15:34 PM
 *  Author: khaled
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "SPI.h"

#define SPI_Master 1
#define SPI_Slave  0

#define SPI_PS_4	0
#define SPI_PS_16	1
#define SPI_PS_64	2
#define SPI_PS_128	3
#define SPI_PS_2	4
#define SPI_PS_8	5
#define SPI_PS_32	6

void SPI_inti(int mode){
	if(mode==SPI_Master){
		SPCR |= (1<<MSTR);
		DDRB |= (1<<4) | (1<<5) | (1<<7);
	}
	SPCR |= (1<<SPE) | (1<<SPR1) | (1<<SPR0);
}

void SPI_Master_Send(char data){
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
}


void SPI_Master_Send_string(char* data){
	for(int i=0;data[i] != '\0';i++){
		SPI_Master_Send(data[i]);
	}
}

void SPI_Master_Send_num(int data){
	char str[10];
	itoa(data,str,10);
	SPI_Master_Send_string(str);
}

char SPI_Slave_Resive(){
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}