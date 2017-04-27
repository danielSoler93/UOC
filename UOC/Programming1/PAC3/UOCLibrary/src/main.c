#include <stdio.h>
#include "ex1.h"

int main(int argc, char **argv)
{	
	tDiscount discounts[MAXDISCOUNTS];
	tDiscount discount1;
	tDiscount discount2;
	tDiscount discount3;
	tDiscount discount4;
	
	discount1.dni = 1434;
	discount2.dni = 1122;
	discount3.dni = 1221;
	discount4.dni = 1110;
	
	discount1.changed = FALSE;
	discount2.changed = FALSE;
	discount3.changed = FALSE;
	discount4.changed = FALSE;
	
	
	discounts[0] = discount1;
	discounts[1] = discount2;
	discounts[2] = discount3;
	discounts[3] = discount4;
	
	sortDiscountsShop(&discounts);
	discountChanged(&discounts, 1110);
	
	/*
	if(discounts[3].changed==0){
		printf("True\n");
	} else{
		printf("False\n");
	}
	 * /
	
	return 0;
}
