#include <stdio.h>

int main(void)
{
	int n=0, x=3, temp=1;
	printf("Ingresa un numero para la potencia: ");
	scanf ("%d",&n);
	for(int(i)=0;i<n;i++)
		temp=temp*x;
	printf("%d a la potencia %d es: %d\n", n,x,temp);
	return 0;
}