;---------------------------------------------------------------
; Lab2.asm
; Fibonacci-Algorithm
;
;
; Author: Denis Jur
; Gruppe: Maxim, Tommaso
; ---------------------------------------------------------------

; declaration of functions that are not defined in the module being assembled, i.e. this file

extern printf; Using the  c function for output - the object file needs to be linked with a C library

section .data ; defines which section of the output file the code will be assembled into
              ; here: initialised data
              ; segment can be used instead (exactly equivalent synonym)

  decformat: db `%d\n`,0    ; we define the decimal format for use with C's printf function
  hexformat: db `%x\n`,0    ; Hexadezimal-Format

section .text    ;code segment starts here

global main

main:
    push ebp                  ;Legt Basepointer (EBP) auf dem Stack
    mov ebp, esp              ;Lässt Stackpointer (ESP) auf den Basepointer zeigen 

   ; Initialisierung der ersten beiden Fibonacci-Zahlen (Vorbereitung)
    mov eax, 1                ; Setzt EAX auf 1
    mov ebx, 1                ; Setzt EBX auf 1 
    mov ecx, 20               ; Setzt den Zähler ecx auf 20

loopFibonacci:
    add eax, ebx              ; Berechnet die jeweilige Fibonacci-Zahl, (EAX = EAX + EBX)
    
    ; Ausgabe der aktuellen Fibonacci-Zahl
    push ecx                  ; Pushes ECX auf dem Stack
    push ebx                  ; Pushes EBX on top of the Stack
    push eax                  ; Pushes EAX on top of the Stack
    
    ;Hauptschleife zur Berechnung der Fibonacci-Zahlen
    push decformat            ; Push das Format für printf auf den Stack
    call printf               ; Ruft die printf-Funktion auf, um die aktuelle Fibonacci-Zahl auszugeben bzw. anzuzeigen
    
    add esp, 4                ; Erhöht den Wert von ESP um 4 Bytes, um Platz auf dem Stack freizugeben
                              ; ESP zeigt nicht mehr auf Printf, sondern auf die neue oberste Adresse des Stacks

    ;Zurücksetzen der Register und Zähler
    pop ebx                   ; Entfernt das oberste Wort vom Stack und speichert es in EBX
                              ; Gleichzeitig zeigt nun der StackPointer (ESP) auf die neue oberste Adresse im Stack
    pop eax                   ; Entfernt das oberste Wort vom Stack und speichert es in EAX ...
    pop ecx                   ; ...

    dec ecx                   ; Decreases/Verringert Zähler (ECX) um 1, um Anzahl der verbleibenden Fibonacci Zahlen zu zählen
    jnz loopFibonacci         ; Jump If Not Zero

    ;Beenden der Funktion
    mov eax,0      ; returning 0 by convention
    mov esp, ebp   ; clean up after ourselves 
    pop ebp        ; leave could be used alternatively for the last two commands
   ret
