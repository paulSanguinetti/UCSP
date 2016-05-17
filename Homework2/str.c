#include <stdio.h>
void _strcpy(char *q, char *r);
int strcmp(char *s, char *t);

//copy T to S
void _strcpy(char *q, char *r){
	while(*q++ = *r++)
		;
}

//compare...
int strcmp(char *s, char *t){
	for( ; *s == *t; s++, t++)
		if(*s=='\0')
			return 0;
	return *s - *t;
}

//testing...
int main(){

	char tx[100];
	printf("STRCMP: %d\n",strcmp("abc","abc"));
	_strcpy(tx,"abcd");
	printf("STRCPY: %s\n",tx);
}