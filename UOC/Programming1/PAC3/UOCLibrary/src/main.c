#include <stdio.h>
#include <string.h>
#include "test.h"

int main(int argc, char **argv) {	
	int i;
	bool testMode= FALSE;
	
	for(i=1; i<argc; i++) {
		if(strcmp(argv[i], "-t")==0) {
			testMode=TRUE;			
		}
	}
	/* If test mode is active, run the tests. Otherwise, start the menu */
	if(testMode) {
		runTests();
	} else {

	tDiscountsShop tabDisc;
	initDiscounts(&tabDisc);
	sortDiscountsShop(&tabDisc);
	discountChanged(&tabDisc, 1110);
	}
	
	return 0;
}
