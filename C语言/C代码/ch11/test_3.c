#include<stdio.h>

int main(void)
{
    char *a[7] = {"1y","2Y","3y","4y","5y","6y","7y"};
    int n = 0;
    scanf("%d",&n);
    printf("%s",a[n-1]);
    return 0;
}
