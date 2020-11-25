/*
 * SPI.h
 *
 * Created: 11/23/2020 10:35:48 PM
 *  Author: khaled
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_inti(int mode);
void SPI_Master_Send(char data);
void SPI_Master_Send_string(char* data);
void SPI_Master_Send_num(int data);
char SPI_Slave_Resive();

#endif /* SPI_H_ */