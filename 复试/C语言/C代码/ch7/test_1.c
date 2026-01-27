#include<stdio.h>
int count = 0;
int Fib(int x)
{
    count ++;
    if(x == 0) return 0;
    else if(x == 1) return 1;
    return Fib(x-1) + Fib(x-2);
}
int main(void)
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        count = 0;
        int x = Fib(i);
        printf("fib(%d)=%d   count = %d\n",i,x,count);
    }
    return 0;
}
