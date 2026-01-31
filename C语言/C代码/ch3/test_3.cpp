#include<stdio.h>
#include<math.h>
void fun(int x);

int main(void)
{
    int x = 0;
    scanf("%d",&x);
    x = fabs(x);
    fun(x);
    return 0;
}

void fun(int x)
{
    int cur = x;
    int flag = 1;
    while(cur != 1)
    {
        flag *= 10;
        cur /= 10;
    }
    int sum = 0;
    while(x)
    {
        int r = x%10;
        sum += r * flag;
        x/=10;
        flag /= 10;

    }
    printf("%d",sum);
}
