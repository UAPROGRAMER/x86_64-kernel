#include "print.h"

const static size_t NUM_COLUMNS = 80;
const static size_t NUM_ROWS = 25;

typedef struct CharStruct
{
  uint8_t character;
  uint8_t color;
} Char;

Char* buffer = (Char*) 0xb8000;
size_t column = 0;
size_t row = 0;
uint8_t color = WHITE|BLACK<<4;

void clear_row(size_t crow)
{
  Char empty = (Char) {
    character: ' ',
    color: color,
  };

  for (size_t i = 0; i < NUM_COLUMNS; i++)
  {
    buffer[i + NUM_COLUMNS*crow] = empty;
  }
}

void print_clear()
{
  for (size_t i = 0; i < NUM_ROWS; i++)
  {
    clear_row(i);
  }
}

void print_newline()
{
  column = 0;
  if (row<NUM_ROWS-1)
  {
    row++;
    return;
  }

  for (size_t r = 1; r < NUM_ROWS; r++)
  {
    for (size_t c = 0; c < NUM_COLUMNS; c++)
    {
      Char character = buffer[c+NUM_COLUMNS*r];
      buffer[c+NUM_COLUMNS*(r-1)] = character;
    }
  }

  clear_row(NUM_COLUMNS-1);
}

void print_char(char character)
{
  if (character == '\n')
  {
    print_newline();
    return;
  }

  if (column > NUM_COLUMNS)
  {
    print_newline();
  }

  buffer[column + NUM_COLUMNS*row] = (Char) {
    character:character,
    color:color,
  };

  column++;
}

void print_str(char* string)
{
  for (size_t i = 0; 1; i++)
  {
    char character = (uint8_t) string[i];
    if (character == '\0')
    {
      return;
    }
    print_char(character);
  }
}

void print_set_color(uint8_t foreground, uint8_t background)
{
  color = foreground + (background << 4);
}