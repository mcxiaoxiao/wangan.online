#include<stdio.h>
#include<string.h>
#define N 110

int max(int a, int b)
{
    return a>b?a:b;
}

int main(void)
{
    int f[N],v[N],w[N];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d%d",&v[i],&w[i]);
    }

    memset(f,0,sizeof(f));
    for(int i = 1; i <= n; i ++)
    {
        for(int j = m; j >= v[i]; j --)
        {
                f[j] = max(f[j-v[i]]+w[i],f[j]);
        }
    }

    printf("%d",f[m]);
    return 0;
}
