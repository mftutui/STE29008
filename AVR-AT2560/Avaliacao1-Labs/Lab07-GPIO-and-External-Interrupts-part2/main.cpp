/*
 * Lab07-GPIO-and-External-Interrupts-part2
 * STE29008 - Sistemas Embarcados
 * Aluna: Maria Fernanda Tutui
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void setup(){
	DDRH |=  (1 << PH6); // LED   - Pino 9 - Escreve 1 - Saída
	DDRE &= ~(1 << PE4); // Botão - Pino 2 - Escreve 0 - Entrada

	EICRB |= (1<<ISC41) | (1<<ISC40); // Habilita interrupção na borda de subida
	EIMSK = (1<<INT4);                // Interrupção INT4
	sei();                            // Habilita interrupções globais, ativando bit I no SREG
}

bool debounce(){         // Função simulando millis
	_delay_ms(300);
	if (PINE & (1 << PE4))
		return true;
	else
		return false;
}

int main(){
	setup();
	while(true);
}

ISR(INT4_vect){                   // Trata interrupção externa
	if (debounce())
		while(PINE & (1 << PE4)){ // Verifica botão (5V com chave aberta e 0V fechada)
			PORTH &= ~(1 << PH6); // Escreve 0 no LED
		}
		PORTH |= (1<< PH6);       // Escreve 1 no LED
	}

}
