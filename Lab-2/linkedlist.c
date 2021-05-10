#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

void insertFirst(struct linkedList * head, int ele){
    struct node *temp=(struct node *)(malloc(sizeof(struct node)));
    temp->element = ele;
    temp->next = head->first;
    head->first = temp;
    head->count++;
    // printf("%d ", head->first->next);
    // printf("%d ", head->count);
    // printf("%d ", temp->element);
}

struct node * deleteFirst(struct linkedList * head){

    if(head->count == 0){
        printf("\n%s","Stack is empty");
        return NULL;
    }
    struct node *temp = head->first;
    head->first = head->first->next;
    head->count--;
    return temp;
}

void printList(struct linkedList * head){
    struct node *temp = head->first;
    // printf("%d",temp);
    printf("\n[ ");
    while(temp!=NULL){
        printf("%d, ",temp->element);
        temp = temp->next;
    }
    printf("]");
}

int search(struct linkedList * head, int ele){
    struct node *temp = head->first;
    int res = 0;
    while(temp!=NULL){
        if(temp->element==ele){
            res = 1;
            break;
        }
        else
        {   
            temp = temp->next;
            continue;
        }
    }
    return res;
}

struct node * delete(struct linkedList * head, int ele){
    
    if(head->count == 0){
        return NULL;
    }
    int res = search(head,ele);
    if(res==0)
        return NULL;
    struct node *temp = head->first, *prev;
    if(head->first->element==ele){
        head->first = head->first->next;
        return temp;
    }   

    while(temp!=NULL){
        if(temp->element!=ele){
            prev = temp;
            temp = temp->next;
        }
        else{
            prev->next = temp->next;
            return temp;
        }
    }
}



