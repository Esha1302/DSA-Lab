#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "multiq.h"

MultiQ createMQ(int num){
    MultiQ mq;
    mq.size_of_mq = num;
    mq.array_of_queues = (Queue *)malloc(sizeof(Queue)*num);
    return mq;    
}

MultiQ addMQ(MultiQ mq, Task t){
    Element n;
	n.ele = t.tid;
	n.next = NULL;
    mq.array_of_queues[t.p-1] = addQ(mq.array_of_queues[t.p-1], n);
    return mq;
}

Task nextMQ(MultiQ mq){
    if(isEmptyMQ(mq)){
		Task emptyTaskStruct;
		emptyTaskStruct.tid = -1;
		emptyTaskStruct.p = -1;
		return emptyTaskStruct;
	}
	else{
		int i = mq.size_of_mq-1;
		while(isEmptyQ(mq.array_of_queues[i])) 
            i--;
		Task newTask;
		newTask.tid =  front(mq.array_of_queues[i]).ele;
		newTask.p = i+1;
		return newTask;
	}
}

MultiQ delNextMQ(MultiQ mq){
    if(isEmptyMQ(mq)){
		return mq;
	}
    else{
		int c = MAX_PRIORITY-1;
		while(isEmptyQ(mq.array_of_queues[c])) 
            c--;
		mq.array_of_queues[c] = delQ(mq.array_of_queues[c]);
		return mq;
	}
}

int sizeMQ(MultiQ mq){
    int c = 0;
	for(int i = mq.size_of_mq-1;i >= 0; i--){
		c += lengthQ(mq.array_of_queues[i]);
	}
	return c;
}

bool isEmptyMQ(MultiQ mq){
    for(int i = mq.size_of_mq-1;i >= 0; i--){
        if(isEmptyQ(mq.array_of_queues[i]) == false)
            return false;
	}
	return true;
}

int sizeMQbyPriority(MultiQ mq, Priority p){
    return lengthQ(mq.array_of_queues[p-1]);
}

Queue getQueueFromMQ(MultiQ mq, Priority p){
    return mq.array_of_queues[p-1];
}


