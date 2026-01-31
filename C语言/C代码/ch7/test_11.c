#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{


    char ch[5]="+-*/";
    int score = 0, count = 0;
    do
    {
        srand(time(NULL));
        int a = rand()%10+1;
        int b = rand()%10+1;
        int c = rand()%4;
        printf("%d %c %d=?\n",a,ch[c],b);
        float asw = 0;
        scanf("%f",&asw);
        count++;
        switch(c)
        {
        case 0:
            if(asw == a+b)
            {
                printf("RIGHT\n");
                score += 10;
            }
            break;
        case 1:
            if(asw == a-b)
            {
                printf("RIGHT\n");
                score += 10;
            }
            break;
        case 2:
            if(asw == a*b)
            {
                printf("RIGHT\n");
                score += 10;
            }
            break;
        case 3:
            if(fabs(asw - (float)a/b) <1e-1)
            {
                printf("RIGHT\n");
                score += 10;
            }
            break;
        default:
            puts("------");
        };
        if(count == 10 && (float)score/100 <= 0.75)
        {
            printf("JUST %.2f\n",(float)score/100);
            score = count = 0;
        }
    }
    while(count < 10);

    printf("score:%d & rate:%.2f",score,(float)score/100);

    return 0;
}
