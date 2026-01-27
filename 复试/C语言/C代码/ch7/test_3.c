#include<stdio.h>

void printMax(int a, int b)
{
    int max = a>b?a:b;
    printf("%d\n",max);
}

int getMy(int a, int b)
{
    for(int i = 2; i < a<b?a:b; i++)
    {
        if(a%i==0 && b%i == 0) return i;
    }
    return 0;

}

int getMb(int a,int b)
{
    int max = a>b?a:b;
    while(1)
    {
        if(max%a == 0 && max%b == 0) return max;
        max++;
    }
}

int main()
{

    int a = 0, b = 0;
    scanf("%d%d",&a,&b);

    printMax(a,b);
    if(a<0 || b<0) printf("error!");
    else
    printf("%d",getMb(a,b));
    return 0;
}
