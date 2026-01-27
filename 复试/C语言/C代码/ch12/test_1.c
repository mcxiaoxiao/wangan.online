#include<stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node,*Linklist;

int main(void)
{
    Linklist head = malloc(sizeof(Node));
    head->next = NULL;
    int n = 0;
    scanf("%d",&n);
    while(n!= 9999)
    {
        Linklist node = malloc(sizeof(Node));
        node->data = n;
        node->next = head->next;
        head->next = node;
        scanf("%d",&n);
    }

    Linklist cur = head->next;
    while(cur)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    return 0;
}

