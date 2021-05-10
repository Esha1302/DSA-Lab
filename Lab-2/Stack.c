#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
#include "Stack.h"
struct linkedList *head;
void push(int ele){
    struct node *temp;
    if(temp == NULL){
        head = (struct linkedList *)malloc(sizeof(struct linkedList));
        temp = (struct node *)malloc(sizeof(struct node));
        temp->element = ele;
        temp->next = NULL;
        head->first = temp;
        head->count = 0;
    }

    else{
        head->count++;
        insertFirst(head, ele);
    }
}

struct node * pop(){
    struct node * deleted_node = deleteFirst(head);
    return deleted_node;
}