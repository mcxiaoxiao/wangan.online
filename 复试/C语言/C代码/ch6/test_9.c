#include<stdio.h>

int main(void)
{
    int sum = 0,count = 0;
    while(1)
    {
        int x = 0;
        scanf("%d",&x);
        if(x>0)
        {
            sum+=x;
            count++;
        }
        else if(x == 0) break;
        else continue;
    }
    printf("%d\t%d",sum,count);
    return 0;
}
