#include "stdrender.h"



void RenderClearRow(uint8 row)
{
  for (uint8 count = 0; count < COLUMN_SIZE; count++)
  {
    VIDEO_MEMORY_BUFFER[count + row*COLUMN_SIZE] = RENDER_CHAR_EMPHY;
  }
}

void RenderClear()
{
  for (uint8 count = 0; count < ROW_SIZE; count++)
  {
    RenderClearRow(count);
  }
}

uint8 RenderGetColor(uint8 foreground, uint8 background)
{
  return (foreground + (background << 4));
}

void RenderPutChar(char character, uint8 column, uint8 row, uint8 color)
{
  if (character == 0 || character == '\n')
    return;
  
  if (column > COLUMN_SIZE || row > ROW_SIZE)
    return;
  
  VIDEO_MEMORY_BUFFER[column + row*COLUMN_SIZE] = ((RenderChar){character,color});
}

void RenderPutStr(char* string, uint8 column, uint8 row, uint8 color)
{
  for (uint16 count = 0; true; count++)
  {
    if (string[count] == 0)
      return;
    else if (string[count] == '\n')
    {
      column = 0;
      row++;
      if (row > ROW_SIZE)
        return;
      continue;
    }
    
    RenderPutChar(string[count], column, row, color);

    column++;
    if (column > COLUMN_SIZE)
    {
      column = 0;
      row++;
      if (row > ROW_SIZE)
        return;
    }
  }
}

void RenderFillRow(char character, uint8 row, uint8 color)
{
  if (row > ROW_SIZE)
    return;

  for (uint8 count = 0; count < COLUMN_SIZE; count++)
  {
    VIDEO_MEMORY_BUFFER[count + row*COLUMN_SIZE] = ((RenderChar){character,color});
  }
}

void RenderFill(char character, uint8 color)
{
  for (uint8 count = 0; count < ROW_SIZE; count++)
  {
    RenderFillRow(character, count, color);
  }
}

void RenderReplaceColor(uint8 color)
{

}

void RenderFlip()
{

}

void RenderInit()
{

}