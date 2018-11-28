################################################################################
# Makefile de la primera practica de Pautlen
# Autores: Francisco de Vicente Lana - francisco.vicentel@estudiante.uam.es
#		   Ricardo Riol Gonzalez - ricardo.riol@estudiante.uam.es
################################################################################


all: pruebaSintactico.c lex.yy.c y.tab.c generacion.c graph.c tabla.c
	gcc -Wall -o pruebaSintactico pruebaSintactico.c lex.yy.c y.tab.c generacion.c graph.c tabla.c

lex.yy.c: omicron.l
	$ flex omicron.l

y.tab.c: omicron.y
	$ bison -dyv omicron.y

# nasm -g -o test.o -f elf32 test.asm
# gcc -m32 -o test test.o olib.o

.PHONY: clean

clean:
	rm -f *.out
	rm -f *.o
	rm -f *.gch
	rm -f y.tab.*
	rm -f lex.yy.c
	rm -f y.output
	rm -f pruebaSintactico
	rm -f test
