#include<stdio.h>

int main(void)
{
    char str[7][10]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
    char a[10];
    gets(a);
    int f = 0;
    for(int i = 0; i < 7; i ++)
    {
        if(strcmp(str[i],a) == 0)
        {
            f = 1;
            printf("%d",i);
        }
    }
    if(!f) puts("wrong");

    return 0;
}
