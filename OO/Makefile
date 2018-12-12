CC = gcc
FLAGS = -g -Wall -ansi -pedantic -I generacion

all: prueba_TS generacion

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

generacion_omicron.o: generacion/generacion_omicron.c generacion/generacion_omicron.h
	$(CC) $(FLAGS) generacion/generacion_omicron.c -c

generacion: hash.o graph.o tabla.o generacion_omicron.o
	$(CC) $(FLAGS) -o generacion/generacion hash.o graph.o tabla.o generacion_omicron.o

prueba_TS: hash.o graph.o tabla.o prueba_TS.o
	$(CC) $(FLAGS) -o prueba_TS hash.o graph.o tabla.o prueba_TS.o

test: hash.o graph.o tabla.o test.o
	$(CC) $(FLAGS) -o test hash.o graph.o tabla.o test.o

clean:
	rm -f *.o prueba_TS generacion/generacion test grafo.dot salida.txt tsc.dot
