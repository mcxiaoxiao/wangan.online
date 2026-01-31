#include<stdio.h>
#define N 8

void readMtri(int a[][N], int m, int n)
{
    int i, j;
    printf("INPUT\n");
    for(i = 0; i < m; i ++)
        for( j = 0; j < n; j ++)
            scanf("%d",&a[i][j]);

}

void multi(int a[][N],int b[][N],int c[N][N],int m,int n)
{
    int i, j, k;
    for(i = 0; i < m; i ++)
    {
        for(j = 0; j < m; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < n; k ++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void showM(int a[][N],int m,int n)
{
    int i, j;
    printf("outPUT\n");
    for(i = 0; i < m; i ++)
    {
        for(j = 0; j < n; j ++)
            printf("%d ",a[i][j]);
        puts("");
    }
}

int main(void)
{
    int a[N][N], b[N][N];
    int c[N][N];
    int m, n;
    int i, j, k;

    m = 2;
    n = 3;
    readMtri(a,m,n);
    readMtri(b,n,m);
    multi(a,b,c,m, n);

    showM(c,m,m);
    return 0;
}
