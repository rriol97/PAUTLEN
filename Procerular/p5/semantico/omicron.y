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
    escribir_segmento_codigo(fout);
    escribir_inicio_main(fout);
}

declaraciones: declaracion
    {
    }
    |
    declaracion declaraciones
    {
    }
;

declaracion: modificadores_acceso clase identificadores_declaracion ';'
    {
        if ($2.tipo != $3.tipo) {
            printf("Declaracion de distintos tipos NOT GOOD\n");
        }
    }
    |
    modificadores_acceso declaracion_clase ';'
    {
    }
;

modificadores_acceso: TOK_HIDDEN TOK_UNIQUE
    {
    }
    |
    TOK_SECRET TOK_UNIQUE
    {
    }
    |
    TOK_EXPOSED TOK_UNIQUE
    {
    }
    |
    TOK_HIDDEN
    {
    }
    |
    TOK_SECRET
    {
    }
    |
    TOK_EXPOSED
    {
    }
    |
    TOK_UNIQUE
    {
    }
    }
    |
    /*vacio*/
    {
    }
;

clase: clase_escalar
    {
        $$.tipo = $1.tipo;
    }
    |
    clase_vector
    {
    }
    |
    clase_objeto
    {
    }
;

declaracion_clase: modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' declaraciones funciones '}'
    {
    }
    |
    modificadores_clase TOK_CLASS TOK_IDENTIFICADOR inherits identificadores '{' funciones '}'
    {
    }
    |
    modificadores_clase TOK_CLASS TOK_IDENTIFICADOR '{' declaraciones funciones '}'
    {
    }
;

modificadores_clase: /*vacio*/
    {
    }
;

clase_escalar: tipo
    {
       $$.tipo = $1.tipo;
    }
;

tipo: TOK_INT
    {
        $$.tipo = ENTERO;
        tipo_declaracion = ENTERO;
    }
    |
    TOK_BOOLEAN
    {
        $$.tipo = BOOLEAN;
        tipo_declaracion = BOOLEAN;
    }
;

clase_objeto: '{' TOK_IDENTIFICADOR '}'
    {
    }
;

clase_vector: TOK_ARRAY tipo '[' constante_entera ']'
    {
    }
;

identificadores: TOK_IDENTIFICADOR
    {
    }
    |
    TOK_IDENTIFICADOR ',' identificadores
    {
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
    insertarTablaSimbolosAmbitos(tabla_main, "main", $1.lexema, ESCALAR, $1.tipo, $1.direcciones, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
}

funciones: funcion funciones
    {
    }
    |
    /*vacio*/
    {
    }
;

funcion: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR '(' parametros_funcion ')' '{' declaraciones_funcion sentencias '}'
    {
    }
;

tipo_retorno: TOK_NONE
    {
    }
    |
    tipo
    {
    }
    |
    clase_objeto
    {
    }
;

inherits: TOK_INHERITS
    {
    }
;

parametros_funcion: parametro_funcion resto_parametros_funcion
    {
    }
    |
    /*vacio*/
    {
    }
;

resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
    {
    }
    |
    /*vacio*/
    {
    }
;

parametro_funcion: tipo TOK_IDENTIFICADOR
    {
    }
    |
    clase_objeto TOK_IDENTIFICADOR
    {
    }
;

declaraciones_funcion: declaraciones
    {
    }
    |
    /*vacio*/
    {
    }
;

sentencias: sentencia
    {
    }
    |
    sentencia sentencias
    {
    }
;

sentencia: sentencia_simple ';'
    {
    }
    |
    bloque
    {
    }
;

sentencia_simple: asignacion
    {
    }
    |
    lectura
    {
    }
    |
    escritura
    {
    }
    |
    retorno_funcion
    {
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
    }
    |
    TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
    }
    |
    destruir_objeto
    {
    }
;

destruir_objeto: TOK_DISCARD TOK_IDENTIFICADOR
    {
    }
;

bloque: condicional
    {
    }
    |
    bucle
    {
    }
;

asignacion: TOK_IDENTIFICADOR '=' exp
    {
        //Buscamos en la tabla de simbolos el tipo de $1
        if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            $1.tipo = elem->tipo;
        }
        else {
            sprintf(msg, "Variable no encontrada\n");
        }

        if ($1.tipo != $3.tipo) {
          sprintf(msg, "Variables distintas\n");
        }

        char aux[50];
        if ($3.direcciones == 0) {
            sprintf(aux, "%d", $3.valor_entero);

        }
        asignar(fout, $1.lexema, $3.direcciones);
    }
    |
    elemento_vector '=' exp
    {
        if ($1.tipo != $3.tipo) {
            sprintf(msg, "tipos incompatibles");
        }
    }
    |
    elemento_vector '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
    }
    |
    TOK_IDENTIFICADOR '=' TOK_INSTANCE_OF TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR '=' exp
    {
    }
