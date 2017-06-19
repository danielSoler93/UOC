#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

struct Node *current = NULL;

void initializeList(tLinkedList * linkedList){
    linkedList->sizeList = 0;
    linkedList->head = NULL;
}


bool isEmpty(tLinkedList linkedList){
    printf("%d\n", linkedList.head->data);
    if(linkedList.sizeList==0) {
        printf("Empty List\n");
        return true;
    }
    return false;

}


void insert(int d, tLinkedList * linkedList){
	struct Node *end = (struct Node*) malloc(sizeof(struct Node));
	end->next = NULL;
	end->data = d;
	linkedList->sizeList ++;
	if(linkedList->head != NULL){
		current = linkedList->head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = end;
	} else{
		linkedList->head = end;
	}
}

bool search(int d, tLinkedList  linkedList){

    current = linkedList.head;

    if(isEmpty(linkedList))    return false;


    while(current->next!=NULL && current->data!=d){
        current = current->next;
    }

    if(current->data==d) {
            return true;
    }
    else{
        printf("No Node with data %d\n", d);
        return false;
    }
}

void delete(int position, tLinkedList * linkedList){

    current = linkedList->head;
    struct Node *previous;

    if(isEmpty(*linkedList)) return false;

    else if(position == 1 && current->next == NULL) {
            linkedList->head->next = NULL;
            linkedList->head->data = NULL;
    }

    else{
        int index = 1;
        while(current->data!=NULL && index!=position){
            previous = current;
            current = current->next;
            index ++;
        }
        if(index==position) {
                if(position == 1){
                    linkedList->head = current->next;
                    current->next = NULL;
                }else{
                    previous->next = current->next;
                    current->next = NULL;
                }
        }

        else{
            printf("No Node in position %d\n", position);
        }

    }
    linkedList->sizeList--;


}

void displayList(tLinkedList linkedList){
	current = linkedList.head;

    if(isEmpty(linkedList))  return false;


	int i;
	while(current->next != NULL){
		printf("%d", current->data);
		current= current->next;
	}
	printf("%d", current->data);
}

void deleteRepeted(tLinkedList * linkedList){

    if(isEmpty(*linkedList)) return false;

    int i;
    int index;
    bool found;
    struct Node previous;

    /*Implement hash*/
    current = linkedList->head;
    previous = NULL;
    while(current!=NULL){
        if(hashtable.table[hash(current->data)]!=NULL)
            previous->next = current->next;
            }else {
            hash.add(current->data);
            previous = current;
        }
    current->current->next;
}

