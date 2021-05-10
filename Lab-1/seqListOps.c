/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
 
}

void printJob(Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int initialize_elements(JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{   int k;
    for(k = sl.head; st[k].next!=-1; k=st[k].next){
        // printf("k = %d\n", k);
        if (compare(st[st[k].next].ele , j) == GREATER)
            break;
    }
    int t = nextfreeloc++;
    st[t].next = st[k].next;
    st[t].ele = j;
    st[k].next = t;
    sl.size+=1;
    
    return sl;
}

void insertelements(JobList list , int size, SeqList s[3])
{
    for (int p = 0;p < 3; p++){
        for(int i = 0;i < size;i++){
            // printf("value of i = %d\n",i);
            // printf("itertion = %d\n", i);
            if(list[i].pri==p)
                s[p] = insert(list[i], s[p]);
                // printf("value of pri = %d\n",list[i].pri);
        }
    }
}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{
    int c = 0,j;
    printf ("\n");
    for (int i=2 ; i>=0 ; i--){
        for (j=st[s[i].head].next ; st[j].next != -1; j = st[j].next){
            ele[c] = st[j].ele;
            c++;
        }  
    ele[c] = st[j].ele; 
    c++;
    }
}

void printlist(SeqList sl)
{
   
    for (int t = st[sl.head].next ; st[t].next != -1 ; t = st[t].next)
    {
    printJob(st[t].ele);
    }
}

void printJobList(JobList list, int size)
{
    
    for (int k = 0;k < size; k++){
    printJob(list[k]);
    }

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
//  printf("%s\n","inside sortjoblist done");
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements(list, size, seq);
 printlist(seq[0]);
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele(seq , list);
}


