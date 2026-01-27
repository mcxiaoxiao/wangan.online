#include<stdio.h>
#define N 20
//Ñî»ÔÈý½Ç
void getYh(int a[][N],int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            a[i][j] = 0;
            if(i == 0 && j == 0) a[i][j] = 1;
            if(i > 0)
            {
                if(j == 0)a[i][j] = 1;
                else a[i][j] = a[i-1][j] + a[i-1][j-1];
            }
            if(a[i][j])printf("%4d ",a[i][j]);
        }
        puts("");
    }
}
int main(void)
{
    int a[N][N];
    int n = 0;
    scanf("%d",&n);
    getYh(a,n);
    return 0;
}
