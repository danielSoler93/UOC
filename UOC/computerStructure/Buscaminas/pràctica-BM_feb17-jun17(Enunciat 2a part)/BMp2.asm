section .data               
;Canviar Nom i Cognom per les vostres dades.
developer db "Daniel Soler",0

;Constants que també estan definides en C.
DimMatrix    equ 10
SizeMatrix   equ 100

section .text            
;Variables definides en Assemblador.
global developer     
                         
;Subrutines d'assemblador que es criden des de C.
global posCurScreenP2, showMinesP2  , updateBoardP2, moveCursorP2
global mineMarkerP2  , searchMinesP2, checkEndP2   , playP2	
 
;Variables globals definides en C.
extern rowScreen, colScreen, rowcol, indexMat
extern charac, mines, marks, numMines, state

;Funcions de C que es criden des de assemblador
extern clearScreen_C, gotoxyP2_C, getchP2_C, printchP2_C
extern printBoardP2_C, printMessageP2_C, updateBoardP2_C

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ATENCIÓ: Recordeu que les variables i els paràmetres de tipus 'char',
;;   en assemblador s'han d'assignar a registres de tipus BYTE (1 byte): 
;;   al, ah, bl, bh, cl, ch, dl, dh, sil, dil, ...
;;   i les de tipus 'int' s'han d'assignar a registres 
;;   de tipus DWORD (4 bytes): eax, ebx, ecx, edx, esi, edi, ....
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Les subrutines en assemblador que heu d'implementar són:
;;   posCurScreenP2, showMinesP2,  updateBoardP2, moveCursorP2
;;   calcIndexP2, mineMarkerP2, searchMinesP2, checkEndP2
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Situar el cursor en una fila i una columna de la pantalla
; en funció de la fila (edi) i de la columna (esi) rebuts com 
; a paràmetre cridant a la funció gotoxyP2_C.
; 
; Variables globals utilitzades:	
; Cap
; 
; Paràmetres d'entrada : 
; rdi(edi): Fila
; rsi(esi): Columna
; 
; Paràmetres de sortida: 
; Cap
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
gotoxyP2:
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

   ; Quan cridem la funció gotoxyP2_C(int rowCurScreen, int colCurScreen)
   ; des d'assemblador el primer paràmetre (rowCurScreen) s'ha de passar
   ; pel registre rdi(edi), i el segon  paràmetre (colCurScreen) s'ha de
   ; passar pel registre rsi(esi).	
   call gotoxyP2_C
 
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
; Mostrar un caràcter (dil) a la pantalla, rebut com a paràmetre, 
; en la posició on està el cursor cridant la funció printchP2_C.
; 
; Variables globals utilitzades:	
; Cap
; 
; Paràmetres d'entrada : 
; rdi(dil): Caràcter que volem mostrar
; 
; Paràmetres de sortida: 
; Cap
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
printchP2:
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

   ; Quan cridem la funció printchP2_C(char c) des d'assemblador, 
   ; el paràmetre (c) s'ha de passar pel registre rdi(dil).
   call printchP2_C
 
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
; Llegir una tecla i retornar el caràcter associat (al) sense 
; mostrar-lo per pantalla, cridant la funció getchP2_C
; 
; Variables globals utilitzades:	
; Cap
; 
; Paràmetres d'entrada : 
; Cap
; 
; Paràmetres de sortida: 
; rax(al): Caràcter que llegim de teclat
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
getchP2:
   push rbp
   mov  rbp, rsp
   ;guardem l'estat dels registres del processador perquè
   ;les funcions de C no mantenen l'estat dels registres.
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

   mov rax, 0
   ; Cridem la funció (char) getchP2_C() des d'assemblador, 
   ; retorna sobre el registre rax(al) el caràcter llegit
   call getchP2_C
 
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
   
   mov rsp, rbp
   pop rbp
   ret 


