#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int main(void)
{
    putchar(lower('R'));
    putchar('\n');
    return 0;
}
int lower(int c)
{
    return ('A' <= c && c <= 'Z') ? c - 'A' + 'a' : c;
}