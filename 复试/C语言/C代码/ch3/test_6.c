#include<stdio.h>
#include<math.h>
void func(float a, float b, float c);
int main(void)
{

    float a, b, c;
    a=b=c=0;
    scanf("%f,%f,%f",&a,&b,&c);
    printf("%f,%f,%f\n",a,b,c);
    func(a,b,c);
    return 0;
}
void func(float a, float b, float c)
{

    float y = sqrt(b*b-4*a*c)/(2*a);
    float x = -b/(2*a);
    printf("%7.4f%8.4f",x+y,x-y);

}
