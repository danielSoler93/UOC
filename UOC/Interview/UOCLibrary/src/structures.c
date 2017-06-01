#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "structures.h"

tBoolean uniqueString(char * word){
	/*
	 * 
	 * Search for repited letters in word
	 * 
	 * Input)
	 * 	word: string to look into
	 * 
	 *Concepts to ask for to interviewer: ASCI extended ASCI or Unicode
	 */
	int i;
	int index;
	int size = strlen(word);
	tBoolean alphabet[ALPHABETLENGHT] = {FALSE};
	
	if(size > ALPHABETLENGHT) return FALSE;
	
	for(i=0; i<size; i++){
		index = word[i] - 'a';
		
		if(alphabet[index]) return FALSE;
		
		else alphabet[index]= TRUE;
		
	}
	return TRUE;
}