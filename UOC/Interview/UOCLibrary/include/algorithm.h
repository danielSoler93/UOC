/* This code ensures that this file is included only once */

/* If the constant DATA_H is not defined (ifndef), the code is added, otherwise, this code is excluded. When the code is added, the constant is defined, therefore next time this file will be included it will be defined and no inclusion will be done. */
#define MAXNUMBERS 100
/* Definition of a boolean type */
typedef enum {FALSE, TRUE} tBoolean;

typedef struct{
	int list[MAXNUMBERS];
	int size;
}tArray;

/*Func headers*/
void display(tArray pArray);

void selectionSort(tArray *pArray);

void insertionSort(tArray *pArray);

void quicksort(int number[MAXNUMBERS], int first, int last);

void merge(int *dest, int left[], int right[], int lSize, int rSize);

void mergeSort(int *number, int size);