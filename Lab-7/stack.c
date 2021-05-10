#include "stack.h"

list * newStack(){
    list * stack = (list *)malloc(sizeof(list));
	stack->first = NULL;
	stack->count = 0;
	return stack;
}

void push(list * stack, int a, int b){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->l = a;
	temp->r = b;

	temp->next = stack->first;
	stack->first = temp;
	stack->count++;
}

struct node * pop(list * stack){
    struct node * temp;
	if(stack->count==0){
		temp->l = -1;
		temp->r = -1;
		temp->next = NULL;
		return temp;
	}

	temp = stack->first;
	stack->first = (stack->first)->next;
	(stack->count)--;
	return temp;
}

