#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    int x;
    scanf("%d",&x);
    int res[10];
    int last = x;
    int count = 0;
    memset(res,0,sizeof(res));
    while(x)
    {
        count++;
        int a = fabs(x%10);
        res[a]++;
        x/=10;
    }

    printf("%d:%dbits\n",last,count);
    for(int i = 0; i < 10;  i++)
    {
        if(res[i]!=0) printf("%d:%d\n",i,res[i]);
    }


    return 0;
}
