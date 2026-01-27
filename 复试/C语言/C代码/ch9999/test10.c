#include<stdio.h>
#include<string.h>
#define N 120
int IsAllDigit(char p[]);/*若全由数字组成，则函数返回1，否则返回0*/
int main(void)
{

    char s[N]; // 声明指针要进行分配空间 if 不仅仅是指向作用
    gets(s);
    if(IsAllDigit(s)) puts("Right!!");
    else puts("NO!");
    return 0;
}

int IsAllDigit(char p[])
{
    int flag = 1;
    char *a = p;
    while(*a!='\0')
    {
        if(*a <= '0' || *a >= '9')
        {
            flag = 0;
            break;
        }
        a++;
    }

    return flag;
}
