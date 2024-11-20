
;---------------------------------------------------------------
; helloWorld.asm
; 
; Text after a semicolon up to the end of line is ignored by the assembler
; A semicolon can be used to add comments in order to explain/describe code
; "The purpose of commenting is to help the reader know as much as the writer did" Dustin Boswell
; A semicolon can be used to comment out parts of the code.
;
; Author: NSFR
;
; ---------------------------------------------------------------

; declaration of functions that are not defined in the module being assembled, i.e. this file

extern printf; Using the  c function for output - the object file needs to be linked with a C library

section .data ; defines which section of the output file the code will be assembled into
              ; here: initialised data
              ; segment can be used instead (exactly equivalent synonym)

  say_hi:  db `Hello World\n`,0 ; we define a string 

section .text    ;code segment starts here

global main

main:

  push ebp
  mov ebp, esp
  push say_hi
  call printf    ; 
  add esp, 4     ; remove say_hi from stack
  mov eax,0      ; returing 0 by convention
  mov esp, ebp   ; clean up after ourselves 
  pop ebp        ; leave could be used alternatively for the last two commands
  ret


