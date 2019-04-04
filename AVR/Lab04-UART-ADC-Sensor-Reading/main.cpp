/*
 * Lab04-UART-ADC-Sensor-Reading
 * STE29008 - Sistemas Embarcados
 * Aluna: Maria Fernanda Tutui
 */

#include <avr/io.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>

#define FOSC 16000000
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD)-1

float analog_value, digital_value;
uint8_t channel = 5;

void adc_init(void)
{
	ADMUX |= (1<<REFS0); //Set voltage reference to Avcc (5v)
	ADCSRA |= (1<<ADEN); //Turn on ADC
}

uint16_t read_adc(uint8_t channel){
	ADMUX &= 0xE0;           //Clear bits MUX0-4
	ADMUX |= channel&0x07;   //Defines the new ADC channel to be read by setting bits MUX0-2
	ADCSRB = channel&(1<<3); //Set MUX5                       // DAR UMA OLHADA NA PAG 282
	ADCSRA |= (1<<ADSC);      //Starts a new conversion
	while(ADCSRA & (1<<ADSC));  //Wait until the conversion is done
	return ADCW;  //Returns the ADC value of the chosen channel
}

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

void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );

	/* Put data into buffer, sends the data */
	UDR0 = data;
}

int RMS ( int repeat )
{
	float accumulated = 0;
	float average;

	for (int i = 0; i < repeat; i++)
	{
		digital_value = read_adc(channel);
		accumulated = accumulated + (digital_value * digital_value);
	}
	average = accumulated/repeat;
	return sqrt(average);
}

int main( void )
{
	adc_init();
	USART_Init(MYUBRR);

	while(true)
	{
		digital_value = RMS(30);

		_delay_ms(2000);

		analog_value = (digital_value*5)/1024;

		char digital[10];
		char analog[50];

		dtostrf(digital_value, 5, 0, digital);
		dtostrf(analog_value, 3, 3, analog);

		char label_d[20] = "Digital: ";

		for (int i = 0; i < 9; i++){
			USART_Transmit((uint8_t)label_d[i]);
		}

		for (int i = 1; i < 5; i++){
			USART_Transmit((uint8_t)digital[i]);
		}

		USART_Transmit((uint8_t)32);

		char label_a[13] = "Analogico: ";

		for (int i = 0; i < 11; i++){
			USART_Transmit((uint8_t)label_a[i]);
		}

		for (int i = 0; i < 4; i++){
			USART_Transmit((uint8_t)analog[i]);
		}

		USART_Transmit((uint8_t)32);
		USART_Transmit((uint8_t)124);
		USART_Transmit((uint8_t)32);
	}
}
