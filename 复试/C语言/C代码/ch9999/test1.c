#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct
{
    char name[20];
    int score[3];
    float avg;
    float sum;
    int num;
}Worker;

int main(void)
{
    int n;
    printf("input the number of student ");
    scanf("%d",&n);
    getchar();
    Worker wok[n];
    for(int i = 0; i < n; i ++)
    {
        printf("input name ");
        gets(wok[i].name);
        float sum = 0;
        printf("input score:");
        for(int j = 0; j < 3; j ++)
        {
            scanf("%d",&wok[i].score[j]);
            sum += wok[i].score[j];
        }

        wok[i].sum = sum;
        wok[i].avg = sum / 3;
        printf("input num ");
        scanf("%d",&wok[i].num);
        getchar();
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j = n-1; j > i; j --)
        {
            if(strcmp(wok[j].name,wok[j-1].name) > 0)
            {
                Worker temp = wok[j];
                wok[j] = wok[j-1];
                wok[j-1]=temp;
            }
        }
    }
    for(int i = 0; i < n; i ++)
    {
        if(( wok[i].avg>85 || fabs(wok[i].avg - 85)<1e-6 ) && wok[i].num <= 2)puts(wok[i].name);
    }
    return 0;
}


