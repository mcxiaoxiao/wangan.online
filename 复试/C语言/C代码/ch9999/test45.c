#include<stdio.h>
#define MOD 1000000
long func(int n);

int main(void)
{
    int n;
    int i;
    long sum;
    sum = 0;

    scanf("%d",&n);
    for(i = 1; i <= n; i ++)
    {
        sum += func(i);
        sum %= MOD;
    }
    printf("%ld",sum);
    return 0;
}

long func(int n)
{
    int i;
    long sum;
    sum = 1;
    for(i  = 1; i <= n; i ++)
    {
        sum *= i;
        sum %= MOD;
    }
    return sum;
}
