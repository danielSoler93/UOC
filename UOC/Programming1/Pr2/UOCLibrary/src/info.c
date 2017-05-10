#include <stdio.h>
#include <math.h>
#include <string.h>
#include "info.h"
#include "books.h"
#include "sections.h"

/******************** PR2 - EX3A ********************/
tError si_getSectionInfo(tBookTable tabB, tSectionTable tabS, char sectionId, tSectionInfo *si ){
	tError retVal = OK;

	#ifdef SIMPLE_VERSION
	
	int i;
	int index;
	//Check the excistence of the section
	index = secTable_find(tSectionTable tabSec, char sectionId)
	if(index!=-1){
		section_cpy(tSectionInfo->section, tabS.table[index])
	} else{
		retVal = ERR_INVALID_DATA;
	}
	
	//Find books inside this sectionID	
	if(retVal == OK){
		for(i=0;i<tabB.size;i++){
			if(tabB.table[i].clas.secId == sectionId){
				tSectionInfo->secSubs[tSectionInfo->totSecSubs].id = tabB.table[i].clas.subId;
				tSectionInfo->secSubs.subBooks[tSectionInfo->secSubs.totSubBooks] = i;
				tSectionInfo->secSubs.totSubBooks++;
			}
			if(tSectionInfo->secSubs.totSubBooks == 0){
				retVal = ERR_ENTRY_NOT_FOUND;
			}
		}
	}
}
	#endif
	#ifdef COMPLETE_VERSION	
/******************** PR2 - EX6A ********************/
	#endif 			

	return retVal;
}

/******************** PR2 - EX3B ********************/
tBook si_getBook(tBookTable tabB, tSectionInfo si, unsigned int nSub, unsigned int nBook) {
	tBook book;
	
	#ifdef SIMPLE_VERSION
	#endif
	#ifdef COMPLETE_VERSION
/******************** PR2 - EX6A ********************/
	#endif	

	return book;
}

/******************** PR2 - EX3C ********************/
void si_listSectionInfo(tBookTable tabB, tSectionInfo si){

	#ifdef SIMPLE_VERSION
	#endif
	#ifdef COMPLETE_VERSION	
/******************** PR2 - EX6A ********************/
	#endif 			
	
}