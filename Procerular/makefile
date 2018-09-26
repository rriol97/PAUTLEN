################################################################################
# Makefile de la primera practica de Pautlen
# Autores: Francisco de Vicente Lana - francisco.vicentel@estudiante.uam.es
#		   Ricardo Riol Gonzalez - ricardo.riol@estudiante.uam.es
################################################################################

# Banderas de compilacion
CC = gcc
CFLAGS = -Wall -g -I .
#LDLIBS = -lm -lconfuse -pthread -fPIC
#REDLIB = -Llib/ -lred
#PICOLIB = -Llib/ -lpico

# Macros
#SERVER = obj/server.o obj/http.o
#OBJREDLIB = obj/red.o
#OBJPICOLIB = obj/picohttpparser.o


# Creacion libreria
# lib/libred.a: $(OBJREDLIB)
# 	ar -rv lib/libred.a $(OBJREDLIB)

# Creacion libreria
# lib/libpico.a: $(OBJPICOLIB)
# 	ar -rv lib/libpico.a $(OBJPICOLIB)

# Creacion objetos
test:	generacion.o
	$(CC) -o test generacion.o

generacion.o: generacion.c generacion.h
	$(CC) $(CFLAGS) -c generacion.c generacion.h

#	$(CC) $^ -o $@ $(LDLIBS) $(REDLIB) $(PICOLIB)

# obj/red.o: srclib/red.c includes/red.h
# 	$(CC) $(CFLAGS) -c -o $@ $<

# obj/picohttpparser.o: srclib/picohttpparser.c includes/picohttpparser.h
# 	$(CC) $(CFLAGS) -c -o $@ $<

# obj/http.o: src/http.c includes/http.h
# 	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS) $(REDLIB) $(PICOLIB)

# obj/server.o: src/server.c includes/server.h includes/http.h
# 	$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS) $(REDLIB) $(PICOLIB)

.PHONY: clean

# limpieza
clean:	
	rm -f *.out
	rm -f *.o
	rm -f test
	rm -f *.gch
#	mkdir -p obj
#	mkdir -p lib
# rm -f obj/*.o
# rm -f lib/*.a
# rm -f server
# rm -f *.txt