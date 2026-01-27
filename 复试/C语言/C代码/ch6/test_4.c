#include<stdio.h>
#include<math.h>
int main(void)
{
    // sin x
    float x = 0;
    scanf("%f",&x);
    int i = 1;
    float term, sum;
    sum = x;
    term = x;
    do{
        term = -term*pow(x,2)/((i+1)*(i+2));
        sum += term;
        i += 2;
    }while(fabs(term) >=1e-5);
    printf("%f",sum);
    return 0;
}
