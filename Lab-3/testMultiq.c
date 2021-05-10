#include <stdio.h>
#include <stdlib.h>
#include "multiq.h"
#include <sys/time.h>

MultiQ loadData(FILE* f){
	MultiQ mq = createMQ(10);
	int t,pr;
	Task task;
	while(!feof(f)){
		fscanf(f,"%d,%d",&t,&pr);
		printf("%d,%d\n",t,pr);
		fgetc(f);
		task.tid = t;
		task.p = pr;
		mq = addMQ(mq, task);
	}

	return mq;
}

MultiQ testDel(MultiQ mq, int nums){
	for(int i = 0;i < nums; i++){
		delNextMQ(mq);
	}
	return mq;
}

int main(int argc, char *argv[]){

	struct timeval t1, t2;
	double elapsedTime;

	FILE* fptr;
	MultiQ  mq;

	gettimeofday(&t1, NULL);
	fptr=fopen(argv[1],"r");
	if(fptr==NULL)
	{
		printf("Could not open the file!");
		exit(0);
	}
	else
	{
		
		mq = loadData(fptr);
	}
	
	fclose(fptr);
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for loading is %f ms.\n", elapsedTime);

	int num;
	printf("Enter the number of values to delete:\n");
	scanf("%d", &num);

	gettimeofday(&t1, NULL);
	mq = testDel(mq, num);

	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Total time for %d deletions is %f ms.\n", num, elapsedTime);
	return 0;

}