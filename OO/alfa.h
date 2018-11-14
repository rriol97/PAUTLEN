#define MAX_LONG_ID 50
#define MAX_TAMANIO_VECTOR 64
#define MAX_FILAS_VECTOR 64
#define MAX_COLUMNAS_VECTOR 64
#define MAX_CAPACIDAD_CONJUNTO 64

/* CATEGORIAS */
#define VARIABLE 1
#define PARAMETRO 2
#define FUNCION 3
#define CLASE 4
/* PARA OMICRON */
#define METODO_SOBREESCRIBIBLE 5
#define METODO_NO_SOBREESCRIBIBLE 6
#define ATRIBUTO_CLASE 7
#define ATRIBUTO_INSTANCIA 8

#define NINGUNO 0 /* ES COMUN PARA ACESO Y TIPO DE MIEMBRO */

#define ACCESO_CLASE 2   /* HIDDEN */
#define ACCESO_HERENCIA 1        /* SECRET */
#define ACCESO_TODOS 3        /* EXPOSED O NADA */

#define MIEMBRO_UNICO 1  /* PARA ATRIBUTOS DE CLASE Y MÉTODOS NO SOBREESCRIBIBLES */
#define MIEMBRO_NO_UNICO 2  /* PARA ATRIBUTOS DE INSTANCIA Y MÉTODOS SOBREESCRIBIBLES */


/* PARA OMICRON */

/* CLASES */
#define ESCALAR 1
#define PUNTERO 2
#define VECTOR 3
#define CONJUNTO 4
/* PARA CLASES */
#define OBJETO 5
/* PARA CLASES */

/* TIPOS */
#define INT 1
#define FLOAT 2
#define BOOLEAN 3
/* PARA CLASES */
/* LAS CLASES UTILIZARAN COMO SU TIPO -1 * INDICE EN EL VECTOR DE CLASES LINEALIZADO DEL GRAFO DE CLASES */
/* PARA CLASES */


#define ERR -1
#define OK 0

#define TOK_ERROR -1

