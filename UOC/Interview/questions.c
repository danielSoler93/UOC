/**************************************************************
*
** File:        Example c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        18-03-2017
** Description:
*   """
*

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




int main(int argc, char **argv)
{
//Question to run:
retrieveSequence();
}
}

return 0;

}

/* Implementation of actions and functions*/
