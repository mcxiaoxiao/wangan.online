#include<stdio.h>
#include<math.h>
int main(void)
{
    float r = 0;
    scanf("%f",&r);
    int year = 0;
    float out = 100;
    while(out <= 200)
    {
        out *= 1+r;
        year ++;
    }
    printf("%d",year);
    return 0;
}
