#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "structures.h"
#include <stdio.h>
#include <conio.h>
#include <time.h>

int main(int argc, char **argv)
{	
	tArray array;
	int listOfNumbers[] = {3, 1, 5, 2, 7, 5, 9, 5, 6, 4, 7, 1 ,2, 4, 5, 6 ,7 ,8 ,5 ,4 ,3 ,6 ,3 ,1 ,3};
	memcpy(array.list, listOfNumbers, sizeof(array.list));
	array.size = 25;

	
	insertionSort(array.list, array.size);

	
	selectionSort(&array);
	
	
	quicksort(array.list, 0, array.size);

	
	mergeSort(array.list, array.size);
	
	
	//display(array.list, array.size);
	
	char word[] = "do gi ";
	char word2[] = "godi";
	
	uniqueString(word);
	uniqueString(word2);
	
	permutation(word, word2);
	
	spaces(word);

	return 0;
}
