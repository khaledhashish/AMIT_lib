/*
 * ADC.c
 *
 * Created: 10/16/2020 1:57:19 PM
 *  Author: khaled
 */ 

#include <avr/io.h>
#include "ADC.h"

#define AVCC_MODE 1
#define AREF_MODE 0
#define INTERNAL_MODE 3

#define PRE_2   0
#define PRE_4   2
#define PRE_8   3
#define PRE_16  4
#define PRE_32  5
#define PRE_64  6
#define PRE_128 7




void ADC_CH(int channelNO){
	if (channelNO<8){
	ADMUX = (ADMUX & 0xe0)|channelNO;
	DDRA &= ~(1<<channelNO);
	}
}


void ADC_Ref(int Ref){
	ADMUX = (ADMUX & 0x3f)|(Ref<<6);
}


void ADC_Freq(int prescaler){
	ADCSRA = (ADCSRA&0x07) |(prescaler);
	
}

void ADC_init(int channelNO,int Ref,int Prescaler){
	ADC_CH(channelNO);
	ADC_Ref(Ref);
	ADC_Freq(Prescaler);
	ADCSRA |= (1<<ADEN);
}

void ADC_StartConv(){
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));
}

int ADC_read(){
	int val = ADCL;
	val |= (ADCH<<8);	
	return val*4.887585532746823;
}