#include <stdio.h>
#include <stdlib.h>
#include "Exer2.h"
#include "cycle.h"
#include <sys/time.h>
#include <time.h>

struct node * createList(int N){
    extern long long space;
    struct node * head;
    if(N < 0){
        return NULL;
    }
    else{
        head = (struct node *)(myalloc(1, sizeof(struct node)));
        head->element = rand();
        struct node * temp = head;
        while(N--)
        {
            temp->next = (struct node *)(myalloc(1,sizeof(struct node)));
            if(temp->next==NULL)
            {
                printf("Unable to allocate.\n");
                break;
            }
            temp = temp->next;
            temp->element = rand();
            temp->next = NULL;
        }
    }

    // FILE * fptr;
    // fptr=fopen("exer3_outputfile.txt","w+");
    // if(fptr == NULL)
    // {
    //     printf("Unable to open the file.\n");
    // }
    // else
    // {
    //     printf("File exer3_outputfile.txt opened and total space = %lld allocated stored in it.\n", space);
        
    //     // fclose(fptr);
    // }
    printf("Total space = %lld allocated stored in it.\n", space);

    return head;
}

struct node * createCycle(struct node * head){
    time_t t;
    srand((unsigned)time(&t));
    int coin_toss=(rand()%2);
    printf("\ncoin toss = %d\n", coin_toss);
    // 1 = cycle, 0 = linear
    if(coin_toss==0)
    {
    	printf("Linear list.\n");
        return head;
    }

    else{
        int r = (rand() % 101);
        printf("r = %d\n", r);
        int c = 0;
        struct node * temp = head;
        if(head == NULL)
        {
        	printf("Could not create a cycle as head is null.\n");
        	return NULL;
        }
        else
        {
        	while((temp != NULL) && (c != r))
        	{
        		temp = temp->next;
                c++;
        	}
        	if(temp == NULL)
        	{
        		printf("Could not create a cycle as the r index is not present.\n");
        		return head;
        	}
        	else
        	{
        		struct node* n = head;
        		while(n->next != NULL)
        		{
        			n = n->next;
        		}
        		n->next = temp; //n will be the last node
        		printf("Circular linked list created. Tail node with %d now points to node with %d.\n",n->element, temp->element);
        		return head;
        	}
        }
    } 
}

int main(){
    extern long long space;
    struct timeval t1, t2;
	double elapsedTime;

    struct node * head;
    int N[] = {10,50,100};

    FILE * fp = fopen("observations.csv", "a+");
    fprintf(fp, "%s,%s,%s,%s\n", "Coin toss result","N","Time Taken in ms", "Heap Space"); 
    for(int i=0;i<3;i++){

        gettimeofday(&t1, NULL);

        head = createList(N[i]);
        struct node * temp = head;
        printf("Elements in the list = \n");
        while(temp != NULL)
        {
            printf("%d\t",temp->element);
            temp = (temp->next);
        }
        head = createCycle(head);
        int f = testCyclic(head);
        printf("f = %d\n", f);
        gettimeofday(&t2, NULL);

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken = %d ms.\n", elapsedTime);
        if(f==0)
            fprintf(fp, "%s,%d,%f,%lld\n", "Linear LL",N[i],elapsedTime, space); 
        else if(f==1)
            fprintf(fp, "%s,%d,%f,%lld\n", "Cycle LL",N[i],elapsedTime, space); 
    }

    fclose(fp); 

    return 0;
}


