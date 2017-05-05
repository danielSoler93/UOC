#include <stdio.h>
#include <string.h>
#include "algorithm.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{	
	tArray array;
	int listOfNumbers[] = {3, 1, 5, 2, 7, 5, 9, 5, 6, 4, 7};
	memcpy(array.list, listOfNumbers, sizeof(array.list));
	array.size = 11;
	
	clock_t begin = clock();
	insertionSort(&array);
	clock_t insertion = clock();
	
	//selectionSort(&array);

	//quicksort(array.list, 0, array.size);
	
	//mergeSort(array.list, array.size);
	
	

	
	printf("insertionSort: %f\n", (double)(insertion-begin)/ CLOCKS_PER_SEC);
	//printf("selectionSort: %f\n", (double)(selection-insertion)/ CLOCKS_PER_SEC);
	//printf("quickSort: %f\n", (double)(quick-selection)/ CLOCKS_PER_SEC);
	//printf("mergeSort: %f\n", (double)(merge-quick)/ CLOCKS_PER_SEC);
	display(array);
	
	return 0;
}
