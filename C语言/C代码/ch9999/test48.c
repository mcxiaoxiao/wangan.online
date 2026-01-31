#include<stdio.h>
#include<string.h>
#define N 12

int main(void)
{
    int i;
    int j;
    int count[N];
    int n;
    memset(count,0,sizeof(count));
    for(i = 0; i < 6; i ++)
    {
        scanf("%d",&n);
        count[n]++;
    }
    n = 1;
    for(i = 1; i <= 10; i ++)
    {
        if(count[i]>count[n]) n = i;
    }
    printf("%d",n);
    return 0;
}
