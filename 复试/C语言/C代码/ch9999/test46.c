#include<stdio.h>
#include<string.h>
#define N 81
void inverse(char str[]);

int main(void)
{
    char s[N];
    gets(s);
    inverse(s);
    puts(s);
    return 0;
}

void inverse(char str[])
{
    int len;
    int i, j;
    char str_cp[N];
    len = strlen(str);
    for(i = 0; i < len; i ++)
    {
        str_cp[len-i-1] = str[i];
    }
    str_cp[len] = '\0';
    strcpy(str,str_cp);
}

