%{
#include <stdio.h>
#include "omicron.h"
#include "generacion.h"
#include "graph.h"
#include "tabla.h"

extern int columna;
extern int fila;
extern int yylex();
extern FILE *yyin;
extern FILE *fout;
extern int flag_error;

int tipo_id_actual;
TablaAmbito * tabla_main;
elementoTablaSimbolos * elem;
char nombre_ambito_encontrado[MAX_NAME];
int tipo_declaracion;
int etiqueta = 1;
%}

%union {
    tipo_atributos atributos;
}

%token <atributos> TOK_COMENTARIO
%token <atributos> TOK_SALTO
%token <atributos> TOK_BLANCO
%token <atributos> TOK_NONE
%token <atributos> TOK_CLASS
%token <atributos> TOK_INHERITS
%token <atributos> TOK_INSTANCE_OF
%token <atributos> TOK_DISCARD
%token <atributos> TOK_ITSELF
%token <atributos> TOK_FLECHA
%token <atributos> TOK_HIDDEN
%token <atributos> TOK_SECRET
%token <atributos> TOK_EXPOSED
%token <atributos> TOK_UNIQUE

%token <atributos> TOK_FUNCTION
%token <atributos> TOK_RETURN
%token <atributos> TOK_MAIN
%token <atributos> TOK_INT
%token <atributos> TOK_BOOLEAN
%token <atributos> TOK_ARRAY
%token <atributos> TOK_IF
%token <atributos> TOK_ELSE
%token <atributos> TOK_WHILE
%token <atributos> TOK_SCANF
%token <atributos> TOK_PRINTF
%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_IGUAL
%token <atributos> TOK_DISTINTO
%token <atributos> TOK_MENORIGUAL
%token <atributos> TOK_MAYORIGUAL
%token <atributos> TOK_OR
%token <atributos> TOK_AND
%token <atributos> TOK_CONSTANTE_ENTERA
%token <atributos> TOK_FALSE
%token <atributos> TOK_TRUE
%token <atributos> TOK_ERROR
%token <atributos> TOK_FOR
%token <atributos> TOK_SWITCH
%token <atributos> TOK_CASE
%token <atributos> TOK_DEFAULT
%token <atributos> TOK_FLOAT
%token <atributos> TOK_MALLOC
%token <atributos> TOK_CPRINTF
%token <atributos> TOK_FREE
%token <atributos> TOK_SET
%token <atributos> TOK_OF
%token <atributos> TOK_UNION
%token <atributos> TOK_INTERSECTION
%token <atributos> TOK_ADD
%token <atributos> TOK_CLEAR
%token <atributos> TOK_SIZE
%token <atributos> TOK_CONTAINS
%token <atributos> TOK_CONSTANTE_REAL

%type <atributos> exp
%type <atributos> comparacion
%type <atributos> tipo
%type <atributos> clase_escalar
%type <atributos> identificador
%type <atributos> clase
%type <atributos> declaracion
%type <atributos> identificadores_declaracion
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> asignacion
%type <atributos> elemento_vector
%type <atributos> if_exp_sentencias
%type <atributos> if_exp



%left '+' '-' TOK_OR
%left '*' '/' TOK_AND
%right UNARIO '!'

%start programa

%%

programa: TOK_MAIN inicioTabla '{' declaraciones escribirHastaMain funciones sentencias '}'
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
    |
    TOK_MAIN inicioTabla '{' escribirHastaMain funciones sentencias '}'
    {
        escribir_fin(fout);
        tablaFree(tabla_main);
    }
;

inicioTabla: {
    /* Inic tabla simbolos */

    if ( abrirAmbitoClase(&tabla_main, "main", 1) == -1) { /* init tabla simbolos */
        printf("error inicializando en la tabla de simbolos");
    }
    escribir_subseccion_data(fout);
    escribir_cabecera_bss(fout);
}

escribirHastaMain: {


        //Buscamos la variable en

    //getVarsTS
    //Declararlas

    escribir_segmento_codigo(fout);
    escribir_inicio_main(fout);
}

