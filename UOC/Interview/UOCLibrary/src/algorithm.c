#include <stdio.h>
#include <string.h>
#include "algorithm.h"
#include <stdio.h>

void display(tArray *pArray){
	int i;
	for(i=0; i<pArray->size; i++){
		printf("%d\n", pArray->list[i]);
	}
}

void selectionSort(tArray *pArray){
	/*
	 * O(n^2) Sort algorithm which swap the first 
	 * number with the biggest one after him.
	 * And the same with the 2nd 3rd...
	 * 
	 * input)
	 * 	array: randomly ordered array
	 * 
	 * output)
	 * 	array: array sorted from high numbers to low.
	 */
	int positionToSwap;
	int biggestPosition;
	int i;
	int j;
	
	for(i=0; i<pArray->size; i++){
		//initialize to startingPosition
		positionToSwap = pArray->list[i];
		biggestPosition = i;
		//Look for the biggest
		for(j=i; j<pArray->size; j++){
			if(pArray->list[j] > pArray->list[biggestPosition]){
				biggestPosition = j;
			}
		}
		//Swap numbers
		if(i!=biggestPosition){
			pArray->list[i] = pArray->list[biggestPosition];
			pArray->list[biggestPosition] = positionToSwap;
		}
	}
}

void insertionSort(tArray *pArray){
	/*
	 * O(n^2)[worst case] O(n) [if it's already sorted]
	 * 
	 * Sort algorithm which creates a ordered sublist 
	 * where we will insert the original list values.
	 * 
	 * input)
	 * 	array: randomly ordered array
	 * 
	 * output)
	 * 	array: array sorted from high numbers to low.
	 */
	int i;
	int sortedArray[MAXNUMBERS];
	
	for(i=0; i<pArray->size; i++){
		
		int valueToInsert = pArray->list[i];
		
		int holePosition = i;
		
		while(holePosition>0 && sortedArray[holePosition-1] < valueToInsert){
			sortedArray[holePosition] = sortedArray[holePosition-1];
			holePosition--;
		}
		
		if(holePosition!=i){
			sortedArray[holePosition] = valueToInsert;
		}
		
	}
	memcpy(pArray->list, sortedArray, pArray->size * sizeof(int));
}