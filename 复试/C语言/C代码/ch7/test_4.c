#include<stdio.h>

int Fact(int x)
{
    int re = 1;
    for(int i = 1; i <= x; i ++) re*=i;
    return re;
}
int main()
{

    int n = 0, sum =0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        sum+=Fact(i);
        printf("%d!=%d\n",i,Fact(i));
    }

    printf("%d",sum);
    return 0;
}
