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
*
**Launch:
* gcc checkMean.c -o checkMean
*./checkMean 1 2 3 4 5 3
*
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/
typedef enum { false, true } bool;

/*Pre-declaration of actions and functions*/

void handelingErrors(char **parameters, int numArguments){
    /*
    Handles the excess or lack of arguments
    Handles the wrong type of arg
    */
    int i;

    if ((numArguments-1)!=6){
        printf("\n\n6 arguments need it for this excercise\n"
               "Example: ./main 5 6 7 4 9 5.32\n\n");
    }
}

    float calculateMean(char **Arguments, int numArguments){
    /*
    Calculate the first five numbers mean
    by addind them all and dividing by 5.
    */
    int sum = 0;
    int i;
    for(i=1; i<(numArguments-1); i++){
        sum += atoi(Arguments[i]);
    }
    float calculatedAverage = sum / (float)(numArguments-2);
    return calculatedAverage;
}


void checkMean(char **Arguments, float givenAverage, int numArguments){
    /*
    Check whether or not the given mean
    and the calculated one are the same,
    and output y/n depending on the result.
    */
    float calculatedAverage = calculateMean(Arguments, numArguments);
    if (calculatedAverage==givenAverage){
        printf("y\n");
    }
    else{
        printf("n\n");
    }
}
//Easy Solution to deploy! --> Simpler, Shorter and more time-efficient
//What is best argv or scanf??
int Solution(void) {
   int a, b, c, d, e;
   float mean;
   
   printf("Enter 5 integers:\n");
   scanf("%i %i %i %i %i", &a, &b, &c, &d, &e); 
   
   printf("Enter the mean:\n");
   scanf("%f", &mean);

   if ( (float)((a + b + c + d + e) / 5) == mean)
      printf("y");
   else
      printf("n");
   return 0;
}

/*Main Function*/
int main(int argc, char **argv)
{
//initialize varibles
char **arguments = argv;
int numArguments = argc;
float givenAverage = atof(arguments[6]);

//Calculate Mean and output y/n
//by comparison with the given float
handelingErrors(arguments, numArguments);
checkMean(arguments, givenAverage, numArguments);

}

/* Implementation of actions and functions*/

