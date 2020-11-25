/*
 * UART.h
 *
 * Created: 11/23/2020 1:17:44 PM
 *  Author: khaled
 */ 


#ifndef UART_H_
#define UART_H_

void UART_inti();
void UART_SEND(char data);
void UART_SEND_str(char* str);
void UART_SEND_num(int data);
char UART_READ();
int UART_READ_int();

#endif /* UART_H_ */