#include<stdio.h>
#define N 100
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void func(int *a, int m)
{

    for(int i = 0; i < m; i ++)
    {
        for(int j = i;j < m; j ++)
            swap(&a[i*N+j],&a[j*N+i]);
    }
}

int main()
{
    int a[70][N];
    int m, n;
    scanf("%d%d",&m,&n);

    for(int i = 0; i <m; i++)
    {
        for(int j = 0;j <n; j ++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    int max = m>n?m:n;
    //func(a,max);

    int p = **a, q = **a;
    int pi = 0 ,pj = 0, qi = 0, qj = 0;
    for(int i = 0; i <m; i++)
    {
        for(int j = 0;j <n; j ++)
        {
            printf("%d ",a[i][j]);
            if(a[i][j]>p)
            {
                p = a[i][j];
                pi = i;
                pj = j;
            }
            if(a[i][j]<q)
            {
                q = a[i][j];
                qi = i;
                qj = j;
            }
        }
        puts("");
    }
    printf("%d %d %d\n",p,pi+1,pj+1);
    printf("%d %d %d",q,qi+1,qj+1);
    return 0;
}
