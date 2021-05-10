#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
    int l;
    int r;
    struct node * next;
} ;

typedef struct {
    int count;
    struct node * first;
} list;

list * newStack();
void push(list * stack, int a, int b);
struct node * pop(list * stack);

