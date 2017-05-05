#include <stdio.h>
#include <string.h>
#include "algorithm.h"
#include <stdio.h>

int main(int argc, char **argv)
{	
	tArray array;
	int listOfNumbers[] = {3, 1, 5, 2, 7, 5, 9, 5, 6, 4, 7};
	memcpy(array.list, listOfNumbers, sizeof(array.list));
	array.size = 11;
	
	//insertionSort(&array);
	//selectionSort(&array);
	quicksort(array.list, 0, array.size);
	display(array);
	
	return 0;
}
