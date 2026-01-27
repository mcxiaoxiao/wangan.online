#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N = 180;
void Insert(char s[]);

int main(void)
{

    char str[N];
    printf("Input a string:\n");
    gets(str);
    Insert(str);
    printf("Insert result:\n");
    printf("%s\n",str);
    return 0;
}

void Insert(char s[])
{
    char *newStr = (char*)malloc(N);
    strcpy(newStr,s);
    int i = 0,j = 0;
    while(j < strlen(newStr))
    {
        if(i%2!=0)
        {
            s[i] = ' ';
            i++;
        }
        else
        {
            s[i++] = newStr[j++];
        }
    }
}
