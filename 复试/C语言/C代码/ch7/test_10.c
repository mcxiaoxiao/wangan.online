#include <stdio.h>
#include <math.h>
int IsPrime(int x)
{

    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x%i == 0) return 0;
    }
    return 1;
}

void doNu(int x)
{
    if(!IsPrime(x))
    {
        for(int i = 2; i < x; i++)
        {
            if(x%i == 0)
            {
                printf("%d * ",i);
                doNu(x/i);
                return;
            }
        }
    }
    else
    {
        printf("%d",x);
    }
}

int main()
{
    int x = 0;
    do
    {
        scanf("%d",&x);
    }
    while(x<=1);
    if(IsPrime(x))
    {
        printf("%d is prime!",x);
    }
    else
    {
        doNu(x);
    }

    return 0;
}
