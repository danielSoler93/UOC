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
		tBoolean found = FALSE;
		si->totSecBooks = 0;
		si->totSecSubs = 0;
		for(i=0;i<tabB.size;i++){
			
			//if section we are looking for
			if(tabB.table[i].clas.secId == sectionId){
				//subsection name
				char subsection = tabB.table[i].clas.subId;
				//looking if we already stored that subsection
				int j;
				for(j=0;j<si->totSecSubs;i++){
					if(strcmp(&si->secSubs[j].id, &tabB.table[i].clas.subId)==0){
						found = TRUE;
					}
				}
				if(found == FALSE){
					//If we didn't store the subsection and all its books
					si->secSubs[si->totSecSubs].id = tabB.table[i].clas.subId;
					si->secSubs[si->totSecSubs].totSubBooks = 0;
					int k;
					for(k=0;k<tabB.size;k++){
						if(strcmp(&tabB.table[k].clas.subId, &subsection)==0){
							int subBooksPosition = si->secSubs[si->totSecSubs].totSubBooks;
							si->secSubs[si->totSecSubs].subBooks[subBooksPosition] = i;
							si->secSubs[si->totSecSubs].totSubBooks++;
							si->totSecBooks++;
						}
				} 
			}
		}
	}
	si->totSecSubs++;
}
	if(si->totSecBooks == 0){
		retVal = ERR_ENTRY_NOT_FOUND;
		return retVal;
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
	int position = si.secSubs[nSub].subBooks[nBook];
	book = tabB.table[position];
	
	
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