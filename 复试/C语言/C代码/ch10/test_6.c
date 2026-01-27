#include<stdio.h>

void ni(char *a)
{
    char *p = malloc(sizeof(a));
    p+=strlen(a);
    *p--='\0';
    int i = 0;
    while(*(a+i) != '\0')
    {
        *p-- = *(a+i);
        i++;
    }
    strcpy(a,p);
}

int main(void)
{
    char str[20];
    gets(str);
    ni(str);
    puts(str);
    return 0;
}