;;;;;
; Posicionar el cursor a la pantalla dins del tauler, en funció del 
; vector (rowcol), posició del cursor dins del tauler, vector que es rep
; com a paràmetre (fila rowcol[0] i columna rowcol[1]).
; Per a calcular la posició del cursor a pantalla utilitzar 
; aquestes fórmules:
; edi = rowScreen =(rowcol[0]*2)+7
; esi = colScreen =(rowcol[1]*4)+7
; Per a posicionar el cursor s'ha de cridar a la subrutina gotoxyP2 
; implementant correctament el pas de paràmetres.
;
; Variables globals utilitzades:	
; Cap
;
; Paràmetres d'entrada : 
; rdi     : Adreça del vector de 2 posicions on guardem la fila 
;           (rowcol[0]) i la columna (rowcol[1]) del cursor dins del tauler.
;
; Paràmetres de sortida: 
; Cap
;;;;;  
posCurScreenP2:
	push rbp
	mov  rbp, rsp
	push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	mov  eax, DWORD[rdi+0] ;rc[0]
	mov  ebx, DWORD[rdi+4] ;rc[1]
	imul eax, 2 ;rc[0]*2
	add  eax, 7 ;rowScreen=(rc[0]*2)+7;
	imul ebx, 4 ;rc[1]*4
	add  ebx, 7 ;colScreen=(rc[1]*4)+7;
	mov  edi, eax ;input gotoxyP2 rowScreen
	mov  esi, ebx ;input gotoxyP2 colScreen
	call gotoxyP2
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
; Converteix el valor del nombre de mines que queden per marcar 
; (numMines) que es rep com a paràmetre (entre 0 i 99) en dos caràcters 
; ASCII. S'ha de dividir el valor (numMines) entre 10, el quocient 
; representarà les desenes i el residu les unitats, i després s'han de 
; convertir a ASCII sumant 48, caràcter '0'.
; Mostra els dígits (caràcter ASCII) de les desenes a la fila 27, 
; columna 23 de la pantalla i les unitats a la fila 27, columna 24.
; Per a posicionar el cursor s'ha de cridar a la subrutina gotoxyP2 i 
; per a mostrar els caràcters a la subrutina printchP2 implementant 
; correctament el pas de paràmetres
;
; Variables globals utilitzades:	
; Cap.
;
; Paràmetres d'entrada : 
; rdi(edi) : Nombre de mines que queden per marcar.
;
; Paràmetres de sortida: 
; Cap
;;;;;
showMinesP2:
	push rbp
	mov  rbp, rsp
	push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	mov  eax, edi ;numMines
	mov  edx, 0   ;digit = nMines%10
	mov  ecx, 10 
	div  ecx	  ;digit = nMines/10;//Decenes
	add  al, '0'  ;digit = digit + '0'
	mov  edi, 27
	mov  esi, 23
	call gotoxyP2 ;gotoxyP2_C(27, 23)
	mov  dil, al
	call printchP2 ;printchP2_C(digit)
	add  dl, '0'   ;digit = digit + '0'
	mov  edi, 27 
	mov  esi, 24
	call gotoxyP2 ;gotoxyP2_C(27, 24)
	mov  dil, dl
	call printchP2 ;printchP2_C(digit)
	pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
	pop rax
	mov  rsp, rbp
	pop  rbp
	ret

;;;;;
; Actualitzar el contingut del Tauler de Joc amb les dades de la matriu 
; (marks) i el nombre de mines que queden per marcar que es rep
; com a paràmetre.
; S'ha de recórrer tota la matriu (marks), i per a cada element de la 
; matriu posicionar el cursor a la pantalla i mostrar els caràcters de
; a matriu. 
; Després mostra el valor del nombre de mines que queden per marcar a 
; la part inferior del tauler.
; Per a posicionar el cursor s'ha de cridar a la subrutina gotoxyP2, 
; per a mostrar els caràcters s'ha de cridar a la subrutina printchP2 i 
; per a mostrar el nombre de mines s'ha de cridar a la subrutina
; ShowMinesP2, implementant correctament el pas de paràmetres.
;
; Variables globals utilitzades:	
; marks    : Matriu amb les mines marcades i les mines de les obertes.
;
; Paràmetres d'entrada : 
; rdi(edi) : Nombre de mines que queden per marcar.
;
; Paràmetres de sortida: 
; Cap
;;;;;  
updateBoardP2:

	push rbp
	mov  rbp, rsp
	push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    call updateBoardP2_C
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
; Actualitzar la posició del cursor al tauler que tenim al vector 
; (rowcol), que es rep com a paràmetre (la fila rowcol[0]) i la columna 
; (rowcol[1]) en funció a la tecla premuda, que també rebem com a 
; paràmetre.
; Si es surt fora del tauler no actualitzar la posició del cursor.
; (i:amunt, j:esquerra, k:avall, l:dreta)
; ( rowcol[0] = rowcol[0] +/- 1 ) ( rowcol[1] = rowcol[1] +/- 1 ) 
; No s'ha de posicionar el cursor a pantalla. 
;
; Variables globals utilitzades:	
; Cap
;
; Paràmetres d'entrada : 
; rdi      : Adreça del vector de 2 posicions on guardem la fila 
;           (rowcol[0]) i la columna (rowcol[1]) del cursor dins del tauler.
; rsi(sil) : Caràcter llegit de teclat 
;
; Paràmetres de sortida: 
; Cap
;;;;;  
moveCursorP2:
	push rbp
	mov  rbp, rsp
	push rax
	push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	mov  edx, DWORD[rdi+0]
	mov  ebx, DWORD[rdi+4]
	mov  ecx, DimMatrix
	sub  ecx, 1
	cmp  sil, 'i' ;case 'i'
	je   i
	cmp  sil,  'j' ;case 'j'
	je   j
	cmp  sil,  'k' ;case 'k'
	je   k
	cmp  sil, 'l'  ;case 'l'
	je   l
	jmp moveFin
	
	
