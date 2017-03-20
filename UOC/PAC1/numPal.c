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
typedef enum { false, true } bool;

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


bool handleError(int number){

    /*
    Handle the lack or exces of enter numbers
    on the given input.

    Paramaters:
    -----------

    input:
    -  number:  int
       number to check

    output: 
    -  validation: bool
        true if the number is correct
        false if it's not
    */
        
    int count = 0;
    while(number != 0)
    {
        number /= 10;
        ++count;
    }
    if (count != 5){
        printf("\nInput must be a 5 digit number \n");
        return false;
    }
    else{
        return true;
    }
}


/*Main Function*/
int main(int argc, char **argv)
{
//Intialize variable
int reversedNum = 0;
int originalNum = 0;
int Remainder = 0;
bool validation = false;

while (!validation){
//Get number from command line
printf("\nInsert a number: \n");
scanf("%d", &originalNum);

//check the passed argument has  5 digits
validation = handleError(originalNum);
}

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
