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

extern int developer;	//Variable declarada en assemblador que indica el nom del programador

/**
 * Constants
 */
#define DimMatrix  10    //dimensió de la matriu
#define SizeMatrix DimMatrix*DimMatrix  //=100

/**
 * Definició de variables globals
 */
int  rowScreen;	    //Fila per a posicionar el cursor a la pantalla.
int  colScreen;	    //Columna per a posicionar el cursor a la pantalla
int  rowcol[2];		//vector de dues posicions de tipus int on tenim la 
					//fila (rowcol[0]) i la columna (rowcol[1]) per a 
                    //accedir a les matrius mines i marks i per a 
                    //indicar fila i columna del cursor dins del tauler.
int  indexMat; 		//Índex per a accedir a les matrius mines i marks des d'assemblador.
char charac;        //Caràcter llegit de teclat i per a escriure a pantalla

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

// Matriu 10x10 on s'indiquen les mines marcades 'M'(Hi han 2 mines marcades)
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

int numMines = 18; 	// Nombre de mines que queden per marcar.
                    
int state    = 1;	// 0: Sortir, hem premut la tecla 'ESC' per a sortir.
					// 1: Continuem jugant.
					// 2: Guanyat, s'ha marcat totes les mines.
					

/**
 * Definició de les subrutines d'assemblador que es criden des de C
 */
extern void caclIndexMatP1();
extern void posCurScreenP1();
extern void showMinesP1();
extern void updateBoardP1();
extern void readActionP1();
extern void moveCursorP1();
extern void calcIndexP1();
extern void mineMarkerP1();
extern void checkMinesP1();
extern void playP1();

/**
 * Definició de les funcions de C
 */
void clearscreen_C();
void gotoxyP1_C();
void printchP1_C();
void getchP1_C();

void printMenuP1_C();
void printBoardP1_C();

void posCurScreenP1_C();
void showMinesP1_C();
void updateBoardP1_C();

void readActionP1_C();
void moveCursorP1_C();
void mineMarkerP1_C();
void checkMinesP1_C();

void printMessageP1_C();
void playP1_C();


/**
 * Esborrar la pantalla
 * 
 * Variables globals utilitzades:	
 * Cap
 * 
 * Aquesta funció no es crida des d'assemblador
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
void clearScreen_C(){
	
    printf("\x1B[2J");
    
}


/**
 * Situar el cursor a la fila indicada per la variable (rowScreen) i a 
 * la columna indicada per la variable (colScreen) de la pantalla.
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * 
 * S'ha definit un subrutina en assemblador equivalent 'gotoxyP1' per a 
 * poder cridar aquesta funció guardant l'estat dels registres del 
 * processador.
 * Això es fa perquè les funcions de C no mantenen l'estat dels registres.
 */
void gotoxyP1_C(){
	
   printf("\x1B[%d;%dH",rowScreen,colScreen);
   
}


/**
 * Mostrar un caràcter guardat a la variable (charac) a la pantalla, 
 * en la posició on està el cursor.
 * 
 * Variables globals utilitzades:	
 * charac   : Caràcter que volem mostrar.
 * 
 * S'ha definit un subrutina en assemblador equivalent 'printchP1' per a
 * cridar aquesta funció guardant l'estat dels registres del processador.
 * Això es fa perquè les funcions de C no mantenen l'estat dels registres.
 */
void printchP1_C(){

   printf("%c",charac);
   
}


/**
 * Llegir una tecla i guarda el caràcter associat a la variable (charac)
 * sense mostrar-lo per pantalla. 
 * 
 * Variables globals utilitzades:	
 * charac   : Caràcter que llegim de teclat.
 * 
 * S'ha definit un subrutina en assemblador equivalent 'getchP1' per a
 * cridar aquesta funció guardant l'estat dels registres del processador.
 * Això es fa perquè les funcions de C no mantenen l'estat dels 
 * registres.
 */
void getchP1_C(){

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
   charac = (char) getchar();                 
    
   /*restaurar els paràmetres originals*/
   tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
   
}


