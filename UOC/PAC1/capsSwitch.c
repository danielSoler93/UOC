/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*    Pass a character as argument check whether
*    is capital or lowercase letter and convert
*    it to the other type.   
*   """
*
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <ctype.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/


/*Pre-declaration of actions and functions*/

char capsSwitch(char character){
    /*
    Convert to capital Character
    */
    char newCharacter;
    newCharacter = toupper(character);
    return newCharacter;
    
}

char lowercaseSwitch(char character){
    /*
    Convert to lowercase Character
    */
    char newCharacter;
    newCharacter = tolower(character);
    return newCharacter;
}

/*Main Function*/
int main(int argc, char **argv)
{
//Intialize variable
char character;
char newCharacter;

printf("Insert one character: \n");
scanf("%c", &character);
//Recognising whether we have a capital or a lowercase letter
if (character >= 65 && character <= 90){
    newCharacter = lowercaseSwitch(character);
}
else{
    newCharacter = capsSwitch(character); 
}
//Output results
printf("The new character is: %c\n", newCharacter);
return 0;

}

/* Implementation of actions and functions*/
