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

void initializeList(tLinkedList * linkedList);

bool search(int d, tLinkedList  linkedList);

void insert(int d, tLinkedList * linkedList);

void delete(int d, tLinkedList * linkedList);

void displayList(tLinkedList linkedList);

#endif // LINKEDLIST_H_INCLUDED
