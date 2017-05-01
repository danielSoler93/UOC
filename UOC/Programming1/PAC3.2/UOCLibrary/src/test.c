#include <stdio.h>
#include <string.h>
#include <math.h>
#include "test.h"


void runTests() {	
	int passedTestPAC3 = 0;
	int totalTestPAC3 = 0;
	
	printf("=================================================\n");
	printf("      ====       PAC3 1 TESTS        ====\n");
	printf("=================================================\n");	
	runTestsPAC3(&totalTestPAC3, &passedTestPAC3);

	printf("\n===================================\n");
	printf("====       TEST SUMMARY        ====\n");
	printf("===================================\n");		
	printf("\nPAC3: Passed %d of %d [%0.2f%%]\n", passedTestPAC3, totalTestPAC3, (float)passedTestPAC3/totalTestPAC3*100.0);
	printf("===================================\n");		
}

void runTestsPAC3(int *totalTest, int *passedTest) {
	*totalTest=0;
	*passedTest=0;
}
