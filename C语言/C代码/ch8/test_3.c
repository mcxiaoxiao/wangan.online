#include<stdio.h>
#define N 40

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int readScore(int a[], int b[])
{
    int i = 0;
    for(i;;i++)
    {
        printf("INPUT YOUR NUMBER AND SCORE:");
        scanf("%d%d",&a[i],&b[i]);
        if(a[i] <= 0 || b[i] <= 0) return i;
    }
}
void sortSc(int a[],int b[],int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = n-1; j>i;j--)
        {
            if(b[j]>b[j-1])
            {
                swap(b+j,b+j-1);
                swap(a+j,a+j-1);
            }
        }
    }
}

void sortNum(int a[],int b[],int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = n-1; j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(b+j,b+j-1);
                swap(a+j,a+j-1);
            }
        }
    }
}

void show(int a[], int b[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d:%d\n",a[i],b[i]);
    }
}

int search(int a[],int n,int x)
{
    int i = 0, j = n-1;
    while(i<j)
    {
        int mid = (i+j)/2;
        if(a[mid]<x) i = mid+1;
        else j = mid;
    }
    if(x == a[i])return i;
    return -1;

//    for(int i = 0; i <n; i++)
//    {
//        if(a[i] == x) return i;
//    }
//    return -1;
}
int main(void)
{

    int num[N],score[N];
    int n = readScore(num,score);
    sortSc(num,score,n);
    show(num,score,n);
    int x = 0;
    scanf("%d",&x);
    sortNum(num,score,n);
    int p = search(num,n,x);
    if(p!=-1)printf("%d",score[p]);
    else printf("NO!");
    return 0;
}
