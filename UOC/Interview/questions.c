/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*   Programming
*   Interviews
*   Experience
*   Problems
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

void reverse(char string[]){
    
    /*
    Given a string, reverse the sentence without
    changing the letters order inside each word.

    Parameters
    ------------

    Input)

        string[] : Initial sentence

    Output)

        Printf with the reversed sentence if no failure
    */

    char *buffer;
    int wordStart;
    int wordEnd;
    int writePos = 0;
    int stringLenght = strlen(string);
    int readPosition = stringLenght-1;
    buffer = (char *) malloc(stringLenght + 1);
    
    if(!buffer){
        printf("Failed");
    }
    while(readPosition>=0){
        if (string[readPosition] == ' '){
            /*Write non word characters */
            buffer[writePos++] = string[readPosition--];
            }
        else{
            /*Write word characters*/
            //Store end of the word position
            wordEnd = readPosition;
            //Look start position
            while(readPosition>=0 && string[readPosition] != ' '){
                readPosition--;
            }
            wordStart = readPosition + 1;

            //write to buffer
            while(wordStart<=wordEnd){
                buffer[writePos++] = string[wordStart++];
            }
        }
    }
    buffer[writePos] = '\0';
    strncpy(string, buffer, stringLenght + 1);
    free(buffer);
   //Printing string
   int i;
   for(i=0; i<stringLenght; i++){
        printf("%c", string[i]);
    }
}

int * StringToInt(char string[]){

    /*
    Convert string to int
    with O(n)

    Parameters:
    ...........

    Input)

    string [] : string to convert

    Output)

    convertedString[]: converted string 
    */

    int readPosition;
    int convertedNum;
    stringLenght = strlen(string);
    int intArray[stringLenght];
    for (readPosition; readPosition<stringLenght; i++){
        //Numbers
        if(string[readPosition] >= 48  && string[readPosition] <= '57' ){
            convertedNum = ((int) string[readPosition] + 2) % 10;
            intArray[readPosition] = convertedNum;
        }

        else{
            printf("Just Integers")
        }
    }
    return(intArray);
}


int main(int argc, char **argv)
{
    char string[] = "12342";
    intString =StringToInt(string);



return 0;

}

/* Implementation of actions and functions*/
