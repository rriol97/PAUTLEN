#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include "graph.h"

typedef struct _tablaSimbolosClases tablaSimbolosClases;

int iniciarTablaSimbolosClases(tablaSimbolosClases** t, char * nombre);

int abrirAmbitoClase(tablaAmbito** t, char* id_clase, int tamanio);

int abrirClase(tablaSimbolosClases* t, char* id_clase);

int abrirClaseHereda(tablaSimbolosClases* t, char* id_clase, ...);

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
