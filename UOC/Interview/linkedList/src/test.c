#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"


void runTests() {
	int passedTest = 0;
	int totalTest = 0;

	printf("=================================================\n");
	printf("      ====       TEST        ====\n");
	printf("=================================================\n");

	runTestsLinkedList(&totalTest, &passedTest);

	printf("\n===================================\n");
	printf("====       TEST SUMMARY        ====\n");
	printf("===================================\n");
	printf("\nPAC3: Passed %d of %d [%0.2f%%]\n", passedTest, totalTest, (float)passedTest/totalTest*100.0);
	printf("===================================\n");
}

void runTestsLinkedList(int *totalTest, int *passedTest) {
	*totalTest=0;
	*passedTest=0;


    initializeList(&linkedList);

	test_insert(totalTest, passedTest, &linkedList);
	test_delete(totalTest, passedTest, &linkedList);
	test_deleteRepeated(totalTest, passedTest, &linkedList);

}


void test_insert(int * totalTest, int * passedTest, tLinkedList *linkedList){

    //Empty ist insertion
    (*totalTest)++;
    insert(2, linkedList);
    bool found = search(2, *linkedList);
    if(found) (*passedTest)++;


    //One element list insertion
    (*totalTest)++;
    insert(3, linkedList);
    found = search(3, *linkedList);
    if(found) (*passedTest)++;


    //More than one element list insertion
    (*totalTest)++;
    insert(4, linkedList);
    found = search(4, *linkedList);
    if(found) (*passedTest)++;


}

void test_delete(int * totalTest, int * passedTest, tLinkedList *linkedList){
    //Delete first element
    (*totalTest)++;
    delete(1, linkedList);
    bool found = search(2, *linkedList);
    if(!found) (*passedTest)++;


    //Delete in between element
    (*totalTest)++;
    delete(1, linkedList);
    found = search(3, *linkedList);
    if(!found) (*passedTest)++;



    //Delete last element
    (*totalTest)++;
    delete(1, linkedList);
    found = search(4, *linkedList);
    if(!found) (*passedTest)++;

    //Delete only element
    (*totalTest)++;
    insert(2, linkedList);
    delete(1, linkedList);
    found = search(2, *linkedList);
    if(!found) ;(*passedTest)++;

}

void test_deleteRepeated(int * totalTest, int * passedTest, tLinkedList *linkedList){
    (*totalTest)++;
    insert(2, linkedList);
    insert(3, linkedList);
    insert(4, linkedList);
    insert(2, linkedList);
    insert(3, linkedList);
    insert(8, linkedList);
    insert(10, linkedList);
    insert(2, linkedList);
    displayList(*linkedList);
    deleteRepeted(linkedList);
    displayList(*linkedList);



}


