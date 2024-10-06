#include "stdtypes.h"
#include "stdrender.h"
#include "stdstring.h"

void kernel_main()
{
  uint8 stdcolor = RenderGetColor(WHITE, BLACK);
  RenderClear();
  RenderFill('+', stdcolor);
}