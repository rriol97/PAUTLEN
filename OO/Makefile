CC = gcc
FLAGS = -g -Wall -ansi -pedantic

all: prueba_TS

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
    
prueba_TS: hash.o graph.o tabla.o prueba_TS.o
	$(CC) $(FLAGS) -o prueba_TS hash.o graph.o tabla.o prueba_TS.o

test: hash.o graph.o tabla.o test.o
	$(CC) $(FLAGS) -o test hash.o graph.o tabla.o test.o

clean:
	rm -f *.o prueba_TS test grafo.dot salida.txt
