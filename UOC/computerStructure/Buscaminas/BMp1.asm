BITS 64

section .data               
section .data               
;Canviar Nom i Cognom per les vostres dades.
developer db "Daniel Soler",0

;Constants que també estan definides en C.
DimMatrix    equ 10
SizeMatrix   equ 100
;reservant espai
buffer resb 10 

section .text            
;Variables definides en Assemblador.
global developer     
                         
;Subrutines d'assemblador que es criden des de C.
global posCurScreenP1, showMinesP1, updateBoardP1, moveCursorP1
global calcIndexP1, mineMarkerP1, checkMinesP1, playP1	 

;Variables globals definides en C.
extern rowScreen, colScreen, rowcol, indexMat
extern charac, mines, marks, numMines, state

;Funcions de C que es criden des de assemblador
extern clearScreen_C, gotoxyP1_C, getchP1_C, printchP1_C
extern printBoardP1_C, printMessageP1_C,  	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ATENCIÓ: Recordeu que les variables i els paràmetres de tipus 'char',
;;   en assemblador s'han d'assignar a registres de tipus BYTE (1 byte): 
;;   al, ah, bl, bh, cl, ch, dl, dh, sil, dil, ...
;;   i les de tipus 'int' s'han d'assignar a registres 
;;   de tipus DWORD (4 bytes): eax, ebx, ecx, edx, esi, edi, ....
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Les subrutines en assemblador que heu d'implementar són:
;;   posCurScreenP1, showMinesP1, updateBoardP1
;;   moveCursorP1, calcIndexP1, mineMarkerP1
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Aquesta subrutina es dóna feta. NO LA PODEU MODIFICAR.
; Situar el cursor a la fila indicada per la variable (rowScreen) i a 
; la columna indicada per la variable (colScreen) de la pantalla,
; cridant la funció gotoxyP1_C.
; 
; Variables globals utilitzades:	
; rowScreen: fila de la pantalla on posicionem el cursor.
; colScreen: columna de la pantalla on posicionem el cursor.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
gotoxyP1:
   push rbp
   mov  rbp, rsp
   ;guardem l'estat dels registres del processador perquè
   ;les funcions de C no mantenen l'estat dels registres.
   push rax
   push rbx
   push rcx
   push rdx
   push rsi
   push rdi
   push r8
   push r9
   push r10
   push r11
   push r12
   push r13
   push r14
   push r15

   call gotoxyP1_C
 
   pop r15
   pop r14
   pop r13
   pop r12
   pop r11
   pop r10
   pop r9
   pop r8
   pop rdi
   pop rsi
   pop rdx
   pop rcx
   pop rbx
   pop rax

   mov rsp, rbp
   pop rbp
   ret


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Aquesta subrutina es dóna feta. NO LA PODEU MODIFICAR.
; Mostrar un caràcter guardat a la variable (charac) a la pantalla, 
; en la posició on està el cursor, cridant la funció printchP1_C
; 
; Variables globals utilitzades:	
; charac   : caràcter que volem mostrar.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
printchP1:
   push rbp
   mov  rbp, rsp
   ;guardem l'estat dels registres del processador perquè
   ;les funcions de C no mantenen l'estat dels registres.
   push rax
   push rbx
   push rcx
   push rdx
   push rsi
   push rdi
   push r8
   push r9
   push r10
   push r11
   push r12
   push r13
   push r14
   push r15

   call printchP1_C
 
   pop r15
   pop r14
   pop r13
   pop r12
   pop r11
   pop r10
   pop r9
   pop r8
   pop rdi
   pop rsi
   pop rdx
   pop rcx
   pop rbx
   pop rax

   mov rsp, rbp
   pop rbp
   ret
   

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Aquesta subrutina es dóna feta. NO LA PODEU MODIFICAR.
; Llegir una tecla i guarda el caràcter associat a la variable (charac)
; sense mostrar-la per pantalla, cridant la funció getchP1. 
; 
; Variables globals utilitzades:	
; charac   : caràcter que llegim de teclat.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
getchP1:
   push rbp
   mov  rbp, rsp
   ;guardem l'estat dels registres del processador perquè
   ;les funcions de C no mantenen l'estat dels registres.
   push rax
   push rbx
   push rcx
   push rdx
   push rsi
   push rdi
   push r8
   push r9
   push r10
   push r11
   push r12
   push r13
   push r14
   push r15

   call getchP1_C
 
   pop r15
   pop r14
   pop r13
   pop r12
   pop r11
   pop r10
   pop r9
   pop r8
   pop rdi
   pop rsi
   pop rdx
   pop rcx
   pop rbx
   pop rax
   
   mov rsp, rbp
   pop rbp
   ret 
   

