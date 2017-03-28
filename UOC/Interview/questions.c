/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*

*   """
*
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/


/*Pre-declaration of actions and functions*/
void forToWhile(){

    /*
    Get the equivalent code of the following for statement in WHILE LOOP format: 
    for (a=1; a&lt;=100; a++) 
    printf (&quot;%d\n&quot;, a * a);
    */

    int a = 1;
    while (a<100){
        printf ("&quot;%d\n&quot;", a * a);
        a++;
    }
}

void retrieveSequence(){
    
    /*
    Func to Retrieve next pattern:
    1
    12
    123
    1234
    12345
    */

    int i = 0;
    int Pow = 10;
    int Newsequence = 0;
    for (i=1; i<6; i++){
        Newsequence = (Newsequence * Pow + i); 
        printf("%d\n", Newsequence);
    }
}

int nonRepit(char string[], int lenght){
    /*
    Prints out to terminal the first
    non repite character from a string

    Parameters:
    -----------
    Input)   
        string char []
            initial string

        lenght int
            lenght of the string

    Output)
        First non repit character
        in case there is not prints
        an alert message.
    */
    int i = 0;
    int storage[200] = {0};
    int number;
    char character;
    //printf("%d", lenght );
    for (i=0; i<lenght; i++){
        character = string[i];
        number = (int)(character);
        storage[number] += 1;
        //printf("%c", character);

    }
    for (i=0; i<lenght; i++){
        character = string[i];
        if (storage[(int)(character)] == 1){
            printf("The first non repited character is --> %c\n", string[i]);
            return(0);
        }
    }
    printf("Non repited value\n");
}

char removeChars(char string[], char charsToRemove[], int stringLenght, int removeLenght){
    
    /*
    Given a string and some chars,
    remove these chars from inside
    the string and print out to terminal.

    Paramaters:
    ------------
    input)

        string[]: original string

        charsToRemove[]: characters to remove form string

        stringLenght(int): lenght of string

        removeLenght(int): lenght of charstoremove

    output)

        Printed string with removed characters
    */

    //Saving items to remove
    int storage[200] = {0}; //It's a dinamic array how can I do it to not specify memory
    int i;    
    for(i=0; i<removeLenght; i++){
        char character = charsToRemove[i];
        int number = (int)(character);
        storage[number] = 1;
    }
    //Copyng not removed items
    char *copy; //It's a dinamic array how can I do it to not specify memory
    copy = (char *) malloc(sizeof(int));
    int j = 0;
    for(i=0; i<stringLenght; i++){      
        if (storage[(int) string[i]] == 0){
            char characterToCopy = string[i];
            copy[j] = characterToCopy;
            j++;
            copy = realloc(copy, (j+1) * sizeof(int));
        }
    }
    //Print string without charsToRemove
    printf("The string with the removed character is:\n");
    i=0;
    while(copy[i]){
        printf("%c", copy[i]);
        i++;
    }
    printf("\n");
    free(copy);
}

int main(int argc, char **argv)
{
    char string[] = "Battle of the Vowels: Hawaii vs. Grozny";
    char charsToRemove[] = "aeiou";
    int stringLenght = strlen(string);
    int removeLenght = strlen(charsToRemove);

    removeChars(string, charsToRemove, stringLenght, removeLenght);



return 0;

}

/* Implementation of actions and functions*/
