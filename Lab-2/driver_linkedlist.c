#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
// Create a file pointer and open the file read as command line argument.
FILE * fileptr = fopen(argv[1], "r");

// Declare a pointer to a linked list (head) and allocate memory to it.
struct linkedList * head = (struct linkedList *) malloc (sizeof(struct linkedList));
// In a loop read the file and insert elements into the linkedList.
head->count = 0;
while (!feof(fileptr))
{
// read the next element and store into the temp variable.
    int temp;
    fscanf(fileptr, "%d", &temp);
    

    if(head->count == 0){
        struct node *first_n=(struct node *)(malloc(sizeof(struct node)));
        first_n->element = temp;
        first_n->next = NULL;
        head->first = first_n;
        head->count++;
        // printf("%d ", head->first->next);
        // printf("%d ", head->count);
    }
    // insert temp into the linked list.
    else{
        insertFirst(head,temp);
    }

}


// close the file pointer
fclose(fileptr);
// printf("%s","done");
// print the linked list.
printList(head);
// delete the first element of the linked list.
struct node *deleted_node = deleteFirst(head);
// delete a specific element
// struct node *deleted_node = delete(head, 100);
// if(deleted_node == NULL)
//     printf("%s\n", "Element that you want to delete could not be found");
// print the linked list again to check if delete was successful.
printList(head);
// print the linked list to a new file.
struct node *temp = head->first;
FILE *fptr;
fptr = fopen("linkedlistoutput.txt","a+");
while(temp!=NULL){
    fprintf(fptr,"%d\n",temp->element);
    temp = temp->next;
}
fclose(fptr);
return 0;
}