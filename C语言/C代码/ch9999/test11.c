#include<stdio.h>
#include<math.h>
int IsPrime(int x)
{
    for(int i = 2; i <= sqrt(x); i ++)
    {
        if(x%i == 0) return 0;
    }
    return 1;
}
//Ïà²î2µÄËØÊý
int main(void)
{
    int m, n;
    scanf("%d%d",&m,&n);
    int a[n - m + 2];
    int j = 0;
    for(int i = m; i <= n; i ++)
    {
        if(IsPrime(i) == 1)
        {
            a[j++] = i;
        }
    }

    int total = 0;
    for(int i = 1; i < j; i ++)
    {
        if(a[i] - a[i-1] == 2)
        {
            printf("(%d,%d)\n",a[i-1],a[i]);
            total ++;
            i ++;
        }
    }
    printf("%d\n",total);
    return 0;
}
