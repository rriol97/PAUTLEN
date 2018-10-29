#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "class.h"

void tablaInit(TablaAmbito* tabla, char* name) {
    if(tabla == NULL || name == NULL)
        return;
    strcpy(tabla->name, name);
    tabla->th_ppal = NULL;
    tabla->th_func = NULL;
    return;
}

