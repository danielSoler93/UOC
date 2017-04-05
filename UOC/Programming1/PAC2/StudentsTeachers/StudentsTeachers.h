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
	tTeacher teacher[3];
} tTeacherVector;

typedef struct
{
	tStudent student[5];
} tStudentVector;


/*Pre-declaration of actions and functions*/

void fillTeachersVector(tTeacherVector* teachers);

void readStudent(int dni, bool bEnglish, char cLevel, tStudent * student);

void updateTeacherStudent(tTeacherVector *teacher, tStudent *student);

void writeStudent(tStudent * student);


/* Implementation of actions and functions*/