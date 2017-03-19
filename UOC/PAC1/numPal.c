/**************************************************************
*
** File:        numPal.c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        19-03-2017
** Description:
*   """
*    Check whether or not the given
*    argument is a palindrome number.
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
int isPalindrome(int number){
    int i;
    int *numberArray = &number;
    int numberLenght = sizeof(numberArray);
    int forLoops = div(numberLenght, number) + (numberLenght % number);

    for (i=0; i<forLoops; i++){
        if (numberArray[i] != numberArray[-i]){
            printf("The number is not palindrome\n");
            printf("%d",numberArray[i]);
            return(0);
        }
    }
    printf("The number is palindrome\n");
    return(0);
    
}


/*Main Function*/
int main(int argc, char **argv)
{
//Intialize variable
int targetNum;
//Get number from command line
printf("Insert a number: \n");
scanf("%d", &targetNum);
//Check whether or not is palindrome
isPalindrome(targetNum);
return 0;

}

/* Implementation of actions and functions*/
