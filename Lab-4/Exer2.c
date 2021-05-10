#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Exer2.h"

long long space = 0;
void * myalloc(int num, int sizeofelement){
    space += (long long)(num*sizeofelement);
    void * address = malloc(sizeofelement*num);
    if(address == NULL){
        return NULL;
    }
    return address;
}

void myfree(int * memory, int length){
    free(memory);
    space -= (long long)(length);
}

// int main(){
//     srand(time(0));

//     int random_M;
// 	int * data;
//     while(1){

//         random_M = (rand() % (25000 - 10000 + 1)) + 10000;
//         data = (int * )myalloc(random_M, sizeof(int));

//         if(data==NULL)
//         {
//             printf("Unable to allocate any memory.\n");
//             break;
//         }
//         else{
//             printf("First: %p. Last: %p.\n",&data[0], &data[random_M-1]);
//             printf("\t%d\n", random_M);
//             printf("\t\tHeap: %lld\n", space);
//             myfree(data, random_M);
//         }

//     }
//     printf("Out of the loop.\n");
// }





