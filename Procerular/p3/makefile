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
analisis_morf: analisis_morf.o lex.yy.o
	$(CC) -o analisis_morf analisis_morf.o lex.yy.o

analisis_morf.o: analisis_morf.c tokens.h
	$(CC) $(CFLAGS) -c analisis_morf.c tokens.h

lex.yy.o: lex.yy.o tokens.h
	$(CC) $(CFLAGS) -c lex.yy.c tokens.h

# bison -dyv omicron.y
# flex omicron.l
# gcc -Wall -o omicron pruebaSintactica.c lex.yy.c y.tab.c


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
	rm analisis_morf
#	mkdir -p obj
#	mkdir -p lib
# rm -f obj/*.o
# rm -f lib/*.a
# rm -f server
# rm -f *.txt