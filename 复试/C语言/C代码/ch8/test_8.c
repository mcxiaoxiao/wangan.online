#include<stdio.h>
#include<time.h>
#include<string.h>
#define N 6000
int main(void)
{
    int count = N;
    int a[7];
    srand(time(NULL));
    memset(a,0,sizeof(a));
    while(count --)
    {
        int x = rand()%6+1;
        a[x] ++;
        printf("%d\n",x);
    }
    for(int i = 1; i <=6; i++)
    {
        printf("%d-->%f-->%d\n",i,(float)a[i]/N,a[i]);
    }
    return 0;
}
