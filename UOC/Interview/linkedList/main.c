#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "test.h"

int main(int argc, char **argv)
{
    int i;
    bool testMode = false;

    for(i=1; i<argc; i++) {
		if(strcmp(argv[i], "-t")==0) {
			testMode=true;
		}
	}

    if(testMode){
        runTests();
    } else{
        initializeList(&linkedList);
        insert(2, &linkedList);
        insert(3, &linkedList);
        insert(4, &linkedList);
        insert(5, &linkedList);
        insert(6, &linkedList);
        delete(4,&linkedList);
        displayList(linkedList);
    }

}

