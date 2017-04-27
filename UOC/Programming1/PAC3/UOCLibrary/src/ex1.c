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
