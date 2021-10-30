#include "HAL.h"

void uart_init()
{
	   UBRR0 = bauddivider;
	   UCSR0B |= (1 << TXEN0)|(1 << RXEN0);//|(1 << RXCIE0); Включаем uart rx tx. RXCIE0 - разрешает прерывания для RX линии приема данных.
	   UCSR0C |= (1 << UCSZ00)|(1 << UCSZ01); // Включаем 8 bit режим передачи данных.
}
void uart_WriteByte(uint8_t data)
{
	while(!( UCSR0A & ( 1 << UDRE0 )));
	UDR0 = data;
}
void uart_WriteString(const char *str)
{
	while(*str!=0) {
		uart_WriteByte(*str++);
	}
}