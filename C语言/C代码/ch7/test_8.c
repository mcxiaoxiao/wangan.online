#include <stdio.h>
#include <time.h>
int rad()
{
    srand(time(NULL));
    return rand()%2;
}
int ipt(int tol)
{
    int n = 0;
    do
    {
        printf("INPUT YOUR TIMES:");
        scanf("%d",&n);
    }
    while(n<=0 || n>2);

    return n;
}
int cmpIpt(int tol)
{
    int n = 30 - tol;
    if(n%3 == 1) return 1;
    if(n%3 == 2) return 2;
    if(n%3 == 0) return rad()+1;
}
int main()
{
    int tol = 0;
    if(rad())
    {
        tol+=ipt(tol);
    }
    while(tol<30)
    {
        int guess = cmpIpt(tol);
        tol+=guess;
        printf("time:%dcount:%d\n",guess,tol);
        if(tol>=30)
        {
            printf("cm WIN\n");
            break;
        }
        tol+=ipt(tol);
        printf("%d\n",tol);
        if(tol>=30)
        {
            printf("you win\n");
            break;
        }
    }
    return 0;
}
