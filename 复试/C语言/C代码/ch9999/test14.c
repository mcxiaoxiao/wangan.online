#include<stdio.h>

int asce(int a, int b)
{
    return a > b;
}

int desc(int a,int b)
{
    return a < b;
}

void f(int *a, int *b, int* compare(int x, int y))
{
    if(compare(*a,*b))
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main(void)
{
    int a, b;
    scanf("%d%d",&a,&b);
    f(&a,&b,desc);
    printf("%d %d",a,b);
    return 0;
}
