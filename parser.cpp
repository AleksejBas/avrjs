#include "HAL.h"

void parts(uint8_t *data, uint8_t *a, uint8_t *b, uint8_t *c, uint8_t *d)
{
  while(*data != ' ' && *data != 0)
  {
    *a++ = *data;
    data++;
  }
  if(*data == ' ') {
    data++;
    }
 
  while(*data != ' ' && *data != 0)
  {
    *b++ = *data;
    data++;
  }
  if(*data == ' ') {
    data++;
    }

  while(*data != ' ' && *data != 0)
  {
    *c++ = *data;
    data++;
  }
  if(*data == ' ') {
    data++;
    }
 
  while(*data != 0)
  {
    if(*data != ';'){
      *d++ = *data;
    }
    data++;
  }
  // do
  // {
  //     *a++ = *data;
  // } while(*data++ != ' ');
  // if(*data != 0){
  // do
  // {
  //     *b++ = *data;
  // } while(*data++ != ' ');
  // }
  // if(*data != 0){
  // do
  // {
  //     *c++ = *data;
  // } while(*data++ != ' ');
  // }
  // if(*data != 0){
  // do
  // {
  //   if(*data != ';'){
  //     *d++ = *data;
  //   }
  // } while(*data++ != 0);
  // }
}

void type(uint8_t *type)
{
    
}