/* Run all the test set */
#include "shop.h"

//Test Function Headers
void runTests();

void runTestsPAC3(int *totalTest, int *passedTest);

void addToEmptyList(tShop *shop, tClient client, int *totalTest, int *passedTest);

void addToNonemptyList(tShop *shop, tClient client1, tClient client2, tClient client3, int *totalTest, int *passedTest);