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
#include <ctype.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/


/*Pre-declaration of actions and functions*/

void handleErrors(){
    

}

char capsSwitch(char character){
    char newCharacter;
    newCharacter = toupper(character);
    return newCharacter;
    
}

char lowercaseSwitch(char character){
    char newCharacter;
    newCharacter = tolower(character);
    return newCharacter;
}

/*Main Function*/
int main(int argc, char **argv)
{

char character;
char newCharacter;

printf("Ingrese una character: ");
scanf("%c", &character);

handleErrors();

if (character >= 65 && character <= 90){
    newCharacter = lowercaseSwitch(character);
}
else{
    newCharacter = capsSwitch(character); 
}

printf("The new character is: %c\n", newCharacter);
return 0;

}

/* Implementation of actions and functions*/
