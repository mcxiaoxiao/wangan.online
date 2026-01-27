#include<stdio.h>
#define N 20
int readArr(int a[])
{
    int i = 0;
    for(i = 0;; i ++)
    {
        scanf("%d",a+i);
        if(a[i] < 0) return i;
    }
}

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArr(int a[], int n)
{
    for(int i = 1; i < n; i ++)
    {
        int key = a[i];
        for(int j = i - 1; j >= 0; j --)
        {
            if(a[j]>a[j+1]) swap(a+j,a+j+1);
            else
            {
                a[j+1] = key;
                break;
            }
        }
    }
}

void show(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    puts("");
}

int search(int a[],int n, int x)
{
    int l = 0, r = n-1;
    while(l<r)
    {
        int mid = l+r >> 1;
        if(a[mid]<x)  l = mid+1;
        else r = mid;
    }
    if(a[r] == x)return r + 1;
    return -1;
}

int main()
{

    int num[N];
    int n = readArr(num);
    sortArr(num,n);
    show(num,n);
    int x = 0;
    scanf("%d",&x);
    int res = search(num,n,x);
    if(res>=0) printf("%d",res);
    else puts("wrong");
    return 0;
}
