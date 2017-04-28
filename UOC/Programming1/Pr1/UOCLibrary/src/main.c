#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "test.h"
#include <stdio.h>
#include "ex.h"

int main(int argc, char **argv)
{	
	tDiscount discounts[];
	tDiscount discount1;
	tDiscount discount2;
	tDiscount discount3;
	tDiscount discount4;
	
	printf("%d", 1);
	discount1.dni = 1234;
	discount2.dni = 1222;
	discount3.dni = 1121;
	discount4.dni = 1110;
	
	discounts[0] = discount1;
	discounts[1] = discount2;
	discounts[2] = discount3;
	discounts[3] = discount4;
	
	sortDiscountsShop(discounts);
	
	return 0;
}
