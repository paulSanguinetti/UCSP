#include <stdio.h>

int main(void)
{
  int c;
  int esp;

  esp = 0;
  while((c = getchar()) != EOF)
  {
    if(c == ' ')
    {
      if(esp == 0)
      {
        esp = 1;
        putchar(c);
      }
    }

    if(c != ' ')
    {
      esp = 0;
      putchar(c);
    }
  }

  return 0;
}