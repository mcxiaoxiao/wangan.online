#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 51

int bigf(int n, int a[])
{
    int index = 1;
    memset(a,0,sizeof(int)*SIZE);

    a[1]=1;
    for(int i = 1; i <= n; i ++)
    {

        for(int j = 1; j <= index; j ++) a[j] *= i;

        for(int j = 1; j < index; j ++)
        {
            if(a[j] >= 10)
            {
                a[j+1] += a[j] /10;
                a[j] %= 10;
            }
        }
        while(a[index]>=10&&index<=SIZE-1)
        {
            a[index+1] = a[index]/10;
            a[index] %= 10;
            index++;
        }
    }
    if(index >= SIZE) return 0;
        return index;
}

int main(void)
{
    int data[SIZE];
    int n;
    scanf("%d",&n);
    for(int i =  1; i <= n; i ++)
    {
        int index = bigf(i,data);
        if(index!=0)
        {
            printf("%d:",i);
            for(int j = index; j > 0; j --)
            {
                printf("%d",data[j]);
            }
            printf("\n");
        }
        else
        {
            printf("OUT FLOW");
            exit(1);
        }
    }

    return 0;
}
