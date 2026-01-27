#include<stdio.h>

int main()
{
    char ch;
    scanf("%c",&ch);
    ch -= 0x20;
    printf("%c\n%d",ch,ch);
    return 0;
}
