CC = gcc
FLAGS = -g -Wall -ansi -pedantic -I generacion

all: prueba_TS tests11
#generacion

hash.o: hash.c hash.h
	$(CC) $(FLAGS) hash.c -c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) graph.c -c

tabla.o: tabla.c tabla.h
	$(CC) $(FLAGS) tabla.c -c

prueba_TS.o: prueba_TS.c prueba_TS.h
	$(CC) $(FLAGS) prueba_TS.c -c

test.o: test.c
	$(CC) $(FLAGS) test.c -c

tests11.o: generacion/tests11.c
	$(CC) $(FLAGS) generacion/tests11.c -c

gentest.o: generacion/test.c
	$(CC) $(FLAGS) generacion/test.c -c -o gentest.o

generacion_omicron.o: generacion/generacion_omicron.c generacion/generacion_omicron.h
	$(CC) $(FLAGS) generacion/generacion_omicron.c -c

generacion.o: generacion/generacion.c generacion/generacion_omicron.h
	$(CC) $(FLAGS) generacion/generacion.c -c

tests11: hash.o graph.o tabla.o generacion_omicron.o generacion.o tests11.o
	$(CC) $(FLAGS) -o generacion/tests11 hash.o graph.o tabla.o generacion_omicron.o generacion.o tests11.o

generacion: hash.o graph.o tabla.o generacion_omicron.o generacion.o gentest.o
	$(CC) $(FLAGS) -o generacion/generacion hash.o graph.o tabla.o generacion_omicron.o generacion.o gentest.o

prueba_TS: hash.o graph.o tabla.o prueba_TS.o
	$(CC) $(FLAGS) -o prueba_TS hash.o graph.o tabla.o prueba_TS.o

test: hash.o graph.o tabla.o test.o
	$(CC) $(FLAGS) -o test hash.o graph.o tabla.o test.o

clean:
	rm -f *.o prueba_TS generacion/generacion generacion/tests11 test grafo.dot salida.txt tsc.dot
