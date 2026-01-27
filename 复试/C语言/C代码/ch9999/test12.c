#include<stdio.h>
#include<math.h>

int main(void)
{
    int m;
    double s, n;
    scanf("%lf",&n);
    for( m = 1; m < 1000; m ++)
    {
        s = 0;
        for(int i = m; i <= 2*m; i++)
        {
            s += sqrt(i);
        }
        if(s>=n)
        {
            printf("result:%d\n",m);
            printf("s=%.2f",s);
            break;
        }
    }
    return 0;
}