i:
	cmp  edx, 0 ;if (rc[0]>0)
	jle  moveFin
	sub edx, 1   ;rc[0]--
	mov DWORD[rdi+0], edx
	jmp moveFin
j:
	cmp  ebx, 0 ;if (rc[1]>0)
	jle  moveFin
	sub ebx, 1   ;rc[1]--
	mov DWORD[rdi+4], ebx
	jmp  moveFin	
	
k:
	cmp  edx, ecx ;if (rc[0]<DimMatrix-1)
	jge  moveFin
	add edx, 1
	mov DWORD[rdi+0], edx ;rc[0]++;
	jmp moveFin
	
l:
	cmp  ebx, ecx  ;if (rc[1]<DimMatrix-1)
	jge  moveFin
	add ebx, 1     ;rc[1]++;
	mov DWORD[rdi+4], ebx
	jmp moveFin

	
moveFin:
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
; Calcular el valor de l'índex per a accedir a la matriu marks i mines  
; (10x10) que guardarem al registre eax per a retornar-ho, a partir 
; dels valors de la posició actual del cursor, indicats pel 
; vector: (rowcol): vector amb la fila (rowcol[0]) i la columna (rowcol[1]) 
; del cursor dins del tauler.
; eax=(rowcol[0]*DimMatrix)+([rowcol[1]).
; L'índex es retornar sobre el registre eax.
;
; Aquesta subrutina no té una funció en C equivalent.
;
; Variables globals utilitzades:	
; Cap
;
; Paràmetres d'entrada : 
; rdi      : Adreça del vector de 2 posicions on guardem la fila 
;            (rowcol[0]) i la columna (rowcol[1]) del cursor dins del tauler.
;
; Paràmetres de sortida: 
; rax(eax) : índex per a accedir a les matrius mines i marks.
;;;;;  
calcIndexP2:
	push rbp
	mov  rbp, rsp
	push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	mov eax, DWORD[rdi + 0]
	mov ebx, DWORD[rdi + 4]
	mov edx, 10 
	mul edx    	 ;rcol[0]*10
	add eax, ebx ;rcol[0]*10 + rcol[1]
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
	mov rsp, rbp
	pop rbp
	ret


;;;;;  
; Marcar/desmarcar una mina a la matriu (marks) a la posició actual del
; cursor, indicada pel vector(rowcol), que es rep com a paràmetre (fila
; (rowcol[0]) i columna (rowcol[1])).
; Si en aquella posició de la matriu (marks) hi ha un espai en blanc i 
; no hem marcat totes les mines, marquem una mina posant una 'M' 
; i decrementem el nombre de mines que queden per marcar (numMines), 
; que es rep com a paràmetre, si en aquella posició de la matriu (marks)
; hi ha una 'M', posarem un espai (' ') i incrementem el nombre de mines
; que queden per marcar.
; Si hi ha un altre valor no canviarem res.
; Retornar el nombre de mines que queden per marcar actualitzat.
; Calcular el valor de l'índex, que es deixa al registre eax, per a 
; accedir a la matriu (marks) a partir dels valors de la fila i la 
; columna (posició actual del cursor) que tenim a (rowcol), cridant a 
; la subrutina calcIndexP2. (eax=(rowcol[0]*DimMatrix)+(rowcol[1]))
; No s'ha de mostrar la matriu.
;
; Variables globals utilitzades:	
; marks    : Matriu amb les mines marcades i les mines de les obertes.
; 
; Paràmetres d'entrada : 
; rdi      : Adreça del vector de 2 posicions on guardem la fila 
;            (rowcol[0]) i la columna (rowcol[1]) del cursor dins del tauler.
; rsi(esi) : Nombre de mines que queden per marcar.
; 
; Paràmetres de sortida: 
; rax(eax) : Nombre de mines que queden per marcar.
;;;;;  
mineMarkerP2:
	push rbp
	mov  rbp, rsp
	push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	call calcIndexP2 ;return index in eax
	cmp BYTE[marks+eax], ' ' ;marks[row[i]][row[j]] == ' ' 
	jne desmarca
	cmp BYTE[numMines], 0  ;numMines > 0
	jl  desmarca
	mov BYTE[marks+eax], 'M'  ;marks[rowScreen][ColScreen] = 'M'
	sub ecx, 1				;numMines--
	jmp final
	
desmarca:
	cmp BYTE[marks+eax], 'M'   ;marks[row[i]][row[j]] == 'M' 
	jne final
	mov BYTE[marks+eax], ' '   ;marks[rowScreen][ColScreen] = ' '
	add ecx, 1					;numMines++
		
final:
	mov eax, ecx      ;return numMines
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx	
	mov rsp, rbp
	pop rbp
	ret
		

;;;;;  
; Obrir casella. Mirar quantes mines hi ha al voltant de la posició 
; actual del cursor, indicada pel vector (rowcol) que es rep com a 
; paràmetre (fila (rowcol[0]) i columna (rowcol[1])), de la 
; matriu (mines).
; Si a la posició actual de la matriu (marks) hi ha un espai (' ') 
;   Mirar si a la matriu (mines) hi ha una mina ('*').
;   Si hi ha una mina canviar l'estat (state), que es rep com a 
;     paràmetre a 3 "Explosió", per a sortir.
;	 Sinó, comptar quantes mines hi ha al voltant de la posició 
;     actual i actualitzar la posició de la matriu (marks) amb 
;     el nombre de mines (caràcter ASCII del valor, per fer-ho, cal 
;     sumar 48 ('0') al valor).
; Sinó hi ha un espai, vol dir que hi ha una mina marcada ('M') o la 
; casella ja s'ha obert (hi ha el nombre de mines que ja s'ha calculat 
; anteriorment), no fer res.
; Retornar l'estat del joc actualitzat.
; No s'ha de mostrar la matriu.
;
; Variables globals utilitzades:	
; marks  : Matriu amb les mines marcades i les mines de les obertes.
; mines  : Matriu on posem les mines.
 
