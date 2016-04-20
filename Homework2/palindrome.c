// Evalúa si un string es palindrome
#include <stdio.h>
int leng(char *s);
int pal(char *text, int x);

int main(){

	int x=0, y=0;

	//test
	char tx[] = "abc1xy1cba";

	x=leng(tx);
	//printf("%d\n", leng(tx));
	y=pal(tx,x);
	if(y==1)
		printf("True\n");
	else
		printf("False\n");

}

//devuelve tamaño de la cadena
int leng(char *s){

	char *p = s;

	while(*p != '\0')
		p++;
	return p-s;

}

//funcion palindrome
int pal(char *text, int x){

	int pass=0, i=0;

	char *q = text+x-1; // -'\0'

	while((*text++ == *q--) && i<x/2){
		pass++;
		i++;
	}

	return pass==x/2 ? 1:0;
}