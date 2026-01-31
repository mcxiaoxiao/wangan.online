#include<stdio.h>
#define INF 1e6;

int main(void)
{
    int n, m;
    scanf("%d",&n);
    int s1[n];
    for(int i = 0; i < n; i ++) scanf("%d",&s1[i]);

    scanf("%d",&m);
    int s2[m];
    for(int i = 0; i < m; i ++) scanf("%d",&s2[i]);

    s1[n] = INF;
    s2[m] = INF;

    int i = 0, j = 0, count = 0, p;
    while(count < (m+n-1)/2 + 1)
    {
        if(s1[i] < s2[j])
        {
            p = s1[i];
            i ++;
        }
        else
        {
            p = s2[j];
            j ++;
        }
        count ++;
    }
    printf("%d",p);
    return 0;
}
