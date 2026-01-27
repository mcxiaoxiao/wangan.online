#include<stdio.h>
#include<string.h>
void addSpa(char *a)
{


    char *p = malloc(sizeof(a)*2);
    int i,j;
    for(i = 0, j = 0; a[i] != '\0'; i ++, j += 2)
    {
        *(p+j) = *(a+i);
        *(p+j+1) = ' ';
    }
    *(p+j-1)= '\0';
    strcpy(a,p);
}
int main(void)
{
    char str[20];
    gets(str);
    addSpa(str);
    puts(str);
    return 0;
}