declaraciones: declaracion
    {
        //fprintf(fout, ";R:\tdeclaraciones: declaracion\n");
    }
    |
    declaracion declaraciones
    {
        //fprintf(fout, ";R:\tdeclaraciones: declaracion, declaraciones\n");
    }
;

declaracion: modificadores_acceso clase identificadores_declaracion ';'
    {
        if ($2.tipo != $3.tipo) {
            printf("Declaracion de distintos tipos NOT GOOD\n");
        }
        // Lo suyo sería hacer aqui las declaraciones
    }
    |
    modificadores_acceso declaracion_clase ';'
    {
        //fprintf(fout, ";R:\tdeclaracion: modificadores_acceso declaracion_clase ';'\n");
    }
;

modificadores_acceso: TOK_HIDDEN TOK_UNIQUE
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN TOK_UNIQUE\n");
    }
    |
    TOK_SECRET TOK_UNIQUE
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET TOK_UNIQUE\n");
    }
    |
    TOK_EXPOSED TOK_UNIQUE
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED TOK_UNIQUE\n");
    }
    |
    TOK_HIDDEN
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_HIDDEN\n");
    }
    |
    TOK_SECRET
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_SECRET\n");
    }
    |
    TOK_EXPOSED
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_EXPOSED\n");
    }
    |
    TOK_UNIQUE
    {
        //fprintf(fout, ";R:\tmodificadores_acceso: TOK_UNIQUE\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tmodificadores_acceso:\n");
    }
;

clase: clase_escalar
    {
        //fprintf(fout, ";R:\tclase: clase_escalar\n");
        $$.tipo = $1.tipo;
    }
    |
    clase_vector
    {
        //fprintf(fout, ";R:\tclase: clase_vector\n");
    }
    |
    clase_objeto
    {
        //fprintf(fout, ";R:\tclase: clase_objeto\n");
    }
;

declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'\n");
    }
    |
    modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' funciones '}'
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'\n");
    }
    |
    modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'
    {
        //fprintf(fout, ";R:\tdeclaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'\n");
    }
;

modificadores_clase: /*vacio*/
    {
        //fprintf(fout, ";R:\tmodificadores_clase:\n");
    }
;

clase_escalar: tipo
    {
       //fprintf(fout, ";R:\tclase_escalar: tipo\n");
       $$.tipo = $1.tipo;
    }
;

tipo: TOK_INT
    {
        //fprintf(fout, ";R:\ttipo: TOK_INT\n");
        $$.tipo = ENTERO;
        tipo_declaracion = ENTERO;
    }
    |
    TOK_BOOLEAN
    {
        //fprintf(fout, ";R:\ttipo: TOK_BOOLEAN\n");
        $$.tipo = BOOLEAN;
        tipo_declaracion = BOOLEAN;
    }
;

clase_objeto: '{' TOK_IDENTIFICADOR '}'
    {
        //fprintf(fout, ";R:\tclase_objeto: '{' TOK_IDENTIFICADOR '}'\n");
    }
;

clase_vector: TOK_ARRAY tipo '[' constante_entera ']'
    {
        //fprintf(fout, ";R:\tclase_vector: TOK_ARRAY tipo '[' constante_entera ']'\n");
    }
;

identificadores: TOK_IDENTIFICADOR
    {
        //fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR\n");
    }
    |
    TOK_IDENTIFICADOR ',' identificadores
    {
        //fprintf(fout, ";R:\tidentificadores: TOK_IDENTIFICADOR ',' identificadores\n");
    }
;

identificadores_declaracion: identificador
    {
        /* Aqui solo se accede al declarar varibles */
        $$.tipo = $1.tipo;

    }
    |
    identificador ',' identificadores_declaracion
    {
      $$.tipo = $1.tipo;
    }
;

