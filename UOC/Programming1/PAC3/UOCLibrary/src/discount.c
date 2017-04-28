#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "discount.h"


void initDiscounts(tDiscountsShop *tabDisc)
{
	/*
     *
     * Initialize Discounts table with 5
     * random discounts and ids.
	 * 
     *Input:
     * 		table: Storage of discounts
     * Output:
     * 		table: Discounts storage in increasing id number
     *
     */
   	tDiscount discount1;
    tDiscount discount2;
    tDiscount discount3;
    tDiscount discount4;
    tDiscount discount5;

    discount1.dni = 1434;
    discount2.dni = 1122;
    discount3.dni = 1221;
    discount4.dni = 1110;
    discount5.dni = 1234;

    discount1.changed = FALSE;
    discount2.changed = FALSE;
    discount3.changed = FALSE;
    discount4.changed = FALSE;
    discount5.changed = TRUE;
	
	
	tabDisc->discounts[0] = discount1;
	tabDisc->discounts[1] = discount2;
	tabDisc->discounts[2] = discount3;
	tabDisc->discounts[3] = discount4;
	tabDisc->discounts[4] = discount5;
	
	tabDisc->numDiscounts = 5; 
}

void sortDiscountsShop(tDiscountsShop *tabDisc)
{
    /*
     *
     * Sort Discounts by id from
     * higher to lower. O[nlog(n)]
     *
     *Input:
     * 		table: Storage of discounts
     * Output:
     * 		table: Discounts storage in increasing id number
     *
     */
    int i;
    int j;
    int index;
    tDiscount smallest;
    for(i = 0; i < tabDisc->numDiscounts; i++) {
	// initialize index and smallest value
	index = i;
	smallest = tabDisc->discounts[i];
	for(j = i; j < tabDisc->numDiscounts; j++) {
	    if(tabDisc->discounts[j].dni < smallest.dni) {
		smallest = tabDisc->discounts[j];
		index = j;
	    }
	}
	// Right to table only in case there's a switch of postions
	if(i != index) {
	    tabDisc->discounts[index] = tabDisc->discounts[i];
	    tabDisc->discounts[i] = smallest;
	}
	// In cas you wanna printout the result to terminal
	//printf("%d\n", smallest.dni);
    }
	printf("Discounts sorted by id\n");
}

void discountChanged(tDiscountsShop *tabDisc, int id, bool *found, bool *changed)
{
	/*
	*
	* Search for discount and change it.
	* Switch the change bool from false to true.
	*
	*Input:
	* 		table: Storage of discounts
	* 		id: Discount id
	* Output:
	* 		table: Discounts with the discount
	* 			   with the selected id changed
	*
	*/

    int i;
    (*found) = FALSE;
	(*changed) = FALSE;
    for(i = 0; i < tabDisc->numDiscounts; i++) {
	//Change discount from false true
	if(tabDisc->discounts[i].dni == id && tabDisc->discounts[i].changed == FALSE) {
	    tabDisc->discounts[i].changed = TRUE;
	    (*found) = TRUE;
		(*changed) = TRUE;
	    printf("Cupon with id %d changed\n", id);
	//already changed descount
	} else if(tabDisc->discounts[i].dni == id && tabDisc->discounts[i].changed == TRUE) {
	    (*found) = TRUE;
	    printf("Cupon with id %d already changed\n", id);
	}
    }
	//unknown id
    if(!(*found)) {
	printf("No cupon with that id %d. Check again \n", id);
    }
}

