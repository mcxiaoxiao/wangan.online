#include<stdio.h>
#include<math.h>
int main()
{
//    float a, b, c;
//    a=b=c=0;
//    scanf("%f%f%f",&a,&b,&c);
//    if(a+b>c && a+c>b && b+c>a)
//    {
//        puts("三角形的面积：");
//        float p = (a+b+c)/2;
//        float s=sqrt(p*(p-a)*(p-b)*(p-c));
//        printf("%.3f",s);
//
//    }
//    else
//        printf("NOT 三角形");

    float x = 0, y = 0;

    scanf("%f%f",&y,&x);
    char cy = y + '0';
    switch(cy)
    {
    case '1':
        printf("%.4f",x*pow(1+2.25/100,y));
        break;
    case '2':
        printf("%.4f",x*pow(1+2.43/100,y));
        break;
    case '3':
        printf("%.4f",x*pow(1+2.7/100,y));
        break;
    case '5':
        printf("%.4f",x*pow(1+2.88/100,y));
        break;
    case '8':
        printf("%.4f",x*pow(1+3/100,y));
        break;
    default:
        printf("Wrong year");
    }
    return 0;
}
