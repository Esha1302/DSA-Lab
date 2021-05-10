#include "header.h"

hashtable* creation()
{
	hashtable* htable = (hashtable *)malloc(sizeof(hashtable));
	htable->elementCount = 0;
	htable->insertionCost = 0;
	htable->queryingCost = 0;
	htable->arrLink = (Node **)malloc(tableSize*sizeof(Node*));
	for(int i = 0; i < tableSize; i++)
	{
		htable->arrLink[i] = NULL;
	}
	return htable;
}


void insert(hashtable * ht, char ** A,int j)
{
	if(ht == NULL)
	{
		printf("Hashtable Invalid!!\n");
		return;
	}

	int index = hashFunction(A[j]);
	Node * temp = ht->arrLink[index];
	if(temp == NULL)
	{
		Node * new = (Node *)malloc(sizeof(Node));
		new->count = 1;
		new->index = j;
		new->str = (char *)malloc((strlen(A[j])+1)*sizeof(char));
		strcpy(new->str,A[j]);
		new->next = NULL;
		ht->arrLink[index] = new;
		ht->elementCount ++;
		return;
	}
	while(temp->next != NULL && strcmp(temp->str,A[j])!=0)
	{
		temp = temp->next;
		ht->insertionCost++;
	}
	if(strcmp(temp->str,A[j]) == 0)
		temp->count ++;
	else
	{
		Node * new = (Node *)malloc(sizeof(Node));
		new->count = 1;
		new->index = j;
		new->str = (char *)malloc((strlen(A[j])+1)*sizeof(char));
		strcpy(new->str,A[j]);

		new->next = NULL;
		temp->next = new;
		ht->elementCount++;
	}

}

int insertAll(hashtable * ht, char ** book,int size)
{
	for(int i = 0; i < size; i++)
	{
		insert(ht, book, i);
	}
	return ht->insertionCost;
}

Node * lookUp(hashtable * ht, char * str)
{
	if(ht == NULL)
	{
		printf("Hashtable invalid!!\n");
		return NULL;
	}

	int index = hashFunction(str);
	Node * temp = ht->arrLink[index]; 
	if(temp == NULL)
	{
		printf("%s not in Hashtable!!\n",str);
		ht->queryingCost++;
		return NULL;
	}
	while(temp->next != NULL && strcmp(temp->str, str) !=0 )
	{
		temp = temp->next;
		ht -> queryingCost++;
	}
	if(strcmp(temp->str,str) == 0)
	{
		ht->queryingCost++;
		return temp;
	}
	else
		return NULL;
}

int lookUpAll(hashtable * ht,char ** A, int size, float m)
{
	int entries = m * size;
	int z;
	for(int i = 0 ; i < entries; i++)
	{
		z = i % size;
		Node * temp = lookUp(ht, A[z]);
	}
	return ht->queryingCost;
}