;;;;;
; Posiciona el cursor a la pantalla dins del tauler, en funció 
; del vector (rowcol), posició del cursor dins del tauler,
; (fila rowcol[0] i columna rowcol[1]).
; Per a calcular la posició del cursor a la pantalla utilitzar 
; aquestes fórmules:
; rowScreen =(rowcol[0]*2)+7
; colScreen =(rowcol[1]*4)+7
; Per a posicionar el cursor cridar a la subrutina gotoxyP1.
;
; Variables globals utilitzades:	
; rowScreen: Fila de la pantalla on posicionem el cursor.
; colScreen: Columna de la pantalla on posicionem el cursor.
; rowcol   : vector amb la fila i la columna del cursor dins del tauler.
;;;;;  ;;;;;  
posCurScreenP1:
	push rbp
	mov  rbp, rsp
	mov  eax, DWORD[rowcol+0] 
	mov  ebx, DWORD[rowcol+4]
	imul eax, 2
	add  eax, 7
	imul ebx, 4
	add  ebx, 7
	mov  [rowScreen], eax
	mov  [colScreen], ebx
	call gotoxyP1
	mov rsp, rbp
	pop rbp
	ret


;;;;;
; Converteix el valor del Número de mines que queden per marcar (numMines)
; (entre 0 i 99) a dos caràcters ASCII. 
; S'ha de dividir el valor (numMines) entre 10, el quocient representarà 
; les desenes i el residu les unitats, i després s'han de convertir 
; a ASCII sumant 48, carácter '0'.
; Mostra els dígits (caràcter ASCII) de les desenes a la fila 27, 
; columna 23 de la pantalla i les unitats a la fila 27, columna 24, 
; (la posició s'indica a través de les variables rowScreen i colScreen).
; Per a posicionar el cursor cridar a la subrutina gotoxyP1 i per a mostrar 
; els caràcters a la subrutina printchP1.
;
; Variables globals utilitzades:	
; rowScreen: Fila de la pantalla on posicionem el cursor.
; colScreen: Columna de la pantalla on posicionem el cursor.
; numMines : Nombre de mines que queden per marcar.
; charac   : Caràcter a escriure a pantalla.
;;;;;
showMinesP1:
	push rbp
	mov  rbp, rsp
	mov  eax, DWORD[numMines]
	mov  edx, 0
	mov  ecx, 10
	div  ecx
	add  al, 48
	mov  [charac], al
	mov  ebx, 27
	mov  [rowScreen], ebx
	mov  ebx, 23
	mov  [colScreen], ebx
	call gotoxyP1
	call printchP1
	add  dl, 48
	mov  [charac], al
	mov  ebx, 24
	mov  [colScreen], ebx
	call gotoxyP1
	call printchP1
	mov  rsp, rbp
	pop  rbp
	ret


;;;;;
; Actualitzar el contingut del Tauler de Joc amb les dades de la matriu 
; (marks) i el nombre de mines que queden per marcar. 
; S'ha de recórrer tot la matriu (marks), i per a cada element de la matriu
; posicionar el cursor a la pantalla i mostrar els caràcters de la matriu.
; Després mostrar el valor de (numMines) a la part inferior del tauler.
; Per a posicionar el cursor cridar a la subrutina gotoxyP1, per a mostrar 
; els caràcters a la subrutina printchP1 i per a mostrar (numMines) 
; a la subrutina ShowMinesP1.
;
; Variables globals utilitzades:	
; rowScreen: Fila de la pantalla on posicionem el cursor.
; colScreen: Columna de la pantalla on posicionem el cursor.
; charac   : Caràcter a escriure a pantalla.
; marks    : Matriu amb les mines marcades i les mines de les obertes.   
;;;;;  
updateBoardP1:
	push rbp
	mov  rbp, rsp
	mov  eax, 7
	mov  [rowScreen], eax
	mov  ebx, 0
	mov  ecx, 0
for:
	cmp ebx, DimMatrix
	jl  cert
	jmp fin

cert:
	mov eax, 7
	mov [colScreen], eax
	cmp ecx, DimMatrix
	jl  cert2
	mov eax,2
	add [rowScreen], eax
	add ebx, 1
	jmp for

cert2:
	call gotoxyP1
	mov  al, BYTE[marks + 11]
	mov  [charac], al
	call printchP1
	mov eax, 4
	add  [colScreen], eax
	mov eax, 2
	add  [rowScreen], eax
	add ecx, 1
	jmp  for

fin:
	call showMinesP1
	mov rsp, rbp
	pop rbp
	ret


;;;;;		
; Actualitzar la posició del cursor al tauler, que tenim al vector 
; (rowcol) (fila rowcol[0] i columna rowcol[1]) en funció a la tecla 
; premuda, que tenim a la variable (charac).
; Si es surt fora del tauler no actualitzar la posició del cursor.
; (i:amunt, j:esquerra, k:avall, l:dreta)
; ( rowcol[0] = rowcol[0] +/- 1 ) ( rowcol[1] = rowcol[1] +/- 1 ) 
; No s'ha de posicionar el cursor a la pantalla.
;
; Variables globals utilitzades:	
; rowcol   : vector amb la fila i la columna del cursor dins del tauler.
; charac   : Caràcter llegit de teclat.
;;;;;  
moveCursorP1:
	push rbp
	mov  rbp, rsp
	mov  eax, 3
	mov  ebx, 0
	mov  ecx, charac
	mov  edx,1
	int 80h
	mov  eax, DWORD[rowcol+0] 
	mov  ebx, DWORD[rowcol+4]
	mov  ecx, DimMatrix
	sub  ecx, 1
	mov  al, BYTE[charac]
	cmp  al, 'i'
	je   i
	cmp  al,  'j'
	je   j
	cmp  al,  'k'
	je   k
	cmp  al, 'l'
	je   l
	jmp moveFin
i:
	cmp  eax, 0
	jg  up
	jmp moveFin
j:
	cmp  ebx, 0
	jg  left
	jmp moveFin
k:
	cmp  eax, ecx
	jl  down
	jmp moveFin
l:
	cmp  ebx, ecx
	jl   right
	jmp  moveFin
	
up:
	sub eax, 1
	mov [rowcol+0], eax
	jmp moveFin
	
left:
	sub ebx, 1
	mov [rowcol+4], ebx
	jmp moveFin
	
down:
	add eax, 1
	mov [rowcol+0], eax
	jmp moveFin
	
right:
	add ebx, 1
	mov [rowcol+4], ebx
	jmp moveFin
	
moveFin:
	mov rsp, rbp
	pop rbp
	ret


;;;;;  
; Calcular el valor de l'índex per a accedir a la matriu (marks) i (mines)
; (10x10) que guardarem a la variable (indexMat) a partir dels valors de 
; la posició actual del cursor. Indicades pel vector: (rowcol).
; (rowcol: vector amb la fila rowcol[0] i la columna rowcol[1] del 
; cursor dins del tauler.)
;
; Aquesta subrutina no té una funció en C equivalent.
;
; Variables globals utilitzades:	
; rowcol   : vector amb la fila i la columna del cursor dins del tauler.
; indexMat : índex per a accedir a les matrius mines i marks.
;;;;;  
calcIndexP1:
	push rbp
	mov  rbp, rsp

	
		
	mov rsp, rbp
	pop rbp
	ret


;;;;;  
; Marcar/desmarcar una mina a la matriu (marks) a la posició actual del 
; cursor, indicada pel vector (rowcol) (fila (rowcol[0]) i columna 
; (rowcol[1]) del cursor dins del tauler).
; Si en aquella posició de la matriu (marks) hi ha un espai en blanc i 
; no s'han marcat totes les mines, marquem una mina posant una 'M' i 
; decrementem el número de mines que queden per marcar (numMines), 
; si en aquella posició de la matriu (marks) hi ha una 'M', hi posarem 
; un espai (' ') i incrementarem el número de mines que quedan per 
; marcar (numMines).
; Si hi ha un altre valor no canviarem res.
; Calcular el valor de l'índex, que es guarda a la variable (indexMat), 
; per a accedir a la matriu (marks) a partir dels valors indicats pel
; vector (rowcol)(rowcol: vector amb la fila rowcol[0] i la columna 
; rowcol[1] del cursor dins del tauler), cridant a la subrutina 
; calcIndexP1. (indexMat=(rowcol[0]*DimMatrix)+(rowcol[1]))
; No s'ha de mostrar la matriu, només actualitzar la matriu (marks) 
; i la variable (numMines).
;
; Variables globals utilitzades:	
; indexMat : índex per a accedir a la matriu marks.
; marks    : Matriu amb les mines marcades i les mines de les obertes. 
; numMines : nombre de mines que queden per marcar.
;;;;;  
mineMarkerP1:
	push rbp
	mov  rbp, rsp

	          
	
	mov rsp, rbp
	pop rbp
	ret
	

;;;;;  
; Aquesta subrutina es dóna feta. NO LA PODEU MODIFICAR.
; Verificar si hem marcat totes les mines (numMines=0),
; si és així, canviar l'estat a 2 (state=2, Guanya).
;
; Variables globals utilitzades:	
; numMines : nombre de mines que queden per posar. 
; state    : Indica l'estat del joc. 0:sortir, 1:jugar, 2:guanya, 3:explosió
;;;;;  
checkMinesP1:
	push rbp
	mov  rbp, rsp

	cmp DWORD[numMines], 0  ;if (numMines == 0) {	
	jne checkMinesP1_End

	mov DWORD[state], 2     ;state = 2;
	
	checkMinesP1_End:
	mov rsp, rbp
	pop rbp
	ret


;;;;;
; Joc del Buscamines
; Subrutina principal del joc
; Aquesta subrutina es dóna feta. NO LA PODEU MODIFICAR.
; Permet jugar al joc del buscamines cridant totes les funcionalitats.
;
; Pseudo codi:
; Inicialitzar estat del joc, (state=1)
; Inicialitzar posició inicial del cursor:
; fila:(rowcol[0] = 4) i columna:(rowcol[1] = 4).
; Mostrar el tauler de joc cridant la funció PrintBoardP1_C.
; Mentre (state=1) fer
;   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
;     queden per marcar (cridar la subrutina updateBoardP1).
;   Posicionar el cursor dins del tauler (cridar la subrutina posCurScreenP1).
;   Llegir una tecla i guardar la tecla llegida a la variable (charac).
;   Segons la tecla llegida cridarem a la funció corresponent.
;     - ['i','j','k' o 'l']      (cridar a la subrutina MoveCursorP1).
;     - 'm'                      (cridar a la subrutina MineMarkerP1).
;     - '<ESC>'  (codi ASCII 27) posar (state = 0) per a sortir.   
;   Verificar si hem marcat totes les mines (crida a la subrutina CheckMinesP1).
; Fi mentre.
; Sortir: 
;   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
;   queden per marcar (cridar la subrutina updateBoardP1).
;   Mostrar missatge de sortida que correspongui (cridar a la funció
;   printMessageP1_C)
; S'acabat el joc.
;
; Variables globals utilitzades:	
; rowcol   : vector amb la fila i la columna del cursor dins del tauler.
; charac   : Caràcter llegit de teclat.
; state    : Estat del joc.
;;;;;  
playP1:
	push rbp
	mov  rbp, rsp

	mov DWORD[state], 1       ;Estat per a començar a jugar

	mov DWORD[rowcol+0], 4	  ;rowcol[0]=4;//Posició inicial del cursor.
	mov DWORD[rowcol+4], 4    ;rowcol[1]=4;

	call printBoardP1_C

	playP1_Loop:              ;Bucle principal del joc
		cmp  DWORD[state], 1
		jne  playP1_PrintMessage

		call updateBoardP1
		
		call posCurScreenP1
		
		call getchP1          ; Llegir una tecla 
		mov  al, BYTE[charac] ; i guardar-la a la variable charac.

		cmp al, 'i'		      ; moure cursor amunt
		je  playP1_MoveCursor
		cmp al, 'j'		      ; moure cursor esquerra
		je  playP1_MoveCursor
		cmp al, 'k'		      ; moure cursor dreta
		je  playP1_MoveCursor
		cmp al, 'l'		      ; moure cursor avall
		je  playP1_MoveCursor
		cmp al, 'm'		      ; Marcar una mina
		je  playP1_MineMarker
		cmp al, 27		      ; Sortir del programa
		je  playP1_Exit
		jmp playP1_Check

		playP1_MoveCursor     ; Moure el cursor
		call moveCursorP1
		jmp  playP1_Check

		playP1_MineMarker     ; Marcar/desmarcar una mina.
		call mineMarkerP1
		jmp  playP1_Check

		playP1_Exit:
		mov DWORD[state], 0
		
		playP1_Check:
		call checkMinesP1     ;Verificar si hem marcat totes les mines. 

		jmp  playP1_Loop

	playP1_PrintMessage:
	call updateBoardP1
	call printMessageP1_C;//Mostrar el missatge per a indicar com acaba.
    
	playP1_End:		
	mov rsp, rbp
	pop rbp
	ret
