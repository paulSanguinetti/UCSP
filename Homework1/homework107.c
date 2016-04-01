#include <stdio.h>

int main()
{
    int n;
    int fact=1;

    printf("Calcular el factorial de: ");
    scanf("%d", &n);

    if (n==0)
        fact = 1;
    else{
        for(int(i)=1; i<=n; ++i)
            fact = fact * i;
    }
    printf("el factorial de: %d es %d", n, fact);
    return 0;
}