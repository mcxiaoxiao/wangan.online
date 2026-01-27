#include<stdio.h>
#define N 20

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void getArr(int a[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i ++)
    {
        a[i] = rand()%20+1;
    }
}
void sort(int a[], int n)
{
    //Ã°ÅÝ
    for(int i = 0; i < n; i ++)
    {
        for(int j = n - 1; j > i; j --)
        {
            if(a[j]<a[j-1]) swap(&a[j],&a[j-1]);
        }
    }

//    //²åÈë
//    for(int i = 1; i < n; i ++)
//    {
//        int key = a[i], j = i -1;
//        while(a[j] > a[j+1] && j >= 0)
//        {
//            a[j+1] = a[j];
//            j--;
//        }
//        a[j+1] = key;
//    }

//    //Ñ¡Ôñ
//    for(int i = 0; i < n - 1; i ++)
//    {
//        int min = i;
//        for(int j = i+1;j < n; j++)
//        {
//            if(a[min] > a[j]) min = j;
//        }
//        if(i != min) swap(&a[min],&a[i]);
//    }

}
void show(int a[], int n)
{
    for(int i = 0; i < n; i ++) printf("%d ",a[i]);
    puts("");
}
int main()
{
    int a[N];
    int n = 10;
    getArr(a, n);
    show(a,n);
    sort(a,n);
    show(a,n);
    return 0;
}
