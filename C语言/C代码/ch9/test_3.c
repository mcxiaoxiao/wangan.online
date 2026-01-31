#include<stdio.h>

int main(void)
{
    int *p = malloc(sizeof(int));
    scanf("%d",p);
    printf("%d=%p",*p,p);
    return 0;
}
