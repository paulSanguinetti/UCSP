
#include <stdio.h>

int prime(int num);

int main(){
	int temp=0, n=0,r=0;
	printf("Ingrese un número: ");
	scanf("%d",&n);
	for(int(i)=2;i<n;++i)
		if(prime(i)){
			temp=temp+i;
			//printf("%d\n",i);
		}
	printf("la suma de los primos menores que %d es: %d.\n",n,temp);
	return 0;
}

int prime(int num){

	int factor=0;
	for(int(i)=1;i<=num;i++){
		if(num%i==0)
			factor++;
		if(factor>2)
			return 0;
	}

	if(factor==2)
		return 1;

}