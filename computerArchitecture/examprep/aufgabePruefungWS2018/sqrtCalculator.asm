section .data
    values dd 17, 4, 5, 6    ; Array von Zahlen, jede als DWORD
    n dd 4                  ; Anzahl der Elemente im Array
    format db "Ergebnis: %d", 10, 0 ; Formatstring für printf

section .text
    global main             ; Einstiegspunkt
    extern printf           ; Externe Funktion für Ausgabe

main:
    mov ecx, [n]            ; ECX = Anzahl der Elemente
    mov esi, values         ; ESI zeigt auf den Anfang des Arrays
    xor eax, eax            ; EAX = 0 (Akkumulator für die Summe der Quadrate)

.loop:
    mov ebx, [esi]          ; Lade den aktuellen Wert in EBX
    imul ebx, ebx           ; Quadriere den Wert (v^2)
    add eax, ebx            ; Addiere das Quadrat zur Summe

    add esi, 4              ; Gehe zum nächsten Element (DWORD-Schritt)
    loop .loop              ; Wiederhole, bis alle Elemente verarbeitet sind

    ; Quadratwurzel mit fsqrt berechnen
    mov dword [esp-4], eax  ; Schreibe die Summe der Quadrate auf den Stack
    fild dword [esp-4]      ; Lade die Ganzzahl in den FPU-Stack
    fsqrt                   ; Berechne die Quadratwurzel
    fistp dword [esp-4]     ; Schreibe das Ergebnis als Ganzzahl zurück
    mov eax, dword [esp-4]  ; Lade das Ergebnis in EAX

    ; Ergebnis ausgeben
    push eax                ; Übergabe des Ergebnisses an printf
    push format             ; Übergabe des Formatstrings
    call printf             ; Aufruf von printf
    add esp, 8              ; Bereinige den Stack

    ret                     ; Beende das Programm