identificador: TOK_IDENTIFICADOR
{
  $$.direcciones = 1;
  $1.tipo = tipo_declaracion;

  printf("entro en una declaracion de variable (%s) [%d]\n", $1.lexema, $1.tipo);
  $$.tipo = $1.tipo;
  declarar_variable(fout, $1.lexema, $1.tipo, 1);
  // TODO: insertar en tabla simbolos
  insertarTablaSimbolosAmbitos(tabla_main, "main", $1.lexema, ESCALAR, $1.tipo, $1.direcciones, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
}

funciones: funcion funciones
    {
        //fprintf(fout, ";R:\tfunciones: funcion funciones\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tfunciones:\n");
    }
;

funcion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
    {
        //fprintf(fout, ";R:\tfuncion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'\n");
    }
;

tipo_retorno: TOK_NONE
    {
        //fprintf(fout, ";R:\ttipo_retorno: TOK_NONE\n");
    }
    |
    tipo
    {
        //fprintf(fout, ";R:\ttipo_retorno: tipo\n");
    }
    |
    clase_objeto
    {
        //fprintf(fout, ";R:\ttipo_retorno: clase_objeto\n");
    }
;

inherits: TOK_INHERITS
    {
        //fprintf(fout, ";R:\tinherits: TOK_INHERITS\n");
    }
;

parametros_funcion: parametro_funcion resto_parametros_funcion
    {
        //fprintf(fout, ";R:\tparametros_funcion: parametro_funcion resto_parametros_funcion\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tparametros_funcion:\n");
    }
;

resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
    {
        //fprintf(fout, ";R:\tresto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tresto_parametros_funcion:\n");
    }
;

parametro_funcion: tipo TOK_IDENTIFICADOR
    {
        //fprintf(fout, ";R:\tparametro_funcion: tipo TOK_IDENTIFICADOR\n");
    }
    |
    clase_objeto TOK_IDENTIFICADOR
    {
        //fprintf(fout, ";R:\tparametro_funcion: clase_objeto TOK_IDENTIFICADOR\n");
    }
;

declaraciones_funcion: declaraciones
    {
        //fprintf(fout, ";R:\tdeclaraciones_funcion: declaraciones\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tdeclaraciones_funcion:\n");
    }
;

sentencias: sentencia
    {
        //fprintf(fout, ";R:\tsentencias: sentencia\n");
    }
    |
    sentencia sentencias
    {
        //fprintf(fout, ";R:\tsentencias: sentencia sentencias\n");
    }
;

sentencia: sentencia_simple ';'
    {
        //fprintf(fout, ";R:\tsentencia: sentencia_simple ';'\n");
    }
    |
    bloque
    {
        //fprintf(fout, ";R:\tsentencia: bloque\n");
    }
;

sentencia_simple: asignacion
    {
        //fprintf(fout, ";R:\tsentencia_simple: asignacion\n");
    }
    |
    lectura
    {
        //fprintf(fout, ";R:\tsentencia_simple: lectura\n");
    }
    |
    escritura
    {
        //fprintf(fout, ";R:\tsentencia_simple: escritura\n");
    }
    |
    retorno_funcion
    {
        //fprintf(fout, ";R:\tsentencia_simple: retorno_funcion\n");
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
        //fprintf(fout, ";R:\tsentencia_simple: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
    |
    TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
        //fprintf(fout, ";R:\tsentencia_simple: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
    |
    destruir_objeto
    {
        //fprintf(fout, ";R:\tsentencia_simple: destruir_objeto\n");
    }
;

destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR
    {
        //fprintf(fout, ";R:\tdestruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR\n");
    }
;

bloque: condicional
    {
        //fprintf(fout, ";R:\tbloque: condicional\n");
    }
    |
    bucle
    {
        //fprintf(fout, ";R:\tbloque: bucle\n");
    }
;

asignacion: TOK_IDENTIFICADOR '=' exp
    {
        //Buscamos en la tabla de simbolos el tipo de $1
        if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            $1.tipo = elem->tipo;
        }
        else {
            printf("Error: Variable no encontrada\n");
        }

        if ($1.tipo != $3.tipo) {
          printf("Error: Variables distintas\n");
        }

        char aux[50];
        if ($3.direcciones == 0) {
            sprintf(aux, "%d", $3.valor_entero);

        }
        //escribir_operando(fout, aux, $3.direcciones);
        asignar(fout, $1.lexema, $3.direcciones);
    }
    |
    elemento_vector '=' exp
    {
        if ($1.tipo != $3.tipo) {
            printf("Error: tipos incompatibles");
        }
    }
    |
    elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
        //fprintf(fout, ";R:\tasignacion: elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
    |
    TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
        //fprintf(fout, ";R:\tasignacion: TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR '=' exp
    {
        //fprintf(fout, ";R:\tasignacion: identificador_clase '.' TOK_IDENTIFICADOR '=' exp\n");
    }
;

elemento_vector: TOK_IDENTIFICADOR '[' exp ']'
    {
        if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            $1.tipo = elem->tipo;
            if (elem->clase != VECTOR) {
                printf("Error: no es vector");
            }
            if ($3.tipo != ENTERO) {
                printf("Error: el indice debe ser de tipo entero");
            }

            $$.tipo = elem->tipo;
            $$.direcciones = 1;
            //Comprobacion indice, 0<i<64
        }
        else {
            printf("Error: Variable no encontrada\n");
        }
    }
