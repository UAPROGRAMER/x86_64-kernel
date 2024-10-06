#pragma once

#include "stdtypes.h"

enum RenderColorEnum
{
  BLACK = 0,
  BLUE = 1,
  GREEN = 2,
  CYAN = 3,
  RED = 4,
  MAGENTA = 5,
  BROWN = 6,
  LIGHT_GRAY = 7,
  DARK_GRAY = 8,
  LIGHT_BLUE = 9,
  LIGHT_GREEN = 10,
  LIGHT_CYAN = 11,
  LIGHT_RED = 12,
  PINK = 13,
  YELLOW = 14,
  WHITE = 15
};

typedef struct RenderCharStruct
{
  uint8 character;
  uint8 color;
} RenderChar;

#define RENDER_CHAR_EMPHY ((RenderChar){' ',0})
#define VIDEO_MEMORY_BUFFER ((RenderChar*)0xb8000)
#define COLUMN_SIZE (80)
#define ROW_SIZE (25)

void RenderClearRow(uint8 row);

void RenderClear();

uint8 RenderGetColor(uint8 foreground, uint8 background);

void RenderPutChar(char character, uint8 column, uint8 row, uint8 color);

void RenderPutStr(char* string, uint8 column, uint8 row, uint8 color);

void RenderFillRow(char character, uint8 row, uint8 color);

void RenderFill(char character, uint8 color);

void RenderReplaceColor(uint8 color);

void RenderFlip();

RenderChar* get_video_memory_back_image_pointer();

void RenderInit();