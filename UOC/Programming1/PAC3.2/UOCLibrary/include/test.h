/* Run all the test set */
#include "shop.h"

//Test Function Headers
void runTests();

void runTestsPAC3(int *totalTest, int *passedTest);

/*Test to add a client to an empty table*/
void testAddToEmptyList(tShop *shop, tClient client, int *totalTest, int *passedTest);
/*Test to add a client to a non empty table at the beggining/midle and end of the list.*/
void testAddToNonemptyList(tShop *shop, tClient client1, tClient client2, tClient client3, int *totalTest, int *passedTest);
/*Test to add an already existent client on the table*/
void testAddExistentClient(tShop *shop, tClient client, int *totalTest, int *passedTest);
/*Test to generate cupons*/
void testGenerateCupon(tShop *shop, int *totalTest, int *passedTest);