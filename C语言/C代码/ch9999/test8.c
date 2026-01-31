#include<stdio.h>

void move(int n,char a, char b)
{
    printf("%d: %c-->%c\n",n,a,b);
}
void hanoi(int n, char a, char b, char c)
{
    if(n == 1) move(n,a,c);
    else{
    hanoi(n-1,a,c,b);
    move(n,a,c);
    hanoi(n-1,b,a,c);}
}
int main(void)
{
    int n;
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}
