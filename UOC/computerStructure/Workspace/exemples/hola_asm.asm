                                ;1: fitxer hola_asm.asm
section .data                   ;2: Inici de la  secció de dades
  msg db "Hola!",10             ;3: El 10 correspon al codi ASCII
                                ;4: del salt de línia
                                ;5: 
section .text                   ;6: Inici de la secció de codi
  global printHola              ;7: Aquesta directiva és per fer visible 
                                ;8: una etiqueta per al compilador de C
                                ;9:
  printHola:                    ;10: Nom que donem a la subrutina d'assemblador
                                ;11: que cridarem des del programa en C
                                ;12: Mostrar un missatge
  mov rax,4                     ;13: Posa el valor 4 al registre rax per a fer
                                ;14: la crida a la funció write (sys_write)
  mov rbx,1                     ;15: Posa el valor 1 al registre rbx
                                ;16: per indicar el descriptor que fa referència  
                                ;17: a la sortida estàndard
  mov rcx,msg                   ;18: Posa l'adreça de la variable msg 
                                ;19: al registre rcx
  mov rdx,6                     ;20: Posa la longitud del missatge inclòs el 10 
                                ;21: del final al registre rdx
  int 80h                       ;22: crida al sistema operatiu
				;23:
  ret                           ;24: retorn de la crida a subrutina.
                                ;25:
