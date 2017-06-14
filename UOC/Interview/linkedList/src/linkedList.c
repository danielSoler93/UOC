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
    if(current->data==NULL) {
            printf("Empty List\n");
            return false;
    }


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

void delete(int d, tLinkedList * linkedList){

    current = linkedList->head;
    struct Node *previous;

    if(current->data==NULL) {
            printf("Empty List\n");
            return false;
    }

    else if(current->next == NULL && current->data == d) {
            linkedList->head->next = NULL;
            linkedList->head->data = NULL;
    }

    else{
        while(current->next!=NULL && current->data!=d){
            previous = current;
            current = current->next;
        }
        if(current->data==d) {
                if(current == linkedList->head){
                    linkedList->head = current->next;
                    current->next = NULL;
                }else{
                    previous->next = current->next;
                    current->next = NULL;
                }
        }

        else{
            printf("No Node with data %d\n", d);
        }

    }


}

void displayList(tLinkedList linkedList){
	current = linkedList.head;
	int i;
	while(current->next != NULL){
		printf("%d", current->data);
		current= current->next;
	}
	printf("%d", current->data);
}
