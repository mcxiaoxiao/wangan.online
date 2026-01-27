#include<stdio.h>
#include<string.h>
#define N 10
#define MAX_LEN 20
void SortString(char str[][MAX_LEN], int n);
int main(void)
{
    int i;
    char str[N][MAX_LEN];
    for(i = 0; i < N; i ++)
    {
        gets(str[i]);
    }
    SortString(str,N);
    printf("Sorted results\n");
    for(i = 0; i < N; i ++)
    {
        puts(str[i]);
    }
    return 0;
}
void SortString(char str[][MAX_LEN], int n)
{
    char temp[MAX_LEN];
    int i;
    int j;
    for(i = 0; i < n; i++)
    {
        for(j = n-1; j > i; j --)
        {
            if(strcmp(str[j],str[j-1])<0)
            {
                memset(temp,0,sizeof(temp));
                strcpy(temp, str[j]);
                strcpy(str[j],str[j-1]);
                strcpy(str[j-1],temp);
            }
        }
    }
}


