#include<stdio.h>
#include<math.h>

const float PI = 3.14159;
int main()
{
    double r = 0;
    scanf("%lf",&r);
    double x = 4*PI*pow(r,2);
    double y = 4*PI*pow(r,3)/3;
    printf("%8.3lf\t%lf",x,y);

    return 0;
}
