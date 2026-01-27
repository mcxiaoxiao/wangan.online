#include<stdio.h>
#include<math.h>
int is(int x)
{
    for(int i = 2; i < sqrt(x); i ++)
    {
        if(x%i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    int flag = 0;
    for(int i = 2; n!= 1; i++ )
    {
        if(is(i)&& n%i ==0)
        {
            while(n%i == 0)
            {
                if(flag == 0)
                {
                    printf("%d",i);
                    flag = 1;
                }
                else printf("*%d",i);
                n/=i;
            }
        }
    }
    return 0;
}


/*
*
*
*质因子问题
*
*/
