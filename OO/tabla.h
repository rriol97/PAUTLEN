#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include "graph.h"

typedef struct _tablaSimbolosClases tablaSimbolosClases;

int iniciarTablaSimbolosClases(tablaSimbolosClases** t, char * nombre);

int abrirAmbitoClase(tablaAmbito** t, char* id_clase, int tamanio);

int abrirClase(tablaSimbolosClases* t, char* id_clase);

int abrirClaseHereda(tablaSimbolosClases* t, char* id_clase, ...);

int insertarTablaSimbolosClases(tablaSimbolosClases * grafo, char * id_clase,
    char* id,                        int clase,
    int tipo,                        int estructura,
    int direcciones,                    int numero_parametros,
    int numero_variables_locales,        int posicion_variable_local,
    int posicion_parametro,            int dimension,
    int tamanio,                    int filas,
    int columnas,                    int capacidad,
    int numero_atributos_clase,            int numero_atributos_instancia,
    int numero_metodos_sobreescribibles,    int numero_metodos_no_sobreescribibles,
    int tipo_acceso,                  int tipo_miembro,
    int posicion_atributo_instancia,        int posicion_metodo_sobreescribible,
    int num_acumulado_atributos_instancia,    int num_acumulado_metodos_sobreescritura,
    int posicion_acumulada_atributos_instancia,
    int posicion_acumulada_metodos_sobreescritura,
    int * tipo_args);

int tablaSimbolosClasesAbrirAmbitoEnClase(    tablaSimbolosClases * grafo,
                                    char * id_clase,
                                    char* id_ambito,
                                    int categoria_ambito,
                                    int acceso_metodo,
                                    int tipo_metodo,
                                    int posicion_metodo_sobre,
                                    int tamanio);

int tablaSimbolosClasesCerrarAmbitoEnClase(    tablaSimbolosClases * grafo,
                                                                char * id_clase);
int cerrarClase(tablaSimbolosClases* t,
                char* id_clase,
                int num_atributos_clase,
                int num_atributos_instancia,
                int num_metodos_sobreescribibles,
                int num_metodos_no_sobreescribibles);

int cerrarTablaSimbolosClases(tablaSimbolosClases* t);

int liberarTablaSimbolosClases(tablaSimbolosClases* t);

void graph_enrouteParentsLastNode(tablaSimbolosClases * g);

void cerrarAmbito(TablaAmbito* tabla);

#endif
