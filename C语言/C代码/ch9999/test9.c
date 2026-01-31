#include<stdio.h>
#include<string.h>
#define N 120
void swap(char* a, char* b)
{
    char *temp = (char*)malloc(sizeof(a));
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}
int main(void)
{
    char s[N][30];
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i ++)
    {
        gets(s[i]);
    }

// ×Ö·û´®µÄÅÅÐò
    for(int i = 0; i < n; i ++)
    {
        for(int j = n-1; j > i; j --)
        {
            if(strcmp(s[j],s[j-1]) < 0) swap(s[j],s[j-1]);
        }
    }

    for(int i = 0; i < n; i ++) puts(s[i]);
    return 0;
}
