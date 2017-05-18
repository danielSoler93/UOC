#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"


void getBookStr(tBook book, int maxSize, char *str) {
	int length;
	unsigned short int tmpAvail;
	
	if (book.avail==TRUE)
		tmpAvail=1;
	else
		tmpAvail=0;
		
	length = snprintf(str,maxSize-1,"%s %hu %hu %c %c %s %s", book.ISBN, book.year, tmpAvail, book.clas.secId, book.clas.subId, book.author, book.title);
	if (length>0) 
		str[length]='\0';
}

tError getBookObject(const char *str, tBook *book) {

	tError retVal = OK;
	unsigned short int tmpAvail;
	
	sscanf(str, "%s %hu %hu %c %c %s %s", book->ISBN, &book->year, &tmpAvail, &book->clas.secId, &book->clas.subId, book->author, book->title);
	
	book->avail = (tmpAvail==1);

	return retVal;
}

void bookTable_init(tBookTable *bookTable) {
	bookTable->size=0;
#ifdef COMPLETE_VERSION
/******************** PR2 - EX6C ********************/
	bookTable->size = 0;
	bookTable->table=NULL;
#endif
}

int book_cmp(tBook b1, tBook b2) {
	
	int retVal=0;
	
	if (b1.clas.secId>b2.clas.secId)  retVal = 1;
	else if (b1.clas.secId<b2.clas.secId)  retVal = -1;
	else {
		if (b1.clas.subId>b2.clas.subId)  retVal = 1;
		else if (b1.clas.subId<b2.clas.subId)  retVal = -1;
		else {
			retVal = strcmp(b1.author, b2.author);
			if(retVal==0) {
				/* If the author is equal, order by title */
				retVal=strcmp(b1.title, b2.title);
				if (retVal==0)
					retVal=strcmp(b1.ISBN,b2.ISBN);
			}
		}
	}
	
	return retVal;
}

void book_cpy(tBook *dst, tBook src) {
	strcpy(dst->ISBN,src.ISBN); 
	dst->year = src.year;
	dst->avail = src.avail;
	dst->clas.secId = src.clas.secId;
	dst->clas.subId = src.clas.subId;
	strcpy(dst->author, src.author); 
	strcpy(dst->title, src.title); 
}

tError bookTable_add(tBookTable *tabBook, tBook book) {

	tError retVal = OK;

#ifdef SIMPLE_VERSION
	/* Check if there enough space for the new book */
	if(tabBook->size>=MAX_BOOKS) {
		retVal = ERR_MEMORY;
	}  
	if (retVal==OK){
	/* Add the new book to the end of the table */
		book_cpy(&(tabBook->table[tabBook->size]), book);	
		tabBook->size++;
	}
#endif
#ifdef COMPLETE_VERSION
/******************** PR2 - EX6D ********************/
	/* Add the new book to the end of the table */
		if(tabBook->size == 0) {
			tabBook->table=(tBook*)malloc(sizeof(tBook));
		} else {
			tabBook->table=(tBook*)realloc(tabBook->table, (tabBook->size+1) * sizeof(tBook));
		}
		
		book_cpy(&(tabBook->table[tabBook->size]), book);	
		tabBook->size++;
#endif


	return retVal;
}

int bookTable_find(tBookTable tabBook, char *ISBN) {
	int i;
	int idx = -1;
	
	i=0;
	while(i< tabBook.size && idx==-1) {
		/* Check if the id is the same */
		if(strcmp(tabBook.table[i].ISBN,ISBN)==0) {
			/* Get the position of the match */
			idx = i;
		}
		i++;
	}
	
	return idx;
}

void bookTable_del(tBookTable *tabBook, tBook book) {
	int i;
	int pos;

	pos = bookTable_find(*tabBook,book.ISBN);
	if (pos!=-1){
	/* If the book is found, all the rest of the elements are displaced one position */
		for(i=pos;i<tabBook->size-1; i++) {		
			book_cpy(&(tabBook->table[i]), tabBook->table[i+1]);			
		}
		tabBook->size=tabBook->size-1;
	}	
#ifdef COMPLETE_VERSION
/******************** PR2 - EX6E ********************/
	pos = bookTable_find(*tabBook,book.ISBN);
	if (pos!=-1){
	/* If the book is found, all the rest of the elements are displaced one position */
		for(i=pos;i<tabBook->size-1; i++) {		
			book_cpy(&(tabBook->table[i]), tabBook->table[i+1]);			
		}
		tabBook->size=tabBook->size-1;
		if(tabBook->size==0){
			free(tabBook->table);
			tabBook->table = NULL;
		} else {
			tabBook->table = (tBook*)realloc(tabBook->table, tabBook->size*sizeof(tBook));
		}
	}
#endif	
}

