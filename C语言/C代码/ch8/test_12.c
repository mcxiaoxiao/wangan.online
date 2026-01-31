#include <stdio.h>
#define size 51
int getRes(int a[], int x)
{
    int index = 1;
    a[1] = 1;
    for(int i = 1; i <= x; i ++)
    {
        for(int j = 1; j <= index; j++)
        {
            a[j] *= i;
        }
        for(int k = 1; k < index; k ++)
        {
            if(a[k] >= 10) a[k+1] += a[k] / 10;
            a[k] %= 10;
        }
        while(a[index] >= 10 && index < size)
        {
            a[index+1] = a[index] / 10;
            a[index] %= 10;
            index ++;
        }
        if(index >= size) return 0;
    }
    return index;
}
int main(void)
{

    int num[size];
    memset(num,0,sizeof(num));
    for(int i = 1; i <= 40; i ++)
    {
        printf("%2d! = ",i);
        int j = getRes(num,i);
        if(!j) printf("LONNG!");
        while(j)
        {
            printf("%d",num[j]);
            j--;
        }
        puts("");
    }

    return 0;
}
