#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    while(1)
    {


        srand(time(NULL));
        int magic = rand()%100;
        int flag = 0;
        int count = 0;
        while(!flag)
        {
            int guess = 0;
            int ret=scanf("%d",&guess);
            while(ret!=1)
            {
                while(getchar()!='\n');
                ret=scanf("%d",&guess);
            }
            if(guess > magic) puts("big");
            else if(guess <magic) puts("small");
            else flag = 1;
            count ++;
            if(count >= 10) break;
        }

        if(flag)puts("right");
        printf("together:%d times",count);

        printf("continue YorN:");
        char ch = getchar();
        while(ch!='N' && ch!='Y') ch = getchar();
        if(ch == 'N') break;
    }
    return 0;
}
