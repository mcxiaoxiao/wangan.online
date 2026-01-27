#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 16

void YHTriangle(int a[][15], int n);      // 计算杨辉三角
void PrintYHTriangle(int a[][15], int n); // 打印杨辉三角

int main(void)
{
    int a[N][N];
    int n;
    printf("Input n(n<=15):\n");
    scanf("%d",&n);
    YHTriangle(a,n);
    PrintYHTriangle(a,n);
    return 0;
}

void YHTriangle(int a[][15], int n)
{
    memset(a,0,sizeof());
    printf("%d\n\n",sizeof(int));
    for(int i = 0;i < n; i ++)
    {
        for(int j = 0; j <= i; j ++)
        {
            if(j==0) a[i][0] = 1;
            else
            {
                a[i][j] = a[i-1][j]+a[i-1][j-1];
            }
        }
    }
}

void PrintYHTriangle(int a[][15], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j ++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}
