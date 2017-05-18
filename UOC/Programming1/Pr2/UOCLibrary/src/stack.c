#include "books.h"
#include "stack.h"
#include <string.h>

/******************** PR2 - EX4B ********************/
void bookStack_create(tBookStack *stack) {
	stack->size = 0;
}

/******************** PR2 - EX4C ********************/
tBoolean bookStack_empty(tBookStack stack) {	
	if(stack.size == 0){
		return TRUE;
	}
		return FALSE;
	
}

/******************** PR2 - EX4D ********************/
tError bookStack_push(tBookStack *stack, tBook newElement) {
	tError retVal = OK;
	if(stack->size == MAX_BOOKS){
		retVal = ERR_MEMORY;
	} else {
		stack->bookStack[stack->size++] = newElement;
	}
	
	return retVal;
}

/******************** PR2 - EX4E ********************/
tError bookStack_pop (tBookStack *stack, tBook *element) {
    tError retVal = OK;
		if(stack->size == 0){
		retVal = ERROR;
	} else {
		*element = stack->bookStack[stack->size-1];
		stack->size--;
	}
	return retVal;
}

/******************** PR2 - EX5A ********************/
void bookStack_transfer(tBookStack *stack_dest, tBookStack *stack){
	int i;
	for(i=stack->size-1; i>=0; i--){
		int stackDestSize = stack_dest->size;
		stack_dest->bookStack[stackDestSize] = stack->bookStack[i];
		stack_dest->size++;
		stack->size--;
	}
	
}

/******************** PR2 - EX5B ********************/
tError bookStack_search(tBookStack *stack, char *ISBN, tBook *book){
	tError retVal = OK;
	int idx = -1;
	int i = 0;
	
	//Looking for element
	while(i< stack->size && idx==-1) {
		/* Check if the id is the same */
		if(strcmp(stack->bookStack[i].ISBN,ISBN)==0) {
			/* Get the position of the match */
			idx = i;
		}
		i++;
	}
	
	//Not ffound error
	if(idx == -1){
		retVal = ERR_ENTRY_NOT_FOUND;
		return retVal;
	}
	
	//returning element
	*book = stack->bookStack[idx];
	
	//Eliminating element
	stack->size--;
	for(i=idx; i<stack->size; i++){
		stack->bookStack[i] = stack->bookStack[i+1];
	}
	
	return retVal;
}


