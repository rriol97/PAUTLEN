################################################################################
# Makefile de la primera practica de Pautlen
# Autores: Francisco de Vicente Lana - francisco.vicentel@estudiante.uam.es
#		   Ricardo Riol Gonzalez - ricardo.riol@estudiante.uam.es
################################################################################

all: pruebaSintactico.c lex.yy.c y.tab.c generacion.c
	gcc -Wall -o pruebaSintactico pruebaSintactico.c lex.yy.c y.tab.c generacion.c

lex.yy.c: omicron.l
	$ flex omicron.l

y.tab.c: omicron.y
	$ bison -dyv omicron.y


.PHONY: clean

clean:	
	rm -f *.out
	rm -f *.o
	rm -f *.gch
	rm -f y.tab.*
	rm -f lex.yy.c
	rm -f y.output
	rm -f pruebaSintactico
