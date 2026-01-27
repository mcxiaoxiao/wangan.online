#include<stdio.h>
#include<time.h>
#define N 21
void getArr(int a[], int n);
void showarr(int a[],int n);
void insert(int a[],int n, int x);
int main()
{
    int a[N];
    int n = 0;
    scanf("%d",&n);
    getArr(a,n);
    showarr(a,n);

    printf("INPUT NUMBET:");
    int x = 0;
    scanf("%d",&x);
    insert(a,n,x);
    n++;
    showarr(a,n);
    return 0;
}
void getArr(int a[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i ++)
    {
        a[i] = rand()%20+1;
    }
}
void showarr(int a[], int n)
{
    for(int i = 0; i < n; i ++) printf("%d ",a[i]);
    puts("");
}
void insert(int a[], int n, int x)
{
    int i;
    for(i = n - 1; i >= 0; i--)
    {
        if(a[i]>x) a[i+1] = a[i];
        else break;
    }
    a[i+1] = x;
}
