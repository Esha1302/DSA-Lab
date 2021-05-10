#include "calcTimeAndStackSpace.h"

void Time_taken_Reading(){
	CREDIT_CARD * credit_card_array;
	int size;
	FILE* f_output = fopen("TimeOutputForReading.txt","w+");

	char file_name[10];

	struct timeval t1, t2;
	double elapsedTime;

	for(int i = 1; i < 8; i++){
		int file_number = pow(10,i);
		
		gettimeofday(&t1, NULL);
		if(i<6){
			sprintf(file_name,"%d", file_number);
			credit_card_array = read_cards(credit_card_array, file_name, &size);
		}
		else{
			for(int j = 0; j < file_number / 100000; j++)
				credit_card_array = read_cards(credit_card_array, file_name, &size);
		}

		gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
		fprintf(f_output, "Read %d structs in %lf milliseconds.\n", file_number, elapsedTime);
	}
	fclose(f_output);
}

void timeForSorting(){
    CREDIT_CARD * card_array;
	int size;
	FILE* f_output = fopen("TimeOutputForSorting.txt","w+");

	char file_name[10];

	struct timeval t1, t2;
	double elapsedTime;

	
	for(int i = 1; i < 8; i++){
		int file_number = pow(10,i);
		
		gettimeofday(&t1, NULL);
		if(i < 6){
			sprintf(file_name,"%d", file_number);
			card_array = read_cards(card_array, file_name, &size);
		}
		else{
			for(int j=0;j<file_number/100000;j++)
				card_array = read_cards(card_array, file_name, &size);
		}


		InsertionSort(card_array, size);
		gettimeofday(&t2, NULL);

		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

		fprintf(f_output, "Sorted %d structs in %lf milliseconds.\n", file_number, elapsedTime);
	}
	fclose(f_output);
}

void stackspaceForSorting(){
    CREDIT_CARD * card_array;
	int size;
	FILE* f_output = fopen("SpaceOutputForSorting.txt","w+");
	char filename[10];

	
	for(int i = 1; i < 8; i++){
		int bottomofstack;
		int file_number = pow(10, i);
		
		if(i < 6){
			sprintf(filename,"%d", file_number);
			card_array = read_cards(card_array, filename, &size);
		}
		else{
			for(int j = 0; j < file_number/100000; j++)
				card_array = read_cards(card_array, filename, &size);
		}
		InsertionSort(card_array,size);
		fprintf(f_output, "Number of elements sorted: %d, Top Of Stack: %llu, Bottom Of Stack: %llu, Difference in the two: %llu.\n",file_number, topofstack, &bottomofstack, (unsigned long long)&bottomofstack-(unsigned long long)topofstack);
	}
	fclose(f_output);
}