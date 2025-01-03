#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

// Function to display the doubly linked list]]
void disp(struct node *ptr) {
    printf("Doubly Linked List Elements:\n");
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third;

    // Memory allocation for nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Initialize head node
    head->data = 7;
    head->next = second;
    head->prev = NULL;

    // Initialize second node
    second->data = 8;
    second->next = third;
    second->prev = head;

    // Initialize third node
    third->data = 9;
    third->next = NULL;
    third->prev = second;

    // Display the doubly linked list
    disp(head);

    return 0;
}
