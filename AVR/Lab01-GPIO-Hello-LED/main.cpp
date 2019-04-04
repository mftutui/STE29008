/*
 * Lab01-GPIO-Hello-LED
 * STE29008 - Sistemas Embarcados
 * Aluna: Maria Fernanda Tutui
 */

#include <avr/io.h>

void setup(){
	DDRH |=  (1 << PH5); // LED   1 - Pino 8 - Escreve 1 - Saída
	DDRE &= ~(1 << PE4); // Botão 1 - Pino 2 - Escreve 0 - Entrada

	DDRH |=  (1 << PH6); // LED   2 - Pino 9 - Escreve 1 - Saída
	DDRE &= ~(1 << PE5); // Botão 2 - Pino 3 - Rscreve 0 - Entrada
}

int main(){
	setup();

	while (true){
		// Botão e Pino 1
		if (PINE & (1 << PE4)){
			PORTH &= ~(1 << PH5); // Escreve 0 no LED   1
		}else{
			PORTH |=  (1 << PH5); // Escreve 1 no Botão 1
		}

		// Botão e Pino 2
		if (PINE & (1 << PE5)){
			PORTH |=  (1 << PH6); // Escreve 1 no LED   2
		}else{
			PORTH &= ~(1 << PH6); // Escreve 0 no Botão 2
		}
	}
}
