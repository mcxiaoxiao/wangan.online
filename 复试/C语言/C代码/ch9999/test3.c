#include <stdio.h>

int main(void)
{
    int res1 = 0, res2 = 0 ;
    int n = 0;
    scanf("%d",&n);
    while(n --)
    {
        int a, a1, b, b1;
        scanf("%d%d%d%d",&a,&a1,&b,&b1);
        if(a+b == a1)
        {
            if(a+b!=b1) res2 ++;
        }
        if(a+b == b1)
        {
            if(a+b != a1) res1 ++;
        }
    }
    printf("%d %d",res1,res2);

    return 0;
}
