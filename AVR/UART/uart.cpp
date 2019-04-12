/*
 * uart.cpp
 *
 *  Created on: 12/04/2019
 *      Author: aluno
 */


#include "uart.h"

UART::UART(uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb)
:
{
	UBRR0 = baud;
	UCSR0B |= (1 << TXen0) | (1 << RXEN0));
	UCSR0C = db | parity | sb; //Tamanho do quadro, paridade e stopbit
}

UART::~UART(){}

void UART::put(uint8_t data){
	while(! (UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}

uint8_t UART::get(){
	while(! (UCSR0A & (1<<RXC0)) );
		return UDR0;
}

void UART::puts(const char data){

}
