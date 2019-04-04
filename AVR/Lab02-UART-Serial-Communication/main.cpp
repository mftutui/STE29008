/*
 * Lab02-UART-Serial-Communication
 * STE29008 - Sistemas Embarcados
 * Aluna: Maria Fernanda Tutui
 */

#include <avr/io.h>

#define FOSC 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD)-1

void USART_Init(unsigned int ubrr)
{
UBRR0H = (unsigned char)(ubrr>>8); //Ajusta a taxa de transmissão
UBRR0L = (unsigned char)ubrr;
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
//Habilita o transmissor e o receptor

//Ajusta o formato do frame:
UCSR0C &= ~(1<<USBS0);
UCSR0C |= (3<<UCSZ00);
}

unsigned char USART_Receive()
{
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );

	/* Get and return received data from buffer */
	return UDR0;
}

void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );

	/* Put data into buffer, sends the data */
	UDR0 = data;
}

int main( void )
{
	USART_Init(MYUBRR);
	while(true){
		uint8_t data;
		data = USART_Receive();
		data = data+1;
		USART_Transmit(data);
	}
}



