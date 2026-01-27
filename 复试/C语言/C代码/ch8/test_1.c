#include<stdio.h>

int readScore(int a[])
{
    int i = 0, max = 0;
    for(i = 0;; i++)
    {
        scanf("%d",a+i);
        if(max < a[i]) max = a[i];
        if(a[i]<0) break;
    }
    return max;
}

int Average(int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i ++)
    {
        sum += a[i];
    }
    return sum / n;
}

int main(void)
{
    int score[40];

    int max = readScore(score);
    printf("%d",max);
    //printf("%d人的平均值%d",n,Average(score,n));
    return 0;
}
