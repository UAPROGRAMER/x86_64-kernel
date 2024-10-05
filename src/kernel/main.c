#include "print.h"

void kernel_main()
{
  print_set_color(WHITE, BLACK);
  print_clear();
  print_str("Hello, x64 World!");
}