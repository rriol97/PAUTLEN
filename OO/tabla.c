#include <stdio.h> 
#include <stdlib.h> 
#include <stdarg.h>
#include "tabla.h"

struct _tablaSimbolosClases {
    char* name;
    Graph* graph;
} ;

int iniciarTablaSimbolosClases(tablaSimbolosClases** t, char * nombre) {
    if(t == NULL || nombre == NULL) {
        return -1;
    }
    *t = (tablaSimbolosClases *) malloc(sizeof(tablaSimbolosClases));
    if(*t == NULL)
        return -1;
    (*t)->name = malloc((strlen(nombre)+1)*sizeof(char));
    if((*t)->name == NULL) {
        free(*t);
        return -1;
    }
    strcpy((*t)->name, nombre);
    (*t)->graph = createGraph();
    if((*t)->graph == NULL) {
        free((*t)->name);
        free(*t);
        return -1;
    }
    return 0;
}

int abrirClase(tablaSimbolosClases* t, char* id_clase) {
    Class* class;
    if(t == NULL || id_clase == NULL)
        return -1;
    class = malloc(sizeof(Class));
    if(class == NULL)
        return -1;
    strcpy(class->name, id_clase);
    tablaInit(&class->tabla, id_clase);
    return addClass(t->graph, class);
}

int abrirClaseHereda(tablaSimbolosClases* t, char* id_clase, ...) {
    va_list ap;
    Class *parent;
    char* next;
    int i;
    int cid = abrirClase(t, id_clase);
    if(cid == -1)
        return -1;
    va_start(ap, id_clase);
    while( (next=va_arg(ap, char*)) != NULL) {
        for(i = 0; (parent=getClass(t->graph, i)) != NULL; i++) {
            if(strcpy(next, parent->name) == 0) {
                break;
            }
        }
        if(parent != NULL) {
            addEdge(t->graph, parent->index, cid);
        }
    }
    va_end(ap);
    return 0;
}

int cerrarClase(tablaSimbolosClases* t,
                char* id_clase, 
                int num_atributos_clase, 
                int num_atributos_instancia, 
                int num_metodos_sobreescribibles, 
                int num_metodos_no_sobreescribibles) {
    int i;
    Class *class;
    if(t == NULL || id_clase == NULL)
        return -1;
    for(i = 0; (class=getClass(t->graph, i)) != NULL; i++) {
        if(strcmp(id_clase, class->name) == 0) {
            break;
        }
    }
    if(class == NULL)
        return -1;
    class->num_at_c = num_atributos_clase;
    class->num_at_i = num_atributos_instancia;
    class->num_me_s = num_metodos_sobreescribibles;
    class->num_me_ns = num_metodos_no_sobreescribibles;
    return 0;
}

int cerrarTablaSimbolosClases(tablaSimbolosClases* t) {
    int i;
    Class* class;
    if(t == NULL)
        return -1;
    free(t->name);
    for(i = 0; (class=getClass(t->graph, i)) != NULL; i++) {
        free(class);
    }
    freeGraph(t->graph);
    free(t);
    return 0;
}

