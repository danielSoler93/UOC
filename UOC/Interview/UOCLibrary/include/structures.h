#define ALPHABETLENGHT 128

typedef struct{
	int key;
	char value;
} tEntries;



typedef struct{
	tEntries table[ALPHABETLENGHT];
} tHashtable;

tEntries entry;

tHashtable hashtable;


/*Function headers*/

tBoolean uniqueString(char * word);

tBoolean permutation(char * word1, char * word2);

void sort(char * word);

void spaces(char * word);

void initHashTable(tHashtable * hashtable);

void addHashTable(tHashtable * hashtable, char value);

tBoolean palindrome(tHashtable hashtable, char * string);

tBoolean oneWay(char * string1, char * string2);