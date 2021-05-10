#include "insertionsort.h"
#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fptr;
    fptr = fopen("10", "r");
    Employee * arr = (Employee *)malloc(sizeof(Employee) * 10);
    int i;
    if(fptr==NULL)
	{
		printf("Could not open the file!");
		exit(0);
	}

    else{
        // printf("reached else\n");
        i = 0;
        while(!feof(fptr)){
            // printf("%d\n", i);
            char n[11];
            int ID;
            fscanf(fptr,"%[^ ] %d\n",arr[i].name,&arr[i].empID);
            // printf("%s,%d\n",n, ID);
            // printf("%d\n", ID);
            // fgetc(fptr);
            
            // printf("reached outside for\n");
            i++;
            // if(i == 9){
			//     arr = (Employee *)realloc(arr, sizeof(Employee)*20);
		    // }
            
        }
        // printf("reached outside while\n");
        
    }
    // printf("reached out\n");
    printf("before sorting =\n ");
    for( int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}

    quickSort(arr, 10, 0);
    // insertionSort(arr, 10);
    printf("\nafter sorting = \n");

    for(int i=0;i<10;i++){
		printf("%d ",arr[i].empID);
	}


}