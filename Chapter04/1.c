#include <stdio.h>
#include <string.h>


int slen(char *s){

	int i=0;
	//char s;
	while(s[i]!='\0')
		i++;
	return i;

}

int main(void)
{
	char tx[100];
	scanf("%s", tx);
	printf("%d\n", slen(tx));
	return 0;
}
