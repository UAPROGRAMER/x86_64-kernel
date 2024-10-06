#include "stdstring.h"

char* UIntToStr(uint32 value, uint8 base)
{
  if (base > 16)
    return null;

  static char buffer[INT_TO_STR_BUFFER+1] = {0};

  if (value == 0)
  {
    buffer[INT_TO_STR_BUFFER-1] = '0';
    return &buffer[INT_TO_STR_BUFFER-1];
  }

  int8 i = (INT_TO_STR_BUFFER-1);

  while (value&&(i+1))
  {
    buffer[i] = "0123456789abcdef"[value%base];
    i--;
    value/=base;
  }

  return &buffer[i+1];
}