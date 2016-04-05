#include <stdio.h>

int main(void)
{
  int c=0, temp=0, i=0;
  printf("Ingresa un número:");
  scanf ("%d",&c);

  for(i=1;i<=c;i++)
  	temp=temp+i;
  
  printf("sumatoria:%d\n",temp);
  return 0;
}