#include <stdio.h>

int main(void)
{
  int espacios, tabs, saltos;
  int c;

  espacios = 0;
  tabs = 0;
  saltos = 0;

  while((c = getchar()) != EOF)
  {
    if(c == ' ')
      ++espacios;

    if(c == '\t')
      ++tabs;

    if(c == '\n')
      ++saltos;
    }
  }

  printf("espacios: %d\nTabs: %d\nsaltos: %d\n", espacios, tabs, saltos);
  return 0;
}