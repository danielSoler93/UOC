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
	/* If test mode is active, run the tests. Otherwise, trigger the sort and search algotihms */
	if(testMode) {
		runTests();
	} else {
	tDiscountsShop tabDisc;
	initDiscounts(&tabDisc);
	sortDiscountsShop(&tabDisc);
	bool found;
	bool changed;
	discountChanged(&tabDisc, 1110, &found, &changed);
	}
	
	return 0;
}