; Paràmetres d'entrada : 
; rdi      : Adreça del vector de 2 posicions on guardem la fila 
;            (rowcol[0]) i la columna (rowcol[1]) del cursor dins del tauler.
; rsi(esi) : Estat del joc.
; 
; Paràmetres de sortida: 
; rax(eax) : Estat del joc.
;;;;;  
searchMinesP2:
	push rbp
	mov  rbp, rsp
	push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	mov cl, 0 ;digit
	mov eax, DWORD[rdi +0] ;row
	mov ebx, DWORD[rdi +4] ;col
	mov edx, 10
	mul edx          ;row*10
	add eax, ebx     ;row*10 + col = Index
	mov edx, DimMatrix  
	sub edx, 1       ;DimMatrix-1
	cmp BYTE[marks+eax], ' '
	jne  status
	cmp BYTE[mines+eax], ' '
	je else
	mov esi, 3
	jmp status
	
else:
	cmp  DWORD[rdi +0], 0
	jg  upleft
	jmp leftcenter
	

upleft:
	cmp DWORD[rdi +4], 0
	jle upcenter
	cmp BYTE[mines+eax-11], '*'
	jne upcenter
	add cl, 1
	jmp upcenter
	
upcenter:
	cmp BYTE[mines+eax-10], '*'
	jne upright
	add cl, 1
	jmp upright
	
