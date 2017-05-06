#include <stdio.h>
#include <string.h>
#include "sort.h"
#include <stdio.h>

void display(int array[], int size){
	/*
	 * 
	 * Print array to screen
	 * 
	*/
	int i;
	for(i=0; i<size; i++){
		printf("%d\n", array[i]);
	}
}

void quicksort(int number[MAXNUMBERS],int first,int last){
	/*
	 * best O(n) avrg O(nlogn) worst O(n2)
	 * 
	 * Not really efficient
	 * needs more memory
	 * it's ok if we dont know whic type of data
	 * and need a good average
	 * 
	 * Sort algorithm order the original array
	 * split in two more and do the same recursevly
	 * 
	 * input)
	 * 	number: randomly ordered array
	 * 	first: first index of the array
	 *  last: second index of the array
	 * 
	 * output)
	 * 	number: array sorted from low numbers to high.
	 */
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;			
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}
void merge(int *dest, int left[], int right[], int lSize, int rSize){
	 /*
	 * 
	 * 
	 * Sort algorith joins the left and right
	 * array to the original one while sorting
	 * 
	 * input)
	 * 	dest: original randomly ordered array
	 * 	left: array make from the left part of the original
	 * 	right: array make from the right part of the original
	 * 	lSize: array left size
	 *  rSize: array right size
	 * 
	 * output)
	 * 	dest: semi ordered original array.
	 */
	int dind = 0;
	int lind = 0;
	int rind = 0;
	
	int leftSize = lSize;
	int rightSize = rSize;
	//Merge array while sorting
	while(lind<leftSize&&rind<rightSize){
		if(left[lind]<=right[rind]){
			dest[dind++] = left[lind++];
		} else{
			dest[dind++] = right[rind++];
		}
	}
	while(lind<leftSize){
		dest[dind++] = left[lind++];
	}
	while(rind<rightSize){
		dest[dind++] = right[rind++];
	}
}
void mergeSort(int *number, int size){
	/*
	 * O(nlogn) "high effixiency"
	 * 
	 * Sort algorithm which splits the original in two
	 * merge while sorting and splits again in two
	 * 
	 * input)
	 * 	array: randomly ordered array
	 * 	size: array length
	 * 
	 * output)
	 * 	array: array sorted from low numbers to high.
	 */
	if(size<2){
		return;
	}
	int i;
	int n = size;
	int mid = n/2;
	//Divide and conquer
	int left[mid];
	int right[n-mid];
	//Copy original data in two sets
	for(i=0; i<mid; i++){
		left[i] = number[i];
	}
	for(i=mid; i<n; i++){
		right[i-(mid)] = number[i];
	}
	//merge&sort
	mergeSort(left, mid);
	mergeSort(right, n-mid);
	
	merge(number, left, right, mid, n-mid);
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


void insertionSort(int *numbers, int n){
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
	 int sortedNumbers[n-1];
	 int position;
	 //Initialize to 0
	 int i;
	 for(i=0; i<n; i++){
		 sortedNumbers[i] = 0;
	 }
	 //Insertion Sort algorithm
	 for(i=0; i<n; i++){
		int valueToInsert = numbers[i];
		position = i;
		//Search for position tot inserrt value
		while(valueToInsert > sortedNumbers[position] && position>=0){
			sortedNumbers[position+1] = sortedNumbers[position];
			position --;
		}
		sortedNumbers[position+1] = valueToInsert;		
	 }
	 memcpy(numbers, sortedNumbers, n*sizeof(int));
}