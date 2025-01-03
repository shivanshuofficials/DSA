#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
} node;

int insertend(node**, node**, int);
int display(node*);
int deletend(node**, node**);

node* head = NULL;
node* tail = NULL;
int item;

int main()
{
	int item, choice;
	char ch;
	do {
		printf("\n1.Insert at end into Linked List\n2.Delete from linked list\nEnter Choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the item to be inserted: ");
			scanf("%d", &item);
			insertend(&head, &tail, item);
			display(head);
			break;
		case 2:
			deletend(&head, &tail);
			display(head);
			break;
		default:
			printf("Wrong Input\n");
		}
		getchar();
		printf("Do you want to continue [Y/N]: ");
		scanf("%c", &ch);
	} while ('y' == ch || 'Y' == ch);
	display(head);
	return 0;
}

int insertend(node** head, node** tail, int item)
{
	node* new = (node*)malloc(sizeof(node));
	if (NULL == new)
	{
		printf("Memory allocation failure");
		return 0;
	}
	new->data = item;
	new->next = NULL;
	if (NULL == *head)
	{
		new->prev = NULL;
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		new->prev = *tail;
		*tail = new;
	}
	return 1;
}

int display(node* head)
{
	node* p = head;
	if (NULL == p)
	{
		printf("Empty list\n");
		return 0;
	}
	while (NULL != p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 1;
}

int deletend(node** head, node** tail)
{
	node* p;
	if (NULL == *head)
	{
		printf("Empty list\n");
		return 0;
	}
	p = *tail;
	item = (*tail)->data;
	if (*head == *tail)
	{
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		*tail = p->prev;
		(*tail)->next = NULL;
	}
	free(p);
	return item;
}
