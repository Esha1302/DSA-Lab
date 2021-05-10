#include "Merge.h"
#include <stdio.h>


int main(){

    Element arr[10];
	arr[0].cgpa =  9;
	arr[1].cgpa =  7;
	arr[2].cgpa =  8;
	arr[3].cgpa =  2;
	arr[4].cgpa =  1;
	arr[5].cgpa =  4;
	arr[6].cgpa =  3;
	arr[7].cgpa =  3;
	arr[8].cgpa =  2;
	arr[9].cgpa =  3;


    mergeSort_recursive(arr, 0, 9);
    // mergeSort_iterative(arr, 0, 9);

    for(int i=0;i<10;i++){
		printf("%lf ",arr[i].cgpa);
	}
	putchar('\n');
}
