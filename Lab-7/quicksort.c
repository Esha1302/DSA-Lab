#include "quicksort.h"

void swap(Employee * e1, Employee * e2){
	Employee temp = * e1;
	* e1 = * e2;
	* e2 = temp;
}

int partition(Employee arr[], int l, int r){
	int pivot = arr[r].empID;
	int i = l-1;
	for(int j = l; j < r; j++){
		if(arr[j].empID <= pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[++i], &arr[r]);
	return i;
}

void quickSort(Employee arr[], int n, int S){
	list * stack = newStack();
	struct node * temp;
	int l,r,next;
	push(stack, 0, n-1);

	while(stack->count > 0){
		temp = pop(stack);
		l = temp->l; 
		r = temp->r;
		if(r - l > S){
			next = partition(arr, l, r);
			push(stack, l, next - 1);
			push(stack, next + 1, r);
		}
	}
}