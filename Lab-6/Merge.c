#include "Merge.h"

void merge(Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[]){
    int sz = sz1 + sz2;
    int i = 0, j = 0, k = 0;
    while(i!=sz1 && j!=sz2){
        
        if(Ls1[i].cgpa<Ls2[j].cgpa){
            Ls[k++] = Ls1[i++];
        }
        else {
            Ls[k++] = Ls1[j++];
        }
    }
    if(i!=sz1){
        while(i!=sz1){
            Ls[k++] = Ls1[i++];   
        }
    }
    else if(j!=sz2) {
       while(j!=sz2){
            Ls[k++] = Ls2[j++];   
        } 
    }

    for(int u = 0;u<sz;u++){
        printf("%d\n",Ls[u]);
    }
 
}





