#include<stdio.h>

void del(char a[], char c)
{
    int i = 0;
    while(a[i] != '\0')
    {
        if(a[i] == c)
        {
            int k = i;
            while(a[k] != '\0')
            {
                a[k] = a[k+1];
                k++;
            }
            i -= 1;
        }
        i++;
    }
}

int main(void)
{
    char str[10];
    gets(str);
    char c = getchar();
    del(str,c);
    puts(str);
    return 0;
}
