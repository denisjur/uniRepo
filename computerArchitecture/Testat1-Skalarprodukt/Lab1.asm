;
;---------------------------------------------------------------
; Lab1.asm
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

  decformat: db `%d \n`,0 ; we define the decimal format for use with C's printf function
  hexformat: db `%x\n`,0    ; and the hex format
  a: dd 21  ;Variable a mit dem Wert 21
  b: dd 2   ;Variable b mit dem Wert 2

  x123: dd 17, 11, 4 ;Array x mit 3 Werten bzw. dreidimensionale Doppelwort Speichervariable
  y123: dd 4, -9, 8 ;das Selbe für y-Werte


section .text    ;code segment starts here

global main

main:
    push ebp          
    mov ebp, esp      
    

    ;Berechnung der Multiplikation von a und b
    mov eax, [a]      ;Lade den Wert von a in Register eax
    mov ebx, [b]      ;Lade den Wert von b in ebx
    imul eax, ebx     ;Multipliziere a und b, Ergebnis in eax laden

    ;Produkt aus a und b ausgeben in Hexadezimal
    push eax          ;Ergebnis auf den Stack legen
    push hexformat    
    call printf
    add esp, 8        ;Stack aufräumen


    ; Initialisierung - Setzen der Variablen auf Ausgangswert
    mov ecx, 0        ; ecx-Register wird auf Null gesetzt für das Zählen der Loop
    mov eax, 0        ; eax-Register auf Null gesetzt (für später Addition der Produkte)
loop_start:
    ; Berechnung des Skalarprodukts durch Loop
    mov ebx, [x123 + ecx*4]  ; Lade das aktuelle Element von x in ebx (4 Bytes pro Element)
    mov edx, [y123 + ecx*4]  ; Das Selbe für y
    imul ebx, edx      ; Multiplizierung der Elemente und Speicherung in ebx
    add eax, ebx       ; Addiere das Produkt in ebx zu eax 

    inc ecx           ; Erhöhe den Zähler ecx
    cmp ecx, 3        ; Vergleiche ecx mit 3
    jne loop_start    ; Jump If Not Equal 

    ;Ergebnis des Skalarprodukts in Hexadezimal ausgeben
    push eax          
    push hexformat
    call printf
    add esp, 8

    mov eax,0      ; returning 0 by convention
    mov esp, ebp   ; clean up after ourselves 
    pop ebp        ; leave could be used alternatively for the last two commands
   ret