/**
 * Mostrar a la pantalla el menú del joc i demana una opció.
 * Només accepta una de les opcions correctes del menú ('0'-'9')
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * charac   : Caràcter que llegim de teclat.
 * developer:((char *)&developer): Variable definida en el codi assemblador.
 * 
 * Aquesta funció no es crida des d'assemblador
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
void printMenuP1_C(){
	clearScreen_C();
    rowScreen = 1;
    colScreen = 1;
    gotoxyP1_C();
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
    printf("|          5. calcIndexMat          |\n");
    printf("|          6. mineMarker            |\n");
    printf("|          7. checkMines            |\n");
    printf("|          8. Play Game             |\n");
    printf("|          9. Play Game C           |\n");
    printf("|          0. Exit                  |\n");
    printf("|___________________________________|\n");
    printf("|                                   |\n");
    printf("|             OPTION:               |\n");
    printf("|___________________________________|\n"); 
    
    charac=' ';
    while (charac < '0' || charac > '9') {
      rowScreen = 21;
      colScreen = 23;
      gotoxyP1_C();           //posicionar el cursor
	  getchP1_C();            //Llegir una opció
	  printchP1_C();		  //Mostrar opció
	}
	
}


/**
 * Mostrar el tauler de joc a la pantalla. Les línies del tauler.
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * numMines : Nombre de mines que queden per marcar.
 *  
 * Aquesta funció es crida des de C i des d'assemblador,
 * i no hi ha definida una subrutina d'assemblador equivalent.
 */
