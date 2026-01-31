#include<stdio.h>
#include<math.h>

// Ë®ÏÉ»¨
int func(int x)
{
    int b2 = x/100;
    int b1 = (x-b2*100)/10;
    int b0 = x%10;
    return pow(b0,3)+pow(b1,3)+pow(b2,3);
}
int main(void)
{
    for(int i = 100; i <= 999; i ++)
        if(i == func(i)) printf("%d\n",i);

    return 0;
}
