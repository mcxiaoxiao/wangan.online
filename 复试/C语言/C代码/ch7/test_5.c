#include<stdio.h>

int gcd(int a, int b)
{
//    int r = a%b;
//    while(r)
//    {
//        a = b;
//        b = r;
//        r = a%b;
//    }
    if(a%b == 0) return b;
    return gcd(b,a%b);
}
int main(void)
{
    int a = 0, b = 0;
    scanf("%d%d",&a,&b);
    if(a<=0||b<=0) puts("error");
    else
    printf("%d",gcd(a,b));
    return 0;
}
