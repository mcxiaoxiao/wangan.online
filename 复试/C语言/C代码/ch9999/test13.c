#include  <stdio.h>

#include  <stdlib.h>

#include  <string.h>

#define   MAX_LEN  10                	    /* 字符串最大长度 */

#define   STU_NUM 30                       /* 最多的学生人数 */

#define   COURSE_NUM 6                     /* 最多的考试科目数 */

typedef struct student

{

    long num;			/* 每个学生的学号 */

    char name[MAX_LEN];            	/* 每个学生的姓名 */

    float score[COURSE_NUM];	/* 每个学生COURSE_NUM门功课的成绩 */

    float sum;                   	/* 每个学生的总成绩 */

    float aver;               	/* 每个学生的平均成绩 */

} STU;

int   Menu(void);

void  ReadScore(STU stu[], int n, int m);

void  AverSumofEveryStudent(STU stu[], int n, int m);

void  AverSumofEveryCourse(STU stu[], int n, int m);

void  SortbyScore(STU stu[],int n,int m,int (*compare)(float a,float b));

int   Ascending(float a, float b);

int   Descending(float a, float b);

void  SwapFloat(float *x, float *y);

void  SwapLong(long *x, long *y);

void  SwapChar(char x[], char y[]);

void  AsSortbyNum(STU stu[], int n, int m);

void  SortbyName(STU stu[], int n, int m);

void  SearchbyNum(STU stu[], int n, int m);

void  SearchbyName(STU stu[], int n, int m);

void  StatisticAnalysis(STU stu[], int n, int m);

void  PrintScore(STU stu[], int n, int m);

int main()

{

    char  ch;

    int   n = 0, m = 0;  /* 学生人数为n，课程门数为m */

    STU   stu[STU_NUM];

    printf("Input student number(n<=30):\n", STU_NUM);

    scanf("%d", &n);

    while (1)

    {

        ch = Menu();       /* 显示菜单，并读取用户输入 */

        switch (ch)

        {

        case 1:

            printf("Input course number(m<=%d):\n",COURSE_NUM);

            scanf("%d", &m);

            ReadScore(stu,n,m);

            break;

        case 2:

            AverSumofEveryCourse(..........);

            break;

        case 3:

            AverSumofEveryStudent(..........);

            break;

        case 4:

            SortbyScore(..........);

            printf("Sort in descending order by score:\n");

            PrintScore(..........);

            break;

        case 5:

            SortbyScore(..........);

            printf("Sort in ascending order by score:\n");

            PrintScore(..........);

            break;

        case 6:

            AsSortbyNum(..........);

            printf("Sort in ascending order by number:\n");

            PrintScore(..........);

            break;

        case 7:

            SortbyName(..........);

            printf("Sort in dictionary order by name:\n");

            PrintScore(..........);

            break;

        case 8:

            SearchbyNum(..........);

            break;

        case 9:

            SearchbyName(..........);

            break;

        case 10:

            StatisticAnalysis(..........);

            break;

        case 11:

            PrintScore(..........);

            break;

        case 0:

            printf("End of program!");

            exit(0);

        default:
            printf("Input error!\n");

        }

    }

    return 0;

}



/*  函数功能：显示菜单并获得用户键盘输入的选项 */

int Menu(void)

{
    int res;
    puts("1.Input record");
    puts("2.Caculate total and average score of every course");
    puts("3.Caculate total and average score of every student");
    puts("4.Sort in descending order by score");
    puts("5.Sort in ascending order by score");
    puts("6.Sort in ascending order by numbe");
    puts("7.Sort in dictionary order by name");
    puts("8.Search by number");
    puts("9.Search by name");
    puts("10.Statistic analysis");
    puts("11.List record");
    puts("0.Exit");
    printf("Please Input your choice: ");
    scanf("%d",&res);
    return res;
}



/* 函数功能：输入n个学生的m门课成绩 */

void ReadScore(STU stu[], int n, int m)

