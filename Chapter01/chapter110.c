#include <stdio.h>

#define CH '\\'

int main(void)
{
  int c;

  while((c = getchar()) != EOF)
  {
    switch(c)
    {
      case '\b':
        putchar(CH);
        putchar('b');
        break;
      case '\t':
        putchar(CH);
        putchar('t');
        break;
      case CH:
        putchar(CH);
        putchar(CH);
        break;
      default:
        putchar(c);
        break;
    }
  }
  return 0;
}