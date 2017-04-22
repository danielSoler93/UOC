#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"


/******************** PR1 - EX 2C ********************/
void getBookStr(tBook book, int maxSize, char *str) {
	int length;
	
	length = snprintf(str,maxSize-1,"%lld %d %d %d %d %s %s", book.isbn, book.publicationYear, book.available, book.identificator.mainSection, book.identificator.subSection, book.authorCode, book.bookTitle);			
	str[length]='\0';
}


/******************** PR1 - EX 2D ********************/
tError getBookObject(const char *str, tBook *book) {

	tError retVal = OK;
	
	sscanf(str, "%lld %d %d %d %d %s %s", &book->isbn, &book->publicationYear, &book->available,
										  &book->identificator.mainSection, &book->identificator.subSection,
										  book->authorCode, book->bookTitle);
	
	return retVal;
	
}


void bookTable_init(tBookTable *bookTable) {
	
	bookTable->size=0;

}

/******************** PR1 - EX 3A ********************/
int book_cmp(tBook b1, tBook b2) {
	
	int retVal=0;
	
	if (b1.identificator.mainSection > b2.identificator.mainSection) {
        retVal = 1;
		return retVal;
		
	} else if (b1.identificator.subSection < b2.identificator.subSection) {
        retVal = -1;
		return retVal;
    }
		else if (b1.identificator.subSection == b2.identificator.subSection){
			
			if (b1.identificator.subSection > b2.identificator.subSection) {
			retVal = 1;
			return retVal;
			
		} 	else if (b1.identificator.subSection < b2.identificator.subSection) {
			retVal = -1;
			return retVal;
		} 
			else if (b1.identificator.subSection == b2.identificator.subSection){
				
				int ret = strcmp(b1.authorCode, b2.authorCode);
				
				if (ret>0) {
				retVal = 1;
				return retVal;
				
			} 	else if (ret<0) {
				retVal = -1;
				return retVal;
				
			}   else if (ret == 0){
					
					int ret = strcmp(b1.bookTitle, b2.bookTitle);
					
					if (ret>0) {
					retVal = 1;
					return retVal;
					
				} 	else if (ret<0) {
					retVal = -1;
					return retVal;
					
				}   else if (ret==0) {
						
						if (b1.isbn > b2.isbn) {
							retVal = 1;
							return retVal;
							
						} else if (b1.isbn < b2.isbn) {
							retVal = -1;
							return retVal;
							
						} else {
							retVal = 0;
							return retVal;
						}
					}
				}
			}
		}
}


/******************** PR1 - EX 3B ********************/
void book_cpy(tBook *dst, tBook src) {

}

/******************** PR1 - EX 4A ********************/
tError bookTable_add(tBookTable *tabBook, tBook book) {

	tError retVal = OK;
	
	return retVal;
}

/******************** PR1 - EX 4B ********************/
int bookTable_find(tBookTable tabBook, char *ISBN) {

	int idx = -1;

	return idx;
}

/******************** PR1 - EX 4C ********************/
void bookTable_del(tBookTable *tabBook, tBook book) {

}

/******************** PR1 - EX 5A ********************/
tError bookTable_save(tBookTable tabBook, const char* filename) {

	tError retVal = OK;
	
	return retVal;
}

/******************** PR1 - EX 5B ********************/
tError bookTable_load(tBookTable *tabBook, const char* filename) {
	
	tError retVal = OK;
	
	return retVal;
}

/******************** PR1 - EX 6 ********************/
void bookTable_filterBySection(tBookTable tabBook, char sectionId, tBookTable *result) {

}

/******************** PR1 - EX 7A ********************/
unsigned int bookTable_getOnLoanNumber(tBookTable tabBook){

	int numBooks = 0;

	return numBooks;
}

/******************** PR1 - EX 7B ********************/
unsigned int bookTable_getAuthorNumber(tBookTable tabBook, char *author){

	int numBooks = 0;

	return numBooks;
}

