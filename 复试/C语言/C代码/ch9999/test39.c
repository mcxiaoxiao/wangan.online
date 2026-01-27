#include<stdio.h>
#define N 30
int main(void)
{
    int i ,j, k;
    int score[N];
    int count[N];
    int n;

    scanf("%d",&n);
    for(i = 0; i < n;i ++)
    {
        scanf("%d",&score[i]);
        count[i] = 1;
    }

    for(i = 1; i < n; i ++)
    {
        if(score[i] > score[i-1]) count[i] = count[i-1]+1;
    }

    for(i = n-2; i >= 0; i --)
    {
        if(score[i]>score[i+1]) count[i] = count[i+1]+1;
    }

    for(i = 0; i < n; i ++)
    {
        printf("%d:%d\n",score[i],count[i]);
    }

    return 0;
}
