#include<stdio.h>
#define N 1000
int prm[N];
int i,j;
int n,m;
int cnt,ttl;
int isprm(int x);
int main(void)
{


    scanf("%d,%d",&n,&m);
    for(i = n; i <= m; i ++)
    {
        if(!isprm(i)) continue;
        prm[j++]=i;
    }

    cnt = j;
    ttl = 0;
    for(i = 0, j = 0; i < cnt; i ++)
    {
        while(prm[j]-prm[i]<2 && prm[j]>0) j ++;
        if(prm[j] - prm[i] == 2)
        {
            ttl ++;
            printf("(%d,%d)\n", prm[i], prm[j]);
        }
    }

    printf("Totle=%d",ttl);

    return 0;
}

int isprm(int x)
{
    int i;
    for(i = 2; i < x; i ++)
    {
        if(x % i == 0) return 0;
    }
    return 1;
}

/*

孪生素数对 双指针算法

*/
