#include <stdio.h>

int main(void)
{
  int c, ant;

  while((c = getchar()) != EOF)
  {
    if(c == ' ')
    {
      if(ant != ' ')
        putchar(c);
    }
    else
      putchar(c);
    ant=c;
  }
  return 0;
}