#include<stdio.h>
#define N 20

int Median(int answer[], int n);
void DataSort(int a[], int n);
int main(void)
{
    int feedbacks[N] = {0};
    int n = 0;
    int i = 0;
    printf("Input total number of feedback\n");
    scanf("%d",&n);

    printf("Input feedbacks\n");
    for(i = 0;i < n ;i ++)
    {
        scanf("%d",&feedbacks[i]);
    }

    printf("Median value=%d\n",Median(feedbacks,n));

    return 0;
}

int Median(int answer[], int n)
{
    int x = 0;
    int y = 0;
    DataSort(answer,n);
    if(n%2 == 0)
    {
        x = n/2 - 1;
        y = n/2;
        return answer[x]+answer[y] >> 1;
    }
    return answer[n/2];
}

void DataSort(int a[], int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for(i = 0; i <n ; i++)
    {
        for(j = n - 1; j > i; j --)
        {
            if(a[j] < a[j-1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}