upright:
	cmp ebx, edx
	jge leftcenter
	cmp BYTE[mines+eax-9], '*'
	jne leftcenter
	add cl, 1
	jmp leftcenter
	
leftcenter:
	cmp ebx, 0
	jle rightcenter
	cmp BYTE[mines+eax-1], '*'
	jne rightcenter
	add cl, 1
	jmp rightcenter

rightcenter:
	cmp ebx, edx
	jge downleft
	cmp BYTE[mines+eax+1], '*'
	jne downleft
	add cl, 1
	jmp downleft

downleft:
	cmp DWORD[rdi +0], edx
	jge elsend
	cmp ebx, 0
	jle downcenter
	cmp BYTE[mines+eax+9], '*'
	jne downcenter
	add cl, 1
	jmp downcenter
	
downcenter:
	cmp BYTE[mines+eax+10], '*'
	jne downright
	add cl, 1
	jmp downright
	
downright:
	cmp ebx, edx
	jge elsend
	cmp BYTE[mines+eax+11], '*'
	jne elsend
	add cl, 1
	jmp elsend

elsend:
	add cl, '0'
	mov BYTE[marks + eax], cl


status:
	mov eax, esi
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
	mov rsp, rbp
	pop rbp
	ret


;;;;;  
; Verificar si hem marcat totes les mines (numMines=0), que es rep com 
; a paràmetre i hem obert o marcat amb una mina totes  les altres 
; caselles i no hi ha cap espai en blanc (' ') a la matriu (marks), 
; si és així, canviar l'estat (state) que es rep com a paràmetre, a 
; 2 "Guanya".
; Retornar l'estat del joc actualitzat.
; 
; Variables globals utilitzades:	
; marks    : Matriu amb les mines marcades i les mines de les obertes.
; 
; Paràmetres d'entrada : 
; rdi(edi) : Nombre de mines que queden per marcar.
; rsi(esi) : Estat del joc. 
; 
; Paràmetres de sortida: 
; rax(eax) : Estat del joc. 
;;;;;  
checkEndP2:
	push rbp
	mov  rbp, rsp
	push rbx
    push rcx
    push rdx
    push rsi
    push rdi
	mov ebx, 0 ;notOpenMarks
	cmp edi, 0  ;nombre de mines per marcar=0?
	jne checkEnd ;si no res
	mov ecx, 0 ;si si inicialitza variable first for
	jmp for1; and jump right to it

for1:
	cmp ecx, DimMatrix 
	jge statusChange ;if its >DimMatrix jump for
	add ecx, 1 ;add 1 to the loop variabl
	mov edx, 0 ;initialize vsriable second for
	jmp for2 ;jump to it
	
for2:
	cmp edx, DimMatrix
	jge for1 ;if i>DimMatrix get out of the for
	push rdx
	push rbx
	mov ebx, edx
	mov eax, ecx
	mov edx, 10
	mul edx
	add eax, ebx
	mov  al, BYTE[marks+eax]
	pop rbx
	pop rdx
	add edx, 1 ; sum one to varibale of the second for 
	cmp al, ' '  ;mines[i][j]!=' ' get to the for1
	jne for2		
	add ebx, 1 ;notopen++
	jmp for2
	
	
	
	
	
statusChange:
	cmp ebx, 0
	jne checkEnd
	mov esi, 2
	jmp checkEnd
	
	

	
