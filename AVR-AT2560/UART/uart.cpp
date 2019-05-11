#include <avr/io.h>
#include "uart.h"


UART::UART(uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb)
{
	UBRR0 = ((F_CPU/16/baud)-1);
	UCSR0B = 24; //(pagina 220)
	UCSR0C = db | parity | sb; //Tamanho do quadro, paridade e stopbit
}

UART::~UART(){}

uint8_t UART::get(){
	while(! (UCSR0A & (1<<RXC0)) );
		return UDR0;
}

void UART::put(uint8_t data){
	while(! (UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}

//void UART::puts(const char data){

//}
