#!/bin/bash

nasm -f elf64 $1.asm -o $1.o
ld $1.o -o $1
./$1 
echo $?

rm *.o
rm $1
