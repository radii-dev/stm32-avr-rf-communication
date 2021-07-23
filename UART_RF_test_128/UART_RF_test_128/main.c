/*
 * UART_RF_test_128.c
 *
 * Created: 2019-10-15 오후 10:17:40
 * Author : gigas
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "UART1.h"

int main(void)
{
	UART0_init();
	char testchar[] = "I'm hungry!\r\n";
	
    /* Replace with your application code */
    while (1) 
    {
		UART0_string_transmit(testchar);
    }
}
