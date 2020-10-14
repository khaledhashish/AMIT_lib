/*
 * shortcuts.h
 *
 * Created: 10/1/2020 7:21:35 PM
 *  Author: khaled
 */ 


#ifndef SHORTCUTS_H_
#define SHORTCUTS_H_



void setPinA(int pinNumber);
void setPinB(int pinNumber);
void setPinC(int pinNumber);
void setPinD(int pinNumber);
void setPin(char data,int pinNumber);

void resetPinA(int pinNumber);
void resetPinB(int pinNumber);
void resetPinC(int pinNumber);
void resetPinD(int pinNumber);
void resetPin(char data,int pinNumber);

void togglepinA(int pinNumber);
void togglepinB(int pinNumber);
void togglepinC(int pinNumber);
void togglepinD(int pinNumber);
void togglepin(char data,int pinNumber);

int isPressedA(int pinNumber);
int isPressedB(int pinNumber);
int isPressedC(int pinNumber);
int isPressedD(int pinNumber);
int isPressed(char data,int pinNumber);




#endif /* SHORTCUTS_H_ */