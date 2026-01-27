#include<stdio.h>

int Magic(int m); //是就输出abc并返回1

int main(void)
{
    int n;
    int res;
    scanf("%d",&n);
    res = Magic(n);
    if(res != 1) printf("WRONG!\n");

    return 0;
}

int Magic(int m)
{
    int a, b, c;
    for(a = 1; a <= 9; a++)
    {
        for(b = 0; b <= 9; b ++)
        {
            for(c = 0; c <= 9; c++)
            {
                if(122*a+212*b+221*c == m)
                {
                    printf("%d%d%d\n",a,b,c);
                    return 1;
                }
                if(122*a+212*b+221*c > m) break;
            }
        }
    }
    return 0;
}
