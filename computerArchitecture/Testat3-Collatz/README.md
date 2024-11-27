# 📚 Lab 3: Collatz Conjecture Calculator

This program calculates the Collatz sequence (also known as the "3n + 1 problem") for a positive integer provided as a command-line argument. The program handles input validation, processes even and odd numbers, and outputs the sequence until it reaches 1.

## 🛠️  First, assemble and link the program:

To prepare the program for execution, assemble and link it using the following command:

```sh
nasm -f elf32 -g Lab3.asm && gcc Lab3.o -o Lab3.out
```

## 📋Run the Program

After assembling and linking, run the program with a positive integer as an argument. For example:

```sh
./Lab3.out 15
```

The program will calculate and display the Collatz sequence for the given input number.

