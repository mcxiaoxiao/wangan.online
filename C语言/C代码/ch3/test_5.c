#include<stdio.h>
#include<math.h>
const double rate = 2.25/100;

void fun(int n, double c);

int main(void)
{
    int n = 0;
    double capital = 0;
    scanf("%d,%lf",&n, &capital);
    fun(n, capital);
    return 0;
}

void fun(int n, double c)
{

    //while(n --) c += c*rate;
    c = c*pow(1+rate, n); //pow fabs sqrt
    printf("%lf",c);
}
