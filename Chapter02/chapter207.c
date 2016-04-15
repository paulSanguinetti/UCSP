/*
 * Author:      Thomas van der Burgt <thomas@thvdburgt.nl>

 * Exercise 2-7
 *
 * Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged. 
 */

#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(3, 0, 1));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    int mask;
    mask = (~(~0U << n)) << (p-n+1);
    return mask ^ x;
}
