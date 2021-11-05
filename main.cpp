#include "HAL.h"

unsigned char Buff[32] = { };

unsigned char type[32];
unsigned char name[32];
unsigned char action[32];
unsigned char value[32];

void clearBuff();
void clearData(uint8_t *data);
void parser(uint8_t *data, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d);

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
        uart_WriteByte('\r');
        parser(Buff, type, name, action, value);
        uart_WriteArray(type);
        uart_WriteByte('\r');
        uart_WriteArray(name);
        uart_WriteByte('\r');
        uart_WriteArray(action);
        uart_WriteByte('\r');
        uart_WriteArray(value);
        uart_WriteByte('\r');
        clearData(Buff);
        clearData(type);
        clearData(name);
        clearData(action);
        clearData(value);
        // _delay_ms(1000);
    }
  return 0;
}

void clearBuff(){
  for(uint8_t i = 0; i < 32; i++) Buff[i] = 0;
}
void clearData(uint8_t *data){
  for(uint8_t i = 0; i < 32; i++) *data++ = 0;
}

void parser(uint8_t *data, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d)
{
  do
  {
      *a++ = *data;
  } while(*data++ != ' ');

  do
  {
      *b++ = *data;
  } while(*data++ != ' ');
  
  do
  {
      *c++ = *data;
  } while(*data++ != ' ');
  
  while(*data != 0 )
  {
    if(*data != ';' && *data != ' '){
      *d++ = *data++;
    }else{
      data++;
    }
  }
  // switch (Buff[1])
  // {
  // case '-': switch (Buff[2])
  // {
  // case 'v': uart_WriteString("Version 1.0.0"); break;
  // default: uart_WriteString("Error"); break;
  // } break;
  
  // default: uart_WriteString("Not command!"); break;
  // }
}
