#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;

};
void disp(struct node *ptr){
    while (ptr !=  NULL)
    {
        printf("ELEMENTS: %d \n",ptr->data);
        ptr= ptr->next;
    }
    
}
//insert in the begin
struct node * insertbeg(struct node * head ,int data){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));// head node
    ptr->next =head;
    ptr ->data = data;
    return ptr;
}

//insert at the middle 
struct node * insertmid(struct node*head,int data,int index){
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i =0;
    while (i != index -1)//next value 
    {
        p = p->next;
        i++;
    }
    
    ptr ->data= data;
    ptr -> next = p->next;
    p -> next =ptr;
    return head;
}

int main(){
    //nodes
    struct node * head  = (struct node *)malloc(sizeof(struct node));
    struct node * second;
    struct node * third;

   
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head ->data = 7;
    head ->next =second;

    second ->data = 8;
    second ->next =third;

    third ->data = 9;
    third ->next =NULL;

    disp(head);

    head = insertbeg(head,15);
    disp(head);

    head = insertmid(head,30,2);
    disp(head);
    return 0;
}