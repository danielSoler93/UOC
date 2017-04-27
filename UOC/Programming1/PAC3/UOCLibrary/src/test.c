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
	
	
	tDiscountsShop tabDisc;
	initDiscounts(&tabDisc);

	
	test_sortedId(totalTest, passedTest, &tabDisc);
	test_searchFalseId(totalTest, passedTest,&tabDisc, 1434);	
	test_searchTrueId(totalTest, passedTest, &tabDisc, 1234);
	test_searchMissingId(totalTest, passedTest,&tabDisc, 2222);
	
}

void test_sortedId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc){
	printf("\n=================================================\n");
	printf(" SORT DISCOUNTS\n");
	printf("=================================================\n");
	(*totalTest)++;
	sortDiscountsShop(tabDisc);
	if(tabDisc->discounts[0].dni<tabDisc->discounts[1].dni && tabDisc->discounts[1].dni<tabDisc->discounts[2].dni && \
	   tabDisc->discounts[2].dni<tabDisc->discounts[3].dni && tabDisc->discounts[3].dni<tabDisc->discounts[4].dni){
			printf("\n\t-> OK\n");
			(*passedTest)++;
		} else{
			printf("\n\t-> FAIL\n");
		}
	
}

void test_searchFalseId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc, int dni){
	printf("\n=================================================\n");
	printf(" CHANGE UNGIVEN DISCOUNT\n");
	printf("=================================================\n");
	(*totalTest)++;
	discountChanged(tabDisc, dni);
	//Verify
	int i;
	for(i = 0; i < tabDisc->numDiscounts; i++) {
		if(tabDisc->discounts[i].dni == dni){
			if(tabDisc->discounts[i].changed == TRUE){
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else{
				printf("\n\t-> FAIL\n");
			}
		}
	}
	
}

void test_searchTrueId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc, int dni){
	printf("\n=================================================\n");
	printf(" CHANGE ALREADY GIVEN DISCOUNT\n");
	printf("=================================================\n");
	(*totalTest)++;
	discountChanged(tabDisc, dni);
	//Verify
	int i;
	for(i = 0; i < tabDisc->numDiscounts; i++) {
		if(tabDisc->discounts[i].dni == dni){
			if(tabDisc->discounts[i].changed == TRUE){
				printf("\n\t-> OK\n");
				(*passedTest)++;
			} else{
				printf("\n\t-> FAIL\n");
			}
		}
	}
	
}


void test_searchMissingId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc, int dni){
	printf("\n=================================================\n");
	printf(" CHANGE NON EXISTENT DISCOUNT\n");
	printf("=================================================\n");
	(*totalTest)++;
	(*passedTest)++;
	discountChanged(tabDisc, dni);
	}
