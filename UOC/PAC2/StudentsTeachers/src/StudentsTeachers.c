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

void fillTeachersVector(tTeacherVector * tTeacherVector){
    
    /*
    Initialize Teacher's information
    
    Parameters:
    ------------

    Input)

        tTeacherVector tTeacher: Original Teachers Info
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


void readStudent(tStudentVector * tStudentVector){
    
    /*
    ReadStudent infromation from terminal
    and update data to Student tuple vector.

    Input)

    tStudentVector tStudent: Original Students Information
    */
    printf('Enter Student ID\n')
    scnaf("%d", &tStudentVector.dni);

    printf('Is the student native (n=0/y=0)\n')
    scnaf("%d", &tStudentVector.bEnglish);    

    printf('Which level the student has (P/S)\n')
    tStudentVector.cLevel = getchar();


}

void updateTeacherStudent(tTeacherVector *teacher, tStudent *student){
    
    /*
    Look for Student English and subject Level
    iterate over professors to find out which
    one of them is suitable for him.
    Otherwise, wirte -1 to Student.idteacher.

    Input)

    teacher *tTeacherVector: Teachers information

    student *tStudent: Student information

    Output) 

    student *tstudent: Student id teacher updated
    */
    
    bool bEnglish = *student.bEnglish;
    bool found = false;
    char cLevel = *student.cLevel;
    int vectorLenght = strlen(*teacher);
    int vectorPos;
    for (vectorPos=0; vectorPos<vectorLenght; vectorPos++){
        if (*teacher[i].bEnglish == *student.bEnglish && *teacher[i].cLevel == *student.cLevel){
            *student.idTeacher == *teacher[i].idTeacher;
            found = true;
        }
    }
    if (!found){
        *student.idTeacher = -1;
    }
}
