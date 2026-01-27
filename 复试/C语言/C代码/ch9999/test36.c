#include<stdio.h>
#include<math.h>
#define LL long long
int main(void)
{
    int i;
    LL sum_a;
    LL sum_b;
    sum_a = 0;
    sum_b = 0;
    for(i = 0; i < 30; i ++)
    {
        sum_b += pow(2,i);
        sum_a += 10;
    }

    sum_a *= 10000;
    sum_b /= 100;

    printf("a:%ld  b:%ld",sum_a, sum_b);
    return 0;
}
