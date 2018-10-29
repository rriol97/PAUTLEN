#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "class.h"

TablaAmbito* tablaInit(char* name) {
    TablaAmbito* tabla;
    if(name == NULL)
        return NULL;
    tabla = malloc(sizeof(TablaAmbito));
    if(tabla == NULL)
        return NULL;
    strcpy(tabla->name, name);
    tabla->th_ppal = NULL;
    tabla->th_func = NULL;
    return tabla;
}

void tablaFree(TablaAmbito* tabla) {
    if(tabla == NULL)
        return;
    clear_symbols(&(tabla->th_ppal));
    clear_symbols(&(tabla->th_func));
    free(tabla);
}
