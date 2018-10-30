CC = gcc
FLAGS = -g -Wall -ansi -pedantic

all: test

class.o: class.c class.h
	$(CC) $(FLAGS) class.c -c

hash.o: hash.c hash.h
	$(CC) $(FLAGS) hash.c -c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) graph.c -c

test.o: test.c
	$(CC) $(FLAGS) test.c -c

test: class.o hash.o graph.o test.o
	$(CC) $(FLAGS) -o test class.o hash.o graph.o test.o

clean:
	rm -f *.o test
