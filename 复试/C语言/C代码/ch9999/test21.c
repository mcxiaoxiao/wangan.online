#include<stdio.h>
#include<stdlib.h>

int isTrue(int n)
{
    while(n)
    {
        int a = n%10;
        if(a == 6) return 1;
        n /= 10;
    }
    return 0;
}

int main(void)
{
    int data;
    printf("Input n(0<n<1000):\n");
    scanf("%d",&data);

    float sum = 0;

    for(int i = 6; i <= data; i ++)
    {
        if(isTrue(i))
        {
            sum += 1.0/i;
        }
    }
    printf("%.2f",sum);
    return 0;
}
