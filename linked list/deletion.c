#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//function
void disp(struct node *ptr)
{
    while (ptr != NULL)

    {
        printf("\nElement %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * deletefirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head ;

}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;
    // memory allocate
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

//data assign 
    head->data = 7;
    head->next = second;
    second->data = 8;
    second->next = third;
    third->data = 9;
    third->next = NULL;


    printf("\n linked list before deletion :");

    disp(head);
    head = deletefirst(head);

    printf("\n linked list after deletion :");
    disp(head);
    head = deletefirst(head); 

    // printf("\n linked list after deletion :");
    // disp(head);
    return 0;
    
}