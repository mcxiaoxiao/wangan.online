#include<stdio.h>
#include<math.h>
int isZhi(float a, float b, float c)
{
    if(fabs(a*a+b*b-c*c)<=1e-1) return 1;
    return 0;
}

int main()
{
    float a, b, c;
    a = b = c = 0;
    scanf("%f%f%f",&a, &b, &c);

    if(a+b>c && a+c>b && b+c>a)
    {
        int flag = 1;
        if(a==b && a==c && b==c)
        {
            printf("等边");
        }
        else
        {
            if(a==b || a==c || b==c)
            {
                printf("等腰");
                flag = 0;
            }
            if(isZhi(a,b,c) || isZhi(a,c,b) || isZhi(b,c,a))
            {
                printf("直角");
                flag=0;
            }
            if(flag) printf("一般");

        }
    }
    else printf("NOT ");
    printf("三角形");
    return 0;
}
