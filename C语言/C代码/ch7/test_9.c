#include<stdio.h>
#include<math.h>
int IsPerfect(int x)
{
    int sum = 0;
    for(int i = 1; i < x;i++)
    {
        if(x%i == 0) sum += i;
    }
    if(sum == x) return 1;
    else return 0;
}
int IsPrime(int x)
{
    int flag = 1;
    for(int i = 2; i <= sqrt(x); i ++)
    {
        if(x%i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(void)
{

    int x = 0,sum = 0;
    do
    {
        printf("INPUT prime:");
        scanf("%d",&x);
    }
    while(x<=1);
    for(int i = 2; i <= x; i++)
    {
        if(IsPrime(i)) {
                sum+=i;
                printf("%d\t",i);
        }
    }
    printf("\n所有素数之和：%d\n%d",sum,x);

    if(IsPrime(x)) printf("Yes!\nNO divisor");
    else
    {
        printf("NO!\n其所有因子：\n");
        for(int i=2; i<x; i++) if(x%i == 0) printf("%d\t",i);
    }

    puts("");
    if(IsPerfect(x)) puts("Yes! Perfect");
    else printf("No! Perfect\n");

    return 0;
}
