#include<stdio.h>

void readData(int *a,int m,int n)
{
    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d",&a[i*n+j]);
    }
}

void outData(int *a,int m,int n)
{
    float avg = 0, sum = 0;
    for(int i = 0; i < m; i ++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            printf("%d ",a[i*n+j]);
            sum += a[i*n+j];
        }
        printf("%.2f %.2f\n",sum,sum/n);
    }

}



int main(void)
{
    int m,n;
    scanf("%d%d",&m,&n);
    int a[10][10];
    readData(a,m,n);
    outData(a,m,n);
    return 0;
}
