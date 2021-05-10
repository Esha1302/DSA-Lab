#include "header.h"

int main()
{
	FILE * fp = fopen("aliceinwonderland.txt","r");
	if(fp == NULL)
	{
		printf("File doesn't exist\n");
		return 0;
	}
	Book * book1 = parsing(fp);
	printf("Parsing successful\n");
	baseNumber = 5011;
	tableSize = 5000;

	hashtable * ht = creation();
	printf("%d\n",insertAll(ht,book1->book,book1->size));
	char ** temp = book1->book;
	for(int i = 0; i < book1->size; i++)
	{
		printf("%s\n",temp[i] );
	} 
	printf("%d\n",lookUpAll(ht,book1->book,book1->size,0.1));
	
	
	return 0;
}