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
#include <math.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/


/*Pre-declaration of actions and functions*/

int reverseNumber(int originalNumber){
    /*
    Create the reversed number from the one given.

    Example: 212
    1- 212%10-->212/10=21,2-->we keep the decimal-->2
    2- reversenumber = 2
    3- new number--> 212/10=21,2-->keep the non decimal part --> 21

    1- 21%10 = 1
    2- reverse number = 21
    3- new number = 2

    1- 2%10 = 2
    2- reverse number = 212
    3- new number 0---> exit while!
    */

int Remainder;
int reversedNum;


    while(originalNumber!=0 )
{
    Remainder = originalNumber%10;
    reversedNum = reversedNum*10 + Remainder;
    originalNumber /= 10; 
}
return reversedNum;
}


/*Main Function*/
int main(int argc, char **argv)
{
//Intialize variable
int reversedNum = 0;
int originalNum = 0;
int Remainder = 0;

//Get number from command line
printf("Insert a number: \n");
scanf("%d", &originalNum);

//Create reversedNumber
reversedNum = reverseNumber(originalNum);

//Output whether or not the given num is palidrome
if (originalNum == reversedNum)
        printf("%d is a palindrome. \n", originalNum);
    else
        printf("%d is not a palindrome. \n", originalNum);

return 0;

}

/* Implementation of actions and functions*/
