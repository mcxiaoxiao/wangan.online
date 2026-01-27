#include<stdio.h>
#define N 10
void readMatrix(int a[][N],int m,int n)
{
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j ++) scanf("%d",&a[i][j]);
    }
}

void sumOfMatrix(int a[][N], int b[][N], int c[][N],int m, int n)
{
    for(int i = 0; i < m; i ++)
    {

        for(int j = 0; j <n; j ++)
        {
            c[i][j] = 0;
            c[i][j] = a[i][j]+b[i][j];
        }
    }
}

void show(int a[][N],int m, int n)
{
    puts("result:");
    for(int i = 0; i < m; i ++)
    {

        for(int j = 0; j <n; j ++)
        {
            printf("%3d",a[i][j]);
        }
        puts("");
    }
}

int main(void)
{
    int a[N][N], b[N][N],m,n;
    scanf("%d%d",&m,&n);
    readMatrix(a,m,n);
    puts("---------");
    readMatrix(b,m,n);
    int c[N][N];
    sumOfMatrix(a,b,c,m,n);
    show(c,m,n);
    return 0;
}
