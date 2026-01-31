#include<stdio.h>

int main()
{
    int m = 1, i;
    float n = 0;
    scanf("%f", &n);
    float sum = 0;
    for(i = 1;;i++)
    {
        m *= i;
        sum += m;
        if(sum >= n) break;
    }
    printf("<%d",i);
    return 0;
}