;

elemento_vector: TOK_IDENTIFICADOR '[' exp ']'
    {
        if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
            $1.tipo = elem->tipo;
            if (elem->clase != VECTOR) {
                sprintf(msg, "no es vector");
            }
            if ($3.tipo != ENTERO) {
                sprintf(msg, "el indice debe ser de tipo entero");
            }

            $$.tipo = elem->tipo;
            $$.direcciones = 1;
            //Comprobacion indice, 0<i<64
        }
        else {
            sprintf(msg, "Variable no encontrada\n");
        }
    }
;

condicional: if_exp_sentencias TOK_ELSE '{' sentencias '}'
    {
        ifthenelse_fin(fout, $1.etiqueta);
    }
;

if_exp_sentencias: if_exp sentencias '}'
    {
        $$.etiqueta = $1.etiqueta;

        ifthenelse_fin_then(fout, $1.etiqueta);
    }   
;

if_exp: TOK_IF '(' exp ')' '{'
    {
        if ($3.tipo != BOOLEAN) {
            sprintf(msg, "condicion del if no booleano");
        }
        $$.etiqueta = etiqueta;
        etiqueta++;

        ifthenelse_inicio(fout, $3.direcciones, $$.etiqueta);
    }
;

bucle: bucle_inicio sentencias '}'
    {
        while_fin(fout, $1.etiqueta);
    }
;

bucle_inicio: TOK_WHILE '(' exp ')' '{'
    {
        if ($3.tipo != BOOLEAN) {
            sprintf(msg, "condicion del if no booleano");
        }
        $$.etiqueta = etiqueta;
        etiqueta++;

        while_inicio(fout, $$.etiqueta);
        while_exp_pila(fout, $3.direcciones, $$.etiqueta);
    }
;

lectura: TOK_SCANF TOK_IDENTIFICADOR
    {
        if (buscarIdNoCualificado(NULL, tabla_main, $2.lexema, "main", &elem, nombre_ambito_encontrado) != OK) {
            sprintf(msg, "Elem no encontrado\n");
        } else {
            if (elem->categoria == FUNCION || elem->categoria == VECTOR) {
                sprintf(msg, "no se puede imprimir funciones ni vectores\n");
            }

            escribir_operando(fout, $2.lexema, $2.direcciones);
            leer(fout, $2.lexema, elem->tipo);
        }
    }
    |
    TOK_SCANF elemento_vector
    {
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
                sprintf(msg, "Elem no encontrado\n");
            }
        }
        else{
            escribir(fout, $2.direcciones, $2.tipo);
        }


    }
;

retorno_funcion: TOK_RETURN exp
    {
    }
    |
    TOK_RETURN TOK_NONE
    {
    }
;
  //8  +  x1
exp: exp '+' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La suma requiere que ambos operandos sean numeros");
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
            sprintf(msg, "La resta requiere que ambos operandos sean numeros");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '/' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        if ($3.tipo == 0) {
            sprintf(msg, "La division entre 0 no se permite");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '*' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La multiplicacion requiere que ambos operandos sean numeros");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    '-' %prec UNARIO exp
    {
        if ($2.tipo == BOOLEAN) {
            sprintf(msg, "El cambio de signo requiere operandos que sean numeros");
        }
        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp TOK_AND exp
    {
        if ($1.tipo == ENTERO || $3.tipo == ENTERO) {
            sprintf(msg, "La conjuncion requiere operandos que sean booleans");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_OR exp
    {
        if ($1.tipo == ENTERO || $3.tipo == ENTERO) {
            sprintf(msg, "La disyuncion requiere operandos que sean booleans");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    '!' exp
    {
        if ($2.tipo == ENTERO) {
            sprintf(msg, "La negacion requiere operandos que sean booleans");
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
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR '(' lista_expresiones ')'
    {
    }
    |
    identificador_clase '.' TOK_IDENTIFICADOR
    {
    }
;


identificador_clase: TOK_IDENTIFICADOR
    {
    }
    |
    TOK_ITSELF
    {
    }
;

lista_expresiones: exp resto_lista_expresiones
    {
    }
    |
    /*vacio*/
    {
    }
;

resto_lista_expresiones: ',' exp resto_lista_expresiones
    {
    }
    |
    /*vacio*/
    {
    }
;

comparacion: exp TOK_IGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
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
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_MENORIGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_MAYORIGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp '<' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, La division requiere que ambos operandos sean numeros");
        }
        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp '>' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            sprintf(msg, "La division requiere que ambos operandos sean numeros");
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
        fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    if (!flag_error)
    {
        fprintf(stderr, "****Error semantico en lin %d: %s\n", fila, msg);
    }
    flag_error = 0;
    return -1;
}
