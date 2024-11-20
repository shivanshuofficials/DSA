#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to insert a new node at the end of the linked list
void insertNode(Node **head)
{
    int data;
    printf("Enter data for new node: ");
    scanf("%d", &data);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *lastNode = *head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

// Function to insert a new node at the middle of the linked list
void insertAtMid(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *slowPtr = *head;
        Node *fastPtr = *head;

        while (fastPtr->next != NULL && fastPtr->next->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }

        newNode->next = slowPtr->next;
        slowPtr->next = newNode;
    }
}

// Function to delete a node from the linked list
void deleteNode(Node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head)->data == data)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *prevNode = *head;
    Node *currentNode = (*head)->next;

    while (currentNode != NULL)
    {
        if (currentNode->data == data)
        {
            prevNode->next = currentNode->next;
            free(currentNode);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    printf("Node not found\n");
}

// Function to find the middle value of the linked list
int findMiddle(Node *head)
{
    Node *slowPtr = head;
    Node *fastPtr = head;

    if (head != NULL)
    {
        while (fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
    }
    return slowPtr->data;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    char choice;

    do
    {
        insertNode(&head);
        printf("Do you want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    printf("Linked List: ");
    printList(head);

    printf("Middle Value: %d\n", findMiddle(head));

    int data;
    printf("Enter data to insert at mid: ");
    scanf("%d", &data);
    insertAtMid(&head, data);

    printf("Linked List after inserting at mid: ");
    printList(head);

    printf("Enter data to delete: ");
    scanf("%d", &data);
    deleteNode(&head, data);

    printf("Linked List after deleting: ");
    printList(head);

    return 0;
}