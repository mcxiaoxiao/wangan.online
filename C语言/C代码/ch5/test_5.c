#include<stdio.h>

int main(void)
{

    int a=1, b=2;
    scanf("%d%d",&a,&b);
    printf("%d_%d\n",a,b);
    fflush(stdin);
    char ch = getchar();
    putchar(ch);
    return 0;
}
