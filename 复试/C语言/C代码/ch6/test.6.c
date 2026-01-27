#include<stdio.h>
#include<math.h>
int main(void)
{
    // pi
    int count = 1,n=3;
    float sum = 1;
    float term = 1;
    int sign = 1;
    while(fabs(term) > 1e-4)
    {
        term = -(float)sign/n;
        sum+=term;
        n+=2;
        sign *= -1;
        count ++;
    }
    printf("%f===%d",4*sum,count);
    return 0;
}
