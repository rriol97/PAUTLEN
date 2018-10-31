CC = gcc
FLAGS = -g -Wall -ansi -pedantic

all: test

class.o: class.c class.h
	$(CC) $(FLAGS) class.c -c

hash.o: hash.c hash.h
	$(CC) $(FLAGS) hash.c -c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) graph.c -c

tabla.o: tabla.c tabla.h
	$(CC) $(FLAGS) tabla.c -c

test.o: test.c
	$(CC) $(FLAGS) test.c -c

test: class.o hash.o graph.o tabla.o test.o
	$(CC) $(FLAGS) -o test class.o hash.o graph.o tabla.o test.o

clean:
	rm -f *.o test
