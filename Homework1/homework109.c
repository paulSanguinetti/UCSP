#include <stdio.h>

int mcd(int a, int b);

int main(){

    int i, x, y;
    int l[4];

    for(i=0; i<4; ++i){
        printf("Ingrese un numero: ");
        scanf("%d", &l[i]);
    }

    x=mcd(l[0],l[1]);
    y=mcd(l[2],l[3]);

	//printf("-mcd1 = %d ; -mcd2 = %d  ;  +mcd3 = %d\n", x, y, mcd(x,y));
	printf("el MCD de los 4 numeros es: %d\n", mcd(x,y));
    return 0;
}

int mcd(int a, int b){
    if(b == 0)
        return a;
    else
        return mcd(b, a%b);
}