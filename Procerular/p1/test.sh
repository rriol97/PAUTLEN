#!/bin/bash
nasm -g -o test.o -f elf32 salida.asm
gcc -m32 -o ejecutale_asm test.o olib.o
rm test.o