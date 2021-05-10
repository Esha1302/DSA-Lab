#include "quicksort.h"
#include "insertionsort.h"
#include <sys/time.h>
#include <math.h>


void testRun(Employee arr[], int n, double res[2])
{
	Employee arr1[n], arr2[n];

	for(int i = 0; i < n; i++)
	{
		arr1[i] = arr[i];
		arr2[i] = arr[i];
	}

	struct timeval t1,t2;
	double elapsedTime_is;

	gettimeofday(&t1, NULL);
	insertionSort(arr1, n);
	gettimeofday(&t2, NULL);

	elapsedTime_is = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime_is += (t2.tv_usec - t1.tv_usec)/1000.0 ;		      

	struct timeval t3,t4;
	double elapsedTime_qs;

	gettimeofday(&t3,NULL);
	quickSort(arr2, 0, n);
	gettimeofday(&t4,NULL);
	elapsedTime_qs = (t4.tv_sec - t3.tv_sec) * 1000.0;
	elapsedTime_qs += (t4.tv_usec - t3.tv_usec)/1000.0 ;

	res[0] = elapsedTime_is;
	res[1] = elapsedTime_qs;
}

// 
int estimateCutoff(Employee arr[], int n)
{
	double res1[2];
	double res2[2];
	testRun(arr, 2, res1);
	testRun(arr, n, res2);

	double res[2];
	int min = 2, max = n, mid;

	do{
		mid = (min + max) / 2;
		testRun(arr, mid, res);
		if(res[1] < res[0])
			max = mid;
		else if(abs(res[1] - res[1]) < 0.0001)
			break;
		else
			min = mid;
	}while(1);

	return mid;
}

int main(int argc, char* argv[]){
	struct timeval t1, t2, t3, t4;
	double elapsedTime;	

	gettimeofday(&t1, NULL);
	// gettimeofday(&t3, NULL);
	
    FILE * fptr;
    fptr = fopen(argv[1], "r");
	int num = atoi(argv[1]);
    Employee * arr = (Employee *)malloc(sizeof(Employee) * num);
    int i=0;
    if(fptr==NULL)
	{
		printf("Could not open the file!");
		exit(0);
	}

    else{
        // printf("reached else\n");
        
        while(!feof(fptr)){
            // printf("%d\n", i);
            char n[11];
            int ID;
            fscanf(fptr,"%[^ ] %d\n",arr[i].name,&arr[i].empID);
            // printf("%s,%d\n",n, ID);
            // printf("%d\n", ID);
            fgetc(fptr);
            
            // printf("reached outside for\n");
            i++;
			// printf("%d ", i);
            
        }
		// for(int j = 0;j<i;j++){
		// printf("%d\n", arr[j].empID);
		// }
        // printf("reached outside while\n");
        
    }	
	
	int cut_off_value = estimateCutoff(arr, i);
	// printf("%d\n", cut_off_value);

	fclose(fptr);

	FILE* outptr = fopen(argv[2],"a+");
	// printf("reached ere\n");
	quickSort(arr, i, cut_off_value);
	
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	// for(int j = 0;j<i;j++){
	// 	printf("%d\n", arr[j].empID);
	// }

	fprintf(outptr, "Time Taken to sort %d elements with quickSort, cutoff %d: %lf milliseconds.\n",i, cut_off_value, elapsedTime);
	printf("Time Taken to sort %d elements with quickSort, cutoff %d: %lf milliseconds.\n",i, cut_off_value, elapsedTime);
	// printf("%d", i);
	for(int j = 0;j<i;j++){
		fprintf(outptr, "%s %d\n",arr[j].name, arr[j].empID);
	}

}
