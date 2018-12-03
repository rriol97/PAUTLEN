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
    return cid;
}

int abrirClaseHeredaN(TablaSimbolosClases* t, char* id_clase, char** id_clase_hereda, int num_clases_hereda) {
    NodoGrafo *parent;
    int i;
    int cid = abrirClase(t, id_clase);
    if(cid == -1)
        return -1;
    for(i = 0; i < num_clases_hereda; i++) {
        parent = graphGetClassFromName(t->graph, id_clase_hereda[i]);
        if(parent != NULL) {
            graphAddEdge(t->graph, parent->index, cid);
        }
    }
    return cid;
}

int AbrirAmbitoPrefijos(TablaAmbito * tabla,
                                    char * id_clase,
                                    char* id_ambito,
                                    int categoria_ambito,
                                    int acceso_metodo,
                                    int tipo_metodo,
                                    int posicion_metodo_sobre,
                                    int tamanio) {
    char nombre_real[MAX_NAME];
                               
    if(strlen(tabla->func_name) > 0) {
        /*ya hay una funcion abierta, no se permite anidar funciones*/
        return -1;
    }

    /*inicializa el nombre de funcion*/
    strcpy(tabla->func_name, id_ambito);
    sprintf(nombre_real, "%s_%s", id_clase, id_ambito);
    
    /*inserta el simbolo de la funcion en su propia tabla*/
    insertarTablaSimbolosAmbitos(tabla, id_clase,
        nombre_real, categoria_ambito,
        tipo_metodo, /*??*/ FUNCION,
        0, /*??*/ 0, /*por donde se pasa esto?*/
        0, /*??*/ 0, /*??*/
        0, /*??*/
        tamanio,
        0, 0,
        0, 0,
        acceso_metodo, tipo_metodo, /*??*/
        0, posicion_metodo_sobre,
        0, 0, /*??*/
        0,
        posicion_metodo_sobre, /*??*/
        NULL); /*??*/
    return 0;
}

int abrirAmbitoEnClase(TablaSimbolosClases * grafo,
                                  char * id_clase,
                                  char* id_ambito,
                                  int categoria_ambito,
                                  int acceso_metodo,
                                  int tipo_metodo,
                                  int posicion_metodo_sobre, int tamanio){
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
        int tipo, int estructura,
        int direcciones, int numero_parametros,
        int numero_variables_locales,int posicion_variable_local,
        int posicion_parametro,
        int tamanio,
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
    
    strcpy(elemento->clave, id);
    elemento->clase = clase;
    elemento->tipo = tipo;
    elemento->estructura = estructura;
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
    if(strlen(tabla->func_name) == 0) /*no hay funcion abierta*/
        insert_symbol(&(tabla->th_ppal), elemento->clave, elemento);
    else
        insert_symbol(&(tabla->th_func), elemento->clave, elemento);
    return 0;
}

int insertarTablaSimbolosClases(TablaSimbolosClases * grafo, char * id_clase,
        char* id, int clase,
        int tipo, int estructura,
        int direcciones, int numero_parametros,
        int numero_variables_locales,int posicion_variable_local,
        int posicion_parametro,
        int tamanio,
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
        id, clase, tipo, estructura, direcciones, numero_parametros,
        numero_variables_locales,posicion_variable_local,
        posicion_parametro,
        tamanio,
        numero_atributos_clase,numero_atributos_instancia,
        numero_metodos_sobreescribibles, numero_metodos_no_sobreescribibles,
        tipo_acceso,tipo_miembro,
        posicion_atributo_instancia,posicion_metodo_sobreescribible,
        num_acumulado_atributos_instancia,num_acumulado_metodos_sobreescritura,
        posicion_acumulada_atributos_instancia,
        posicion_acumulada_metodos_sobreescritura,
        tipo_args);
}

int buscarTablaSimbolosAmbitosConPrefijos(TablaAmbito * t, char* id, elementoTablaSimbolos** e,
    char* id_ambito, char* nombre_ambito_encontrado){
    char nombre_real[MAX_NAME];

    if(strlen(t->func_name) > 0) {
        /*funcion abierta: busca tambien en la tabla de funcion*/
        strcpy(nombre_real, t->func_name);
        strcat(nombre_real, "_");
        strcat(nombre_real, id);

        *e = find_symbol(&(t->th_func), nombre_real);
        if(*e != NULL) {
            strcpy(nombre_ambito_encontrado, t->func_name);
            return OK;
        }
    }

    strcpy(nombre_real, id_ambito);
    strcat(nombre_real, "_");
    strcat(nombre_real, id);
    *e = find_symbol(&(t->th_ppal), nombre_real);
    if(*e != NULL) {
        strcpy(nombre_ambito_encontrado, id_ambito);
        return OK;
    }
    return ERR;
}


