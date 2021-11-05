#include "HAL.h"

void parts(uint8_t *data, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d)
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
  
  do
  {
    if(*data != ';'){
      *d++ = *data;
    }
  } while(*data++ != 0);
}

void type(uint8_t *type)
{
    
}