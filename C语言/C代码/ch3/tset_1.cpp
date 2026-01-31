#include <stdio.h>

int main(void)
{
    const double PI = 3.14159;
    double r = 0;
    scanf("%lf", &r);
    printf("%f\t%f",PI*r*r,2*PI*r);

    return 0;

}
