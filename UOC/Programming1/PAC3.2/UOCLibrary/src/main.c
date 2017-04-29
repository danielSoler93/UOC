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
		//runTests();
	} else {
		tShop shop;
		tClient client1, client2, client3;
		shopInit(&shop);
		clientInit(&client1, 123476,  "Dani", "Dani@gmail.com", 2.123, TRUE);
		clientInit(&client2, 123466,  "Pepe", "Pepe@gmail.com", 1.123, TRUE);
		clientInit(&client3, 123477,  "Anna", "Anna@gmail.com", 3.123, TRUE);
		clientAdd(&shop, client1);
		clientAdd(&shop, client2);
		posClient(shop, 123456);
		insertClient(&shop, client3);
	}
	return 0;
}
