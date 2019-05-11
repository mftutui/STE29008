/*
 * Lab02-UART-Serial-Communication
 * STE29008 - Sistemas Embarcados
 * Aluna: Maria Fernanda Tutui
 */

#include <avr/io.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD)-1

void USART_Init(unsigned int ubrr){
	UBRR0H = (unsigned char)(ubrr>>8); // Taxa de transmissão
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);    // Habilita RX e TX

	UCSR0C &= ~(1<<USBS0);             // Formato do frame
	UCSR0C |= (3<<UCSZ00);
}

unsigned char USART_Receive(){
	while ( !(UCSR0A & (1<<RXC0)) );   // Espera dados
	return UDR0;                       // Retorna dado recebido
}

void USART_Transmit( uint8_t data ){
	while ( !( UCSR0A & (1<<UDRE0)) ); // Espera para transmitir
	UDR0 = data;                       // Envia dado
}

int main( void ){
	USART_Init(MYUBRR);

	while(true){
		uint8_t data;
		data = USART_Receive();
		data = data+1;
		USART_Transmit(data);
	}
}



