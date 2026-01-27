#include<stdio.h>

int main()
{
    int sot;
    int n, now = 0, to;
    scanf("%d",&n);
    sot = n * 5;
    while(n --)
    {
        scanf("%d",&to);
        if(to > now) sot += (to-now)*6;
        else sot += (now - to) * 4;
        now = to;
    }
    printf("%d",sot);
    return 0;
}