void printBoardP1_C(){

   rowScreen = 1;
   colScreen = 1;
   gotoxyP1_C();
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
 * vector (rowcol), posició del cursor dins del tauler, (fila rowcol[0] 
 * i columna rowcol[1] del cursor al tauler).
 * Per a calcular la posició del cursor a pantalla utilitzar 
 * aquestes fórmules:
 * rowScreen=(rowcol[0]*2)+7
 * colScreen=(rowcol[1]*4)+7
 * Per a posicionar el cursor es cridar a la funció gotoxyP1_C.
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * rowcol   : vector amb la fila i la columna del cursor dins del tauler.
 * 
 * Aquesta funció no es crida des d'assemblador.
 * Hi ha una subrutina en assemblador equivalent 'posCurScreenP1',  
 */
void posCurScreenP1_C() {

   rowScreen=(rowcol[0]*2)+7;
   colScreen=(rowcol[1]*4)+7;
   gotoxyP1_C();
   
}


/**
 * Converteix el valor del nombre de mines que queden per marcar (numMines)
 * (entre 0 i 99) en dos caràcters ASCII. 
 * S'ha de dividir el valor (numMines) entre 10, el quocient representarà 
 * les desenes i el residu les unitats, i després s'han de convertir a 
 * ASCII sumant 48, caràcter '0'.
 * Mostra els dígits (caràcter ASCII) de les desenes a la fila 27, 
 * columna 23 de la pantalla i les unitats a la fila 27, columna 24.
 * Per a posicionar el cursor es cridar a la funció gotoxyP1_C i per a mostrar 
 * els caràcters a la funció printchP1_C.
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * numMines : Nombre de mines que queden per marcar.
 * charac   : Caràcter a escriure a pantalla
 * 
 * Aquesta funció no es crida des d'assemblador.
 * Hi ha una subrutina en assemblador equivalent 'showMinesP1',  
 */
 void showMinesP1_C() {
	
	charac = numMines/10;//Decenes
	charac = charac + '0';
	rowScreen = 27;
	colScreen = 23;
	gotoxyP1_C();   
	printchP1_C();

	charac = numMines%10;//Unitats
	charac = charac + '0';
	colScreen = 24; 
	gotoxyP1_C();   
	printchP1_C();
	
}


/**
 * Actualitzar el contingut del Tauler de Joc amb les dades de la matriu 
 * (marks) i el nombre de mines que queden per a marcar.  
 * S'ha de recórrer tot la matriu (marks), i per a cada element de la matriu
 * posicionar el cursor a la pantalla i mostrar els caràcters de la matriu.
 * Després mostrar el valor de (numMines) a la part inferior del tauler.
 * Per a posicionar el cursor es cridar a la funció gotoxyP1_C, per a mostrar 
 * els caràcters a la funció printchP1_C i per a mostrar (numMines)  
 * a la funció ShowMinesP1_C.
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * charac   : Caràcter a escriure a pantalla.
 * marks    : Matriu amb les mines marcades i les mines de les obertes.   
 * 
 * Aquesta funció no es crida des d'assemblador.
 * Hi ha una subrutina en assemblador equivalent 'updateBoardP1', 
 */
void updateBoardP1_C(){

   int i,j;
   
   rowScreen = 7;
   for (i=0;i<DimMatrix;i++){
	  colScreen = 7;
      for (j=0;j<DimMatrix;j++){
         gotoxyP1_C();
         charac = marks[i][j];
         printchP1_C();
         colScreen = colScreen + 4;
      }
      rowScreen = rowScreen + 2;
   }
   showMinesP1_C();   //Mostrar nombre de mines que queden per a marcar
   
}


/**
 * Actualitzar la posició del cursor al tauler, que tenim al vector 
 * (rowcol) (fila rowcol[0] i columna rowcol[1]) en funció a la tecla 
 * premuda, que tenim a la variable (charac).
 * Si es surt fora del tauler no actualitzar la posició del cursor.
 * (i:amunt, j:esquerra, k:avall, l:dreta)
 * ( rowcol[0] = rowcol[0] +/- 1 ) ( rowcol[1] = rowcol[1] +/- 1 ) 
 * No s'ha de posicionar el cursor a la pantalla.
 *  
 * Variables globals utilitzades:	
 * rowcol   : Vector amb la fila i la columna del cursor dins del tauler.
 * charac   : Caràcter llegit de teclat.
 *  
 * Aquesta funció no es crida des d'assemblador.
 * Hi ha una subrutina en assemblador equivalent  'moveCursorP1', 
 */
void moveCursorP1_C(){
 
   switch(charac){
      case 'i': //amunt
         if (rowcol[0]>0) rowcol[0]--;
      break;
      case 'j': //esquerra
         if (rowcol[1]>0) rowcol[1]--;
      break;
      case 'k': //avall
         if (rowcol[0]<DimMatrix-1) rowcol[0]++;
      break;
      case 'l': //dreta
		 if (rowcol[1]<DimMatrix-1) rowcol[1]++;
      break;     
	}
	
}


/**
 * Marcar/desmarcar una mina a la matriu (marks) a la posició actual del
 *  cursor, indicada pel vector(rowcol), (fila (rowcol[0]) i columna 
 * (rowcol[1]) del cursor en tablero) .
 * Si en aquella posició de la matriu (marks) hi ha un espai en blanc i 
 * no hem marcat totes les mines, marquem una mina posant una 'M' 
 * i decrementarem el nombre de mines que queden per marcar (numMines), 
 * si en aquella posició de la matriu (marks) hi ha una 'M', posarem un 
 * espai (' ') i incrementarem el nombre de mines que queden per marcar 
 * (numMines).
 * Si hi ha un altre valor no canviarem res.
 * No s'ha de mosrar la matriu, només actualitzar la matriu (marks) i 
 * la variable (numMines).
 * 
 * Variables globals utilitzades:	
 * marks    : Matriu amb les mines marcades i les mines de les obertes.
 * rowcol   : Vector amb la fila i la columna del cursor dins del tauler.
 * numMines : Nombre de mines que queden per marcar.
 * 
 * Aquesta funció no es crida des d'assemblador.
 * Hi ha una subrutina en assemblador equivalent 'mineMarkerP1'.
 */
void mineMarkerP1_C() {
	
	int row = rowcol[0];
	int col = rowcol[1];
	if (marks[row][col] == ' ' && numMines > 0) {
		marks[row][col] = 'M';      //Marcar
		numMines--;
	} else {
		if (marks[row][col] == 'M') {
			marks[row][col] = ' ';  //Desmarcar
			numMines++;
		}
	}
		
} 

  
/**
 * Verificar si hem marcat totes les mines. 
 * Si (numMines==0) canvia l'estat (state=2) (Guanya).
 * 
 * Variables globals utilitzades:	
 * numMines : Nombre de mines que queden per marcar.
 * state    : Estat del joc.
 * 
 * Aquesta funció no es crida des d'assemblador.
 * Hi ha una subrutina en assemblador equivalent 'checkMinesP1', 
 */
void checkMinesP1_C() {
	
	if (numMines == 0) {
		state = 2;
	}
	
} 


/**
 * Mostra un missatge a sota del tauler segons el valor de la variable 
 * (state).
 * state: 0: Hem premut la tecla 'ESC' per a sortir del joc.
 * 		  1: Continuem jugant.
 * 		  2: Guanya, s'han marcat totes les mines.
 * S'espera que es premi una tecla per a continuar.
 * 
 * Variables globals utilitzades:	
 * rowScreen: Fila de la pantalla on posicionem el cursor.
 * colScreen: Columna de la pantalla on posicionem el cursor.
 * state    : Estat del joc.
 * 
 * Aquesta funció es crida des de C i des d'assemblador.
 * No hi ha una subrutina en assemblador equivalent
 */
void printMessageP1_C() {

   rowScreen = 27;
   colScreen = 30;
   gotoxyP1_C();  
   
   switch(state){
      case 0:
         printf("<< EXIT: ESC >>");
        break;
      case 2:
         printf("++ YOU WIN ! ++");
      break;
   }
   getchP1_C();		//Espera que l'usuari premi una tecla.
   
}
 

/**
 * Joc del Buscamines
 * Funció principal del joc
 * Permet jugar al joc del buscamines cridant totes les funcionalitats.
 *
 * Pseudo codi:
 * Inicialitzar estat del joc, state=1
 * Inicialitzar posició inicial del cursor:
 * fila:(rowcol[0] = 4) i columna:(rowcol[1] = 4).
 * Mostrar el tauler de joc cridant a la funció PrintBoardP1_C.
 * Mentre (state=1) fer
 *   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
 *     queden per marcar (cridar la funció updateBoardP1_C.
 *   Posicionar el cursor dins del tauler (cridar la funció posCurScreenP1_C).
 *   Llegir una tecla i guardar la tecla llegida a la variable (charac).
 *   Segons la tecla llegida cridarem a la funció corresponent.
 *     - ['i','j','k' o 'l']      (cridar a la funció MoveCursorP1_C).
 *     - 'm'                      (cridar a la funció MineMarkerP1_C).
 *     - '<ESC>'  (codi ASCII 27) posar state = 0 per a sortir. 
 *   Verificar si hem marcat totes les mines (crida la funció CheckMinesP1_C).
 * Fi mentre.
 * Sortir: 
 *   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
 *   queden per marcar (cridar la función updateBoardP1_C).
 *   Mostrar missatge de sortida que correspongui (cridar a la funció
 *   printMessageP1_C).
 * S'acabat el joc.

 * Variables globals utilitzades:	
 * rowcol   : vector amb la fila i la columna del cursor dins del tauler.
 * charac   : Caràcter llegit de teclat.
 * state    : Estat del joc.
 */
void playP1_C(){
	
   state = 1;  //Estat per a començar a jugar
			   			   
   rowcol[0]=  4;	   //Posició inicial del cursor.
   rowcol[1] = 4;      
  
   printBoardP1_C();
          
   while (state == 1) {  //Bucle principal del joc
	 updateBoardP1_C();
	 posCurScreenP1_C();

     getchP1_C();	//llegir una tecla i guardar-la a la variable charac.
     if (charac>='i' && charac<='l') { //Moure cursor
       moveCursorP1_C();
     }
     if (charac=='m') {                //Marcar mina
       mineMarkerP1_C();
     }
     if (charac==27) {                 //Sortir del programa
       state = 0;
     }
     checkMinesP1_C();
   }
   updateBoardP1_C();
   printMessageP1_C();	//Mostrar el missatge per a indicar com acaba.
   
}


/**
 * Programa Principal
 * 
 * ATENCIÓ: A cada opció es crida a una subrutina d'assemblador.
 * A sota hi ha comentada la funció en C equivalent que us donem feta 
 * per si voleu veure com funciona.
 *  */
int main(void){   

   int op=1;
     
   while (op!='0') {
	  clearScreen_C();
      printMenuP1_C();		  //Mostrar menú i llegir opció
      op=charac;	   		  
      
      switch(op){
         case '1':// Posicionar el cursor al tauler
            printf(" %c",op);
            clearScreen_C();  //Esborra la pantalla
            printBoardP1_C();   //Mostrar el tauler
            rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
            printf(" Press any key ");
            //=======================================================
            rowcol[0]=1;  //Fila i columna on es posiciona el cursor
            rowcol[1]=1;
            posCurScreenP1();
            //posCurScreenP1_C();
            //=======================================================
            getchP1_C();
         break;
         case '2': //Mostrar nombre de mines que quedem per marcar
            printf(" %c",op);
            clearScreen_C();  //Esborra la pantalla
            printBoardP1_C();   //Mostrar el tauler
            //=======================================================
            showMinesP1();
            showMinesP1_C();  //Actualitzar nombre de mines
            //=======================================================
            rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
            printf("Press any key ");
            getchP1_C();
         break;
         case '3': //Mostrar el tauler i actualitzar el contingut
            printf(" %c",op);
            clearScreen_C();  //Esborra la pantalla
            printBoardP1_C();   //Mostrar el tauler
            //=======================================================
            updateBoardP1();
            //updateBoardP1_C();  //Actualitzar el contingut del tauler
            //=======================================================
            rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
            printf("Press any key ");
            getchP1_C();
         break;
         case '4': //Moure cursor
            clearScreen_C();  //Esborra la pantalla
            printBoardP1_C();   //Mostrar el tauler
            printf("\n    Move cursor: i:Up, j:Left, k:Down, l:Right ");//posCurScreenP1();
            rowcol[0]=2;  //Fila i columna on es posiciona el cursor
            rowcol[1]=2;
            posCurScreenP1_C();
            getchP1_C();	
            rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
			printf("Press any key ");
	        if (charac>='i' && charac<='l') { 
				//===================================================
				moveCursorP1();
				//moveCursorP1_C();
				//===================================================
				posCurScreenP1_C();
            } else {
				printf("\n       Incorrect option                         ");
			}
            getchP1_C();
         break;
         case '5': //Calcular l'índex (indexMat) per a accedir 
                   //a la matriu marks i mines  des d'assemblador
            clearScreen_C();  
            printBoardP1_C(); 
            updateBoardP1_C();
			//===================================================
            rowcol[0]=9;      //Fila i columna on es posiciona el cursor
            rowcol[1]=9;
            calcIndexP1();
			//No hi ha la funció equivalent en C.
			//===================================================
            rowScreen = 31;
			colScreen = 1;
            gotoxyP1_C();
            printf("\n\n The index to access the position (%i)(%i) is %i", rowcol[0], rowcol[1], indexMat); 
            rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
			printf("Press any key ");
			getchP1_C();
          break;
         case '6': //Marcar Mina
            clearScreen_C();  
            printBoardP1_C(); 
            updateBoardP1_C();  
            printf("\n\n\n          Mark a Mine: m:mark/unmark");
            rowcol[0]=3;      //Fila i columna on es posiciona el cursor
            rowcol[1]=3;
            posCurScreenP1_C();
            getchP1_C();
   			if (charac=='m') {
			    //===================================================
            	mineMarkerP1();
				//mineMarkerP1_C();
				//===================================================
                updateBoardP1_C();  
			} else {
				printf("\n       Incorrect option                         ");
			}
			rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
			printf("Press any key ");
			getchP1_C();
          break;
          case '7': //Moure cursor
            clearScreen_C();  //Esborra la pantalla
            printBoardP1_C();   //Mostrar el tauler
            updateBoardP1();
            rowScreen = 27;
			colScreen = 30;
            gotoxyP1_C();
			//===================================================
            int n = numMines;
            numMines = 0;
            checkMinesP1();
			//checkMinesP1_C();
			//===================================================
 	        if (state==2) { 
				printf("++ YOU WIN ! ++");
            } else {
				printf("** MORE MINES **");
			}
			numMines = n;
            getchP1_C();
         break;
          case '8': //Joc complet en assemblador
            clearScreen_C();
            //=======================================================
            playP1();
            //=======================================================
         break;
         case '9': //Joc complet en C
            clearScreen_C();
            //=======================================================
            playP1_C();
            //=======================================================
         break;
         case '0':
		 break;	 
      }
   }
   printf("\n\n");
   
   return 0;
}
