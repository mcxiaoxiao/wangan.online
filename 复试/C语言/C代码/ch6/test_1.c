#include<stdio.h>

int func(int x)
{

    if(x == 1) return 1;
    return x*func(x-1);
}
int main(void)
{
    // ¿€º”
    int n = 0, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) sum += i+1;
    printf("%d\t",sum);
    sum = 0;
    for(int i = 1, j = n; i <= j ; ++i, --j)
        sum += i!=j?i+j:i;

    printf("%d", sum);


    // 5!
    puts("");
    int sum1=1;
    for(int i = 1; i <= n; i++)
    {
        sum1*=i;
        printf("%d! = %d\t",i, sum1);
    }
    printf("\n%d\n",sum1);
    printf("%d\n",func(n));
    return 0;
}
