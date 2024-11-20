#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
typedef struct node {
    int data;
    struct node* next;
} node;

// Function declarations
void insertend(node** head, int item);
void display(node* head);
void deletend(node** head);

// Main function
int main() {
    int item;
    char choice;
    node* head = NULL;  // Initializing head to NULL

    while (1) {
        printf("\nDo you want to insert a node at the end? [Y/N]: ");
        scanf(" %c", &choice);  // Added space before %c to ignore newline character
        
        if (choice == 'Y' || choice == 'y') {
            printf("Enter the item to insert into the linked list: ");
            scanf("%d", &item);
            insertend(&head, item);
            display(head);
        }

        printf("\nDo you want to delete a node from the end? [Y/N]: ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            deletend(&head);
            display(head);
        }

        printf("\nDo you want to continue? [Y/N]: ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            break;  // Exit the loop if the user doesn't want to continue
        }
    }

    printf("\nFinal linked list: ");
    display(head);

    return 0;
}

// Function to insert a node at the end of the linked list
void insertend(node** head, int item) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = item;  // Assign the data
    new_node->next = NULL;  // New node will point to NULL

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = new_node;
    } else {
        node* temp = *head;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Make the last node point to the new node
        temp->next = new_node;
    }
}

// Function to display the linked list
void display(node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the end of the linked list
void deletend(node** head) {
    if (*head == NULL) {
        printf("The linked list is empty. Nothing to delete.\n");
        return;
    }

    node* temp = *head;
    // If there's only one node
    if (temp->next == NULL) {
        printf("Deleted node with value: %d\n", temp->data);
        free(temp);
        *head = NULL;  // List becomes empty
        return;
    }

    // Traverse to the second last node
    node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Delete the last node
    printf("Deleted node with value: %d\n", temp->data);
    free(temp);
    prev->next = NULL;  // Second last node now becomes the last node
}