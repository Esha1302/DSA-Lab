#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "que.h"

Queue newQ(){
    Queue new_q;
    new_q.front = NULL;
    new_q.rear = NULL;
    new_q.size = 0;
    return new_q;
}

bool isEmptyQ(Queue q){
    if(q.size == 0){
        return true;
    }
    return false;
}

Queue delQ(Queue q){
    if(q.size == 0){
        printf("\n%s","Queue is empty");
        return q;
    }

    else if(q.size == 1){
        q.size--;
        q.front = NULL;
        q.rear = NULL;
        return q;
    }
    else {
        q.front = q.front->next;
        q.size--;
        return q;
    }
}

Element front(Queue q){
    return *(q.front);
}

Queue addQ(Queue q, Element e){
    Element *temp = (Element *)(malloc(sizeof(Element)));
    temp->ele = e.ele;
    temp->next = e.next;
    if(isEmptyQ(q)){
		q.size++;
		q.front = temp;
        q.rear = temp;
	}
	else{
		q.size++;
		q.rear->next = temp;
		q.rear = temp;
	}
	return q;
}

int lengthQ(Queue q){
    return q.size;
}







