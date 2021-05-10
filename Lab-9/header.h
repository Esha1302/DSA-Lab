#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int baseNumber,tableSize;

struct read
{
	char ** book;
	int size;
};

typedef struct read Book;

struct node
{
	int index;
	int count;
	char * str;
	struct node * next;
};

typedef struct node Node;

struct hash
{
	int elementCount;
	int insertionCost;
	int queryingCost;
	Node ** arrLink;
};

typedef struct hash hashtable;


int hashFunction(char * str);
int collisionCount(char ** arr,int size);
Book* parsing(FILE * fp);
void profiling(char ** book, int size);
hashtable* creation();
void insert(hashtable * ht, char ** A,int j);
int insertAll(hashtable * ht, char ** book,int size);
Node * lookUp(hashtable * ht, char * str);
int lookUpAll(hashtable * ht,char ** A,int size,float m);

