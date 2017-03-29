     /**************************************************************
*
** File:        StudentsTeacher.c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        29-03-2017
** Description:
*   """
*   Logic of init functions
*   for all different data
*   structure types. 
*   """
*
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/*Application headers file*/


/*Symboli constants*/

/*User defined types*/
typedef enum { false, true } bool;



/*Pre-declaration of actions and functions*/



/* Implementation of actions and functions*/

void fillTeachersVector(tTeacher * tTeacherVector){
    
    /*
    Initialize Teacher's information
    
    Parameters:
    ------------

    Input)

        tTeacherVector tTeacher: Original Teacher vector
    */

    int teachersId[] = {1,2,3,4};
    bool teachersEnglish[] = {true, false, true, false};
    char teachersCLevel[] = {'P', 'P', 'S', 'S'};
    int vectorsLenght = strlen(studentsCLevel);
    int readPos;

    for (readPos=0; readPos<vectorsLenght; readPos++){
        *tTeacherVector[i].idTeacher = studentsId[i];
        *tTeacherVector[i].bEnglish = studentsEnglish[i];
        *tTeacherVector[i].cLevel = studentsCLevel[i];
    }
}


void readStudent(tStudent * tStudentVector){
    
    /*
    ReadStudent infromation from terminal
    and update data to Student tuple vector.

    Input)

    tStudentVector tStudent: Original Student Information
    */

    

}
