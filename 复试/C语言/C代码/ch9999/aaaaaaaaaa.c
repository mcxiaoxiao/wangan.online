#include<stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;
int main(void)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    Node* p = head;
    int data = 0;
    scanf("%d",&data);
    while(data)
    {
        Node *nd = (Node*)malloc(sizeof(Node));
        nd->data = data;
        p->next=nd;
        p=nd;
        scanf("%d",&data);
    }
    p->next = NULL;
    p=head->next;
    while(p)
    {
        printf("%d",p->data);
        p = p->next;
    }
    return 0;
}
