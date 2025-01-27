## 🛠️    Getting Started: Assemble and Link the Program

To prepare the program for execution, you need to assemble and link it. Follow the steps below:

1. **Assemble the program**: Convert the assembly code into an object file.
2. **Link the program**: Combine the object file into an executable.

Use the following command in your terminal:

```sh
nasm -f elf32 maxCalculatorFINAL.asm && gcc -m32 maxCalculatorFINAL.o -o maxCalculatorFINAL.out && ./maxCalculatorFINAL.out
```
~
~

