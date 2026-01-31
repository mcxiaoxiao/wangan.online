//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
///*
//创建动态链表并打印链表内容。要求通过键盘读入学生的学号和分数，
//当输入的学号为0时表示链表创建结束，并将读入的学生学号和成绩打印输出。
//*/
//
//typedef struct stu
//{
//    int num;
//    int score;
//    struct stu * next;
//}Stu;
//
//void insert(Stu* stulink)
//{
//    Stu* p = stulink;
//    int num, score;
//    scanf("%d%d",&num,&score);
//    while(num)
//    {
//        Stu* student = (Stu*)malloc(sizeof(Stu));
//        p->next = student;
//        student->num = num, student->score = score;
//        p = student;
//        printf("======\n");
//        scanf("%d%d",&num,&score);
//    }
//    p->next = NULL;
//}
//
//void show(Stu *p)
//{
//
//    p = p->next;
//    while(p!=NULL)
//    {
//
//        printf("%d %d\n",p->num,p->score);
//        p = p->next;
//    }
//}
//
//int main(void)
//{
//    Stu* stulink = (Stu*)malloc(sizeof(Stu));
//    stulink->next = NULL;
//    stulink->num = -1;
//    stulink->score = -1;
//    insert(stulink);
//    show(stulink);
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
struct node
{
    long num;
    float score;
    struct node *next;
};
int main()
{
    struct node *head, *p, *q;

    head = (struct node*)malloc(sizeof(struct node));
    p = (struct node*)malloc(sizeof(struct node));
    q = p;

    head->next = p;
    scanf("%ld%f", &p->num, &p->score );

    while (p->num != 0)
    {
        p = (struct node*)malloc(sizeof(struct node));
        q->next = p;
        scanf("%ld%f", &p->num, &p->score);
        q = p;
    }
    p->next = NULL;
    p = head->next;
    while(p->next)
    {
        printf("%ld %.2f\n", p->num, p->score);
        p = p->next;
    }

    free(p);
    return 0;
}
