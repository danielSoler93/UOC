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
	index = secTable_find(tabS, sectionId);
	if(index!=-1){
		section_cpy(&(si->section), tabS.table[index]);
	} else{
		retVal = ERR_INVALID_DATA;
		return retVal;
	}
	
	
	//Find books inside this sectionID	
	if(retVal == OK){
		for(i=0;i<tabB.size;i++){
			if(tabB.table[i].clas.secId == sectionId){
				si->secSubs[si->totSecSubs].id = tabB.table[i].clas.subId;
				//int subBooksPosition = si->secSubs[si->totSecSubs].totSubBooks;
				//si->secSubs[si->totSecSubs].subBooks[subBooksPosition] = i;
				si->secSubs[si->totSecSubs].totSubBooks++;
				si->totSecBooks++;
				si->totSecSubs++;
			}
		}
	}
	if(si->totSecBooks == 0){
		retVal = ERR_ENTRY_NOT_FOUND;
		return retVal;
	}
	
	#endif
	#ifdef COMPLETE_VERSION	
/******************** PR2 - EX6A ********************/
	#endif 			
	
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