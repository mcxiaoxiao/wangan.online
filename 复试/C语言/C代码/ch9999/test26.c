#include<stdio.h>
#include<string.h>
#define N 199
int CountWords(char str[])
{
    int count = 1;
    int length = strlen(str);
    for(int i = 0; i < length; i ++)
    {
        if(str[i]-' ' == 0)
        {
            while(str[i] - ' ' == 0)
            {
                i ++;
            }
            count++;
        }
    }
    return count;
}

int main(void)
{
    char s[N];
    printf("Input a string:\n");
    gets(s);
    printf("Numbers of words = %d",CountWords(s));
    return 0;
}
