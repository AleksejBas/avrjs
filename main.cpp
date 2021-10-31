#include "HAL.h"

int main (void)
{
    uart_init();
    DDRB |= (1 << PB5);
    while (1)
    {
        // _delay_ms(1000);
        // PORTB ^= (1 << PB5);
        // uart_WriteString("\r");
        // uart_WriteString("Hi, I'am Aleksey!");
        uint8_t data = uart_ReadByte();
        if(data == 'A'){
          uart_WriteString("\r");
          uart_WriteString("PortB5 togle");
          PORTB ^= (1 << PB5);
        }else{
          uart_WriteString("\f");
        }
    }
  return 0;
}