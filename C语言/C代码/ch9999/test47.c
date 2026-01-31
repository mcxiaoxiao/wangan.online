#include<stdio.h>

int gcd(int a, int b);
int main(void)
{

    int a;
    int b;
    int temp;
    scanf("%d%d",&a,&b);
    while(b!=0)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    printf("%d",a);
    //printf("%d",gcd(a,b));
    return 0;
}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

/*
最大公约数
gcd

递归 非递归
*/
