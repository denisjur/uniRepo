section .data
    werte dd  20, 30, 40, 50, 60, 70, 80   ; Array mit Zahlen
    count equ 7                               ; Anzahl der Elemente
    format db "Ergebnis: %d", 10, 0         ; Format-String für printf

section .text
    extern printf
    global main

main:
    xor eax, eax            ; Summe auf 0 setzen
    xor esi, esi            ; Index auf 0 setzen

sum_loop:
    add eax, [werte + esi*4] ; Addiere aktuellen Wert zur Summe
    add esi, 1               ; Nächster Index
    cmp esi, count           ; Prüfen, ob alle Elemente verarbeitet wurden
    jl sum_loop              ; Wiederhole, wenn noch nicht am Ende

    mov ecx, count          ; Anzahl der Elemente
    cdq                     ; Bereite Division vor
    idiv ecx                ; Teile Summe durch Anzahl

    push eax                ; Ergebnis auf den Stack legen
    push format             ; Format-String auf den Stack legen
    call printf             ; printf aufrufen
    add esp, 8              ; Stack bereinigen

    ret                     ; Rücksprung

