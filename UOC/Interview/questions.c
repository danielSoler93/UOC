/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*
*   What is the equivalent code of the following statement in WHILE LOOP format?  
*   for (a=1; a&lt;=100; a++) 
*   printf (&quot;%d\n&quot;, a * a);
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
void forToWhile(){
    int a = 1;
    while (a<100){
        printf ("&quot;%d\n&quot;", a * a);
        a++;
    }

}


int main(int argc, char **argv)
{

forToWhile();
return 0;

}

/* Implementation of actions and functions*/