{


    for(int i = 0; i < n; i ++)
    {
        printf("Input student's ID, name and score:\n");
        scanf("%ld",&stu[i].num);
        while(getchar()!='\n');
        gets(stu[i].name);
        for(int j = 0; j < m; j ++)
        {
            scanf("%f",&stu[i].score[j]);
        }
    }

}



/* 函数功能：计算每个学生各门课程的总分和平均分 */

void AverSumofEveryStudent(STU stu[], int n, int m)

{
    float s;
    for(int i = 0; i < n; i ++)
    {
        s = 0;
        for(int j = 0; j < m; j ++)
        {
            s+=stu[i].score[j];
        }
        stu[i].sum = s;
        stu[i].aver = s / m;
        printf("student %d:sum=%f,aver=%.0f",i+1,s,s/m);
    }

}



/* 函数功能：计算每门课程的总分和平均分 */

void AverSumofEveryCourse(STU stu[], int n, int m)

{
    float s;
    for(int i = 0; i < m; i ++)
    {
        s = 0;
        for(int j = 0; j <= n; j ++)
        {
            s+= stu[j].score[i];
        }
        printf("course %d:sum=%f,aver=%d",i+1,s,(int)s/n);
    }

}

/* 函数功能：按选择法将数组sum的元素值排序 */

void SortbyScore(STU stu[], int n, int m, int (*compare)(float a, float b))

{

    for(int i = 0; i < n-1; i ++)
    {
        int min = i;
        for(int j = i; j < n; j ++)
        {
            if(compare(stu[j].num, stu[min].num))
            {
                min = j;
            }
        }
        STU student = stu[i];
        if(min != i)
        {
            stu[i] = stu[min];
            stu[min] = student;
        }
    }

}



/* 使数据按升序排序 */

int Ascending(float a, float b)

{

    return a<b;

}



/* 使数据按降序排序 */

int Descending(float a, float b)

{

    return a>b;

}



/* 交换两个单精度浮点型数据 */

void  SwapFloat(float *x, float *y)

{

    float temp = *x;
    *x = *y;
    *y = temp;

}



/* 交换两个长整型数据 */

void  SwapLong(long *x, long *y)

{

    long temp = *x;
    *x = *y;
    *y = temp;


}



/* 交换两个字符串 */

void  SwapChar(char x[], char y[])

{

    char temp[MAX_LEN];
    strcpy(temp,x);
    strcpy(x,y);
    strcpy(y,temp);
}



/* 函数功能：按选择法将数组num的元素值按从低到高排序 */

void AsSortbyNum(STU stu[], int n, int m)

{

    for(in i = 0; i <n-1; i ++)
    {
        int min = i;
        for(int j = i+1; j< n; j++)
        {
            if(stu[j].num<stu[min].name)
            {
                min = j;
            }
        }
        STU student = stu[i];
        if(min != i)
        {
            stu[i] = stu[min];
            stu[min] = student;
        }
    }
}



/* 函数功能：交换法实现字符串按字典顺序排序 */

void SortbyName(STU stu[], int n, int m)

{

    for(int i = 0; i < n; i ++)
    {
        for(int j = n-1; j > i; j--)
        {
            if(strcmp(stu[j].name, stu[j-1].name)<0)
            {
                STU stedent = stu[j];
                stu[j] = stu[j-1];
                stu[j-1] = student;
            }
        }
    }
}



/* 函数功能：按学号查找学生成绩并显示查找结果 */

void SearchbyNum(STU stu[], int n, int m)

{



}



/* 函数功能：按姓名的字典顺序排出成绩表 */

void SearchbyName(STU stu[], int n, int m)

{

    ..........

}

/* 函数功能：统计各分数段的学生人数及所占的百分比 */

void StatisticAnalysis(STU stu[], int n, int m)

{

    ..........

}



/* 函数功能： 打印学生成绩 */

void PrintScore(STU stu[], int n, int m)

{

    ..........

}
