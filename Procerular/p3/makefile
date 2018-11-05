################################################################################
# Makefile de la primera practica de Pautlen
# Autores: Francisco de Vicente Lana - francisco.vicentel@estudiante.uam.es
#		   Ricardo Riol Gonzalez - ricardo.riol@estudiante.uam.es
################################################################################

# Banderas de compilacion
CC = gcc
CFLAGS = -Wall

# Creacion objetos
all: pruebaSintactico.c lex.yy.c y.tab.c
	$(CC) $(CFLAGS) -o omicron pruebaSintactico.c lex.yy.c y.tab.c

lex.yy.c: omicron.l
	$ flex omicron.l

y.tab.c: omicron.y
	$ bison -dyv omicron.y

# bison -dyv omicron.y
# flex omicron.l
# gcc -Wall -o omicron pruebaSintactica.c lex.yy.c y.tab.c


.PHONY: clean

# limpieza
clean:	
	rm -f *.out
	rm -f *.o
	rm -f test
	rm -f *.gch
	rm omicron
	rm -f y.tab.*
	rm -f lex.yy.c
	rm -f y.output