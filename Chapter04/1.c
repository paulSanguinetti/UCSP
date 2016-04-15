#include <stdio.h>
#include <string.h>


int slen(char *s, char c){

	int i=0;
	int x=0;
	while(s[i]!='\0'){
		if(c==s[i]){
			x=i;
		}
		i++;
	}
	return x;

}

int main(void)
{
	char tx[100];
	int c;
	c=getchar();
	scanf("%s", tx);
	printf("%d\n", slen(tx, c));
	return 0;
}
