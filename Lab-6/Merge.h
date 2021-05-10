#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[10];
    float cgpa;
};
typedef struct Student Element;

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]);

void mergeSort_recursive(Element arr[], int l, int r);

void mergeSort_iterative(Element arr[], int l, int r);