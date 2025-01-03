#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
} node;

void insertbeg(node**, node**, int);
void display(node*);
void deletebeg(node**, node**);

node* head = NULL;
node* tail = NULL;

int main()
{
	int item, choice;
	char ch;
	do {
		printf("\n1.Insert into Linked List\n2.Delete from linked list\nEnter Choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the item to be inserted: ");
			scanf("%d", &item);
			insertbeg(&head, &tail, item);
			display(head);
			break;
		case 2:
			deletebeg(&head, &tail);
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

void insertbeg(node** head, node** tail, int item)
{
	node* new = (node*)malloc(sizeof(node));
	if (NULL == new)
	{
		printf("Memory allocation failure");
		return;
	}
	new->data = item;
	new->prev = NULL;
	if (NULL == *head)
	{
		new->next = NULL;
		*head = new;
		*tail = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

void display(node* head)
{
	node* p = head;
	if (NULL == head)
	{
		printf("Empty list\n");
		return;
	}
	while (NULL != p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void deletebeg(node** head, node** tail)
{
	node* p = *head;
	if (NULL == *head)
	{
		printf("Empty list\n");
		return;
	}

	if (*head == *tail)
	{
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		*head = p->next;
		(*head)->prev = NULL;
	}
	free(p);
}