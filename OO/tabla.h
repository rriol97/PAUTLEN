#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include "graph.h"
#include "alfa.h"

typedef struct elemento {
    char clave[MAX_NAME];    
    int categoria; /* VARIABLE PARAMETRO FUNCION CLASE METODO_SOBREESCRIBIBLE METODO_NO_SOBREESCRIBIBLE ATRIBUTO_CLASE ATRIBUTO_INSTANCIA */
    int tipo; /* INT BOOLEAN Y PARA LAS CLASES, ALGÚN MECANISMO (-índice en el vector del grafo??)  */
    int clase; /* ESCALAR PUNTERO OBJETO */
    int direcciones; /* >=1  SI ES VARIABLE 1*/
    int numero_parametros; /* >=0 */
    int numero_variables_locales; /* >=0 */
    int posicion_variable_local; /* >=1 */
    int posicion_parametro; /* >=0 */
    int tamanio;        /* 1-64 */
    /* INFORMACION PARA CLASES */
    int numero_atributos_clase;
    int numero_atributos_instancia;
    int numero_metodos_sobreescribibles;
    int numero_metodos_no_sobreescribibles;
    int tipo_acceso; /*NINGUNO (exposed) ACCESO_CLASE (hidden) ACCESO_HERENCIA (secret) ACCESO_TODOS (exposed) */
    int tipo_miembro; /*MIEMBRO_UNICO (unique) MIEMBRO_NO_UNICO*/
    int posicion_atributo_instancia;
    int posicion_metodo_sobreescribible;
    int num_acumulado_atributos_instancia;
    int num_acumulado_metodos_sobreescritura;
    int posicion_acumulada_atributos_instancia;
    int posicion_acumulada_metodos_sobreescritura;
    int * tipo_args;
} elementoTablaSimbolos;

typedef struct _TablaSimbolosClases TablaSimbolosClases;

/**********************************************************
 **********************************************************
 **********************************************************
 *************     FUNCIONES DE APERTURA      *************
 **********************************************************
 **********************************************************
 **********************************************************/

int iniciarTablaSimbolosClases(TablaSimbolosClases** t, char * nombre);

int abrirAmbitoClase(TablaAmbito** t, char* id_clase, int tamanio);

int abrirClase(TablaSimbolosClases* t, char* id_clase);

int abrirClaseHereda(TablaSimbolosClases* t, char* id_clase, ...);

int AbrirAmbitoPrefijos(TablaAmbito * tabla,
                                    char * id_clase,
                                    char* id_ambito,
                                    int categoria_ambito,
                                    int acceso_metodo,
                                    int tipo_metodo,
                                    int posicion_metodo_sobre,
                                    int tamanio);

int tablaSimbolosClasesAbrirAmbitoEnClase(TablaSimbolosClases * grafo,
                                    char * id_clase,
                                    char* id_ambito,
                                    int categoria_ambito,
                                    int acceso_metodo,
                                    int tipo_metodo,
                                    int posicion_metodo_sobre,
                                    int tamanio);

/**********************************************************
 **********************************************************
 **********************************************************
 *************     FUNCIONES DE INSERCION     *************
 **********************************************************
 **********************************************************
 **********************************************************/

int insertarTablaSimbolosAmbitos(TablaAmbito * tabla, char * id_clase,
        char* id, int clase,
        int tipo, int categoria,
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
        int * tipo_args);

int insertarTablaSimbolosClases(TablaSimbolosClases * grafo, char * id_clase,
        char* id, int clase,
        int tipo, int categoria,
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
        int * tipo_args);

/**********************************************************
 **********************************************************
 **********************************************************
 *************      FUNCIONES DE BUSQUEDA     *************
 **********************************************************
 **********************************************************
 **********************************************************/

int aplicarAccesos(TablaSimbolosClases* t, char* nombre_clase_ambito_actual, char* clase_declaro, elementoTablaSimbolos* pelem);

int buscarIdEnJerarquiaDesdeClase(TablaSimbolosClases *t, char * nombre_id,
		char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

int buscarIdNoCualificado(TablaSimbolosClases *t, TablaAmbito* tabla_main,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

int buscarIdCualificadoClase(TablaSimbolosClases *t, char * nombre_clase_cualifica,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

int buscarIdCualificadoInstancia(TablaSimbolosClases *t, TablaAmbito* tabla_main,
		char * nombre_instancia_cualifica,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

/**********************************************************
 **********************************************************
 **********************************************************
 *************      FUNCIONES DE CIERRE       *************
 **********************************************************
 **********************************************************
 **********************************************************/

int cerrarAmbitoPrefijos(TablaAmbito* tabla);

int cerrarAmbitoEnClase(TablaSimbolosClases * grafo,
		char * id_clase);

void cerrarAmbito(TablaAmbito* tabla);

int cerrarClase(TablaSimbolosClases* t,
                char* id_clase,
                int num_atributos_clase,
                int num_atributos_instancia,
                int num_metodos_sobreescribibles,
                int num_metodos_no_sobreescribibles);

int cerrarTablaSimbolosClases(TablaSimbolosClases* t);

void graph_enrouteParentsLastNode(TablaSimbolosClases * g);

/**********************************************************
 **********************************************************
 **********************************************************
 *************        OTRAS FUNCIONES         *************
 **********************************************************
 **********************************************************
 **********************************************************/

int liberarTablaSimbolosClases(TablaSimbolosClases* t);

void tablaSimbolosClasesToDot(TablaSimbolosClases* tabla, FILE* fsalida);

#endif
