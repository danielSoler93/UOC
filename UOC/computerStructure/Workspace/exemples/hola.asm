                        ;1: fitxer hola.asm
section .data           ;2: Inici de la  secció de dades
  msg db "Hola!",10     ;3: El 10 correspon al codi ASCII
                        ;4: del salt de línia
                        ;5:
section .text           ;6: Inici de la secció de codi
  global main           ;7: Aquesta directiva és per a fer visible 
                        ;8: una etiqueta per al compilador de C
                        ;9:
  main:                 ;10: Per defecte el compilador de C reconeix com
                        ;11: a punt d'inici del programa l'etiqueta main
                        ;12: Mostrar un missatge
  mov rax,4             ;13: Posa el valor 4 al registre rax per a fer
                        ;14: la crida a la funció write (sys_write)
  mov rbx,1             ;15: Posa el valor 1 al registre rbx
                        ;16: indica el descriptor que fa referència  
                        ;17: a la sortida estàndard
  mov rcx,msg           ;18: Posa l'adreça de la variable msg 
                        ;19: al registre rcx
  mov rdx,6             ;20: Posa la longitud del missatge inclòs el 10 
                        ;21: del final al registre rdx
  int 80h               ;22: crida al sistema operatiu
                        ;23: retorna el control al terminal
                        ;24: del sistema operatiu
  mov rax,1             ;25: Posa el valor 1 al registre rax
                        ;26: per a cridar a la funció exit (sys_exit)
  mov rbx,0             ;27: Posa el valor 0 al registre rbx indica
                        ;28: el codi de retorn (0 = sense errors)
  int 80h               ;29: crida al sistema operatiu
                        ;30:
