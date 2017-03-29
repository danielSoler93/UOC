     /**************************************************************
*
** File:        StudentTeachers.h
** Author:      Daniel Soler (www.github.com/miniaoshi)
** Date:        29-03-2017
** Description:
*   """
*   Type definition library
*   with several init
*   functions.
*   """
*
*****************************************************************/

/* System header files */


/*Application headers file*/


/*Symboli constants*/

/*User defined types*/
typedef enum { false, true } bool;

typedef struct
{
   int idTeacher;
   bool bEnglish;
   char cLevel;
} tTeacher;

typedef struct
{
   int dni;
   bool bEnglish;
   char cLevel;
   int idTeacher;
} tStudent;

tTeacher tTeacherVector[4];

tStudent tStudentVector[6];


/*Pre-declaration of actions and functions*/

void fillTeachersVecotor(tTeacher * tTeacherVector);

void readStudent(tStudent * tStudentVector);


/* Implementation of actions and functions*/
