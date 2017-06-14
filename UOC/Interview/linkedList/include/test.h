#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

void runTests();

void runTestsLinkedList(int *totalTest, int *passedTest);

void test_insert(int *totalTest, int *passedTest, tLinkedList *linkedList);

void test_delete(int * totalTest, int * passedTest, tLinkedList *linkedList);

#endif // TEST_H_INCLUDED
