#include<stdio.h>
#define N 40
int readScore(int score[])
{
    for(int i = 0; ; i ++)
    {
        scanf("%d",&score[i]);
        if(score[i] < 0) return i;
    }
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortSc(int a[], int n)
{
    //Ã°ÅÝ
//    for(int i = 0; i < n; i ++)
//        for(int j = n-1; j > i; j --)
//    {
//        if(a[j]>a[j-1]) swap(a+j,a+j-1);
//    }

    // Ñ¡Ôñ

//    for(int i = 0; i < n-1; i++)
//    {
//        int max = i;
//        for(int j = i+1; j < n; j ++)
//            if(a[max] < a[j]) max = j;
//        swap(a+max, a+i);
//    }

    // ²åÈë
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        while(a[j]<a[j+1] && j >=0)
        {
            swap(a+j,a+j+1);
            j--;
        }
    }
}
void show(int a[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        printf("%d\t",a[i]);
    }
}
int main()
{

    int score[N];
    int n = readScore(score);
    sortSc(score, n);
    show(score,n);
    return 0;
}
