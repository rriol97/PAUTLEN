#include "tabla.h"

void asignarDestinoEnPila(FILE* fpasm, int es_variable);

void instance_of (FILE * fd_asm, char * nombre_fuente_clase, 
                  int numero_atributos_instancia);

void discardPila (FILE * fd_asm);

void tablaSimbolosClasesANasm(FILE * fd_asm, TablaSimbolosClases* t);