checkEnd:
	mov eax, esi
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx	
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
; Inicialitzar fila i columna, posició inicial, (rowcol[0]=4) i (rowcol[1]=4)
; Mostrar el tauler de joc (cridar la funció PrintBoardP2_C).
; Mentre (state=1) fer:
;   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
;     queden per marcar (cridar la subrutina updateBoardP2).
;   Posicionar el cursor dins del tauler (cridar la subrutina posCurScreenP2).
;   Llegir una tecla. 
;   Segons la tecla llegida cridarem a la subrutina corresponent.
;     - ['i','j','k' o 'l']      (cridar a la subrutina MoveCursorP2).
;     - 'x'                      (cridar a la subrutina MineMarkerP2).
;     - '<espai>'(codi ASCII 32) (cridar a la subrutina SearchMinesP2).
;     - '<ESC>'  (codi ASCII 27) posar (state = 0) per a sortir.   
;   Verificar si hem marcat totes les mines i si hem obert totes  
;     les altres caselles (crida la subrutina CheckEndP2).
; Fi mentre.
; Sortir:
;   Actualitzar el contingut del Tauler de Joc i el nombre de mines que 
;   queden per marcar (cridar la subrutina updateBoardP2).
;   Mostrar missatge de sortida que correspongui (cridar a la funció
;   printMessageP2_C)
; S'acabat el joc.
;
; Variables globals utilitzades:	
; Cap
; 
; Paràmetres d'entrada : 
; rdi(edi) : Nombre de mines que queden per marcar.
; 
; Paràmetres de sortida: 
; rax(eax) : Nombre de mines que queden per marcar.
;;;;;  
playP2:
   push rbp
   mov  rbp, rsp

   push rdi
   call printBoardP2_C   ;printBoard2_C();
   pop  rdi
   
		            ;Declaració de variable local.
   sub rsp, 8       ;Reservem 8 bytes per al vector rowcol format per 
                    ;dues posicions de tipus int (4 bytes cadascuna)
                    ;rsp: conté l'adreça del vector.
   mov rbx, rsp     ;guardem l'adreça del vector rowcol.
                    ;int  rowcol[2];
                    ;La resta de variables s'emmagatzemaran sobre registres.
   push rbx
   push rcx
   push rdx
   push rdi
   push rsi

   mov DWORD[rbx+0], 4   ;rowcol[0]=  4; //Posició inicial del cursor.
   mov DWORD[rbx+4], 4   ;rowcol[1] = 4; 
   mov ecx, edi          ;int numMines = nMines; 
   mov edx, 1            ;int state = 1;

   

   playP2_Loop:          ;bucle principal del joc
   cmp  edx, 1
   jne  playP2_PrintMessage

   mov  edi, ecx
   call updateBoardP2    ;updateBoardP2_C(numMines);

   mov  rdi, rbx
   call posCurScreenP2   ;posCurScreenP2_C(rowcol); 

   call getchP2     ; Llegir una tecla i deixar-la al regsitre al.
		
   cmp al, 'i'		; moure cursor amunt
   je  playP2_MoveCursor
   cmp al, 'j'		; moure cursor esquerra
   je  playP2_MoveCursor
   cmp al, 'k'		; moure cursor dreta
   je  playP2_MoveCursor
   cmp al, 'l'		; moure cursor avall
   je  playP2_MoveCursor
   cmp al, 'm'		; Marcar una mina
   je  playP2_MineMarker
   cmp al, ' '		; Mirar mines
   je  playP2_SearchMines
   cmp al, 27		; Sortir del programa
   je  playP2_Exit
   jmp playP2_Check  
    
   playP2_MoveCursor:
   mov  rdi, rbx
   mov  sil, al 
   call moveCursorP2     ;moveCursorP2_C(rowcol, c);
   jmp  playP2_Check

   playP2_MineMarker:
   mov  rdi, rbx
   mov  esi, ecx
   call mineMarkerP2     ;numMines = mineMarkerP2_C(rowcol, numMines);
   mov  ecx, eax
   jmp  playP2_Check

   playP2_SearchMines:
   mov  rdi, rbx
   mov  esi, edx
   call searchMinesP2    ;state = searchMinesP2_C(rowcol, state);
   mov  edx, eax
   jmp  playP2_Check

   playP2_Exit:
   mov  edx, 0            ;state = 0;
 
   playP2_Check:
   mov  edi, ecx
   mov  esi, edx
   call checkEndP2       ;state = checkEndP2_C(numMines, state);
   mov  edx, eax
   
   jmp  playP2_Loop

   playP2_PrintMessage:
   mov  edi, ecx
   call updateBoardP2   ;updateBoardP2_C(numMines);

   mov  edi, edx
   push rcx
   call printMessageP2_C ;printMessageP2_C(state);
   pop  rcx
   
   playP2_End:
   mov  eax, ecx

   pop  rdi
   pop  rsi
   pop  rdx
   pop  rcx
   pop  rbx
   
   mov rsp, rbp
   pop rbp
   ret
