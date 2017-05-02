/* Run all the test set */
#include "shop.h"

//Test Function Headers
void runTests();

void runTestsPAC3(int *totalTest, int *passedTest);

void testAddToEmptyList(tShop *shop, tClient client, int *totalTest, int *passedTest);

void testAddToNonemptyList(tShop *shop, tClient client1, tClient client2, tClient client3, int *totalTest, int *passedTest);

void testAddExistentClient(tShop *shop, tClient client, int *totalTest, int *passedTest);