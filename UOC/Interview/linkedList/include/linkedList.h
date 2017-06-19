#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdbool.h>


struct Node{
	struct Node *next;
	int data;
};

typedef struct{
    struct Node *head;
    int sizeList;
} tLinkedList;

tLinkedList linkedList;

typedef struct{
    int * data;
    unsigned int size;
} tBuffer;

tBuffer buffer;


void initializeList(tLinkedList * linkedList);

bool isEmpty(tLinkedList linkedList);

bool search(int d, tLinkedList  linkedList);

void insert(int d, tLinkedList * linkedList);

void delete(int position, tLinkedList * linkedList);

void displayList(tLinkedList linkedList);

void deleteRepeted(tLinkedList * linkedList);

#endif // LINKEDLIST_H_INCLUDED
