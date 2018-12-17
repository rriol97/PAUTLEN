CC = gcc
FLAGS = -g -Wall -pedantic

all: tests11 tests12
#generacion

tests11.o: tests11.c
	$(CC) $(FLAGS) tests11.c -c

tests12.o: tests12.c
	$(CC) $(FLAGS) tests12.c -c

test.o: test.c
	$(CC) $(FLAGS) test.c -c

generacion_omicron.o: generacion_omicron.c generacion_omicron.h
	$(CC) $(FLAGS) generacion_omicron.c -c

generacion.o: generacion.c generacion_omicron.h
	$(CC) $(FLAGS) generacion.c -c

tests11: generacion_omicron.o generacion.o tests11.o
	$(CC) $(FLAGS) -o auxs11 generacion_omicron.o generacion.o tests11.o
	./auxs11 prS11.asm
	nasm -felf32 prS11.asm
	nasm -felf32 tsS11.asm
	gcc -o tests11 -g -m32 prS11.o tsS11.o olib/olib.o

tests12: generacion_omicron.o generacion.o tests12.o
	$(CC) $(FLAGS) -o auxs12 generacion_omicron.o generacion.o tests12.o
	./auxs12 prS12.asm
	nasm -felf32 prS12.asm
	nasm -felf32 tsS12.asm
	gcc -o tests12 -g -m32 prS12.o tsS12.o olib/olib.o

generacion: generacion_omicron.o generacion.o test.o
	$(CC) $(FLAGS) -o generacion generacion_omicron.o generacion.o test.o
	./generacion prtest.asm
	nasm -felf32 prtest.asm
	nasm -felf32 ts.asm
	gcc -o test -g -m32 prtest.o ts.o olib/olib.o

clean:
	rm -f *.o generacion auxs11 auxs12 tests11 tests12 test generacion
