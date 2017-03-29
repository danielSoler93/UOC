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

typedef struct
{
   tTeacher teacher[4];
} tTeacherVector;

typedef struct
{
   tStudent student[6];
} tStudentVector;



/*Pre-declaration of actions and functions*/

void fillTeachersVecotor(tTeacherVector * tTeacherVector);

void readStudent(tStudentVector * tStudentVector);

void updateTeacherStudent(tTeacherVector *tTeacherVector, tStudent *Student);


/* Implementation of actions and functions*/
