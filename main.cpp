#include "HAL.h"

int main (void)
{
    uart_init();
    DDRB |= (1 << PB5);
    while (1)
    {
        _delay_ms(1000);
        PORTB ^= (1 << PB5);
        uart_WriteString("Hi, I'am Aleksey!\n");
    }
  return 0;
}