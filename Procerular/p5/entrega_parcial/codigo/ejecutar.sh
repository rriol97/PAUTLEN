#!/bin/sh

echo "[compilando...]"
make
echo "[generando ensamblador...]"
./pruebaSintactico test.ol test.asm
echo "[compilando ensamblador...]"
nasm -g -o test.o -f elf32 test.asm
gcc -m32 -o test test.o olib.o
echo "[ejecutando programa...]"
./test