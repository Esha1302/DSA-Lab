#include "insertionsort.h"

void insert(Employee arr[], int n, Employee e){
	Employee current = e;
	Employee temp;
	for(int i = 0;i < n; i++){
		if(current.empID < arr[i].empID || i == n - 1){
			temp = current;
			current = arr[i];
			arr[i] = temp;
		}
	}
}

void insertionSort(Employee arr[], int n){
	for(int i = 0;i < n; i++){
		insert(arr, i + 1, arr[i]);
	}
}