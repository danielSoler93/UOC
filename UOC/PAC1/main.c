/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*    Read 5 int and 1 float and check
*    whether or not the float is the
*    average of the integers given.
*   
*   """
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/


/*Pre-declaration of actions and functions*/


void errorHandeling(int choosenflag, int otherflag, int anotherflag)
{
    
    if (choosenflag){
        printf("Only one option allowed");
        exit(1);
            }
    else{
        
        choosenflag++;
        otherflag++;
        anotherflag++;
    }
    
}

void checkMean(int *data, float average){
    int sum = 0;
    int i;

    for(i=0; sizeof(data); i++){
        sum += sum;
    }
    float calculatedAverage = sum/sizeof(data);
    if (calculatedAverage==average){
        printf("y");
    }
    else{
        printf("n");
    }
}

/*Main Function*/
int main(int argc, char **argv)
{
    int option;
    int aflag = 0;
    int bflag = 0;
    int cflag = 0;
    
	 while ((option = getopt(argc, argv, "a:b:c:")) != -1)
     {
     switch (option)
      {
      case 'a':
            //errorHandeling(aflag, bflag, cflag);
            printf("%s", optarg);
            printf("Calculating and comparing 5 first numbers average");
            break;
      case 'b':
            //errorHandeling(bflag, aflag, cflag);
            printf("Reading and printing string backwards");
            break;
      case 'c':
            //errorHandeling(cflag, aflag, bflag);
            printf("Palindrom detection");
            break;
     case '?':
            printf("Invalid option");
      }
    } 
}

/* Implementation of actions and functions*/
