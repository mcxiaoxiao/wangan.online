#include<stdio.h>

int main(void)
{

//    int a = 0, b = 0;
//
//    scanf("%d%d",&a,&b);
//    int max = a>b?a:b;
//    printf("%d",max);

    char a, b;
    scanf("%c%*2c%c",&a,&b);
    char max = a>b?a:b;
    printf("%c _ %d",max,max);
    return 0;
}
