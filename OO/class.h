#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define MAX_NAME 100

typedef struct {
    char name[MAX_NAME];
    Hash* th_ppal;
    Hash* th_func;
} TablaAmbito;

typedef struct {
    int index;
    char name[MAX_NAME];
    TablaAmbito tabla;
    int num_at_c;
    int num_at_i;
    int num_me_s;
    int num_me_ns;
} Class;

void tablaInit(TablaAmbito* tabla, char* name);

/*TODO: funciones para insertar atributos de clase y instancia, metodos sobre y no sobres*/