;

condicional: if_exp_sentencias TOK_ELSE '{' sentencias '}'
    {
        fin_if_else(fout, $1.etiqueta);
    }
;

if_exp_sentencias: if_exp sentencias '}'
    {
        $$.etiqueta = $1.etiqueta;

        medio_if_else(fout, $1.etiqueta);
    }
;

if_exp: TOK_IF '(' exp ')' '{'
    {
        if ($3.tipo != BOOLEAN) {
            printf("Error: condicion del if no booleano");
        }
        $$.etiqueta = etiqueta;
        etiqueta++;

        inicio_if_else(fout, $$.etiqueta, $3.direcciones);
    }
;

bucle: TOK_WHILE '(' exp ')' '{' sentencias '}'
    {
        //fprintf(fout, ";R:\tbucle: TOK_WHILE '(' exp ')' '{' sentencias '}'\n");
    }
;

lectura: TOK_SCANF TOK_IDENTIFICADOR
    {
        if (buscarIdNoCualificado(NULL, tabla_main, $2.lexema, "main", &elem, nombre_ambito_encontrado) != OK) {
            printf("Error: Elem no encontrado\n");
        } else {
            if (elem->clase == FUNCION || elem->clase == VECTOR) {
                printf("Error: no se puede imprimir funciones ni vectores\n");
            }

            escribir_operando(fout, $2.lexema, $2.direcciones);
            leer(fout, $2.lexema, elem->tipo);
        }
    }
    |
    TOK_SCANF elemento_vector
    {
        //fprintf(fout, ";R:\tlectura: TOK_SCANF elemento_vector\n");
    }
;

