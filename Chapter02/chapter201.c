#include <stdio.h>
#include <limits.h>

int 
main ()
{
  printf("El tamaño de Char es: %d\n", CHAR_BIT);
  printf("El tamaño de Char Max es: %d\n", CHAR_MAX);
  printf("El tamaño de Char Min es: %d\n", CHAR_MIN);
  printf("El tamaño de int min es: %d\n", INT_MIN);
  printf("El tamaño de int max es: %d\n", INT_MAX);
  printf("El tamaño de long min es: %d\n", LONG_MIN);
  printf("El tamaño de long max es: %d\n", LONG_MAX);
  printf("El tamaño de short min es: %d\n", SHRT_MIN);
  printf("El tamaño de short max es: %d\n", SHRT_MAX);
  printf("El tamaño de unsigned char es: %d\n", UCHAR_MAX);
  printf("El tamaño de unsigned long es: %d\n", ULONG_MAX);
  printf("El tamaño de unsigned int es: %d\n", UINT_MAX);
  printf("El tamaño de unsigned short es: %d\n", USHRT_MAX);

  return 0;
}