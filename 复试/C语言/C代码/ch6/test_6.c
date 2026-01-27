#include<stdio.h>
#include<math.h>

int main(void)
{

    //e
    float sum = 0, term = 1;
    int n = 1;
    while(fabs(term) >= 1e-5)
    {
        term /= n;
        sum += term;
        n++;
    }
    printf("%f",sum);
    return 0;
}
