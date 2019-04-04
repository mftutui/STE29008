/*
 * Lab06-GPIO-and-External-Interrupts-part1
 * STE29008 - Sistemas Embarcados
 * Aluna: Maria Fernanda Tutui
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void setup(){
	DDRH |=  (1 << PH6); // LED   - Pino 9 - Escreve 1 - Saída
	DDRE &= ~(1 << PE4); // Botão - Pino 2 - Escreve 0 - Entrada

	EICRB |= (1<<ISC41) | (1<<ISC40); //habilitando interrupcao pra borda de subida
	EIMSK = (1<<INT4);//habilita interrupcoes no int4, pino 2 no arduino
	sei();//habilita interrupções globais, ativando o bit I do SREG
}

bool debounce(){
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

ISR(INT4_vect){ //trata a interrup externa 4
	if (debounce())
		//PORTH ^= (1<<PH6);
		PINH |= (1<<PH6);
		// port = escrever, escrever 1 ou zero na saida
		// ddr = configura modo de operacao, leitura ou escrirta, saida ou entrada
		// pin = le o stado do pino e muda ele (quando de entrada)
}
