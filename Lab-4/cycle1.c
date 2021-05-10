#include<stdio.h>
#include<stdlib.h>
#include "Exer2.h"
#include "cycle.h"
int testCyclic(struct node * head)
{
	struct node * hare = head, * tort = head;
	if(head==NULL)
	{
		printf("Not applicable. The list is empty.\n");
		return 0;
	}
	else if(head->next==NULL)
	{
		printf("Not applicable. The list is has only one element.\n");
		return 0;
	}
	else if((head->next)->next==NULL)
	{
		printf("Not applicable. The list is has only two elements.\n");
		return 0;
	}
	else
	{
		tort = head->next;
		hare = (head->next)->next;
		
		while(hare->next != NULL && hare->next->next !=NULL)
		{
			if(hare->next == tort || hare == tort)
			{
				printf("The list is circular.\n");
				return 1;
			}
			hare = (hare->next)->next;
			tort = tort->next;
			
		}
		// printf("out of while here\n");
		printf("Linear list.\n");
		// printf("reached here\n");
		return 0;
	}
}