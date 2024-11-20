;---------------------------------------------------------------
; Lab3.asm
; Collatz Algorithm 
;
;
; Author: Denis Jur
; Gruppe: Maxim, Tommaso 
;---------------------------------------------------------------


  extern printf               ; eine importierte C Funktion (Konsolenausgabe)
  extern atoi                 ; eine importierte C Funktion (a to i = ASCII-character to Integer)

section .data ; -------------------------------------------------

  ;permanent constants and variables used in the computer program are put in this section
    decformat: db `%d\n`,0    ; %d = Dezimaldarstellung
    hexformat: db `%x\n`,0    ; %x = Hexadezimaldarstellung

    errorMessage: db `Error. Please enter a positive integer as an argument in the command line\n`,0

section .text ; -------------------------------------------------

    global main

main: ; ---------------------------------------------------------
    
    push ebp                  ; Legt Basepointer (ebp) auf dem Stack
    mov ebp, esp              ; Lässt Stackpointer (esp) auf den Basepointer zeigen


  ; Überprüfe, ob genügend Argumente übergeben wurden im command line. argc = ArgumentCounter:
    mov eax, [esp+8]          ; [ ] = Inhalt von esp+8 in eax speichern / [esp+8] => argc (Anzahl der übergebenen Argumente)
                              ; eax enthält nun Anzahl der Argumente
    cmp eax, 2                ; Compare eax mit 2. Warum 2? => 2 elemente bzw. arguments werden im command line im Terminal erwartet. Wir erwasten den Programmnamen + eine Zahl (z.B.: ./Lab3.out 376)
    jne error                 ; Jump if not equal to error. Falls wir nicht 2 Argumente erhalten so haben wir ein Problem
    

  ; Lade das erste Argument und zweite Argument (argv[0] = "./Lab3.asm" / argv[1] = "Zahl"):
    mov eax, [esp+12]         ; argv[0] in eax ("./Lab3.asm")
    mov eax, [eax+4]          ; [eax+4] bedeutet => Auf Adresse zugreifen, welche 4 Bytes weiter liegt, also argv[1] = "Zahl"

    push eax                  ; eax wird auf dem Stack gelegt
    call atoi                 ; ASCII to Integer wird aufgerufen
    add esp, 4                ; Stack aufräumen durch Verschiebung von esp um 4 Bytes
    
  ; Falls negative Zahlen eingegeben werden:
    cmp eax, 0                ; Falls Zahlen kleiner 0 sind,
    jl  error                 ; springe zu error


  ; Ergebnis anzeigen:
outcomeCalc:
    push eax                  ; eax auf dem Stack legen
    push decformat            ; eax in decformat umwandeln
    call printf               ; eax in der command line anzeigen
    add esp, 4                ; Stack aufräumen durch Werschiebung von esp um 4 Bytes
    pop eax                   ; eax aus dem Stack nehmen

    cmp eax, 1                ; Compare eax to 1 => Rechnung soll sich nicht wieder holen (4, 2, 1, 4, 2, 1, ...). Also bei 1 stoppen
    je ende                   ; Falls Ergebnis bei 1 ankommt, springe zu "ende"

    
    test eax, 1b              ; Test-Anweisung => bitweise AND-Operation zw. Register eax und Zahl 1b (also 0000001)
                              ; Falls Binärzahl in Register eax auf 1 endet => Zahl ungerade  /  Falls 0 => gerade
    jnz calcOdd               ; Jump if not zero zu calcOdd (Calculation if Odd/ Berechnung falls ungerade Zahl)


  ; Berechnung falls Zahl in eax gerade/ even ist:
calcEven:
    shr eax, 1                ; Shift right = dividing by two in binary (e.g. 10010:10 = 1001 = Shift to right)
    jmp outcomeCalc           ; Jump to outcomeCalc um Ergebnis anzuzeigen und weiterzumachen


  ; Berechnung falls Zahl in eax ungerade/ odd ist:
calcOdd:
    imul eax, 3               ; Multipliziere Zahl mit 3
    add eax, 1                ; (eax * 3) + 1
    jmp outcomeCalc           ; Jump to outcomeCalc um Ergebnis anzuzeigen und weiterzumachen


  ; Error-Message anzeigen:
error:
    push errorMessage         ; Lege errorMessage auf dem Stack
    call printf               ; Rufe printf um Ergebnis in Terminal anzuzeigen
    add esp, 4                ; Stack um 4 Bytes "geräumt", d.h. Stackpointer wird um 4 Bytes erhöht
    mov eax, 1                ; Fehlercode 1. Rückgabewert des Programms auf 1 setzen, da wir einen Fehler haben. Ansonsten wird immer Return 0 wiedergegeben wenn das Programm funktioniert.


  ; Beenden der Funktion:
ende:
    mov eax,0                 ; returning 0 by convention
    mov esp, ebp              ; Cleanup after ourselves
    pop ebp                   ; leave could be used alternatively for the last two commands
   ret

