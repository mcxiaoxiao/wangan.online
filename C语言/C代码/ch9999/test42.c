#include<stdio.h>
#include<string.h>
#define N 112
int gds[N];
int ngds[N];

void swap(int* a, int* b);

int main(void)
{
    int i,j;
    int n, m;
    int temp;

    memset(gds,0,sizeof(gds));
    memset(ngds,-1,sizeof(ngds));
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d",&temp);
        gds[temp] ++;
        if(gds[temp] == m + 1)
        {
            ngds[temp] = temp;
        }
    }
    for(i = 1; i <= 10; i ++)
    {
        for(j = 10; j > i; j --)
        {
            if(gds[j]<gds[j-1])
            {
                swap(&gds[j],&gds[j-1]);
                swap(&ngds[j],&ngds[j-1]);
            }
        }
    }
    puts("res");
    for(i = 1; i <= 10; i ++)
    {
        if(ngds[i]>=0) printf("%d\n",ngds[i]);
    }
    return 0;
}

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
