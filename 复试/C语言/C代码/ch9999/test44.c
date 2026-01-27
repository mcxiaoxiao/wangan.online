#include<stdio.h>
#include<string.h>

#define N 110

char str_1[N], str_2[N];

int Caesar(char s[], int m)
{
    int i;
    int len;
    len = strlen(s);
    for(i = 0; i < len; i ++)
    {
        if(s[i] < 'A' || s[i] > 'z') return 0;
        if(s[i] > 'Z' && s[i] < 'a') return 0;
        str_2[i] = s[i]+m;
        if(str_2[i] > 'Z' && str_2[i] < 'a') str_2[i] = str_2[i] - 26;
        if(str_2[i] > 'z') str_2[i] = str_2[i] - 26;
    }
    return 1;
}

int main(void)
{
    int res;
    printf("Input a string:");
    gets(str_1);
    memset(str_2,0,sizeof(str_1));
    res = Caesar(str_1, 3);
    if(res ==  1) puts(str_2);
    else
    {
        puts("Input error!");
    }
    return 0;
}
