//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//const int N = 6;
//int asc(int a, int b)
//{
//    return a>b;
//}
//
//int desc(int a,int b)
//{
//    return a<b;
//}
//
//void show(int a[])
//{
//    for(int i = 0; i < N; i ++) printf("%d ",a[i]);
//    puts("");
//}
//
//void swap(int *a,int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void sort(int a[],int* compare(int a, int b))
//{
//    for(int i = 0; i < N; i ++)
//    {
//        for(int j = N-1; j > i; j --)
//        {
//            if(compare(a[j-1],a[j])) swap(a+j,a+j-1);
//        }
//    }
//}
//int main(void)
//{
//    int a[N];
//    memset(a,0,sizeof(a));
//    for(int i = 0; i < N; i ++)
//    {
//        scanf("%d",&a[i]);
//    }
//
//    int flag = 0;
//    scanf("%d",&flag);
//    if(flag)
//        sort(a,asc);
//    else
//        sort(a,desc);
//
//    show(a);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#define N 20
int ReadScore(int score[]);
void PrintScore(int score[], int n);
void SelectionSort(int score[], int n, int (*compare)(int a, int b));
void Swap(int *x, int *y);
int Ascending(int a, int b);
int Descending(int a, int b);

int main()
{
    int score[N],n;
    int order;
    n = ReadScore(score);
    printf("Total students are %d\n",n);
    printf("Enter 1 to sort in ascending order\n");
    printf("Enter 2 to sort in descending order\n");
    scanf("%d",&order);

    if(order == 1)
    {
        SelectionSort(score, n, Ascending);
        printf("Data items in asending order\n");
    }
    else
    {
        SelectionSort(score, n, Descending);
        printf("Data items in descending order\n");
    }
    PrintScore(score, n);

    return 0;
}
/*读入成绩以负数结束,返回实际输入的成绩个数*/
int ReadScore(int score[])
{
    int i=-1;
    printf("Input score:\n");
    do
    {
        i++;
        scanf("%d",&score[i]);
    }while (score[i]>=0);
    return i;
}

void PrintScore(int score[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%4d",score[i]);
    printf("\n");

}
void SelectionSort(int score[], int n, int (*compare)(int a, int b))
{
    int i, j, k;
    for(i=0; i<n-1;i++)
    {
        k = i;
        for(j = i+1; j< n; j++)
        {
            if(compare(score[j],score[k]))
            {
                k = j;
            }

        }
        if(k!= i)
        {
            Swap(&score[i],&score[k]);

        }
    }
}
int Ascending(int a, int b)
{
        return a < b;
}
int Descending(int a, int b)
{
        return a > b;
}
void Swap(int *x, int *y)
{
    int  temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
