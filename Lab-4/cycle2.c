#include<stdio.h>
#include<stdlib.h>
#include "Exer2.h"
#include "cycle.h"
int testCyclic(struct node * head)
{
	if(head == NULL)
	{
		printf("Not applicable. The list is empty.\n");
		return 0;
	}
	else if(head->next == NULL)
	{
		printf("Not applicable. The list is has only one element.\n");
		return 0;
	}
	else if((head->next)->next == NULL)
	{
		printf("Not applicable. The list is has only two elements.\n");
		return 0;
	}
	else
	{
		struct node * temp1 = head;
		struct node * temp2 = head->next;
		struct node * temp;
		while(temp2 != NULL)
		{
			temp = temp2->next;
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp;
			if(temp2 == head)
			{
				printf("The linked list is cyclic.\n");
				return 1;
			}
		}
		printf("The linked list is linear.\n");
		return 0;
	}
}