
/*
 * main.cpp
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */


#include "UART.h"

int main(){

	UART serial;
	while(true){
		const char data[] = {"shallow now"};
		serial.puts(data, sizeof(data));
	    //uint8_t data = serial.get();
		//serial.puts(data[], sizeof(data));
	}
}
