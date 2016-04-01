#include <stdio.h>
int main()
{
    int a=0,b=0,c=0;
    int l[3];
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    l[3]=a;
    if(b>a && b>c){
        l[3]=b;
        if(a>c){
            l[2]=a;
            l[1]=c;
        }
        else{
            l[2]=c;
            l[1]=a;
        }
    }
    if(c>a && c>b){
        l[3]=c;
        if(a>b){
            l[2]=a;
            l[1]=b;
        }
        else{
            l[2]=b;
            l[1]=a;
        }
    }
    else if(b>c){
        l[2]=a;
        l[1]=b;
    }
    else{
        l[2]=b;
        l[1]=a;
    }

    printf("ordenados: %d, %d, %d", l[1], l[2],l[3]);
    return 0;
}