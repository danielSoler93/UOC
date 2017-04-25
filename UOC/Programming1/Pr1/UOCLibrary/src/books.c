#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"


/******************** PR1 - EX 2C ********************/
void getBookStr(tBook book, int maxSize, char *str) {
	int length;
	
	length = snprintf(str,maxSize-1,"%s %d %d %c %c %s %s", book.isbn, book.publicationYear, book.available, book.identificator.mainSection, book.identificator.subSection, book.authorCode, book.bookTitle);			
	str[length]='\0';
}


/******************** PR1 - EX 2D ********************/
tError getBookObject(const char *str, tBook *book) {

	tError retVal = OK;
	
	sscanf(str, "%s %d %d %c %c %s %s", &book->isbn, &book->publicationYear, &book->available,
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
					
						int ret = strcmp(b1.isbn, b2.isbn);
						
						if (ret > 0) {
							retVal = 1;
							return retVal;
							
						} else if (ret < 0) {
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
	/*
	int destination[] = {dst->isbn, dst->available, dst->identificator.mainSection,
	dst->identificator.subSection, dst->authorCode, dst->bookTitle};
	int source[] = {src.isbn, src.available, src.identificator.mainSection,
	src.identificator.subSection, src.authorCode, src.bookTitle};
	int i;
	int Size = sizeof(source)/sizeof(source[0]);
	for (i=0; i<Size; i++){
	strcpy(destination[i], source[i]);
	} 
	*/
	strcpy(dst->isbn, src.isbn);
	dst->available = src.available;
	dst->identificator.mainSection = src.identificator.mainSection;
	dst->identificator.subSection = src.identificator.subSection;
	strcpy(dst->authorCode, src.authorCode); 
	strcpy(dst->bookTitle, src.bookTitle); 
}

/******************** PR1 - EX 4A ********************/
tError bookTable_add(tBookTable *tabBook, tBook book) {

	tError retVal = OK;
	
	/* Check if there enough space for the new section */
	if(tabBook->size>=MAX_BOOKS) {
		retVal = ERR_MEMORY;
	}

	if (retVal == OK) {
		/* Add the new section to the end of the table */
		book_cpy(&tabBook->table[tabBook->size],book);
		tabBook->size++;
	}
	
	
	return retVal;
}

/******************** PR1 - EX 4B ********************/
int bookTable_find(tBookTable tabBook, char *ISBN) {
	unsigned int i;
	int idx = -1;
	
	i=0;
	while(i< tabBook.size && idx==-1) {
		/* Check if the id is the same */
		if(strcmp(tabBook.table[i].isbn,ISBN) ==0){
			idx = i;
		}
		i++;
	}

	return idx;
}

/******************** PR1 - EX 4C ********************/
void bookTable_del(tBookTable *tabBook, tBook book) {
	unsigned int i;
    unsigned int pos;

	pos = bookTable_find(*tabBook, book.isbn);
	if (pos!=-1){
	/* If the section is found, all the rest of the elements are displaced one position */
		for(i=pos; i<tabBook->size-1; i++) {		
			book_cpy(&tabBook->table[i],tabBook->table[i+1]);
		}
		tabBook->size=tabBook->size-1;		
	} 
}

/******************** PR1 - EX 5A ********************/
tError bookTable_save(tBookTable tabBook, const char* filename) {

	tError retVal = OK;
	
	FILE *fout=0;
	unsigned int i;
	char str[MAX_LINE];
	
	/* Open the output file */
	if((fout=fopen(filename, "w"))==0) {
		retVal = ERR_CANNOT_WRITE;
	} else {
	
        /* Save all sections to the file */
        for(i=0;i<tabBook.size;i++) {
            getBookStr(tabBook.table[i], MAX_LINE, str);
            fprintf(fout, "%s\n", str);
        }
            
        /* Close the file */
        fclose(fout);
	}
	
	return retVal;
}

/******************** PR1 - EX 5B ********************/
tError bookTable_load(tBookTable *tabBook, const char* filename) {
	
	tError retVal = OK;
	
	FILE *fin=0;
	char line[MAX_LINE];
	tBook newBook;
	
	/* Initialize the output table */
	bookTable_init(tabBook);
	
	/* Open the input file */
	if((fin=fopen(filename, "r"))!=NULL) {

		/* Read all the sections */
		while(!feof(fin) && tabBook->size<MAX_BOOKS) {
			/* Remove any content from the line */
			line[0] = '\0';
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line, MAX_LINE-1, fin);
			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1]='\0';
			if(strlen(line)>0) {
				/* Obtain the object */
				getBookObject(line, &newBook);
				/* Add the new section to the output table */
				bookTable_add(tabBook, newBook);		
			}
		}
		/* Close the file */
		fclose(fin);
		
	}else {
		retVal = ERR_CANNOT_READ;
	}
	
	
	return retVal;
}

/******************** PR1 - EX 6 ********************/
void bookTable_filterBySection(tBookTable tabBook, char sectionId, tBookTable *result) {
	
	unsigned int i=0;
	bookTable_init(result);
	while(i<tabBook.size) {
		/* Check if the idsection is the same */
		if(tabBook.table[i].identificator.mainSection == sectionId){
			bookTable_add(result, tabBook.table[i]);
		}
		i++;
	}
}

/******************** PR1 - EX 7A ********************/
unsigned int bookTable_getOnLoanNumber(tBookTable tabBook){

	int numBooks = 0;
	unsigned int i=0;
	while(i<tabBook.size) {
		/* Check if the idsection is the same */
		if(tabBook.table[i].available==0){
			numBooks++;
		}
		i++;
	}
	return numBooks;
}

/******************** PR1 - EX 7B ********************/
unsigned int bookTable_getAuthorNumber(tBookTable tabBook, char *author){
	int i =0;
	unsigned int numBooks = 0;
		while(i<tabBook.size) {
		/* Check if the author is the same */
		if(strcmp(tabBook.table[i].authorCode, author)==0){
			numBooks ++;
		}
		i++;
	}
	return numBooks;
}

