#include "InsertionSort.h"

void insertInOrder(CREDIT_CARD * credit_card_array, int n, CREDIT_CARD card){
    CREDIT_CARD temp;

    for(int i = 0; i < n; i++){
		if(card.card_number < credit_card_array[i].card_number || i == n-1){
			temp = card;
			card = credit_card_array[i];
			credit_card_array[i] = temp;
		}
	}
}

void InsertionSort(CREDIT_CARD * credit_card_array, int n){
    if(n == 0){
		topofstack = &n;
		return;
	}
	InsertionSort(credit_card_array, n-1);
	insertInOrder(credit_card_array, n, credit_card_array[n-1]);
}