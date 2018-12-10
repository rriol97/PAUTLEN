#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include "graph.h"
#include "alfa.h"

typedef struct elemento {
    char clave[MAX_NAME];
    int clase; /* VARIABLE PARAMETRO FUNCION CLASE METODO_SOBREESCRIBIBLE METODO_NO_SOBREESCRIBIBLE ATRIBUTO_CLASE ATRIBUTO_INSTANCIA */
    int tipo; /* INT BOOLEAN Y PARA LAS CLASES, ALGÚN MECANISMO (-índice en el vector del grafo??)  */
    int estructura; /* ESCALAR PUNTERO OBJETO */
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

#define PREFIJO_TABLA_METODOS_SOBREESCRIBIBLES "_ms"
#define MAX_ETIQUETAS     32768

/**********************************************************
 **********************************************************
 **********************************************************
 *************     FUNCIONES DE APERTURA      *************
 **********************************************************
 **********************************************************
 **********************************************************/

/*inicializa tabla de clases*/
int iniciarTablaSimbolosClases(TablaSimbolosClases** t, char * nombre);

/*inicializa main (equivalente a tablaInit)*/
int abrirAmbitoClase(TablaAmbito** t, char* id_clase, int tamanio);

/*crea una clase raiz en el grafo*/
int abrirClase(TablaSimbolosClases* t, char* id_clase);

/*crea una clase que hereda de un numero arbitrario de clases ya definidas*/
int abrirClaseHereda(TablaSimbolosClases* t, char* id_clase, ...);

/*crea una clase que hereda de un numero arbitrario de clases ya definidas: def alternativa*/
int abrirClaseHeredaN(TablaSimbolosClases* t, char* id_clase, char** id_clase_hereda, int num_clases_hereda);

/*abre funcion en main*/
int AbrirAmbitoPrefijos(TablaAmbito * tabla,
                                    char * id_clase,
                                    char* id_ambito,
                                    int categoria_ambito,
                                    int acceso_metodo,
                                    int tipo_metodo,
                                    int posicion_metodo_sobre,
                                    int tamanio);

/*abre metodo en clase*/
int abrirAmbitoEnClase(TablaSimbolosClases * grafo,
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

/*inserta en main*/
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
        int * tipo_args);

/*inserta en clase*/
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
        int * tipo_args);

/**********************************************************
 **********************************************************
 **********************************************************
 *************      FUNCIONES DE BUSQUEDA     *************
 **********************************************************
 **********************************************************
 **********************************************************/

/*funcion de busqueda general: llamada por las siguientes*/
int buscarTablaSimbolosAmbitosConPrefijos(TablaAmbito * t, char* id, elementoTablaSimbolos** e,
    char* id_ambito, char* nombre_ambito_encontrado);

/*devuelve si es accesible: llamada por las siguientes*/
int aplicarAccesos(TablaSimbolosClases* t, char* nombre_clase_ambito_actual, char* clase_declaro, elementoTablaSimbolos* pelem);

/*busca id en clase: llamada por las siguientes*/
int buscarIdEnJerarquiaDesdeClase(TablaSimbolosClases *t, char * nombre_id,
		char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

/*busca id tal cual: para variabls globales, locales y en general variables que no tengan nada delante*/
int buscarIdNoCualificado(TablaSimbolosClases *t, TablaAmbito* tabla_main,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

/*busca id de clase: para casos del estilo buscar AA.aa donde AA es clase y aa es atributo "static" de AA*/
int buscarIdCualificadoClase(TablaSimbolosClases *t, char * nombre_clase_cualifica,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

/*busca id de instancia: para casos del estilo b.bb donde b es una variable de la clase BB y bb atributo "normal" de BB */
int buscarIdCualificadoInstancia(TablaSimbolosClases *t, TablaAmbito* tabla_main,
		char * nombre_instancia_cualifica,
		char * nombre_id, char * nombre_clase_desde,
		elementoTablaSimbolos ** e,
		char * nombre_ambito_encontrado);

/*busca para declarar atributo/metodo "static" de una clase*/
int buscarParaDeclararMiembroClase(TablaSimbolosClases *t,
    char * nombre_clase_desde,
    char * nombre_miembro,
    elementoTablaSimbolos ** e,
    char * nombre_ambito_encontrado);

/*busca para declarar atributo/metodo "normal" de una clase*/
int buscarParaDeclararMiembroInstancia(TablaSimbolosClases *t, char * nombre_clase_desde,
    char * nombre_miembro, elementoTablaSimbolos ** e,
    char * nombre_ambito_encontrado);

/*busca para declarar en main*/
int buscarParaDeclararIdTablaSimbolosAmbitos(TablaAmbito* t,
                                    char* id,
                                    elementoTablaSimbolos** e,
                                    char* id_ambito,
                                    char * nombre_ambito_encontrado);

/*busca para declarar un id local en un metodo de una clase*/
int buscarParaDeclararIdLocalEnMetodo(TablaSimbolosClases *t,
                            char * nombre_clase,
                            char * nombre_id,
                            elementoTablaSimbolos ** e,
                            char * nombre_ambito_encontrado);

/**********************************************************
 **********************************************************
 **********************************************************
 *************      FUNCIONES DE CIERRE       *************
 **********************************************************
 **********************************************************
 **********************************************************/

/*cierra funcion en main*/
int cerrarAmbitoPrefijos(TablaAmbito* tabla);

/*cierra funcion en clase*/
int cerrarAmbitoEnClase(TablaSimbolosClases * grafo,
		char * id_clase);

/*cierra main*/
void cerrarAmbito(TablaAmbito* tabla);

/*cierra una clase*/
int cerrarClase(TablaSimbolosClases* t,
                char* id_clase,
                int num_atributos_clase,
                int num_atributos_instancia,
                int num_metodos_sobreescribibles,
                int num_metodos_no_sobreescribibles);

/*cierra la tabla de clases*/
int cerrarTablaSimbolosClases(TablaSimbolosClases* t);

/*funcion inutil: conservada por posible compatibilidad con ficheros de prueba*/
void graph_enrouteParentsLastNode(TablaSimbolosClases * g);

/**********************************************************
 **********************************************************
 **********************************************************
 *************        OTRAS FUNCIONES         *************
 **********************************************************
 **********************************************************
 **********************************************************/

/*liberar memoria de tabla de clases (para main usa tablaFree)*/
int liberarTablaSimbolosClases(TablaSimbolosClases* t);

/*imprime la tabla del main*/
void imprimirTabla(TablaAmbito* tabla, FILE* fsalida);

/*imprime la tabla de una clase*/
void imprimirTablaClase(TablaSimbolosClases* tabla, char* clase, FILE* fsalida);

/*crea el .dot del grafo de clases en el fichero dado*/
void tablaSimbolosClasesToDot(TablaSimbolosClases* tabla, FILE* fsalida);

/*crea la lista de elementos declarados en main
  IMPORTANTE: es necesario liberar el ** que se devuelve, pero NO LIBERAR ninguno de los * a elementos que contiene */
elementoTablaSimbolos** listaElementosTabla(TablaAmbito* tabla, int* num_elementos);


#endif
