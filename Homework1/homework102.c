#include <stdio.h>

int main(void)
{
  int space=0, tabs=0, saltos=0, c=0;

  while((c = getchar()) != EOF){
    if(c == ' ')
      ++space;
    if(c == '\t')
      ++tabs;
    if(c == '\n')
      ++saltos;
  }
  //press Ctrl + D
  printf("space: %d\tTabs: %d\tSaltos: %d\n", space, tabs, saltos);
  return 0;
}