/*
	//bucle original:
	for(int i=0;i<lim-1 && (c=getchar()) != '\n' && c != EOF; i++)
 		s[i] = c;
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
    int i=0, c , lim=100;
    char s[100];

    while(i < lim-1) {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        else
            s[i++] = c;
    }
    //s[i] = '\0';
    printf("%d\n", i);

    return 0;
}