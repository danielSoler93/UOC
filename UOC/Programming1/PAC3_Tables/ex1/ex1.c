#include <stdio.h>
#include "ex1/ex1.h"
void sortDiscountsShop(tDiscount table){
	int i;
	int smallest;
	int n = sizeof(table)/sizeof(table[0]);
	for(i=0; i<n, i++){
		if i==0{
			smallest = table[i];
		}
		if (table[i].dni < smallest.dni){
			smallest = table[i];
		}
		table[i] = smallest;
		printf("%d", smallest);
	}
	
}
