/**
 * Implementació en C de la pràctica, per a què tingueu una
 * versió funcional en alt nivell de totes les funcions que heu 
 * d'implementar en assemblador.
 * Des d'aquest codi es fan les crides a les subrutines de assemblador. 
 * AQUEST CODI NO ES POT MODIFICAR I NO S'HA DE LLIURAR.
 **/
 
#include <stdio.h>
#include <termios.h>    //termios, TCSANOW, ECHO, ICANON
#include <unistd.h>     //STDIN_FILENO

/**
 * Constants
 */
#define DimMatrix  10     //dimensió de la matriu
#define SizeMatrix DimMatrix*DimMatrix //=100

extern int developer;	//Variable declarada en assemblador que indica el nom del programador

/**
 * Definició de variables globals
 */
// Matriu 10x10 on posem les mines (Hi han 20 mines marcades)
char mines[DimMatrix][DimMatrix] = { {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ','*',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ','*',' ','*',' ',' ',' ',' '},
                                     {' ','*','*','*','*','*','*','*',' ',' '},
                                     {' ',' ',' ','*',' ','*',' ',' ',' ',' '},
                                     {' ',' ','*','*','*','*','*','*',' ',' '},
                                     {' ',' ',' ','*',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ','*'} };

// Matriu 10x10 on s'indiquen les mines marcades (Hi han 2 mines marcades)
// i el nombre de mines de les posicions obertes.(Hi han 4 posicions obertes)              
char marks[DimMatrix][DimMatrix] = { {'0',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {'1',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {'1','M',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {'2',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                     {' ',' ',' ',' ',' ',' ',' ',' ',' ','M'} };

           
/**
 * Definició de les subrutines d'assemblador que es criden des de C
 */
extern char printMenuP2();
extern void printBoardP2();

extern void posCurScreenP2(int[2]);
extern void showMinesP2(int);
extern void updateBoardP2(int);

extern void moveCursorP2(int[2], char);
extern int  calcIndexP2(int[2]);
extern int  mineMarkerP2(int[2], int);
extern int  searchMinesP2(int[2], int);
extern int  checkEndP2(int, int);
extern int  playP2(int);

/**
 * Definició de les funcions de C
 */
void clearscreen_C();
void gotoxyP2_C(int, int);
void printchP2_C(char);
char getchP2_C();

char printMenuP2_C();
void printBoardP2_C();

void posCurScreenP2_C(int[2]);
void showMinesP2_C(int);
void updateBoardP2_C(int);

void moveCursorP2_C(int[2], char);
int  mineMarkerP2_C(int[2], int);
int  searchMinesP2_C(int[2], int);
int  checkEndP2_C(int, int);

void printMessageP2_C(int);
int  playP2_C(int);


/**
 * Esborrar la pantalla
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * Cap
 *   
 * Paràmetres de sortida: 
 * Cap
 * 
 * Aquesta funció no es crida des d'assemblador
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
void clearScreen_C(){
	
    printf("\x1B[2J");
    
}


/**
 * Situar el cursor en una fila i una columna de la pantalla
 * en funció de la fila (rowCurcreen) i de la columna (colCurScreen) 
 * rebuts com a paràmetre.
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * rowCurScreen  : rdi(edi): Fila
 * colCurScreen  : rsi(esi): Columna
 * 
 * Paràmetres de sortida: 
 * Cap
 * 
 * S'ha definit un subrutina en assemblador equivalent 'gotoxyP2' 
 * per a poder cridar aquesta funció guardant l'estat dels registres 
 * del processador. Això es fa perquè les funcions de C no mantenen 
 * l'estat dels registres.
 * El pas de paràmetres és equivalent.
 */
void gotoxyP2_C(int rowCurScreen, int colCurScreen){
	
   printf("\x1B[%d;%dH",rowCurScreen,colCurScreen);
   
}


/**
 * Mostrar un caràcter (c) a la pantalla, rebut com a paràmetre, 
 * en la posició on està el cursor.
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * c        : rdi(dil): Caràcter que volem mostrar
 * 
 * Paràmetres de sortida: 
 * Cap
 * 
 * S'ha definit un subrutina en assemblador equivalent 'printchP2' 
 * per a cridar aquesta funció guardant l'estat dels registres del 
 * processador. Això es fa perquè les funcions de C no mantenen 
 * l'estat dels registres.
 * El pas de paràmetres és equivalent.
 */
void printchP2_C(char c){
	
   printf("%c",c);
   
}


/**
 * Llegir una tecla i retornar el caràcter associat 
 * sense mostrar-lo per pantalla. 
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * Cap
 * 
 * Paràmetres de sortida: 
 * c        : rax(al): Caràcter llegit de teclat
 * 
 * S'ha definit un subrutina en assemblador equivalent 'getchP2' per a
 * cridar aquesta funció guardant l'estat dels registres del processador.
 * Això es fa perquè les funcions de C no mantenen l'estat dels 
 * registres.
 * El pas de paràmetres és equivalent.
 */
char getchP2_C(){

   int c;   

   static struct termios oldt, newt;

   /*tcgetattr obtenir els paràmetres del terminal
   STDIN_FILENO indica que s'escriguin els paràmetres de l'entrada estàndard (STDIN) sobre oldt*/
   tcgetattr( STDIN_FILENO, &oldt);
   /*es copien els paràmetres*/
   newt = oldt;

   /* ~ICANON per a tractar l'entrada de teclat caràcter a caràcter no com a línia sencera acabada amb /n
      ~ECHO per a què no mostri el caràcter llegit*/
   newt.c_lflag &= ~(ICANON | ECHO);          

   /*Fixar els nous paràmetres del terminal per a l'entrada estàndard (STDIN)
   TCSANOW indica a tcsetattr que canvii els paràmetres immediatament. */
   tcsetattr( STDIN_FILENO, TCSANOW, &newt);

   /*Llegir un caràcter*/
   c=getchar();                 
    
   /*restaurar els paràmetres originals*/
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

   /*Retornar el caràcter llegit*/
   return (char)c;
   
}


/**
 * Mostrar a la pantalla el menú del joc i demanar una opció.
 * Només accepta una de les opcions correctes del menú ('0'-'9')
 * 
 * Variables globals utilitzades:	
 * developer:((char *)&developer): variable definida en el codi assemblador.
 * 
 * Paràmetres d'entrada : 
 * Cap
 * 
 * Paràmetres de sortida: 
 * c        : rax(al): Opció triada del menú, llegida de teclat.
 * 
 * Aquesta funció no es crida des d'assemblador
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
char printMenuP2_C(){
	char c = ' ';
	
	clearScreen_C();
    gotoxyP2_C(1,1);
    printf("                                     \n");
    printf("            Developed by:            \n");
	printf("         ( %s )   \n",(char *)&developer);
    printf(" ___________________________________ \n");
    printf("|                                   |\n");
    printf("|          MENU MINESWEEPER         |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|          1. posCurScreen          |\n");
    printf("|          2. showMines             |\n");
    printf("|          3. updateBoard           |\n");
    printf("|          4. moveCursor            |\n");
    printf("|          5. mineMarker            |\n");
    printf("|          6. searchMines           |\n");
    printf("|          7. checkEnd              |\n");
    printf("|          8. Play Game             |\n");
    printf("|          9. Play Game C           |\n");
    printf("|          0. Exit                  |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|             OPTION:               |\n");
    printf("|___________________________________|\n"); 
    
    while (c < '0' || c > '9') {
      gotoxyP2_C(21,23);      //Posicionar el cursor
	  c = getchP2_C();        //Llegir una opció
	  printchP2_C(c);         //Mostrar opció 
	}
	return c;
}


/**
 * Mostrar el tauler de joc a la pantalla. Les línies del tauler.
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * Cap
 * 
 * Paràmetres de sortida: 
 * Cap
 * 
 * Aquesta funció es crida des de C i des d'assemblador,
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
void printBoardP2_C(){

   gotoxyP2_C(1,1);
   printf(" _____________________________________________ \n");	//01
   printf("|                                             |\n");	//02
   printf("|                  MINESWEEPER                |\n");	//03
   printf("|_____________________________________________|\n");	//04
   printf("|     0   1   2   3   4   5   6   7   8   9   |\n");	//05
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//06
   printf("| 0 |   |   |   |   |   |   |   |   |   |   | |\n");	//07
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//08
   printf("| 1 |   |   |   |   |   |   |   |   |   |   | |\n");	//09
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//10
   printf("| 2 |   |   |   |   |   |   |   |   |   |   | |\n");	//11
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//12
   printf("| 3 |   |   |   |   |   |   |   |   |   |   | |\n");	//13
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//14
   printf("| 4 |   |   |   |   |   |   |   |   |   |   | |\n");	//15
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//16
   printf("| 5 |   |   |   |   |   |   |   |   |   |   | |\n");	//17
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//18
   printf("| 6 |   |   |   |   |   |   |   |   |   |   | |\n");	//19
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//20
   printf("| 7 |   |   |   |   |   |   |   |   |   |   | |\n");	//21
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//22
   printf("| 8 |   |   |   |   |   |   |   |   |   |   | |\n");	//23
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//24
   printf("| 9 |   |   |   |   |   |   |   |   |   |   | |\n");	//25
   printf("|   +---+---+---+---+---+---+---+---+---+---+ |\n");	//26
   printf("|     Mines to  Mark: __                      |\n");	//27
   printf("|_____________________________________________|\n");	//28
   printf("|   (m)Mark Mine    (Space)Open  (ESC)Exit    |\n"); //29
   printf("|   (i)Up    (j)Left    (k)Down    (l)Right   |\n"); //30
   printf("|_____________________________________________|\n");	//31
   
}


/**
 * Posicionar el cursor a la pantalla dins del tauler, en funció del 
 * vector (rowcol), posició del cursor dins del tauler, vector que es rep
 * com a paràmetre i anomenem (rc) (fila rc[0] i columna rc[1]).
 * Per a calcular la posició del cursor a pantalla utilitzar 
 * aquestes fórmules:
 * rowScreen=(rc[0]*2)+7
 * colScreen=(rc[1]*4)+7
 * Per a posicionar el cursor es cridar a la funció gotoxyP2_C.
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * rc : rdi  : Adreça del vector de 2 posicions on guardem la fila 
 *             (rc[0]) i la columna (rc[1]) del cursor dins del tauler.
 * 
 * Paràmetres de sortida: 
 * Cap
 * 
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'posCurScreenP2',  
 * el pas de paràmetres és equivalent. 
 */
 void posCurScreenP2_C(int rc[2]) {
   
   int rowScreen, colScreen;
   rowScreen=(rc[0]*2)+7;
   colScreen=(rc[1]*4)+7;
   gotoxyP2_C(rowScreen, colScreen);
   
}


/**
 * Converteix el valor del nombre de mines que queden per marcar (nMines)
 * que es rep com a paràmetre (entre 0 i 99) en dos caràcters ASCII. 
 * S'ha de dividir el valor (nMines) entre 10, el quocient representarà 
 * les desenes i el residu les unitats, i després s'han de convertir a 
 * ASCII sumant 48, caràcter '0'.
 * Mostra els dígits (caràcter ASCII) de les desenes a la fila 27, 
 * columna 23 de la pantalla i les unitats a la fila 27, columna 24.
 * Per a posicionar el cursor es cridar a la funció gotoxyP2_C i per a 
 * mostrar els caràcters a la funció printchP2_C.
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * nMines : rdi(edi) :Nombre de mines que queden per marcar.
 * 
 * Paràmetres de sortida: 
 * Cap
 * 
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'showMinesP2',  
 * el pas de paràmetres és equivalent.
 */
 void showMinesP2_C(int nMines) {
	
	char digit;
	
	digit = nMines/10;//Decenes
	digit = digit + '0';
	gotoxyP2_C(27, 23);   
	printchP2_C(digit);

	digit = nMines%10;//Unitats
	digit = digit + '0';
	gotoxyP2_C(27, 24);   
	printchP2_C(digit);
	
}


/**
 * Actualitzar el contingut del Tauler de Joc amb les dades de la matriu 
 * (marks) i el nombre de mines que queden per marcar que es rep
 * com a paràmetre i anomenem (nMines).
 * S'ha de recórrer tota la matriu (marks), i per a cada element de la 
 * matriu posicionar el cursor a la pantalla i mostrar els caràcters de
 * la matriu. 
 * Després mostra el valor de (nMines) a la part inferior del tauler.
 * Per a posicionar el cursor es crida a la funció gotoxyP2_C, 
 * per a mostrar els caràcters es crida a la funció printchP2_C i per 
 * a mostrar el nombre de mines es crida a la funció ShowMinesP2_C.
 * 
 * Variables globals utilitzades:	
 * marks  : Matriu amb les mines marcades i les mines de les obertes.
 * 
 * Paràmetres d'entrada : 
 * nMines : rsi(esi) : Nombre de mines que queden per marcar.
 * 
 * Paràmetres de sortida: 
 * Cap
 *  
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'updateBoardP2', 
 * el pas de paràmetres és equivalent.
 */
void updateBoardP2_C(int nMines){

   int rowScreen, colScreen;
   int i,j;
   
   rowScreen = 7;
   for (i=0;i<DimMatrix;i++){
	  colScreen = 7;
      for (j=0;j<DimMatrix;j++){
         gotoxyP2_C(rowScreen,colScreen);
         printchP2_C(marks[i][j]);
         colScreen = colScreen + 4;
      }
      rowScreen = rowScreen + 2;
   }
   showMinesP2_C(nMines);//Mostrar nombre de mines que queden per marcar
   
}


/**
 * Actualitzar la posició del cursor al tauler que tenim al vector 
 * (rowcol), que es rep com a paràmetre i anomenem (rc) (fila (rc[0]) i 
 * columna (rc[1])) en funció a la tecla premuda, que també rebem com a 
 * paràmetre i anomenem (c).
 * Si es surt fora del tauler no actualitzar la posició del cursor.
 * (i:amunt, j:esquerra, k:avall, l:dreta)
 * ( rc[0] = rc[0] +/- 1 ) ( rc[1] = rc[1] +/- 1 ) 
 * No s'ha de posicionar el cursor a la pantalla.
 *  
 * Variables globals utilitzades:	
 * Cap   
 * 
 * Paràmetres d'entrada : 
 * rc : rdi      : Adreça del vector de 2 posicions on guardem la fila 
 *                 (rc[0]) i la columna (rc[1]) del cursor dins del tauler.
 * c  : rsi(sil) : Caràcter llegit de teclat 
 * 
 * Paràmetres de sortida: 
 * Cap
 * 
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'moveCursorP2', 
 * el pas de paràmetres és equivalent.
 */
void moveCursorP2_C(int rc[2], char c){
 
   switch(c){
      case 'i': //amunt
         if (rc[0]>0) rc[0]--;
      break;
      case 'j': //esquerra
         if (rc[1]>0) rc[1]--;
      break;
      case 'k': //avall
         if (rc[0]<DimMatrix-1) rc[0]++;
      break;
      case 'l': //dreta
		 if (rc[1]<DimMatrix-1) rc[1]++;
      break;     
	}
	
}


/**
 * Marcar/desmarcar una mina a la matriu (marks) a la posició actual del
 * cursor, indicada pel vector(rowcol), que es rep com a paràmetre i 
 * anomenem (rc) (fila (rc[0]) i columna (rc[1])).
 * Si en aquella posició de la matriu (marks) hi ha un espai en blanc i 
 * no hem marcat totes les mines, marquem una mina posant una 'M' 
 * i decrementem el nombre de mines que queden per marcar (numMines), 
 * que es rep com a paràmetre i anomenem (nMines), si en aquella posició
 * de la matriu (marks) hi ha una 'M', posarem un espai (' ') i 
 * incrementem el nombre de mines que queden per marcar (nMines).
 * Si hi ha un altre valor no canviarem res.
 * Retornar el nombre de mines que queden per marcar actualitzat (nMines).
 * No s'ha de mostrar la matriu, només actualitzar la matriu (marks) i 
 * la variable (nMines).
 * 
 * Variables globals utilitzades:	
 * marks  : Matriu amb les mines marcades i les mines de les obertes.
 * 
 * Paràmetres d'entrada : 
 * rc     : rdi      : Adreça del vector de 2 posicions on guardem la fila 
 *                     (rc[0]) i la columna (rc[1]) del cursor dins del tauler.
 * nMines : rsi(esi) : Nombre de mines que queden per marcar.
 * 
 * Paràmetres de sortida: 
 * nMines : rax(eax) : Nombre de mines que queden per marcar.
 * 
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'mineMarkerP2', 
 * el pas de paràmetres és equivalent.
 */
int mineMarkerP2_C(int rc[2], int nMines) {
	
	int row = rc[0];
	int col = rc[1];
	
	if (marks[row][col] == ' ' && nMines > 0) {
		marks[row][col] = 'M';
		nMines--;
	} else {
		if (marks[row][col] == 'M') {
			marks[row][col] = ' ';
			nMines++;
		}
	}	
	return nMines;
} 
 

/**
 * Obrir casella. Mirar quantes mines hi ha al voltant de la posició 
 * actual del cursor, indicada pel vector (rowcol) que es rep com a 
 * paràmetre i anomenem (rc) (fila (rc[0]) i columna (rc[1])), de la 
 * matriu (mines).
 * Si a la posició actual de la matriu (marks) hi ha un espai (' ') 
 *   Mirar si a la matriu (mines) hi ha una mina ('*').
 *   Si hi ha una mina canviar l'estat (state), que es rep com a 
 *     paràmetre i anomenem (status) a 3 "Explosió", per a sortir.
 *	 Sinó, comptar quantes mines hi ha al voltant de la posició 
 *     actual i actualitzar la posició de la matriu (marks) amb 
 *     el nombre de mines (caràcter ASCII del valor, per fer-ho, cal 
 *     sumar 48 ('0') al valor).
 * Sinó hi ha un espai, vol dir que hi ha una mina marcada ('M') o la 
 * casella ja s'ha obert (hi ha el nombre de mines que ja s'ha calculat 
 * anteriorment), no fer res.
 * Retornar l'estat del joc actualitzat (status).
 * No s'ha de mostrar la matriu.
 *  
 * Variables globals utilitzades:	
 * marks  : Matriu amb les mines marcades i les mines de les obertes.
 * mines  : Matriu on posem les mines.
 * 
 * Paràmetres d'entrada : 
 * rc    : rdi      : Adreça del vector de 2 posicions on guardem la fila 
 *                    (rc[0]) i la columna (rc[1]) del cursor dins del tauler.
 * status: rsi(esi) : Estat del joc. 
 * 
 * Paràmetres de sortida: 
 * status : rax(eax) : Estat del joc. 
 *  
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'searchMinesP2', 
 * el pas de paràmetres és equivalent.
 */
int searchMinesP2_C(int rc[2], int status) {
	
	char digit = 0;
	int  row = rc[0];
	int  col = rc[1];
	
	if (marks[row][col]==' ') {
		if (mines[row][col]!=' ') {
			status = 3;
		} else {
			if (row > 0) { 
				if (col > 0) {
					if (mines[row-1][col-1]=='*') digit++; //UpLeft
				}
				if (mines[row-1][col]=='*') digit++;       //UpCenter
				if (col < DimMatrix-1) {
					if (mines[row-1][col+1]=='*') digit++; //UpRight
				}
			}
			if (col > 0) {
				if (mines[row][col-1]=='*') digit++;       //LeftCenter
			}
			if (col < DimMatrix-1) {
				if (mines[row][col+1]=='*') digit++;       //RightCenter
			}
			if (row < DimMatrix-1) { 
				if (col > 0) {
					if (mines[row+1][col-1]=='*') digit++; //DownLeft
				}
				if (mines[row+1][col]=='*') digit++;       //DownCenter
				if (col < DimMatrix-1) {
					if (mines[row+1][col+1]=='*') digit++; //DownRight
				}
			}
			marks[row][col] = digit+'0';
		}
	}
	return status;
} 

 


/**
 * Verificar si hem marcat totes les mines (numMines=0), que es rep com 
 * a paràmetre i anomenem (nMines) i hem obert o marcat amb una mina 
 * totes  les altres caselles i no hi ha cap espai en blanc (' ') 
 * a la matriu (marks), si és així, canviar l'estat (state) que es rep 
 * com a paràmetre i anomenem (status), a 2 "Guanya".
 * Retornar l'estat del joc actualitzat (status).
 * 
 * Variables globals utilitzades:	
 * marks  : Matriu amb les mines marcades i les mines de les obertes.
 * 
 * Paràmetres d'entrada : 
 * nMines : rdi(edi) : Nombre de mines que queden per marcar.
 * staus  : rsi(esi) : Estat del joc. 
 * 
 * Paràmetres de sortida: 
 * staus  : rax(eax) : Estat del joc. 
 *  
 * Aquesta funció no es crida des d'assemblador.
 * A la subrutina d'assemblador equivalent 'checkEndP2', 
 * el pas de paràmetres és equivalent.
 */
int checkEndP2_C(int nMines, int status) {
	
	char notOpenMarks = 0;
	int i,j;
	
	if (nMines == 0) {
		for (i=0;i<DimMatrix;i++){
			for (j=0;j<DimMatrix;j++){
				if (marks[i][j] == ' ') notOpenMarks++;
			}
		}
		if (notOpenMarks == 0) {
			status = 2;
		}
	}
	return status;
} 


/**
 * Mostrar un missatge a sota del tauler segons el valor de la variable 
 * (state) que es rep com a paràmetre i anomenem (status).
 * status: 0: Hem premut la tecla 'ESC' per a sortir del joc.
 * 		   1: Continuem jugant.
 * 		   2: Guanya, s'han marcat totes les mines i s'han obert la resta de posicions.
 * 		   3: Explosió, s'ha obert una mina.
 * S'espera que es premi una tecla per a continuar.
 *  
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * staus  : rsi(esi) : Estat del joc. 
 * 
 * Paràmetres de sortida: 
 * Cap
 *   
 * Aquesta funció es crida des de C i des d'assemblador,
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
void printMessageP2_C(int status) {

   gotoxyP2_C(27,30);
   
   switch(status){
      case 0:
         printf("<< EXIT: ESC >>");
        break;
      case 2:
         printf("++ YOU WIN ! ++");
      break;
      case 3:
         printf("-- BOOOM !!! --");
      break;
   }
   getchP2_C();				//Espera que l'usuari premi una tecla.
   
}
 

/**
 * Joc del Buscamines
 * Funció principal del joc
 * Permet jugar al joc del buscamines cridant totes les funcionalitats.
 *
 * Pseudo codi:
 * Inicialitzar estat del joc, (state=1)
 * Inicialitzar fila i columna, posició inicial, (rowcol[0]=4) i (rowcol[1]=4)
 * Mostrar el tauler de joc (cridar la funció PrintBoardP2_C).
 * Mentre (state=1) fer:
 *   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
 *     queden per marcar (cridar la funció updateBoardP2_C).
 *   Posicionar el cursor dins del tauler (cridar la funció posCurScreenP2_C.
 *   Llegir una tecla i guardar-la a la variable local (c). 
 *   Segons la tecla llegida cridarem a la funció corresponent.
 *     - ['i','j','k' o 'l']      (cridar a la funció MoveCursorP2_C).
 *     - 'x'                      (cridar a la funció MineMarkerP2_C).
 *     - '<espai>'(codi ASCII 32) (cridar a la funció SearchMinesP2_C).
 *     - '<ESC>'  (codi ASCII 27) posar (state = 0) per a sortir.   
 *   Verificar si hem marcat totes les mines i si hem obert totes  
 *     les altres caselles (cridar a la funció CheckEndP2_C).
 * Fi mentre.
 * Sortir:
 *   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
 *   queden per marcar (cridar la subrutina updateBoardP2_C).
 *   Mostrar missatge de sortida que correspongui (cridar a la funció
 *   printMessageP2_C).
 * S'acabat el joc.
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Paràmetres d'entrada : 
 * nMines : rdi(edi) : Nombre de mines que queden per marcar.
 * 
 * Paràmetres de sortida: 
 * nMines : rax(eax) : Nombre de mines que queden per marcar.
 */
int playP2_C(int nMines){
/**
 * Definició de variables locals.
 */
   int  rowcol[2];	//vector de dos posicions de tipus int on tenim la 
					//fila (rowcol[0]) i la columna (rowcol[1]) per a 
                    //accedir a les matrius mines i marks i per a 
                    //indicar fila i columna del cursor dins del tauler.


   int numMines = nMines; 	//Nombre de mines que queden per marcar.
 
   int state = 1;	// 0: Sortir, hem premut la tecla 'ESC' per a sortir.
					// 1: Continuem jugant.
					// 2: Guanyat, s'han marcat totes les mines i hem obert la resta de posicions. 
					// 3: Explosió, hem obert una mina.
   char c;

   printBoardP2_C();

   rowcol[0]=  4;	//Posició inicial del cursor.
   rowcol[1] = 4;      
          
   while (state == 1) {  //bucle principal.  
	 updateBoardP2_C(numMines);
	 posCurScreenP2_C(rowcol);
     
     c = getchP2_C();	//llegir una tecla i guardar-la a la variable charac.
	
     if (c>='i' && c<='l') {      //Moure cursor
       moveCursorP2_C(rowcol, c);
     }
     if (c=='m') {                //Marcar mina
       numMines = mineMarkerP2_C(rowcol, numMines);
     }
     if (c==' ') {                //Mirar mines 
       state = searchMinesP2_C(rowcol, state);
     }
     if (c==27) {                 //Sortir del programa
       state = 0;
     }
     state = checkEndP2_C(numMines, state);
   }
   updateBoardP2_C(numMines);
   printMessageP2_C(state);	//Mostrar el missatge per a indicar com acaba.
   
   return numMines;
}


/**
 * Programa Principal
 * 
 * ATENCIÓ: A cada opció es crida a una subrutina d'assemblador.
 * A sota hi ha comentada la funció en C equivalent que us donem feta 
 * per si voleu veure com funciona.
 */
int main(void){   
/**
 * Definició de variables locals.
 */
   int  rowcol[2];	//vector de dos posicions de tipus int on tenim la 
					//fila (rowcol[0]) i la columna (rowcol[1]) per a 
                    //accedir a les matrius mines i marks i per a 
                    //indicar fila i columna del cursor dins del tauler.


   int numMines = 18; 	// Nombre de mines que queden per marcar.
 
   int state = 1;	// 0: Sortir, hem premut la tecla 'ESC' per a sortir.
					// 1: Continuem jugant.
					// 2: Guanyat, s'han marcat totes les mines i hem obert la resta de posicions. 
					// 3: Explosió, hem obert una mina.

   int op=1;
   char c;
     
   while (op!='0') {
	  clearScreen_C();
      op = printMenuP2_C();		  //Mostrar menú i llegir opció
      
      switch(op){
         case '1':// Posicionar el cursor al tauler
            printf(" %c",op);
            clearScreen_C();  //Esborrar la pantalla
            printBoardP2_C();   //Mostrar el tauler
            gotoxyP2_C(27,30);
            printf(" Press any key ");
            //=======================================================
            rowcol[0]=1;  //Fila i columna on es posiciona el cursor
            rowcol[1]=1;
            posCurScreenP2(rowcol);
            //posCurScreenP2_C(rowcol);
            //=======================================================
            getchP2_C();
         break;
         case '2': //Mostrar nombre de mines que queden per marcar
            printf(" %c",op);
            clearScreen_C();  //Esborrar la pantalla
            printBoardP2_C();   //Mostrar el tauler
            //=======================================================
            showMinesP2(numMines);
            //showMinesP2_C(numMines);  //Actualitzar nombre de mines
            //=======================================================
            gotoxyP2_C(27,30);
            printf("Press any key ");
            getchP2_C();
         break;
         case '3': //Mostrar el tauler i actualitzar el contingut
            printf(" %c",op);
            clearScreen_C();    //Esborrar la pantalla
            printBoardP2_C();   //Mostrar el tauler
            //=======================================================
            updateBoardP2(numMines);
            //updateBoardP2_C(numMines);  //Actualitzar el contingut del tauler
            //=======================================================
            gotoxyP2_C(27,30);
            printf("Press any key ");
            getchP2_C();
         break;
         case '4': //Moure el cursor
            clearScreen_C();  //Esborrar la pantalla
            printBoardP2_C(); //Mostrar el tauler
            printf("\n    Move cursor: i:Up, j:Left, k:Down, l:Right ");
            rowcol[0]=2;  //Fila i columna on es posiciona el cursor
            rowcol[1]=2;
            posCurScreenP2_C(rowcol);
            c = getchP2_C();	
            gotoxyP2_C(27,30);
			printf("Press any key ");
	        if (c >= 'i' && c <= 'l') { 
				//===================================================
				moveCursorP2(rowcol, c);
				//moveCursorP2_C(rowcol, c);
				//===================================================
				posCurScreenP2_C(rowcol);
            } else {
				printf("\n       Incorrect option                         ");
			}
            getchP2_C();
         break;
         case '5': //Marcar Mina
            clearScreen_C();  //Esborrar la pantalla
            printBoardP2_C(); //Mostrar el tablero
            printf("\n      Mark a Mine: m:mark/unmark");
            updateBoardP2_C(numMines);  
            rowcol[0]=3;      //Fila i columna on es posiciona el cursor
            rowcol[1]=3;
            posCurScreenP2_C(rowcol);
            c = getchP2_C();
   			if (c=='m') {
			    //===================================================
            	numMines = mineMarkerP2(rowcol, numMines);
				//numMines = mineMarkerP2_C(rowcol, numMines);
				//===================================================
                updateBoardP2_C(numMines);  
			} else {
				printf("\n       Incorrect option                         ");
			}
			gotoxyP2_C(27,30);
			printf("Press any key ");
			getchP2_C();
         break;
         case '6': //Comptar cuantes mines hi ha al voltant d'una posició
            clearScreen_C();  //Esborrar la pantalla
            printBoardP2_C(); //Mostrar el tauler
            printf("\n     Press SPACE ");
            updateBoardP2_C(numMines);
            c = getchP2_C();
            if (c==' ') {
			  rowcol[0]=5;  //Fila i columna no es posiciona el cursor
			  rowcol[1]=4;
			  posCurScreenP2_C(rowcol);
			  //===================================================
			  state = searchMinesP2(rowcol, state);
			  //state = searchMinesP2_C(rowcol, state);
			  //===================================================
			  updateBoardP2_C(numMines);  
			  printMessageP2_C(state);
			} else {
				printf("\n       Incorrect option                         ");
				gotoxyP2_C(27,30);
			    printf("Press any key ");
			getchP2_C();
			}
			state=1;
          break;
          case '7': //Moure cursor
            clearScreen_C();  //Esborrar la pantalla
            printBoardP2_C(); //Mostrar el tauler
            updateBoardP2_C(numMines);
 			//===================================================
            state = checkEndP2(numMines, state);
			//state = checkEndP2_C(numMines, state);
			//===================================================
			printMessageP2_C(state);
			state=1;
         break;
          case '8': //Joc complet en assemblador
            clearScreen_C();  //Esborrar la pantalla
            //=======================================================
            numMines = playP2(numMines);
            //=======================================================
         break;
         case '9': //Joc complet en C
            clearScreen_C();  //Esborrar la pantalla
            //=======================================================
            numMines = playP2_C(numMines);
            //=======================================================
         break;
         case '0':
		 break;	 
      }
   }
   printf("\n\n");
   
   return 0;
}
