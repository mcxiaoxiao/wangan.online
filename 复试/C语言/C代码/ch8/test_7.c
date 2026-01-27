#include<stdio.h>
#define N 200
// 成兔小兔问题
void Fbi(int a[], int n)
{
    a[0]= a[1] = 1;
    a[1] = 2;
    for(int i = 2;i<n;i++) a[i] = a[i-1]+a[i-2];
}

void show(int a[], int n)
{
    for(int i = 0;i < n; i++) printf("%d ",a[i]);
}

int main(void)
{
    int arr[N];
    int n = 12;
    Fbi(arr,n);
    show(arr,n);

    return 0;
}
