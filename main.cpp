#include "HAL.h"

unsigned char Buff[32] = { };

void clearBuff();

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
        uart_ReadArray(Buff);
        uart_WriteArray(Buff);
        uart_WriteByte('\n');
        clearBuff();
        _delay_ms(1000);
    }
  return 0;
}

void clearBuff(){
  for(uint8_t i = 0; i < 32; i++) Buff[i] = 0;
}