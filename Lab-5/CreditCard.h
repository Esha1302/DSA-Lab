#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>


typedef struct {
	unsigned long long card_number;
	char bank_code[5];
	char expiry_date[7];
	char first_name[20];
	char last_name[20];
} CREDIT_CARD;


