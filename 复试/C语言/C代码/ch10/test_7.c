#include<stdio.h>
#include<string.h>
void mycat(char *a, char *b)
{
    int i =strlen(a), j =0;
    while(b[j]!='\0')
    {
        a[i] = b[j];
        j++;
        i++;
    }
    a[i] = '\0';
}
int main(void)
{
    char a[20], b[20];
    gets(a);
    gets(b);
    mycat(a,b);
    puts(a);
    return 0;
}
