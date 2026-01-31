#include<stdio.h>
#define N 1e6+10
int main(void)
{
    int n, m;
    int room[10];
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d",&room[i]);
    }

    int flag = 1;

    while(m --)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        for(int i = b; i <= c; i++)
        {
            room[i] -= a;
            if(room[i] < 0) printf("-1\n%d",flag);
        }
        flag ++;
    }

    return 0;
}
