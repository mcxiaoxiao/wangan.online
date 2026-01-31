#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

void insert(Node* link)
{
    Node* p = link;
    int data;
    scanf("%d",&data);
    while(data)
    {
        link->data++;
        Node* node = (Node*)malloc(sizeof(Node));
        node->data=data;
        p->next = node;
        p = node;
        scanf("%d",&data);
    }
    p->next=NULL;
}

void del(Node* link)
{
    int x;
    printf("INPUT DELETE NUMBER:\n");
    scanf("%d",&x);
    Node* q = link;
    Node* p = q->next;
    while(p)
    {
        if(p->data == x)
        {
            q->next=p->next;
            link->data--;
        }
        q = p;
        p = q->next;
    }
}

void show(Node* link)
{
    Node* p = link->next;
    for(int i = 1; i <= link->data; i ++)
    {
        printf("%d:%d\n",i,p->data);
        p=p->next;
    }
}

int main(void)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;

    char ch=NULL;
    while(ch != 'e')
    {
        printf("INPUT UR CHIOCE(i|d|s):\n");
        scanf(" %c",&ch);
        switch(ch)
        {
        case 'i':
            insert(head);
            break;
        case 'd':
            del(head);
            break;
        case 's':
            show(head);
            break;
        default:
            printf("NO\n");
        }

    }

    return 0;
}
