/**************************************************************
*
** File:        main.c
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        29-03-2017
** Description:
*   """
*   Create a group of teachers
*   and a Student. Afterwards, 
*   finds out which teacher is 
*   more suitable for the level
*   student.
*   """
*
*****************************************************************/

/* System header files */
#include <stdio.h>
#include <stdlib.h>
#include "StudentsTeachers.h"

/*Application headers file*/


/*Symboli constants*/

/*User defined types*/




/*Pre-declaration of actions and functions*/

int main(int argc, char **argv)
{
   //Create Teachers Vector
    tTeacherVector teachers;
    //Initialize Teachers Vector
    fillTeachersVector(&teachers);
   //Create Student
   tStudentVector student;
   //Initialize Student
   readStudent(&student);
   //Find teacher for student
   updateTeacherStudent(&teachers, &student);
   //write ID from student an associate teacher
   writeStudent(&student);    


return 0;

}


/* Implementation of actions and functions*/