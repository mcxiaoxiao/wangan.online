#include<stdio.h>
#include<time.h>
#define N 10
void getNum(int a[])
{
    srand(time(NULL));
    for(int i = 0; i < 10; i ++) a[i] = i;
    for(int i = 0; i < 10; i ++)
    {
        int k = rand()%10;
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
    for(int i = 0; i < 4; i ++)
        printf("%d ",a[i]);
    puts("");
}

int userInput(int a[])
{
    int ref = 0;
    for(int i = 0; i < 4; i ++)
    {
        ref = scanf("%1d",&a[i]);
        if(ref!=1)
        {
            printf("input again!\n");
            while(getchar()!='\n');
            return 0;
        }
    }
    if(a[0] == a[1] || a[0] == a[2] || a[0] == a[3] || a[1] == a[2] || a[2] == a[3] || a[1] == a[3]) return 0;
    return 1;
}

int rightPosi(int a[],int b[])
{
    int count = 0;
    for(int i = 0; i < 4; i ++)
        if(a[i] == b[i]) count ++;
    return count;
}

int rightVal(int a[], int b[])
{
    int count = 0;
    for(int i = 0; i < 4; i ++)
    {
        for(int j = 0; j < 4; j ++)
        {
            if(a[i] == b[j]) count ++;
        }
    }
    return count;
}

int main(void)
{
    int a[N],b[N];
    getNum(a);
    int flag = 1;
    do
    {
        printf("INPUT:");
        flag = userInput(b);
    }
    while(!flag);

    int x = rightPosi(a,b);
    int y = rightVal(a,b);

    printf("%dA%dB",x,y);
    return 0;
}
