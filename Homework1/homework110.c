#include <stdio.h>

int main()
{
    int n;
    float i=2, har=1;

    printf("Ingrese un numero: ");
    scanf("%d", &n);
    while(i<=n){
        har=har + 1/i;
        ++i;
    }
    printf("El %dth numero armonico es: %.3f\n", n, har);
    return 0;
}