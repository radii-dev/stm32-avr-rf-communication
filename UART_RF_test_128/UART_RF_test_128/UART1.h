#ifndef UART1_H_

#define UART1_H_



void UART1_init(void);

void UART1_transmit(char data);

void UART1_string_transmit(char *str);

unsigned char UART1_receive(void);

void UART1_string_receive(char *str);

void UART0_init(void);

void UART0_transmit(char data);

void UART0_string_transmit(char *str);

unsigned char UART0_receive(void);

void UART0_string_receive(char *str);
#endif