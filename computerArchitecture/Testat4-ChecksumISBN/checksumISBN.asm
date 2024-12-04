;-------------------------------------------------------------------------------------
; checksumISBN.asm
; ISBN-Checksum-Calculator 
;
; Author: Denis Jur
; Gruppe: Maxim B, Tommaso A
;-------------------------------------------------------------------------------------
    

section .data ; ----------------------------------------------------------------------

  totalSum: dd 0
  totalDigitCount: dd 0
  totalDashes: dd 0                       ; Numar de 32 bits - valori foarte mari

section .text ; ----------------------------------------------------------------------
  	
  global calculateISBNChecksum


calculateISBNChecksum: ; -------------------------------------------------------------
  push ebp
  mov ebp, esp

; Adresse der aktuellen zu verarbeitenden ISBN
  mov ebx, [esp + 8]

; ecx speichert die Multiplikationszahl
  mov ecx, 3

; Clean eax
  mov eax, 0

; Iterate over the ISBN number

    processISBNDigits:                    ; Iteration (gen foor-loop sau while-loop)
  
  ; AL speichert das aktuell verarbeitete Zeichen / Ziffer
    mov al, [ebx]                         ;ebx = adresa stringului ISBN. Ia un byte din adresa de string si mutal in al.

  ; Check for end of the string. Stringurile se termina in 0. 
    cmp al, 0                             ; 0 = End of string, altfel citeste mai departe.
    je finishISBNProcess

  ; Überprüfe auf "-" dashes
    cmp al, "-"
    je processDash

  ; Converting ASCII char to actual integer value, by subtracting the the ASCII-value of the number:
    sub al, 48                            ; Face cam acelasi lucru ca ATOII

  ; Check for NaN ("Not a number")
    ; Acum verificam ca doar numerele de la 0 la 9 sa fie luate in considerare. Orice altceva e NaN:
    cmp al, 0                             ; daca e equal fa mai departe
    jl processNaN

    cmp al, 9       
    jg processNaN                         ;Jump to processNaN if greater than ...

    ;*** De acum avem numere reale in registorul al ***

    xor ecx, 2                            ; Alternierung von ecx zwischen 1 und 3 mithilfe von 2 anhand der Position in der ISBN. XOR ist nu wahr wenn beide Werte unterschiedlich sind.
                                          ; 2 e numarul potrivit care face alternarea posibila. Ori primit 1 ori 3 ca rezultat.

  ; Calculate next element for "totalSum" and add it to totalSum
    imul eax, ecx                         ; Alternativ: mul (inmulteste mere cu eax)
                                          ; resultatul il pune in eax si edx simultan. Se intampla automat

    add dword [totalSum], eax             ; din cauza ca am definat sus double word dd
                                          ; In der x86-Assembler-Syntax, wenn du auf eine Speicheradresse zugreifst, musst du angeben, wie viele Bytes du lesen oder schreiben möchtest. 
                                          ; In diesem Fall speichern wir einen 32-Bit-Wert also Double Word
    
  ;Jetzt wollen wir auf den nächsten Zeichen in der ISBN Nummer:
    add ebx, 1                            ; Next char in ISBN
                                          ; add ebx, 1 = add 1 zu Adresse ebx, also gehe 1 pos. weiter / add [ebx], 1 = Add 1 zum Inhalt von ebx
    add dword [totalDigitCount], 1        ; Increment `totalDigitCount` by 1
    jmp processISBNDigits                 ; Wiederhole diese Iteration, also Schleife

    finishISBNProcess:
      ; Check for correct amount of dashes (3)
  	cmp dword [totalDashes], 3
  	jne processInvalidDashCount

      ; Check for correct amount of digits (12)
  	cmp dword [totalDigitCount], 12
  	jne processInvalidDigitCount


; Calculate final checksum
; calculeaza resultatul
  mov ax, [totalSum]                      ; ax = 16 bit. Lade den Wert der adresse totalSum in ax
  mov dl, 10                              ; Lade 10 in das niedrigwertige Byte von edx also DL. (L = low)

  div dl                                  ; Hier wird der Wert des ax Register (dh. totalSum) durch dl geteilt.

; Check if AH is already 0 - Daca e asa, nu mai trebuie sa faci nimic
  cmp ah, 0                               ; Daca folosesti div in Assembly wird der Rest in ah Register gespeichert
  je checksumIsZero

; Berechne das Endergebnis, also die ISBN-Prüfzahl:
  mov ebx, 10                             ; Ladet 10 in ebx Register
  movzx edx, ah                           ; "Move with Zero Extension" Da ah nur 8 Bits enthält muss es mit 24 Nuller befüllt werden, damit es auf 32 Bits kommt 
                                          ; Daca are numar mic ii da expand cu zerouri
  sub ebx, edx                            ; ebx - edx  / 10 - totalSum = ISBN-Prüfziffer
  mov eax, ebx                            ; Salveaza totul in eax. Save final result in eax.

  jmp checksumExit                      

checksumIsZero:
    mov eax, 0                            ; Setze eax auf 0, was bedeutet, dass das Egebnis der Prüfziffer 0 ist

  ; Exit this procedure
  checksumExit:
    leave
    ret                                   ; Se intoarce la main programm

processDash:
  add dword [totalDashes], 1
  add ebx, 1                              ; Springe einen Char weiter. Da kein []. Se misca cu un byte, adica se muta la urmatorul numar (char) in sir
  jmp processISBNDigits

processNaN:
  mov eax, -1 ; return -1, ca error
  jmp checksumExit

; Error: Wrong amount of dashes
processInvalidDashCount:
  mov eax, -1
  jmp checksumExit

; Error: Wrong amount of digits
processInvalidDigitCount:
  mov eax, -1
  jmp checksumExit  


