#include <stdio.h>
int main(void)
{
  int c;
  int esp;

  esp = 0;
  while((c = getchar()) != EOF)
  {
    if(c == ' ' || c == '\t' || c == '\n')
    {
      if(esp == 0)
      {
        esp = 1;
        putchar('\n');
      }
    }
    else
    {
      esp = 0;
      putchar(c);
    }
  }
  return 0;
}