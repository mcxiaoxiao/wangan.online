#include<stdio.h>
#define N 100
typedef struct student
{
    char sn[N];
    int score;
}STU;

int main(void)
{
    STU stus[N];
    int n;
    int i, j;
    STU temp;

    printf("INPUT number of student\n");
    scanf("%d",&n);
    for(i = 0; i < n; i ++)
    {
        printf("N.%d student\n",i+1);
        scanf("%s%d",stus[i].sn,&stus[i].score);
    }
    for(i = 0; i < n; i ++)
    {
        for(j = n-1; j > i; j--)
        {
            if(stus[j].score > stus[j-1].score)
            {
                temp = stus[j];
                stus[j]=stus[j-1];
                stus[j-1]=temp;
            }
        }
    }
    for(i = 0; i < n; i ++)
    {
        printf("%s:%d\n",stus[i].sn,stus[i].score);
    }
    return 0;
}
