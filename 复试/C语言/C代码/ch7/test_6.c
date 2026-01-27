#include<stdio.h>

// 水手分堆问题
int count(int n)
{
    int i = 1;
    float x = 1,y;
    y = x*n + 1;
    while(i<n)
    {
        y = n*y/(n-1)+1;
        i ++;
        if(y != (int)y)
        {
            i = 1;
            x++;
            y = x*n+1;
        }
    }
    return (int)y;
}

int main(void)
{
    int x = 0;
    while(1)
    {
        int x1 = x;
        int count=0;
        for(int i = 0; i<5; i++)
        {
            if((x1-1)%5 == 0)x1 -= (x1-1)/5+1;
            else break;
            count ++;
        }
        if(count == 5)
        {
            printf("%d",x);
            break;
        }
        else x++;
    }

    printf("\n%d",count(5));
    return 0;
}
