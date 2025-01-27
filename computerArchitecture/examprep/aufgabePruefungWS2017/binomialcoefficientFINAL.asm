section .data
    decformat: db "%d\n", 0 ; Format string for printf

section .text
    global main
    extern printf           ; Import printf function

main:
    ; Save base pointer and setup stack frame
    push ebp
    mov ebp, esp

    ; Input values: n and k
    mov esi, 5             ; n = 5 (stored in esi)
    mov edi, 3             ; k = 3 (stored in edi)

    ; Initialize result and counter
    mov eax, 1             ; Result = 1
    xor ecx, ecx           ; i = 0 (counter starts at 0)

binomial_loop:
    inc ecx                ; Increment i (i = i + 1)
    cmp ecx, edi           ; Compare i with k
    ja end_loop            ; If i > k, exit loop

    ; Calculate result *= (n - k + i) / i
    mov edx, esi           ; edx = n
    sub edx, edi           ; edx = n - k
    add edx, ecx           ; edx = n - k + i
    imul eax, edx          ; eax = result * (n - k + i)

    mov edx, 0             ; Clear edx for division
    mov ebx, ecx           ; ebx = i
    div ebx                ; eax = eax / i

    jmp binomial_loop      ; Repeat loop

end_loop:
    ; Output result (binomial coefficient)
    push eax               ; Push result onto stack
    push decformat         ; Push format string
    call printf            ; Call printf
    add esp, 8             ; Clean up stack

    ; Exit program
    mov eax, 0             ; Return 0
    mov esp, ebp           ; Restore stack pointer
    pop ebp                ; Restore base pointer
    ret

