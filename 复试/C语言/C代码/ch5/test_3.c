#include<stdio.h>
int main()
{
    int a = 0, b = 0;
    char op;
    scanf("%d%c%d",&a,&op,&b);
    switch(op)
    {

    case '+':
        printf("%d+%d=%d",a,b,a+b);
        break;
    case '-':
        printf("%d-%d=%d",a,b,a-b);
        break;
    case '*':
        printf("%d*%d=%d",a,b,a*b);
        break;
    case '/':
        if(b == 0)
            printf("!!!!!!!!error\n");
        else
            printf("%d/%d=%d",a,b,a/b);
        break;
    default:
        printf("wrong op");
    }

    return 0;
}
