#include<stdio.h>
#include<string.h>
void swap(char a[],char b[])
{
    char temp[10];
    strcpy(temp, a);
    strcpy(a,b);
    strcpy(b,temp);
}
void sort(char a[][10], int n)
{
    char temp[10] = "";
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i+1; j < n; j ++)
        {
            if(strcmp(a[j],a[i]) < 0)
            {
                swap(a[j],a[i]);
            }
        }
    }
}
int main(void)
{
    char ctr[150][10];
    int n = 0;
    scanf("%d",&n);
    getchar(); //读取换行符，scanf不读，留在缓冲区
    for(int i = 0; i < n; i ++)
    {
        gets(ctr[i]);
    }
    sort(ctr,n);
    char str[100]="";
    for(int i = 0; i < n ; i ++)
    {
        puts(ctr[i]);
        strcat(str,ctr[i]);
    }
    puts(str);
    return 0;
}
