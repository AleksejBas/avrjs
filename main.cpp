#include "HAL.h"

unsigned char Buff[32] = { };

unsigned char type[32];
unsigned char name[32];
unsigned char action[32];
unsigned char value[32];

void clearBuff();
void clearData(uint8_t *data);
void Parser_Type(uint8_t *type);
void Parser_Name(uint8_t *name);

int main (void)
{
    uart_init();
    DDRB |= (1 << PB5);
    
    while (1)
    {
        uart_ReadArray(Buff);
        uart_WriteArray(Buff);
        uart_WriteByte('\r');
        parts(Buff, type, name, action, value);
        Parser_Type(type);
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
    }
  return 0;
}

void clearBuff(){
  for(uint8_t i = 0; i < 32; i++) Buff[i] = 0;
}
void clearData(uint8_t *data){
  for(uint8_t i = 0; i < 32; i++) *data++ = 0;
}

void Parser_Type(uint8_t *type)
{
    switch (*type)
    {
    case '-': type++; switch (*type)
    {
    case 'v': uart_WriteString("Version 1.0.0. Data 04.11.2021\r"); break;
    case 'h': uart_WriteString("help\r-v: Version\r-h: Help\r"); break;
    // case 'e': uart_WriteString(Buff); break;
    default: uart_WriteString("No command!\r"); break;
    } break;
      case 'l': type++; switch (*type)
      {
          case 'e': type++; switch (*type)
          {
                case 't': uart_WriteString("Variable\r"); Parser_Name(name); break;
                default: uart_WriteString("No command!"); break;
          } break;
    
      default: uart_WriteString("No command!"); break;
      } break;

    default: uart_WriteString("No command system!\r"); break;
    }
}

void Parser_Name(uint8_t *name)
{
    
}