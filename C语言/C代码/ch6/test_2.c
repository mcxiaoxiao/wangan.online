#include<stdio.h>

int func(int x)
{

    if(x == 1) return 1;
    return x*func(x-1);
}
int main(void)
{

    int n = 0;
    scanf("%d", &n);

    int sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        sum += func(i);
    }
    printf("%d", sum);
    return 0;
}
