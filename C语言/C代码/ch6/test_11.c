#include<stdio.h>

int main(void)
{
    // 同时响的礼炮算成一响
    int n = 0;
    for(int t = 0; t<=20*7; t ++)
    {
        if(t%5 == 0 && t <= 20*5)
        {
            n++;
            continue;
        }
        if(t%6 == 0 && t <= 20*6)
        {
            n++;
            continue;
        }
        if(t%7 == 0)
        {
            n++;
        }
    }
    printf("%d",n);
    return 0;
}
