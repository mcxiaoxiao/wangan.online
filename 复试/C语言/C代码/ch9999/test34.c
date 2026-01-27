#include<stdio.h>
int DayofYear(int year, int month, int day);
int dayTab[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
main()
{
    int year, month, day, yearDay;
    printf("Please enter year, month, day:\n");
    scanf("%d,%d,%d", &year, &month, &day);
    yearDay = DayofYear(year, month, day);
    printf("yearDay = %d\n", yearDay);
}
int DayofYear(int year, int month, int day)
{
    int i;
    for (i = 1; i < month; i++)
    {
        day += dayTab[i];
    }
    return day;
}
