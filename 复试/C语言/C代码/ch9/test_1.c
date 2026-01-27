#include<stdio.h>
#include<time.h>
#define N 100
void getArr(int a[], int n);
void swap(int *a, int *b);
void sortArr(int a[], int n);
int main()
{
    int n = 8;
    int a[N];
    getArr(a,n);
    for(int i = 0; i < n; i ++) printf("%d ",a[i]);
    puts("");
    sortArr(a,n);
    for(int i = 0; i < n; i ++) printf("%d ",a[i]);
    puts("");
    return 0;
}

void getArr(int a[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i ++)
    {
        a[i] = rand()%20 + 1;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArr(int a[], int n)
{
//    //√∞≈›
//    for(int i = 0; i < n; i ++)
//    {
//        for(int j = n - 1; j > i; j --)
//        {
//            if(a[j] < a[j-1]) swap(&a[j],&a[j-1]);
//        }
//    }

//    //≤Â»Î≈≈–Ú
//    for(int i = 1; i < n; i ++)
//    {
//        int k = a[i], j = i-1;
//        while(a[j]>k && j >= 0)
//        {
//            a[j+1] = a[j];
//            j--;
//        }
//        a[j + 1] = k;
//    }

//    //—°‘Ò≈≈–Ú
//    for(int i = 0; i < n-1; i ++)
//    {
//        int min = i;
//        for(int j = i+1; j < n; j ++)
//        {
//            if(a[j] < a[min]) min = j;
//        }
//        if(min != i) swap(&a[min],&a[i]);
//    }
}
