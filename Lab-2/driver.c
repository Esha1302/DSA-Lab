#include<stdio.h>
#include "Stack.h"
#include "linkedlist.h"
#include<stdlib.h>
int main(int argc, char *argv[])
{

FILE * fileptr = fopen(argv[1], "r");
while (!feof(fileptr))
{
    int temp;
    fscanf(fileptr, "%d", &temp);
    push(temp);
    
}
fclose(fileptr);

struct node *link = pop();
while(link!=NULL){
    printf("popped out element = %d\n",link->element);
    // link = link->next;
    link = pop();
}
return 0;
}