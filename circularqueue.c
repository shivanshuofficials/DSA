//circular queue implementation
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
} node;

int enque(node**, node**, int);
int display(node*);
int deque(node**, node**);

node* front = NULL;
node* rear = NULL;
int item;

int main()
{
	int item, choice;
	char ch;
	do {
		printf("\n1.insert in circular queue \n2.delete from circular queue \nEnter Choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("enter the element of queue : ");
			scanf("%d", &item);
			enque(&front, &rear, item);
			display(front);
			break;
		case 2:
			deque(&front, &rear);
			display(front);
			break;
		default:
			printf("Wrong Input\n");
		}
		getchar();
		printf("do you want to continue  [Y/N]:");
		scanf("%c", &ch);
	} while ('y' == ch || 'Y' == ch);
	display(front);
	return 0;
}

int enque(node** front, node** rear, int item)
{
	node* new;
	new = (node*)malloc(sizeof(node));
	if (NULL == new)
	{
		printf("memory allocation failure");
		return 0;
	}
	new->data = item;
	if (NULL == *front)
	{
		*front = new;
		*rear = new;
		(*rear)->next = *front;
	}
	else
	{
		new->next = (*rear)->next;
		(*rear)->next = new;
		*rear = new;
	}
	return 1;
}

int deque(node** front, node** rear)
{
	node* temp;
	if (NULL == *front)
	{
		printf("queue is empty");
		return 0;
	}
	item = (*front)->data;
	if (*front == *rear)
	{
		free(*front);
		*front = NULL;
		*rear = NULL;
	}
	else
	{
		temp = *front;
		*front = (*front)->next;
		(*rear)->next = *front;
		free(temp);
	}
	return item;
}

int display(node* front)
{
	node* p;
	if (NULL == front)
	{
		printf("queue empty\n");
		return 0;
	}
	p = front;
	do
	{
		printf("%d\t", p->data);
		p = p->next;
	} while (p != front);
	printf("\n");
	return 1;
}