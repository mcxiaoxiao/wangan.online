#include <stdio.h>

void hoi(int n, char a, char b, char c)
{
    if(n == 1) move(n,a,b);
    else
    {
        hoi(n-1,a,c,b);
        move(n,a,b);
        hoi(n-1,c,b,a);
    }
}

void move(int n, char a, char b)
{
    printf("%d==%c-->%c\n",n,a,b);
}

int main()
{

    int n = 0;
    scanf("%d",&n);
    hoi(n,'A','B','C');
    return 0;
}
