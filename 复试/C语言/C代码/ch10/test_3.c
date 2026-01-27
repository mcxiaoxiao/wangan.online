#include<stdio.h>

int countstr(char str[])
{
    int count = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i]==' ' && str[i+1] != ' ') count ++;
            i++;
    }
    return count;
}

int main(void)
{
    char str[20]=" ";
    char str1[20];
    gets(str1);
    strcat(str,str1);
    int len = countstr(str);
    printf("%d",len);
    return 0;
}
