
#ifndef USART_H
#define USART_H

/* Заголовки и определения */
#define baudrate 9600UL
#define bauddivider F_CPU/(16*baudrate)-1 

/* UART API command */
void uart_init();
void uart_WriteByte(uint8_t data);
void uart_WriteString(const char *str);
uint8_t uart_ReadByte(void);
void uart_WriteArray(uint8_t *data);
void uart_ReadArray(uint8_t *data);

#endif /* UART_H */