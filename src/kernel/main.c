#include "stdtypes.h"
#include "stdrender.h"
#include "stdstring.h"

void kernel_main()
{
  uint8 stdcolor = RenderGetColor(WHITE, BLACK);
  RenderInit();
  RenderClear();
  for (uint8 count = 0; true; count++)
  {
    RenderPutStr(UIntToStr(count, 10), 0,0,stdcolor);
    RenderFlip();
    RenderClear();
  }
}