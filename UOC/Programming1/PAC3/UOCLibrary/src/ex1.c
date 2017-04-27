#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex1.h"

void sortDiscountsShop(tDiscount *table){
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
	int n;
	
	n= sizeof(table);
	for(i=0; i<n; i++){
			//initialize index and smallest value
			index = i;
			smallest = table[i];
		for(j=i; j<n; j++){
			if (table[j].dni < smallest.dni){
				smallest = table[j];
				index =  j;
			}
		}
		//Right to table only in case there's a switch of postions
		if(i!=index){
			table[index] = table[i];
			table[i] = smallest;
		}
	//In cas you wanna printout the result to terminal
	//printf("%d\n", smallest.dni);
	}
}

void discountChanged(tDiscount *table, int id){
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
	 int n;
	 bool found = FALSE;
	 
	 n = sizeof(table);
	 for(i=0; i<n; i++){
		 if(table[i].dni == id && table[i].changed == FALSE){
			 table[i].changed = TRUE;
			 found = TRUE;
			 printf("Cupon with id %d changed\n", id);
		 }
		 else if(table[i].dni == id && table[i].changed == TRUE){
			 found = TRUE;
			printf("Cupon with id %d already changed\n", id);
		 }
	 }
	 if(!found){
		 printf("No cupon with that id %d. Check again \n", id);
	 }
	
	
}

