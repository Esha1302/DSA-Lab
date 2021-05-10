#include "Merge.h"

int min(int x, int y){
    return (x<y)?x:y;
}

void mergeSort_iterative(Element arr[], int l, int r){ 
    int mid,right;
    for(int curr_size = 1;curr_size < r - l + 1; curr_size *= 2){
		for(int start = 0; start < r - l + 1; start += 2 * curr_size){

			mid = min(start + curr_size - 1, r-l);
			right = min(start + 2 * curr_size - 1, r - l);

			Element temp[right - start + 1];
			
            merge(arr + start, mid - start + 1, arr + mid + 1, right - mid, temp);
			
            for(int i = 0; i < right - start + 1; i++){
				arr[start + i]= temp[i];
			}
		}
	}
}

