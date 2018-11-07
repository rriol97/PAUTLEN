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

int abrirAmbitoClase(tablaAmbito** t, char* id_clase, int tamanio){
  int i;
  for(i = 0 ; i < tamanio; i++){
    tablaInit(t[i], id_clase[i]);
  }
}

int abrirClase(tablaSimbolosClases* t, char* id_clase) {
    NodoGrafo* nodo;
    if(t == NULL || id_clase == NULL)
        return -1;
    nodo = malloc(sizeof(NodoGrafo));
    if(nodo == NULL)
        return -1;
    strcpy(nodo->name, id_clase);
    tablaInit(&nodo->tabla, id_clase);
    return graphAddClass(t->graph, nodo);
}

int abrirClaseHereda(tablaSimbolosClases* t, char* id_clase, ...) {
    va_list ap;
    NodoGrafo *parent;
    char* next;
    int cid = abrirClase(t, id_clase);
    if(cid == -1)
        return -1;
    va_start(ap, id_clase);
    while( (next=va_arg(ap, char*)) != NULL) {
        parent = graphGetClassFromName(t->graph, next);
        if(parent != NULL) {
            graphAddEdge(t->graph, parent->index, cid);
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
    NodoGrafo *nodo;
    if(t == NULL || id_clase == NULL)
        return -1;

    nodo = graphGetClassFromName(t->graph, id_clase);

    if(nodo == NULL)
        return -1;
    nodo->num_at_c = num_atributos_clase;
    nodo->num_at_i = num_atributos_instancia;
    nodo->num_me_s = num_metodos_sobreescribibles;
    nodo->num_me_ns = num_metodos_no_sobreescribibles;

    return 0;
}

int cerrarTablaSimbolosClases(tablaSimbolosClases* t) {
    /*TODO: comprobar si necesitamos hacer alguna operacion aqui*/
    return 0;
}

int liberarTablaSimbolosClases(tablaSimbolosClases* t) {
    int i;
    NodoGrafo* nodo;
    if(t == NULL)
        return -1;
    free(t->name);
    for(i = 0; (nodo=graphGetClass(t->graph, i)) != NULL; i++) {
        free(nodo);
    }
    freeGraph(t->graph);
    free(t);
    return 0;
}

void graph_enrouteParentsLastNode(tablaSimbolosClases * g) {
    return;
}

void cerrarAmbito(TablaAmbito* tabla) {
    return;
}
