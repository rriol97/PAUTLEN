/********************************
Fichero: prueba_TS.h
Autores: Francisco de Vicente Lana, Miguel García Moya, Manuel Suárez y Ricardo Riol González
Descripcion: libreria de definiciones e inclusiones
*********************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

/* OPERACIONES*/
#define TOK_OP_INICIA_TSA_MAIN        "inicia_tsa_main"
#define TOK_OP_ABRIR_AMBITO_PPAL_MAIN    "abrir_ambito_ppal_main"
#define TOK_OP_BUSCAR            "buscar"
#define TOK_OP_INSERTAR_TSA_MAIN     "insertar_tsa_main"
#define TOK_OP_ABRIR_AMBITO_TSA_MAIN    "abrir_ambito_tsa_main"
#define TOK_OP_CERRAR_AMBITO_TSA_MAIN    "cerrar_ambito_tsa_main"
#define TOK_OP_INICIA_TSC         "inicia_tsc"
/*...*/
#define TOK_OP_CERRAR_CLASE        "cerrar_clase"
#define TOK_OP_CERRAR_TSA_MAIN        "cerrar_tsa_main"
#define TOK_OP_CERRAR_TSC        "cerrar_tsc"

/* PARAMETROS*/
#define TOK_DECLARAR_MAIN        "declarar_main"
#define TOK_DECLARAR_MIEMBRO_CLASE    "declarar_miembro_clase"
#define TOK_DECLARAR_MIEMBRO_INSTANCIA    "declarar_miembro_instancia"
#define TOK_DECLARAR_ID_LOCAL_METODO    "declarar_id_local_metodo"
#define TOK_JERARQUIA    "jerarquia"
#define TOK_ID_NO_CUALIFICADO    "id_no_cualificado"
#define TOK_ID_CUALIFICADO_INSTANCIA    "id_cualificado_instancia"
#define TOK_ID_CUALIFICADO_CLASE    "id_cualificado_clase"


void gestiona_ABRIR_CLASE();
void gestiona_ABRIR_CLASE_HEREDA ();
void gestiona_INSERTAR_TSC();
void gestiona_ABRIR_AMBITO_TSC();
void gestiona_CERRAR_AMBITO_TSC ();
void gestiona_CERRAR_CLASE ();
void gestiona_CERRAR_TSA_MAIN();
void gestiona_CERRAR_TSC();