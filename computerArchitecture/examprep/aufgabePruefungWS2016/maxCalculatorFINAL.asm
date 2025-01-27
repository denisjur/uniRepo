section .data
    vec DD -5, -7, 3, -17, 8, -2, 0    ; Beispielvektor
    format DB "Maximum: %d", 10, 0    ; Format-String für printf

section .text
extern printf
global main

main:
    xor ebx, ebx        ; ebx = 0 (aktuelles Maximum)
    mov esi, vec        ; esi = Adresse des Vektors

next:
    mov eax, [esi]      ; eax = aktuelles Element
    cmp eax, 0          ; überprüfen, ob wir das Ende erreicht haben
    je done             ; wenn ja, beenden

    ; Absolutwert berechnen
    test eax, eax       ; prüfen, ob negativ
    jns skip_neg        ; wenn nicht negativ, überspringen
    neg eax             ; wenn negativ, negieren

skip_neg:
    ; Mit aktuellem Maximum vergleichen
    cmp eax, ebx        ;
    jle not_greater     ; wenn nicht größer, überspringen
    mov ebx, eax        ; Maximum aktualisieren

not_greater:
    add esi, 4          ; zum nächsten Element springen
    jmp next            ; wiederholen

done:
    push ebx            ; Maximum auf den Stack legen
    push format         ; Format-String auf den Stack legen
    call printf         ; printf aufrufen
    add esp, 8          ; Stack bereinigen

    ret                 ; zurückkehren