tError bookTable_save(tBookTable tabBook, const char* filename) {
	FILE *fout=0;
	int i;
	char str[MAX_LINE];
	tError retVal = OK;
	
	/* Open the output file */
	if((fout=fopen(filename, "w"))!=0) {

		/* Save all books to the file */
		for(i=0;i<tabBook.size;i++) {
			getBookStr(tabBook.table[i], MAX_LINE, str);
			fprintf(fout, "%s\n", str);
		}
		
		/* Close the file */
		fclose(fout);
		retVal = OK;
	} else {
		retVal = ERR_CANNOT_WRITE;
	}
	
	return retVal;
}

tError bookTable_load(tBookTable *tabBook, const char* filename) {

	tError retVal = OK;
	FILE *fin=0;	
	char line[MAX_LINE];
	tBook newBook;
	
	/* Initialize the output table */
	bookTable_init(tabBook);
	
	/* Open the input file */
	if((fin=fopen(filename, "r"))==0) {
		retVal = ERR_CANNOT_READ;
	}
	
	/* Read all the books */
	while(retVal==OK && !feof(fin) && tabBook->size<MAX_BOOKS) {
		/* Remove any content from the line */
		line[0] = '\0';
		/* Read one line and store it in "line" variable */
		fgets(line, MAX_LINE-1, fin);
		/* Ensure that the string is ended by 0*/
		line[MAX_LINE - 1]='\0';
		if(strlen(line)>0) {
			/* Obtain the object */
			getBookObject(line, &newBook);
			/* Add the new book to the output table */
			bookTable_add(tabBook, newBook);		
		}
	}	
		
	/* Close the file */
	fclose(fin);
	
	return retVal;
}


void bookTable_filterBySection(tBookTable tabBook, char sectionId, tBookTable *result) {
	int i;
	
	bookTable_init(result);
	i=0;
	while(i< tabBook.size) {
		/* Check if the section is the same */
		if(tabBook.table[i].clas.secId==sectionId) {
			/* Add to the result table */
			bookTable_add(result,tabBook.table[i]);
		}
		i++;
	}
}

unsigned int bookTable_getOnLoanNumber(tBookTable tabBook){
	unsigned int i;
	unsigned int numBooks=0;
	
	i=0;
	while(i< tabBook.size) {
		/* Check if the book is not available */
		if(tabBook.table[i].avail!=TRUE) {
			/* Add a unit to the total */
			numBooks++;
		}
		i++;
	}
	
	return numBooks;
}

unsigned int bookTable_getAuthorNumber(tBookTable tabBook, char *author){
	unsigned int i;
	unsigned int numBooks=0;
	
	i=0;
	while(i< tabBook.size) {
		/* Check if the author matches */
		if(strcmp(tabBook.table[i].author,author)==0) {
			/* Add a unit to the total */
			numBooks++;
		}
		i++;
	}
	
	return numBooks;
}

/******************** PR2 - EX1A ********************/
tError bookTable_sortedAdd(tBookTable *tabBook, tBook book){

	/* Check if there enough space for the new book */
#ifdef SIMPLE_VERSION
int returnValue;
int i;
int holePosition;

tError retVal = OK;
holePosition = tabBook->size;

if(tabBook->size >= MAX_BOOKS){
	printf("No Space Left\n");
	retVal = ERR_MEMORY;
} 

if(retVal == OK) {
	for(i=tabBook->size; i>0; i--){
		returnValue = book_cmp(tabBook->table[i-1], book);
		if (returnValue==1){
			book_cpy(&(tabBook->table[i]), tabBook->table[i-1]);
			holePosition--;
		}
	}
	book_cpy(&(tabBook->table[holePosition]), book);	
	tabBook->size++;
}

#endif
#ifdef COMPLETE_VERSION
/******************** PR2 - EX6D ********************/
int returnValue;
int i;
int holePosition;

tError retVal = OK;
holePosition = tabBook->size;

if(tabBook->size==0){
	tabBook->table=(tBook*)malloc(sizeof(tBook));
} else{
	tabBook->table=(tBook*)realloc(tabBook->table, (tabBook->size+1)*sizeof(tBook));
}
if(retVal == OK) {
	for(i=tabBook->size; i>0; i--){
		returnValue = book_cmp(tabBook->table[i-1], book);
		if (returnValue==1){
			book_cpy(&(tabBook->table[i]), tabBook->table[i-1]);
			holePosition--;
		}
	}
	book_cpy(&(tabBook->table[holePosition]), book);	
	tabBook->size++;
}

#endif

	
	return retVal;	
}

/******************** PR2 - EX1B ********************/
void bookTable_sort(tBookTable tabBook, tBookTable *result){
	int i;
	result->size = 0;	
	for(i=0; i<tabBook.size; i++){
		bookTable_sortedAdd(result, tabBook.table[i]);
	}
}

/* Release a books table */
void bookTable_release(tBookTable *tabBook) {
#ifdef COMPLETE_VERSION
/******************** PR2 - EX6F ********************/
tabBook->size = 0;
free(tabBook->table);
tabBook->table = NULL;
#endif	
}