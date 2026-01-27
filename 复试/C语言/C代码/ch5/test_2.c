#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define EPS 1e-6

int main(void)
{
    float a, b, c;
    a = b = c = 0;
    scanf("%f%f%f",&a,&b,&c);

    if(fabs(a-0) < EPS)
    {
        printf("NOT 一元二次方程\n");
        exit(0);
    }

    float cur = pow(b,2) - 4*a*c;
    float p = sqrt(fabs(cur)) /2/a;
    float q = -b/2/a;


    // 在实型比较中 0 用一个范围表示
    if(fabs(cur) <= EPS)
    {
        printf("%.2f=%.2f",q,q);
    }
        if(cur > EPS)
            printf("%.2f_%.2f",q+p, q-p);
        else
            printf("%.2f+%.2fi\n%.2f-%.2fi",q,p,q,p);
    }
    return 0;
}
