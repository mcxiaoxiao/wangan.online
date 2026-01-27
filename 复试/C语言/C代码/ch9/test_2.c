#include<stdio.h>
#define N 51
int getRes(int a[], int m)
{
    int index = 1, i, k, j;
    memset(a,0,sizeof(a));
    a[1]=1;
    for(i = 1; i <= m; i ++)
    {
        for(j = 1;j <= index; j ++)
        {
            a[j] *= i;
        }
        for(k = 1; k < index; k ++)
        {
            if(a[k] >= 10) a[k+1] += a[k] / 10;
            a[k] %= 10;
        }
        while(a[index] >= 10 && index < N)
        {
            a[index + 1] = a[index] / 10;
            a[index] %= 10;
            index ++;
        }
    }
    return index;
}
int main()
{
    int num[N], i;
    for(i = 1; i <= 40; i ++)
    {
        printf("%d != ",i);
        int j = getRes(num,i);
        while(j)
        {
            printf("%d",num[j]);
            j--;
        }
        puts("");
    }

    return 0;
}
