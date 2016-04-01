#include <stdio.h>

int main(void)
{
  int c=1;

  while(c != 0){
    printf("Ingresa un número:");
    scanf ("%d",&c);
    printf("el cuadrado de: %d es: %d\n", c,c*c);
  }
  return 0;
}