/*
 * uart.h
 *
 *  Created on: 17/04/2019
 *      Author: aluno
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

class UART{
public:
	enum DATABITS_t {
		DATABITS_5 = 0,
		DATABITS_6 = 2,
		DATABITS_7 = 4,
		DATABITS_8 = 6
	};

	enum PARITY_t {
		NONE = 0,
		EVEN = 32,
		ODD = 48
	};

	enum STOPBITS_t {
		STOPBIT_1 = 0,
		STOPBIT_2 = 8
	};

	UART(uint32_t baud = 9600,
			DATABITS_t db = DATABITS_8,
			PARITY_t parity = NONE,
			STOPBITS_t sb = STOPBIT_1);

	//UART(uint32_t baud, DATABITS_t db, PARITY_t parity, STOPBITS_t sb);
	~UART();
	void puts(const char data[], int size);
	void put(uint8_t data);
	uint8_t get();

};

#endif /* UART_H_ */
