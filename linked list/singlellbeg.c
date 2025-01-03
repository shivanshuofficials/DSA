#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
int insertbeg(node **, int);
int display(node *);
int deletebeg(node **);
node *head = NULL;
int item;

int main()
{
    int item, choice;
    char ch;
    do
    {
        printf("\n1.Insert into Linked List \n2.Delete from linked list \nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the items of linked list : ");
            scanf("%d", &item);
            insertbeg(&head, item);
            display(head);
            break;
        case 2:
            deletebeg(&head);
            display(head);
            break;
        default:
            printf("Wrong Input\n");
        }
        getchar();
        printf("do you want to continue  [Y/N]:");
        scanf("%c", &ch);
    } while ('y' == ch || 'Y' == ch);
    display(head);
    return 0;
}

int insertbeg(node **head, int item)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    if (NULL == new)
    {
        printf("memory allocation failure");
        return 0;
    }
    memset(new, 0, sizeof(node));
    new->data = item;
    if (NULL == *head)
    {
        *head = new;
        new->next = NULL;
    }
    else
    {
        new->next = *head;
        *head = new;
    }
    return 1;
}

int display(node *head)
{
    node *p;
    p = head;
    if (NULL == p)
    {
        printf("empty list\n");
        return 0;
    }
    while (NULL != p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 1;
}

int deletebeg(node **head)
{
    node *p;
    p = *head;
    if (NULL == *head)
    {
        printf("empty list\n");
        return 0;
    }
    item = (*head)->data;
    if (NULL == (*head)->next)
    {
        *head = NULL;
    }
    else
    {
        *head = p->next;
    }
    free(p);
    p = NULL;
    return item;
}
