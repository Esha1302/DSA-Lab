#include "readRecords.h"

CREDIT_CARD * read_cards(CREDIT_CARD * credit_card_array, char * file_name, int * final_size){
    int initial_size = 10;
	credit_card_array = (CREDIT_CARD *)malloc(sizeof(CREDIT_CARD) * initial_size);
	FILE * f = fopen(file_name, "r");

    if(f == NULL){
		printf("Error! Could not open file.");
		exit(0);
	}
    CREDIT_CARD new_credit_card;
    int index = 0;
    while(!feof){
        fscanf(f, "\"%llu,[^,],[^,],[^,],[^\"]\"\n",&new_credit_card.card_number, &new_credit_card.bank_code,&new_credit_card.expiry_date,&new_credit_card.first_name,&new_credit_card.last_name);
        credit_card_array[index] = new_credit_card;
        index++;

        if(index == initial_size){
            initial_size *= 2;
			credit_card_array = (CREDIT_CARD *)realloc(credit_card_array, sizeof(CREDIT_CARD)*initial_size);
        } 
    }
    fclose(f);
	* final_size = index;
	return credit_card_array;
}