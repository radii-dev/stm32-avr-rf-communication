#include <avr/io.h>
#include <avr/interrupt.h>

void UART1_init(void)
{
	UCSR1A |= (1 << U2X1);			//2배속 모드 사용 설정
	UCSR1B |= (1 << RXEN1) | (1 << TXEN1);	//송수신 기능 활성화
	UCSR1C |= (1 << UCSZ11) | (1 << UCSZ10);	//데이터 비트 수를 8비트로 설정
	UBRR1H = 0;
	UBRR1L = 207;		//보드레이트를 9600으로 설정(2배속모드)
}

void UART1_transmit(char data)
{
	while( !(UCSR1A & (1 << UDRE1)));	//송신 버퍼가 비어있는지 확인, 비어있으면 1
	UDR1 = data;
}

void UART1_string_transmit(char *str)
{
	for(int i = 0; str[i]; i++)
	UART1_transmit(str[i]);
}

unsigned char UART1_receive(void)
{
	uint64_t timeout = 0;
	while(!(UCSR1A & (1 << RXC1)) && (timeout++ < 1666666));	//수신 버퍼가 비어있는지 확인, 비어있으면 0
	return UDR1;
}

void UART1_string_receive(char *str)
{
	int i;
	char data = UART1_receive();
	for(i = 0; data != '\r'; i++)
	{
		str[i] = data;
		data = UART1_receive();
	}
}

void UART0_init(void)
{
	UCSR0A |= (1 << U2X0);			//2배속 모드 사용 설정
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);	//송수신 기능 활성화
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);	//데이터 비트 수를 8비트로 설정
	UBRR0H = 0;
	UBRR0L = 207;		//보드레이트를 9600으로 설정(2배속모드)
	sei();
}

void UART0_transmit(char data)
{
	while( !(UCSR0A & (1 << UDRE0)) );	// 송신 가능 대기
	UDR0 = data;				// 데이터 전송
}

void UART0_string_transmit(char *str)
{
	for(int i = 0; str[i]; i++)
	UART0_transmit(str[i]);
}

unsigned char UART0_receive(void)
{
	while( !(UCSR0A & (1<<RXC0)) );	// 데이터 수신 대기
	return UDR0;
}

void UART0_string_receive(char *str)
{
	int i;
	char data = UART0_receive();
	for(i = 0; data != '\r'; i++)
	{
		str[i] = data;
		data = UART0_receive();
	}
}
