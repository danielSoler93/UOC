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
	
	tShop shop;
	tClient client1, client2, client3, client4;
	shopInit(&shop);
	clientInit(&client1, 123476,  "Dani", "Dani@gmail.com", 2.123, FALSE);
	clientInit(&client2, 123486,  "Pepe", "Pepe@gmail.com", 102.123, FALSE);
	clientInit(&client3, 123477,  "Anna", "Anna@gmail.com", 3.123, FALSE);
	clientInit(&client4, 123457,   "Ron",  "Ron@gmail.com", 100.123, FALSE);
	testAddToEmptyList(&shop, client1, totalTest, passedTest);
	testAddToNonemptyList(&shop, client2, client3, client4, totalTest, passedTest);
	testAddExistentClient(&shop, client1, totalTest, passedTest);
	testGenerateCupon(&shop, totalTest, passedTest);
}

void testAddToEmptyList(tShop *shop, tClient client, int *totalTest, int *passedTest){
	insertClient(shop, client);
	(*totalTest)++;
	if(shop->clients[0].dni== client.dni){
		(*passedTest)++;
		printf("->OK\n");
	} else{
		printf("->ERROR\n");
	}
}

void testAddToNonemptyList(tShop *shop, tClient client1, tClient client2, tClient client3, int *totalTest, int *passedTest){
	//insert at the begging of the list
	insertClient(shop, client1);
	(*totalTest)++;
	if(shop->clients[0].dni== client1.dni){
		(*passedTest)++;
		printf("->OK\n");
	} else{
		printf("->ERROR\n");
	}
	//Insert at the middle of the list
	insertClient(shop, client2);
	(*totalTest)++;
	if(shop->clients[1].dni== client2.dni){
		(*passedTest)++;
		printf("->OK\n");
	} else{
		printf("->ERROR\n");
	}
	//insert at the end of the list
	insertClient(shop, client3);
	(*totalTest)++;
	if(shop->clients[3].dni== client3.dni){
		(*passedTest)++;
		printf("->OK\n\n");
	} else{
		printf("->ERROR\n");
	}
}
	
void testAddExistentClient(tShop *shop, tClient client, int *totalTest, int *passedTest){
	int position = posClient(*shop, client.dni);
	insertClient(shop, client);
	(*totalTest)++;
	if(position== posClient(*shop, client.dni)){
		(*passedTest)++;
		printf("->OK\n");
	} else{
		printf("->ERROR\n");
	}
}

void testGenerateCupon(tShop *shop, int *totalTest, int *passedTest){
	generateDiscount(shop);
	(*totalTest)++;
	if(shop->clients[0].thereIsCupon && shop->clients[3].thereIsCupon){
		(*passedTest)++;
		printf("->OK\n");
	} else{
		printf("->ERROR\n");
	}
}
	