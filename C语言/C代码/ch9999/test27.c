#include<stdio.h>
#include<string.h>
struct person
{
    char name[20];
    int count;
};

struct person leader[3] = {"li",0,"zhang",0,"fun",0};

int main(void)
{
    int i, j, n;
    char leader_name[20];
    scanf("%d",&n);
    for(i = 0; i < n; i ++)
    {
        scanf("%s",leader_name);
        for(j = 0; j < 3; j ++)
        {
            if(strcmp(leader_name, leader[j].name) == 0)
            {
                leader[j].count++;
            }
        }
    }
    printf("\n");
    for(i = 0; i < 3; i ++)
    {
        printf("%s:%d\n", leader[i].name, leader[i].count);
    }
    return 0;
}
