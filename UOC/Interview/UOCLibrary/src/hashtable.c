#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "structures.h"

void initHashTable(tHashtable * hashtable){
	int i;
	for(i=0; i<ALPHABETLENGHT; i++){
		hashtable->table[i].value = 0;
	}
}

void addHashTable(tHashtable * hashtable, char value){
	
	tEntries entry;
	
	entry.key = (int)(value-'a');
	
	if(entry.key>128) return;
	
	else if(hashtable->table[entry.key].value==0) 	hashtable->table[entry.key].value += 1;
	
	else	hashtable->table[entry.key].value += 1;

}
