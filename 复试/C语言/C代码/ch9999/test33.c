#include<stdio.h>

int dayTab[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int DayofYear(int year, int month, int day);

int main(void)
{
    int year, month, day, yearDay;
    printf("Please enter year, month, day:\n");
    scanf("%d,%d,%d", &year, &month, &day);
    yearDay = DayofYear(year, month, day);
    printf("yearDay = %d\n", yearDay);
    return 0;
}

int DayofYear(int year, int month, int day)
{
    int i;
    int count = 0;
    if(year % 4 == 0 && year % 100!= 0 || year % 400 == 0) dayTab[2] = 29;
    for(i = 1; i < month; i ++)
    {
        count += dayTab[i];
    }
    return count+day;
}

/*)输入某年某月某日，计算并输出它是这一年的第几天
（要求考虑闰年的问题）*/
