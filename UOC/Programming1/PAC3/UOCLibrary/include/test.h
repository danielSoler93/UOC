/* Run all the test set */
#include "discount.h"

//Test Function Headers
void runTests();

void runTestsPAC3(int *totalTest, int *passedTest);

/*Test the table sort algorithm*/
void test_sortIds(int *totalTest, int *passedTest, tDiscountsShop *tabDisc);

/*Test to change ungiven discount*/
void test_searchFalseId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc, int dni);

/*Test to change already given discount*/
void test_searchTrueId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc, int dni);

/*Test to change a non existent discount*/
void test_searchMissingId(int *totalTest, int *passedTest, tDiscountsShop *tabDisc, int dni);