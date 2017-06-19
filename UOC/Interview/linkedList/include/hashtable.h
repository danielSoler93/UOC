#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

typedef struct{
    int hash[10];
    int size;
} tHashTable;

struct tElement{
    int data;
    tElement * next;
} ;
struct tElement element;

tHashTable hashTable;

int hash(int data);

int add(int data);

#endif // HASHTABLE_H_INCLUDED
