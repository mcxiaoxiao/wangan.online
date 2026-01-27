#include<stdio.h>
#include<stdlib.h>
const int N = 21, M = 6;

void ReadScore(float score[][M],int n, int m)
{
    printf("Input %d judges' score for %d athletes\n",m,n);
    for(int i = 0; i < n; i ++)
    {
        int min = 0, max = 0;
        for(int j = 0; j < m; j ++)
        {
            scanf("%f",&score[i][j]);
            if(score[i][j]<score[i][min]) min = j;
            if(score[i][j]>score[i][max]) max = j;
        }
        score[i][min] = 0;
        score[i][max] = 0;
    }
}

void CountScore(float averagscore[],float score[][M],int n,int m)
{
    for(int i = 0; i < n; i ++)
    {
        float sum = 0;
        for(int j = 0; j < m; j ++)
        {
            sum += score[i][j];
        }
        averagscore[i] = sum/(m-2);
    }
}

void PrintScore(float averagescore[],int n)
{
    printf("The final scores for each athletes\n");
    for(int i = 0;i < n; i++) printf("%.2f\n",averagescore[i]);
}

int main(void)
{
    float score[N][M];
    float avgs[N];
    int n, m;
    printf("Input the number of athletes\n");
    scanf("%d",&n);
    printf("Input the number of judges\n");
    scanf("%d",&m);

    ReadScore(score,n,m);
    CountScore(avgs,score,n,m);
    PrintScore(avgs,n);

    return 0;
}
