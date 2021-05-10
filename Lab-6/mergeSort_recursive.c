#include "Merge.h"

void mergeSort_recursive(Element arr[], int l, int r){ 
    if(l < r){
        int mid = (l+r)/2;
        mergeSort_recursive(arr, l, mid);
        mergeSort_recursive(arr, mid+1, r);
        Element temp[r-l+1];
        merge(arr + l, mid - l + 1, arr + mid + 1, r - mid, temp);

        for(int i = 0; i < r - l + 1; i++){
            arr[l + i] = temp[i]; 
        }
    }
}