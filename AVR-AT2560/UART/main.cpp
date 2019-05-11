/*
 * main.cpp
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */


#include "uart.h"

int main(){

	UART serial;
	while(true){
		uint8_t data = serial.get();
		serial.put(data);
	}
}