escritura: TOK_PRINTF exp
    {
        if ($2.direcciones == 1) {
            if(buscarIdNoCualificado(NULL, tabla_main, $2.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                escribir_operando(fout, $2.lexema, $2.direcciones);
                escribir(fout, $2.direcciones, elem->tipo);
            }
            else {
                printf("Error: Elem no encontrado\n");
            }
        }
        else{
            escribir(fout, $2.direcciones, $2.tipo);
        }


    }
;

retorno_funcion: TOK_RETURN exp
    {
        //fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN exp\n");
    }
    |
    TOK_RETURN TOK_NONE
    {
        //fprintf(fout, ";R:\tretorno_funcion: TOK_RETURN TOK_NONE\n");
    }
;
  //8  +  x1
exp: exp '+' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La suma requiere que ambos operandos sean numeros");
        }

        printf("op1: %s tipo(%d) direc(%d)\n", $1.lexema, $1.tipo, $1.direcciones);
        printf("op2: %s tipo(%d) direc(%d)\n", $3.lexema, $3.tipo, $3.direcciones);

        if ($1.direcciones) {
            //escribir_operando(fout, $1.lexema, $1.direcciones);
        }
        if ($3.direcciones) {
            //escribir_operando(fout, $3.lexema, $3.direcciones);
        }

        sumar(fout, $1.direcciones, $3.direcciones);

        $$.tipo = ENTERO;
        $$.direcciones = 0;

    }
    |
    exp '-' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La resta requiere que ambos operandos sean numeros");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '/' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        if ($3.tipo == 0) {
            printf("Error: La division entre 0 no se permite");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '*' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La multiplicacion requiere que ambos operandos sean numeros");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    '-' %prec UNARIO exp
    {
        if ($2.tipo == BOOLEAN) {
            printf("Error: El cambio de signo requiere operandos que sean numeros");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp TOK_AND exp
    {
        if ($1.tipo == ENTERO || $3.tipo == ENTERO) {
            printf("Error: La conjuncion requiere operandos que sean booleans");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_OR exp
    {
        if ($1.tipo == ENTERO || $3.tipo == ENTERO) {
            printf("Error: La disyuncion requiere operandos que sean booleans");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    '!' exp
    {
        if ($2.tipo == ENTERO) {
            printf("Error: La negacion requiere operandos que sean booleans");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    TOK_IDENTIFICADOR
    {
      if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK){
          $1.tipo = elem->tipo;
      }
      else {
          printf("Error:Variable no encontrada\n");
      }
      //diapo90 gen
      escribir_operando(fout, $1.lexema, 1);

      //TODO comprobar que no sea de categoria funcion ni clase vector
      $$.tipo = elem->tipo;
      $$.direcciones = 1;
    }
    |
    constante
    {
        $$.tipo = $1.tipo;
        $$.direcciones = $1.direcciones;
    }
    |
    '(' exp ')'
    {
        $$.tipo = $2.tipo;
        $$.direcciones = $2.direcciones;
    }
    |
    '(' comparacion ')'
    {
        $$.tipo = $2.tipo;
        $$.direcciones = $2.direcciones;
    }
    |
    elemento_vector
    {
        $$.tipo = $1.tipo;
        $$.direcciones = $1.direcciones;
    }
    |
    TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
        //fprintf(fout, ";R:\texp: TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
        //fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'\n");
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR
    {
        //fprintf(fout, ";R:\texp: identificador_clase '.' TOK_IDENTIFICADOR\n");
    }
;


identificador_clase: TOK_IDENTIFICADOR
    {
        //fprintf(fout, ";R:\tidentificador_clase: TOK_IDENTIFICADOR\n");
    }
    |
    TOK_ITSELF
    {
        //fprintf(fout, ";R:\tidentificador_clase: TOK_ITSELF\n");
    }
;

lista_expresiones: exp resto_lista_expresiones
    {
        //fprintf(fout, ";R:\tlista_expresiones: exp resto_lista_expresiones\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tlista_expresiones:\n");
    }
;

resto_lista_expresiones: ',' exp resto_lista_expresiones
    {
        //fprintf(fout, ";R:\tresto_lista_expresiones: ',' exp resto_lista_expresiones\n");
    }
    |
    /*vacio*/
    {
        //fprintf(fout, ";R:\tlista_expresiones:\n");
    }
;

comparacion: exp TOK_IGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        if ($1.direcciones == 1) {
            //escribir_operando(fout, $1.lexema, $1.direcciones);
        }
        if ($3.direcciones == 1) {
            //escribir_operando(fout, $3.lexema, $3.direcciones);
        }

        igual(fout, $1.direcciones, $3.direcciones, etiqueta);
        etiqueta++;

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_DISTINTO exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_MENORIGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_MAYORIGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp '<' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp '>' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            printf("Error: La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
;

constante: constante_logica
    {
        $$.tipo = $1.tipo;
        $$.direcciones = $1.direcciones;
    }
    |
    constante_entera
    {
        $$.tipo = $1.tipo;
        $$.direcciones = $1.direcciones;
    }
;

constante_logica: TOK_TRUE
    {
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
        escribir_operando(fout, "1", 0);
    }
    |
    TOK_FALSE
    {
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
        escribir_operando(fout, "0", 0);
    }
;

constante_entera: TOK_CONSTANTE_ENTERA
    {
        $$.tipo = ENTERO;
        $$.direcciones = 0;
        sprintf($1.lexema, "%d", $1.valor_entero);
        escribir_operando(fout, $1.lexema, 0);
    }
;

%%

int yyerror(char* s) {
    if (!flag_error)
    {
        //fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    flag_error = 0;
    return -1;
}
