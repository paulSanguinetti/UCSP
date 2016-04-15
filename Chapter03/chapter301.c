#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n-1;
    while(low < high) {
        mid = (low + high) / 2;
        if(x <= v[mid])
            high = mid;
        else 
            low = mid+1;
    }
    return (x == v[low]) ? low : -1;
}

int main(void)
{
    int v[5] = {3, 6, 9, 12, 4};
    int x = 36;
    printf("%d\n", binsearch(x, v, 5));
    return 0;
}