int aplicarAccesos(TablaSimbolosClases* t, char* nombre_clase_ambito_actual, char* clase_declaro, elementoTablaSimbolos* pelem) {
    NodoGrafo* nodo;
    NodoLista* padres;
    int flag;

    if(strcmp(nombre_clase_ambito_actual, "main") == 0) {
        /*caso main*/
        if(pelem->tipo_acceso == ACCESO_CLASE) {
            return ERR;
        } else {
            return OK;
        }
    } else {
        /*caso clases*/
        if(pelem->tipo_acceso == ACCESO_CLASE) {
            if(strcmp(nombre_clase_ambito_actual, clase_declaro) == 0) {
                return OK;
            } else {
                return ERR;
            }
        } else if(pelem->tipo_acceso == ACCESO_HERENCIA) {
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

    /*buscamos en la propia clase*/
    nodo = graphGetClassFromName(t->graph, nombre_clase_desde);
    if(nodo == NULL)
        return ERR;

    if(buscarTablaSimbolosAmbitosConPrefijos(nodo->tabla, nombre_id, e, nodo->name, nombre_ambito_encontrado) == OK) {
            return OK; /*esta en la misma clase: siempre se tiene acceso*/
    }

    /*buscamos en la jerarquia*/
    padres = graphGetAntecessorList(t->graph, nodo->index);
    for(; padres != NULL; padres = nodoListaGetNext(padres)) {
        nodo = graphGetClass(t->graph, nodoListaGetIndex(padres));

        if(buscarTablaSimbolosAmbitosConPrefijos(nodo->tabla, nombre_id, e, nodo->name, nombre_ambito_encontrado) == OK) {
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

    if(strcmp(nombre_clase_desde, "main") != 0) {
        /*caso clases*/
        if(buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_desde, e, nombre_ambito_encontrado) == OK) {
            return OK;
        }
    }
    /*caso main o variables globales para clases*/

    if(buscarTablaSimbolosAmbitosConPrefijos(tabla_main, nombre_id, e, "main", nombre_ambito_encontrado) == OK) {
        return OK;
    }
    return ERR;
}

int buscarIdCualificadoClase(TablaSimbolosClases *t, char * nombre_clase_cualifica,
        char * nombre_id, char * nombre_clase_desde,
        elementoTablaSimbolos ** e,
        char * nombre_ambito_encontrado) {

    if(buscarIdEnJerarquiaDesdeClase(t, nombre_id, nombre_clase_cualifica, e, nombre_ambito_encontrado) == OK) {
        if((*e)->tipo_miembro == MIEMBRO_UNICO)
            return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
    }
    return ERR;

}

int buscarIdCualificadoInstancia(TablaSimbolosClases *t, TablaAmbito* tabla_main,
        char * nombre_instancia_cualifica,
        char * nombre_id, char * nombre_clase_desde,
        elementoTablaSimbolos ** e,
        char * nombre_ambito_encontrado) {
    NodoGrafo* nodo;
    int clase;
    if(buscarIdNoCualificado(t, tabla_main, nombre_instancia_cualifica, nombre_clase_desde, e, nombre_ambito_encontrado) == ERR) {
        return ERR;
    }
    clase = (*e)->tipo;
    nodo = graphGetClass(t->graph, -clase);
    if(nodo == NULL) /*devuelve NULL si el tipo no era una clase*/
        return ERR;
    if(aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e) == ERR) {
        return ERR;
    }
    if(buscarIdEnJerarquiaDesdeClase(t, nombre_id, nodo->name, e, nombre_ambito_encontrado) == ERR) {
        return ERR;
    }
    return aplicarAccesos(t, nombre_clase_desde, nombre_ambito_encontrado, *e);
}

int buscarParaDeclararMiembroClase(TablaSimbolosClases *t,
        char * nombre_clase_desde,
        char * nombre_miembro,
        elementoTablaSimbolos ** e,
        char * nombre_ambito_encontrado){
    NodoGrafo* nodo;

    nodo = graphGetClassFromName(t->graph, nombre_clase_desde);

    if(nodo == NULL)
      return ERR;

    return buscarTablaSimbolosAmbitosConPrefijos(nodo->tabla,
          nombre_miembro, e, nodo->name, nombre_ambito_encontrado);
}


int buscarParaDeclararMiembroInstancia(TablaSimbolosClases *t, char * nombre_clase_desde,
    char * nombre_miembro, elementoTablaSimbolos ** e,
    char * nombre_ambito_encontrado){

    /*MUY IMPORTANTE: suponemos que nombre_miembro es ya sin el prefijo*/
    return buscarIdEnJerarquiaDesdeClase(t, nombre_miembro,
           nombre_clase_desde, e, nombre_ambito_encontrado);
}

int buscarParaDeclararIdTablaSimbolosAmbitos(TablaAmbito* t, 
                                    char* id, 
                                    elementoTablaSimbolos** e,  
                                    char* id_ambito,
                                    char * nombre_ambito_encontrado) {

    if(strlen(t->func_name) > 0) {
        /*funcion abierta: busca tambien en la tabla de funcion*/
        *e = find_symbol(&(t->th_func), id);
        if(*e != NULL) {
            strcpy(nombre_ambito_encontrado, t->func_name);
            return OK;
        }
    } else {
        *e = find_symbol(&(t->th_ppal), id);
        if(*e != NULL) {
            strcpy(nombre_ambito_encontrado, id_ambito);
            return OK;
        }
    }
    return ERR;
}

int buscarParaDeclararIdLocalEnMetodo(TablaSimbolosClases *t, 
                            char * nombre_clase,
                            char * nombre_id,
                            elementoTablaSimbolos ** e, 
                            char * nombre_ambito_encontrado) {
    NodoGrafo* nodo = graphGetClassFromName(t->graph, nombre_clase);
    if(nodo == NULL)
        return ERR;
    
    return buscarParaDeclararIdTablaSimbolosAmbitos(nodo->tabla, nombre_id, e, nodo->name, nombre_ambito_encontrado);
}

int cerrarAmbitoPrefijos(TablaAmbito* tabla) {
    strcpy(tabla->func_name, "");
    /*Ya no son necesarios los simbolos definidos en la tabla hash de funcion */
    clear_symbols(&(tabla->th_func));
    return OK;
}

int cerrarAmbitoEnClase(TablaSimbolosClases * grafo, char * id_clase){
    NodoGrafo *nodo;
    nodo = graphGetClassFromName(grafo->graph, id_clase);
    if(nodo == NULL)
        return -1;
    return cerrarAmbitoPrefijos(nodo->tabla);
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

void imprimirTabla(TablaAmbito* tabla, FILE* fsalida) {
    Hash *point, *tmp;
    elementoTablaSimbolos* e;
    int i;

    if(strlen(tabla->func_name) > 0) {
        i = 0;
        fprintf(fsalida, "=================== %s =================\n\n", tabla->func_name);
        HASH_ITER(hh, tabla->th_func, point, tmp) {
            e = point->value;
            fprintf(fsalida, "****************Posicion %d ******************\n", i);
            fprintf(fsalida, "%s\tCATEGORIA: %d\tPOS_LOCAL: %d\tPOS ATR. INSTANCIA %d Y ACUMULADA %d\tESTRUCTURA: %d\tTIPO: %d\tDIR: %d\tACCESO: %d\tMIEMBRO: %d\n", e->clave, e->clase, e->posicion_variable_local, e->posicion_atributo_instancia, e->posicion_acumulada_atributos_instancia, e->estructura, e->tipo, e->direcciones, e->tipo_acceso, e->tipo_miembro);
            i++;
        }
        fprintf(fsalida, "\n");
    }

    i = 0;
    fprintf(fsalida, "=================== %s =================\n\n", tabla->name);
    HASH_ITER(hh, tabla->th_ppal, point, tmp) {
        e = point->value;
        fprintf(fsalida, "****************Posicion %d ******************\n", i);
        fprintf(fsalida, "%s\tCATEGORIA: %d\tPOS_LOCAL: %d\tPOS ATR. INSTANCIA %d Y ACUMULADA %d\tESTRUCTURA: %d\tTIPO: %d\tDIR: %d\tACCESO: %d\tMIEMBRO: %d\n", e->clave, e->clase, e->posicion_variable_local, e->posicion_atributo_instancia, e->posicion_acumulada_atributos_instancia, e->estructura, e->tipo, e->direcciones, e->tipo_acceso, e->tipo_miembro);
        i++;
    }
    fprintf(fsalida, "\n");
}

void imprimirTablaClase(TablaSimbolosClases* tabla, char* clase, FILE* fsalida) {
    NodoGrafo* nodo = graphGetClassFromName(tabla->graph, clase);
    if(nodo == NULL)
        return;

    imprimirTabla(nodo->tabla, fsalida);
}

elementoTablaSimbolos** listaElementosTabla(TablaAmbito* tabla, int* num_elementos) {
    int i;
    elementoTablaSimbolos** elementos;
    Hash* s;
    
    if(tabla == NULL || num_elementos == NULL)
        return NULL;
    
    *num_elementos = HASH_COUNT(tabla->th_ppal);
    elementos = malloc((*num_elementos)*sizeof(elementoTablaSimbolos*));
    if (elementos == NULL)
        return NULL;
    
    for(i = 0, s = tabla->th_ppal; i < *num_elementos; i++, s=s->hh.next) {
        elementos[i] = s->value;
    }
    
    return elementos;
}
