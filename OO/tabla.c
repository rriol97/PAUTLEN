#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "tabla.h"

struct _TablaSimbolosClases {
    char* name;
    Graph* graph;
} ;

int iniciarTablaSimbolosClases(TablaSimbolosClases** t, char * nombre) {
    if(t == NULL || nombre == NULL) {
        return -1;
    }
    *t = (TablaSimbolosClases *) malloc(sizeof(TablaSimbolosClases));
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

int abrirAmbitoClase(TablaAmbito** t, char* id_clase, int tamanio){
    if(t == NULL || id_clase == NULL)
        return -1;
    *t = tablaInit(id_clase);
    /*TODO: que cojones es tamanio?*/
    return 0;
}

int abrirClase(TablaSimbolosClases* t, char* id_clase) {
    NodoGrafo* nodo;
    if(t == NULL || id_clase == NULL)
        return -1;
    nodo = malloc(sizeof(NodoGrafo));
    if(nodo == NULL)
        return -1;
    strcpy(nodo->name, id_clase);
    nodo->tabla = tablaInit(id_clase);
    return graphAddClass(t->graph, nodo);
}

int abrirClaseHereda(TablaSimbolosClases* t, char* id_clase, ...) {
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

int AbrirAmbitoPrefijos(TablaAmbito * tabla,
                                    char * id_clase,
                                    char* id_ambito,
                                    int categoria_ambito,
                                    int acceso_metodo,
                                    int tipo_metodo,
                                    int posicion_metodo_sobre,
                                    int tamanio) {

    /*añadir funcion a tabla hash ppal?*/
    /*inicializar tabla hash func*/

    return 0;
}

int tablaSimbolosClasesAbrirAmbitoEnClase(TablaSimbolosClases * grafo,
                                  char * id_clase,
                                  char* id_ambito,
                                  int categoria_ambito,
                                  int acceso_metodo,
                                  int tipo_metodo,
                                  int posicion_metodo_sobre, int tamanio){
    /*TODO para que demonios sirve el resto de cosas?¿?¿
    Son los datos de la funcion que tiene asociado el ambito que abrimos*/
    NodoGrafo * nodo;
    if(grafo == NULL || id_clase == NULL || id_ambito == NULL)
        return -1;
    nodo = graphGetClassFromName(grafo->graph, id_clase);
    if(nodo == NULL)
        return -1;
    return AbrirAmbitoPrefijos(nodo->tabla,
        id_clase,
        id_ambito,
        categoria_ambito,
        acceso_metodo,
        tipo_metodo,
        posicion_metodo_sobre, tamanio);
}

int insertarTablaSimbolosAmbitos(TablaAmbito * tabla, char * id_clase,
        char* id, int clase,
        int tipo, int categoria,
        int direcciones, int numero_parametros,
        int numero_variables_locales,int posicion_variable_local,
        int posicion_parametro,
        int tamanio,int filas,
        int columnas, int capacidad,
        int numero_atributos_clase,int numero_atributos_instancia,
        int numero_metodos_sobreescribibles, int numero_metodos_no_sobreescribibles,
        int tipo_acceso,int tipo_miembro,
        int posicion_atributo_instancia,int posicion_metodo_sobreescribible,
        int num_acumulado_atributos_instancia,int num_acumulado_metodos_sobreescritura,
        int posicion_acumulada_atributos_instancia,
        int posicion_acumulada_metodos_sobreescritura,
        int * tipo_args) {
    elementoTablaSimbolos* elemento;
    elemento = malloc(sizeof(elementoTablaSimbolos));
    if(elemento == NULL)
        return -1;
    elemento->clave = malloc(sizeof(char)*(strlen(id_clase)+1));
    if(elemento->clave == NULL) {
        free(elemento);
        return -1;
    }
    strcpy(elemento->clave, id_clase);
    elemento->clase = clase;
    elemento->tipo = tipo;
    elemento->categoria = categoria;
    elemento->direcciones = direcciones;
    elemento->numero_parametros = numero_parametros;
    elemento->numero_variables_locales = numero_variables_locales;
    elemento->posicion_variable_local = posicion_variable_local;
    elemento->posicion_parametro = posicion_parametro;
    elemento->tamanio = tamanio;
    elemento->numero_atributos_clase = numero_atributos_clase;
    elemento->numero_atributos_instancia = numero_atributos_instancia;
    elemento->numero_metodos_sobreescribibles = numero_metodos_sobreescribibles;
    elemento->numero_metodos_no_sobreescribibles = numero_metodos_no_sobreescribibles;
    elemento->tipo_acceso = tipo_acceso;
    elemento->tipo_miembro = tipo_miembro;
    elemento->posicion_atributo_instancia = posicion_atributo_instancia;
    elemento->posicion_metodo_sobreescribible = posicion_metodo_sobreescribible;
    elemento->num_acumulado_atributos_instancia = num_acumulado_atributos_instancia;
    elemento->num_acumulado_metodos_sobreescritura = num_acumulado_metodos_sobreescritura;
    elemento->posicion_acumulada_atributos_instancia = posicion_acumulada_atributos_instancia;
    elemento->posicion_acumulada_metodos_sobreescritura = posicion_acumulada_metodos_sobreescritura;
    elemento->tipo_args = tipo_args;
    insert_symbol(&(tabla->th_ppal), id_clase, elemento);
    return 0;
}

int insertarTablaSimbolosClases(TablaSimbolosClases * grafo, char * id_clase,
        char* id, int clase,
        int tipo, int categoria,
        int direcciones, int numero_parametros,
        int numero_variables_locales,int posicion_variable_local,
        int posicion_parametro,
        int tamanio,int filas,
        int columnas, int capacidad,
        int numero_atributos_clase,int numero_atributos_instancia,
        int numero_metodos_sobreescribibles, int numero_metodos_no_sobreescribibles,
        int tipo_acceso,int tipo_miembro,
        int posicion_atributo_instancia,int posicion_metodo_sobreescribible,
        int num_acumulado_atributos_instancia,int num_acumulado_metodos_sobreescritura,
        int posicion_acumulada_atributos_instancia,
        int posicion_acumulada_metodos_sobreescritura,
        int * tipo_args) {
    NodoGrafo* nodo;
    if(grafo == NULL || id_clase == NULL)
        return -1;
    nodo = graphGetClassFromName(grafo->graph, id_clase);
    if(nodo == NULL)
        return -1;
    return insertarTablaSimbolosAmbitos(nodo->tabla, id_clase,
        id, clase, tipo, categoria, direcciones, numero_parametros,
        numero_variables_locales,posicion_variable_local,
        posicion_parametro,
        tamanio,filas,
        columnas, capacidad,
        numero_atributos_clase,numero_atributos_instancia,
        numero_metodos_sobreescribibles, numero_metodos_no_sobreescribibles,
        tipo_acceso,tipo_miembro,
        posicion_atributo_instancia,posicion_metodo_sobreescribible,
        num_acumulado_atributos_instancia,num_acumulado_metodos_sobreescritura,
        posicion_acumulada_atributos_instancia,
        posicion_acumulada_metodos_sobreescritura,
        tipo_args);
}


int aplicarAccesos(TablaSimbolosClases* t, char* nombre_clase_ambito_actual, char* clase_declaro, elementoTablaSimbolos* pelem) {
    NodoGrafo* nodo;
    NodoLista* padres;
    int flag;

    if(strcmp(nombre_clase_ambito_actual, "main") == 0) {
        /*caso main*/
        if(pelem->tipo_acceso == ACCESO_HERENCIA) {
            return ERR;
        } else {
            return OK;
        }
    } else {
        /*caso clases*/
        if(pelem->tipo_acceso == ACCESO_HERENCIA) {
            if(strcmp(nombre_clase_ambito_actual, clase_declaro) == 0) {
                return OK;
            } else {
                return ERR;
            }
        } else if(pelem->tipo_acceso == ACCESO_CLASE) {
            if(strcmp(nombre_clase_ambito_actual, clase_declaro) == 0) {
                return OK;
            } else {
                /*buscar en padres*/
                nodo = graphGetClassFromName(t->graph, nombre_clase_ambito_actual);
                if(nodo == NULL) {
                    return ERR;
                }
                padres = graphGetAntecessorList(t->graph, nodo->index);
                for(flag = 0; padres != NULL; padres = nodoListaGetNext(padres)) {
                    nodo = graphGetClass(t->graph, nodoListaGetIndex(padres));
                    if(strcmp(nodo->name, clase_declaro) == 0) {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) { /*no se ha encontrado clase_declaro en padres*/
                    return ERR;
                } else {
                    return OK;
                }
            }
        } else {
            return OK;
        }
    }

}

int buscarIdEnJerarquiaDesdeClase(TablaSimbolosClases *t, char * nombre_id,
		char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado) {
    NodoGrafo* nodo;
    NodoLista* padres;
    char nombre_real[MAX_NAME];
    
    /*buscamos en la propia clase*/
    nodo = graphGetClassFromName(t->graph, nombre_clase_desde);
    if(nodo == NULL)
        return ERR;
    strcpy(nombre_real, nodo->name);
    strcat(nombre_real, "_");
    strcat(nombre_real, nombre_id);
    *e = find_symbol(&(nodo->tabla->th_ppal), nombre_real);
    if(*e != NULL) {
        nombre_ambito_encontrado = nodo->name;
        return OK; /*esta en la misma clase: siempre se tiene acceso*/
    }

    /*buscamos en la jerarquia*/
    padres = graphGetAntecessorList(t->graph, nodo->index);
    for(; padres != NULL; padres = nodoListaGetNext(padres)) {
        nodo = graphGetClass(t->graph, nodoListaGetIndex(padres));
        strcpy(nombre_real, nodo->name);
        strcat(nombre_real, "_");
        strcat(nombre_real, nombre_id);
        *e = find_symbol(&(nodo->tabla->th_ppal), nombre_real);
        if(*e != NULL) {
            nombre_ambito_encontrado = nodo->name;
            return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
        }
    }
    /*no se ha encontrado en la jerarquia*/
    return ERR;
}

int buscarIdNoCualificado(TablaSimbolosClases *t, TablaAmbito* tabla_main,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado) {
    char nombre_real[MAX_NAME];

    if(strcmp(nombre_clase_desde, "main") != 0) {
        /*caso clases*/
        if(buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado) == OK) {
            return OK;
        }
    }
    /*caso main o variables globales para clases*/
    strcpy(nombre_real, "main_");
    strcat(nombre_real, nombre_id);
    *e = find_symbol(&(tabla_main->th_ppal), nombre_real);
    if(e != NULL) {
        nombre_ambito_encontrado = tabla_main->name;
        return OK;
    }
    return ERR;
}

int tablaSimbolosClasesCerrarAmbitoEnClase(TablaSimbolosClases * grafo, char * id_clase){
    NodoGrafo *nodo;
    nodo = graphGetClassFromName(grafo->graph, id_clase);
    if(nodo == NULL)
        return -1;
    /*Ya no son necesarios los simbolos definidos en la tabla hash de funcion */
    clear_symbols(&(nodo->tabla->th_func));
    return 0;
}

void cerrarAmbito(TablaAmbito* tabla) {
    return;
}

int cerrarClase(TablaSimbolosClases* t,
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

int cerrarTablaSimbolosClases(TablaSimbolosClases* t) {
    /*TODO: comprobar si necesitamos hacer alguna operacion aqui*/
    return 0;
}


void graph_enrouteParentsLastNode(TablaSimbolosClases * g) {
    return;
}

int liberarTablaSimbolosClases(TablaSimbolosClases* t) {
    int i;
    NodoGrafo* nodo;
    if(t == NULL)
        return -1;
    free(t->name);
    for(i = 0; (nodo=graphGetClass(t->graph, i)) != NULL; i++) {
        tablaFree(nodo->tabla);
        free(nodo);
    }
    freeGraph(t->graph);
    free(t);
    return 0;
}

void tablaSimbolosClasesToDot(TablaSimbolosClases* tabla, FILE* fsalida) {
    graphToDot(tabla->graph, fsalida);
}
