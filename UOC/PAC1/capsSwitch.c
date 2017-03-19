/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*    Read 5 int and 1 float and check
*    whether or not the float is the
*    average of the integers given
*    by outputting y/n.
*   
*   """
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/


/*Pre-declaration of actions and functions*/
char * stringBackwards(char *string){
    int stringCharacters = strlen(string);
    char *stringBackwards = malloc(stringCharacters); // allocate memory from the heap
    int i;
    for(i=stringCharacters-1; i<0; i--){
        stringBackwards[i] = string[stringCharacters-(i+1)];
    }
    return stringBackwards;
}

/*Main Function*/
int main(int argc, char **argv)
{
//initialize varibles
char *targetString = argv[1];
char *stringBack = stringBackwards(targetString);
printf("\n%s\n", stringBack);


}

/* Implementation of actions and functions*/
