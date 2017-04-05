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
#include "StudentsTeachers.h"


/*Application headers file*/


/*Symboli constants*/

/*User defined types*/



/*Pre-declaration of actions and functions*/



/* Implementation of actions and functions*/

void fillTeachersVector(tTeacherVector* teachers){
    
    /*
    Initialize Teacher's information
    
    Parameters:
    ------------
    Input)
        tTeacherVector teacher: Original Teachers Info
    */

    int teachersId[] = {1,2,3,4};
    bool teachersEnglish[] = {true, false, true, false};
    char teachersCLevel[] = {'P', 'P', 'S', 'S'};
    int vectorsLenght = strlen(teachersCLevel);
    int readPos;

    for (readPos=0; readPos<vectorsLenght; readPos++){
        (*teachers).teacher[readPos].idTeacher = teachersId[readPos];
        (*teachers).teacher[readPos].bEnglish = teachersEnglish[readPos];
        (*teachers).teacher[readPos].cLevel = teachersCLevel[readPos];
		//NOT WORKING??? 
    }
}


void readStudent(int dni, bool bEnglish, char cLevel, tStudent * student){
    
    /*
    ReadStudent infromation from standard entry
    and update data to Student tuple vector.
    Input)
    tStudentVector tStudent: Original Students Information
    */
    (*student).dni = dni;
	(*student).bEnglish = bEnglish;
	(*student).cLevel = cLevel;
	


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
    
    bool found = false;
    int vectorLenght = 4;
    int vectorPos;
    for (vectorPos=0; vectorPos<vectorLenght; vectorPos++){
        if ((*teacher).teacher[vectorPos].bEnglish == (*student).bEnglish && (*teacher).teacher[vectorPos].cLevel == (*student).cLevel){
            (*student).idTeacher = (*teacher).teacher[vectorPos].idTeacher;
            found = true;
        }
    }
    if (!found){
        (*student).idTeacher = -1;
    }
}

void writeStudent(tStudent* student){
    printf("The Student dni is: %d\n", (*student).dni);
    printf("The TeacherID assigned to the Student is: %d\n", (*student).idTeacher);
}