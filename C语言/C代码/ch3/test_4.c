#include<stdio.h>
#include<math.h>

int main(void)
{

    int x, b0, b1, b2;
    x = b0 = b1 = b2 = 0;
    scanf("%d", &x);
    x = fabs(x);
    b2 = x/100;
    b1 = (x-b2*100)/10;
    b0 = (x-b2*100-b1*10);
    int sum = b2+b1*10+b0*100;
    printf("%d",sum);
    return 0;
}
