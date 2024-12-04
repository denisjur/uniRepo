# 📚 Lab 4: ISBN-13 Checksum Calculator

This program calculates **ISBN-13 checksums** based on the provided input.

## 🛠️ First, assemble and compile the program:

To prepare the program for execution, assemble and link it using the following command:

```sh
nasm -f elf32 Lab4.asm && nasm -f elf32 checksumISBN.asm && gcc Lab4.o checksumISBN.o -o Lab4.out
```

## 📋After building the program, run it with an ISBN-13 code (excluding the checksum digit). For example:

```sh
./Lab4.out 128-9-1157-2221
```

