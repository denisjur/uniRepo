;---------------------------------------------------------------
; Lab4.asm
; ISBN-Checksum-Calculator 
;
; Author: Denis Jur
; Gruppe: Maxim B, Tommaso A
;---------------------------------------------------------------

  extern printf                       ; eine importierte C Funktion (Konsolenausgabe)
  extern calculateISBNChecksum        ; Hier importieren wir unsere Prozedur

section .data ; -------------------------------------------------

  ;permanent constants and variables used in the computer program are put in this section
    decformat: db `%d\n`,0            ; %d = Dezimaldarstellung
    formatOutput: db `ISBN checksum: %d\n`, 0
    insufficientArguments: db `An ISBN must be passed as an argument!\n`, 0
    invalidFormat: db `Invalid ISBN format!\n`, 0

section .text ; -------------------------------------------------

    global main

main: ; ---------------------------------------------------------
 
    push ebp                          ; Legt Basepointer (ebp) auf dem Stack
    mov ebp, esp                      ; Lässt Stackpointer (esp) auf den Basepointer zeigen

  ;Überprüfe ob genügend Argumente übergeben wurden im command line. argc = ArgumentCOunter:
    mov eax, [ebp + 8]                ; INhalt von esp+8 in eax speichern / [esp+8] => argc (Anzahl der übergebenen Argumente)
                                      ; eax enthält nun Anzahl der Argumente
    cmp eax, 2                        ; Compare eax mit 2. Warum 2? => 
                                      ; 2 Elemente bzw. Arguments werden in der command line im Terminal erwartet. 
                                      ; Wir erwarten den Programmnamen + eine Zahl (z.B.: ./Lab4.out 978-3-8458-3851)
    jne errorInsufficientArguments    ; Jump if not equal to error. Falls wir nicht 2 Argumente erhalten so haben wir ein Problem.

  ; Lade das erste Argument und zweite Argument (argv[0] = "./Lab4.asm" / argv[1] = "Zahl(also ISBN)"):
  ; Incearca si mov eax, [ebp + 16] in loc de astea doa argumente
    mov eax, [ebp + 12]               ; argv[0] in eax ("./Lab4.asm")
    mov eax, [eax + 4]                ; [eax+4] => Auf Adresse zugreifen welche 4 Bytes weiter liegt, also argv [1] = "Zahl"
    push eax                          ; Pushes eax Adresse auf dem Stack
    call calculateISBNChecksum        ; Call strica eax, ebx si ecx din aceasta cauza trebuie salvate pe stack

  ;###### Nach Aufruf un Ausführung von calculateISBNChecksum kommen wir *hier* zurück: #####
 
  ; Auf Fehlermedlung von calculateISBNChecksum prüfen 
    cmp eax, -1                       ; calculateChecksum-function returns -1 when it encounters an invalid format
    je errorInvalidFormat             ; If it is equal to -1 jump to errorInvalidFormat
    add esp, 4                        ; Clean Stack

  ; Falls alles passt, dann mach weiter und zeige uns das Ergebnis:
  ; Now we want to see the results on the terminal:
    push eax
    push formatOutput           
    call printf
    add esp, 8                        ; Remove eax and formatOutput from stack

    finishExecution:
      mov eax, 0
      mov esp, ebp
      pop ebp
    ret

errorInsufficientArguments:
  push insufficientArguments          
  call printf
  add esp, 4                          ; Remove insufficientArguments from stack
  mov eax, -1                         ; Return -1
  jmp finishExecution

errorInvalidFormat:
  push invalidFormat
  call printf
  add esp, 4                          ; Remove invalidFormat from stack
  mov eax, -1                         ; Return -1
  jmp finishExecution

  
