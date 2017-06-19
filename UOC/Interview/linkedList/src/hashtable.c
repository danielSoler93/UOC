#include "hashtable.h"

int hash(int data){
   return data*10/(data+10);
}

void add(int data, tHashTable * hashTable){
    element.data = data;
    element->next = NULL;
    hashTable[hash(data)] = data;

}
