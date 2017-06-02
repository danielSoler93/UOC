#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

tBoolean permutation(char * word1, char * word2){
	
	/*
	 * 
	 * Check whether or not the first word is
	 * a permutation of the second one
	 * 
	 * input)
	 *  	word 1: first str
	 * 
	 * 		word 2: second str
	 * 
	 * Output)
	 * 		retVal: True if they are false if not.
	 * 
	 * Concepts to ask for: Spaces and capitals count???
	 * 
	 * */
	
	if(strlen(word1) != strlen(word2)) return FALSE;
	
	sort(word1);
	sort(word2);
	
	if(strcmp(word1, word2) == 0) return TRUE;
	
	else return FALSE;
}

void sort(char * word){
	int size = strlen(word);
	int i;
	int j;
	char smallest;
	
	
	for(i=0;i<size;i++){
		smallest = word[i];
		int index = i;
		
		for(j=i;j<size;j++){
			if(strcmp(&word[j], &smallest)<0){
				smallest = word[j];
				index = j;
			}
		}
		
		if(index != i){
			word[index] = word[i];
			word[i] = smallest;
		}
	}
}

void spaces(char * word){
	
	int size = strlen(word);
	int i;
	char buffer[100];
	int indexBuffer = 0;
	
	for(i=0; i<size; i++){
		if(word[i]==' '){
			buffer[indexBuffer++] = '%';
			buffer[indexBuffer++] = '2';
			buffer[indexBuffer++] = '0';
		}
		else buffer[indexBuffer++] = word[i];
	}
	
	printf("%s", buffer);
	
	
}

tBoolean palindrome(tHashtable hashtable, char * string){
	
	int i;
	tBoolean oddFound = FALSE;
	
	
	initHashTable(&hashtable);
	
	
	for(i=0; i<strlen(string); i++) addHashTable(&hashtable, string[i]);
	
	
	for(i=0; i<strlen(string); i++){
		if(oddFound) {
			printf("\nnot palindrom permutation\n");
			return FALSE;
		}
		else {
			if (hashtable.table[(int)(string[i] - 'a')].value %2 != 0) {
				oddFound = TRUE;
			}
		}
	}
	
	
	printf("\npalindrom permutation\n");
	return TRUE;
	
}

tBoolean oneWay(char * string1, char * string2){
	/*
	 * Return true if bothe strings can be identical with one change
	 * This change can be either a insertion/removal or a replacement.
	 * 
	 * Input)
	 *   string1 largest
	 * 	 string2 smallest
	 * 
	 */
	 
	int sizeString1 = strlen(string1);
	int sizeString2 = strlen(string2);
	tBoolean differenceFound = FALSE;
	
	if(abs(sizeString1-sizeString2)>=2) {
		printf("Not equal with one way");
		return FALSE;
	}
	
	else{
		
		int i;
		int j=0;
		
		for(i=0; i<sizeString1; i++){
				
				if(differenceFound>=2) {
					printf("Not equal with one way");
					return FALSE;
				}
				
				else {
					
					if(string1[i]!=string2[j]){
						differenceFound++;
						if(sizeString1 != sizeString2)   j--;
					}
			}
		j++;
		}
		printf("equal with one change");
		return TRUE;
	}
}

	
	
