%{
#include <stdio.h>
#include "omicron.h"
#include "generacion_omicron.h"
#include "graph.h"
#include "tabla.h"

extern int columna;
extern int fila;
extern int yylex();
extern FILE *yyin;
extern FILE *fout;
extern int flag_error;

typedef struct {
    char nombre[MAX_LEN];
    char nombre_args[MAX_LEN][MAX_LEN];
    char nombre_var[MAX_LEN][MAX_LEN];
    int tipo_args[MAX_LEN];
    int tipo_var[MAX_LEN];
    int nargs;
    int tipo_retorno;
} Fcn;

int tipo_id_actual;
TablaAmbito * tabla_main;
elementoTablaSimbolos * elem;
char nombre_ambito_encontrado[MAX_NAME];
int tipo_declaracion;
int etiqueta = 1;
char aux[MAX_LEN+100];
char fname_aux[MAX_LEN];
int nargs;
char msg[MAX_LEN*2];
int i;
int nlocalvar;
int hay_return = 0;
int flag_lista_exp = 0;
int en_funcion = 0;
int error_semantico = 0;

Fcn fcn;
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
%type <atributos> tipo_retorno
%type <atributos> bucle
%type <atributos> bucle_inicio
%type <atributos> sentencia_simple
%type <atributos> bucle_medio

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
        printf("ERROR: No inicializada tabla de simbolos\n");
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

        if (en_funcion){
            strcpy(fcn.nombre_var[nlocalvar], $1.lexema);
            fcn.tipo_var[nlocalvar] = $1.tipo;
            nlocalvar++;
        }


    }
    |
    identificador ',' identificadores_declaracion
    {
        $$.tipo = $1.tipo;

        if (en_funcion){
            strcpy(fcn.nombre_var[nlocalvar], $1.lexema);
            fcn.tipo_var[nlocalvar] = $1.tipo;
            nlocalvar++;
        }
    }
;

identificador: TOK_IDENTIFICADOR
    {
        $$.direcciones = 1;
        $1.tipo = tipo_declaracion;
        $$.tipo = $1.tipo;

        if (en_funcion == 0) {
            declarar_variable(fout, $1.lexema, $1.tipo, 1);
            if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
               error_semantico = 1;
                yyerror("Declaracion duplicada");
            }        
            insertarTablaSimbolosAmbitos(tabla_main, "main", $1.lexema, ESCALAR, $1.tipo, $1.direcciones, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_NO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
        }
    }
;

funciones: funcion funciones
    {
    }
    |
    /*vacio*/
    {
        comienzo_sentencias(fout);
    }
;

funcion: fn_declaracion sentencias '}'
    {
        if (hay_return == 0) {
            error_semantico = 1;
            sprintf(msg, "Funcion %s sin sentencia de retorno.", fcn.nombre);
            yyerror(msg);
        }
        hay_return = 0;
        en_funcion = 0;

    }
;

fn_declaracion: fn_complete_name '{' declaraciones_funcion
    {
        /**Ensamblador*/
        declararFuncion(fout, fcn.nombre, nlocalvar);

        /* Bucle para insertar los argumentos de la funcion */
        for (i = 0; i < fcn.nargs; i++) {
            strcpy(aux, fcn.nombre);
            strcat(aux, "_");
            strcat(aux, fcn.nombre_args[i]);
            printf("introducimos el parametro %s en el ambito %s\n", aux, fcn.nombre);

            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) == OK) {
                error_semantico = 1;
                sprintf(msg, "Declaracion duplicada\n");
                yyerror(msg);
            }
            insertarTablaSimbolosAmbitos(tabla_main, "main", aux, FUNCION, fcn.tipo_args[i], PARAMETRO, 1, fcn.nargs, 0, 1, i, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
        
        }

        for (i = 0; i < nlocalvar; i++) {
            strcpy(aux, fcn.nombre);
            strcat(aux, "_");
            strcat(aux, fcn.nombre_var[i]);

            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) == OK) {
                error_semantico = 1;
                sprintf(msg, "Declaracion duplicada\n");
                yyerror(msg);
            }
            insertarTablaSimbolosAmbitos(tabla_main, "main", aux, FUNCION, fcn.tipo_var[i], VARIABLE, 1, 0, nlocalvar, i, 0, 1, 0, 0, 0, 0, NINGUNO, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);
            
        }
    }
;

fn_complete_name: fn_name '(' parametros_funcion ')'
    {
        for (i = 0; i < fcn.nargs; i++) {
            sprintf(aux, "@%d", fcn.tipo_args[i]);
            strcat(fcn.nombre, aux);
        }

        if (buscarIdNoCualificado(NULL, tabla_main, fname_aux, "main", &elem, nombre_ambito_encontrado) == OK) {
                error_semantico = 1;
                sprintf(msg, "Declaracion duplicada\n");
                yyerror(msg);
        }
        insertarTablaSimbolosAmbitos(tabla_main, "main", fcn.nombre, FUNCION, fcn.tipo_retorno, FUNCION, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, ACCESO_TODOS, MIEMBRO_UNICO, 0, 0, 0, 0, 0, 0, NULL);

        if (AbrirAmbitoPrefijos(tabla_main, "main", fcn.nombre, FUNCION, 0, fcn.tipo_retorno, 0, 1) == -1) {
                error_semantico = 1;
                sprintf(msg, "Acceso a funcion no declarada\n");
                yyerror(msg);
        }
        

        nlocalvar = 0;
    }
;

fn_name: TOK_FUNCTION modificadores_acceso tipo_retorno TOK_IDENTIFICADOR
    {
        en_funcion = 1;
        strcpy(fcn.nombre, $4.lexema);
        fcn.nargs = 0;
        fcn.tipo_retorno = $3.tipo;
    }
;



tipo_retorno: TOK_NONE
    {
    }
    |
    tipo
    {
        $$.tipo = $1.tipo;
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
        printf("precesamos argumento: %s (%d)\n", $2.lexema, fcn.nargs);
        strcpy(fcn.nombre_args[fcn.nargs], $2.lexema);
        printf("hago el strcpy bien\n");
        $2.tipo = $1.tipo;
        fcn.tipo_args[fcn.nargs] = $2.tipo;
        fcn.nargs++;
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
        flag_lista_exp = 0;

        strcat(fname_aux, $1.lexema);
        strcat(fname_aux, aux);

        if (buscarIdNoCualificado(NULL, tabla_main, fname_aux, "main", &elem, nombre_ambito_encontrado) != OK) {
            error_semantico = 1;
            sprintf(msg, "Acceso a funcion no declarada (<%s>).\n", $1.lexema);
            yyerror(msg);
        }
        if (elem->clase != FUNCION) {
            error_semantico = 1;
            sprintf(msg, "Acceso a funcion no declarada (<%s>).\n", $1.lexema);
            yyerror(msg);
        }
        if (elem->numero_parametros != nargs) {
            error_semantico = 1;
            sprintf(msg, "Numero incorrecto de parametros en llamada a funcion.\n");
            yyerror(msg);
        }

        llamarFuncion(fout, fname_aux, nargs);

        $$.tipo = elem->tipo;
        $$.direcciones = 0;
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

        if (en_funcion) {
            sprintf(aux, "%s_", fcn.nombre);
            strcat(aux, $1.lexema);
            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) == OK) {
                asignar_en_funcion(fout, $3.direcciones, elem->posicion_variable_local+1);
            }
            else {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada (<%s>).\n", $1.lexema);
                yyerror(msg);
            }
        }
        else {
            //Buscamos en la tabla de simbolos el tipo de $1
            if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                $1.tipo = elem->tipo;
            }
            else {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada (<%s>).\n", $1.lexema);
                yyerror(msg);
            }

            if ($1.tipo != $3.tipo) {
                error_semantico = 1;
                sprintf(msg, "Asignacion incompatible.\n");
                yyerror(msg);
            }

            if ($3.direcciones == 0) {
                sprintf(aux, "%d", $3.valor_entero);

            }
            asignar(fout, $1.lexema, $3.direcciones);
        }

    }
    |
    elemento_vector '=' exp
    {
        if ($1.tipo != $3.tipo) {
                error_semantico = 1;
                sprintf(msg, "Asignacion incompatible.\n");
                yyerror(msg);
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
                error_semantico = 1;
                sprintf(msg, "Intento de indexacion de una variable que no es de tipo vector.\n");
                yyerror(msg);
            }
            if ($3.tipo != ENTERO) {
                error_semantico = 1;
                sprintf(msg, "El indice en una operacion de indexacion tiene que ser de tipo entero.\n");
                yyerror(msg);
            }

            $$.tipo = elem->tipo;
            $$.direcciones = 1;
            //Comprobacion indice, 0<i<64
        }
        else {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada (<%s>).\n", $1.lexema);
                yyerror(msg);
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
            error_semantico = 1;
            sprintf(msg, "Condicional con condicion de tipo int.\n");
            yyerror(msg);
        }
        $$.etiqueta = etiqueta;
        etiqueta++;

        ifthenelse_inicio(fout, $3.direcciones, $$.etiqueta);
    }
;

bucle: bucle_medio sentencias '}'
    {
        while_fin(fout, $1.etiqueta);
    }
;

bucle_medio: bucle_inicio exp ')' '{'
    {
        if ($2.tipo != BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Bucle con condicion de tipo int.\n");
            yyerror(msg);
        }
        $$.etiqueta = $1.etiqueta;
        
        while_exp_pila(fout, $2.direcciones, $$.etiqueta);
    }
;

bucle_inicio: TOK_WHILE '('
    {
        while_inicio(fout, etiqueta);
        $$.etiqueta = etiqueta;
        etiqueta++;
    }

lectura: TOK_SCANF TOK_IDENTIFICADOR
    {
        if (en_funcion) {
            sprintf(aux, "%s_", fcn.nombre);
            strcat(aux, $1.lexema);
            if (buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) != OK) {
                sprintf(msg, "Varible local no encontrada\n");
                return -1;
            }
            escribirVariableLocal(fout, elem->posicion_variable_local+1);
            leer(fout, $2.lexema, elem->tipo);
        }
        else {
            if (buscarIdNoCualificado(NULL, tabla_main, $2.lexema, "main", &elem, nombre_ambito_encontrado) != OK) {
                sprintf(msg, "no encontrado\n");
                return -1;
            } else {
                if (elem->clase == FUNCION || elem->clase == VECTOR) {
                    sprintf(msg, "no se puede imprimir funciones ni vectores\n");
                    return -1;
                }

                escribir_operando(fout, $2.lexema, $2.direcciones);
                leer(fout, $2.lexema, elem->tipo);
            }
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
                //escribir_operando(fout, $2.lexema, $2.direcciones);
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
        if (en_funcion == 0) {
            error_semantico = 1;
            sprintf(msg, "Sentencia de retorno fuera del cuerpo de una función.\n");
            yyerror(msg);
        }
        retornarFuncion(fout, $2.direcciones);
        hay_return = 1;
    }
    |
    TOK_RETURN TOK_NONE
    {
    }
;

exp: exp '+' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        sumar(fout, $1.direcciones, $3.direcciones);

        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '-' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        restar(fout, $1.direcciones, $3.direcciones);

        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '/' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }
        
        dividir(fout, $1.direcciones, $3.direcciones);

        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp '*' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        multiplicar(fout, $1.direcciones, $3.direcciones);

        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    '-' %prec UNARIO exp
    {
        if ($2.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Operacion aritmetica con operandos boolean.\n");
            yyerror(msg);
        }

        cambiar_signo(fout, $2.direcciones);

        $$.tipo = ENTERO;
        $$.direcciones = 0;
    }
    |
    exp TOK_AND exp
    {

        if ($1.tipo == ENTERO || $3.tipo == ENTERO) {
            error_semantico = 1;
            sprintf(msg, "Operacion logica con operandos int.\n");
            yyerror(msg);
        }

        y(fout, $1.direcciones, $3.direcciones);

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_OR exp
    {
        if ($1.tipo == ENTERO || $3.tipo == ENTERO) {
            error_semantico = 1;
            sprintf(msg, "Operacion logica con operandos int.\n");
            yyerror(msg);
        }

        o(fout, $1.direcciones, $3.direcciones);

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    '!' exp
    {
        if ($2.tipo == ENTERO) {
            error_semantico = 1;
            sprintf(msg, "Operacion logica con operandos int.\n");
            yyerror(msg);
        }

        no(fout, $2.direcciones, etiqueta);
        etiqueta++;

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    TOK_IDENTIFICADOR
    {
        if (en_funcion) {
            sprintf(aux, "%s_", fcn.nombre);
            strcat(aux, $1.lexema);

            if(buscarParaDeclararIdTablaSimbolosAmbitos(tabla_main, aux, &elem, "main", nombre_ambito_encontrado) != OK) {
                error_semantico = 1;
                sprintf(msg, "Acceso a variable no declarada <%s>\n", $1.lexema);
                yyerror(msg);
            }
            printf("[[[ Encontramos %s en el ambito %s ]]]\n", aux, nombre_ambito_encontrado);

            if (elem->categoria == PARAMETRO) {
                escribirParametro(fout, elem->posicion_parametro, elem->numero_parametros);
            }
            else if (elem->categoria == VARIABLE) {
                escribirVariableLocal(fout, elem->posicion_variable_local+1);
            }

        } else {
            if (buscarIdNoCualificado(NULL, tabla_main, $1.lexema, "main", &elem, nombre_ambito_encontrado) == OK) {
                $1.tipo = elem->tipo;
            }
            else {
                printf("Error:Variable no encontrada (%s)\n", $1.lexema);
            }
            escribir_operando(fout, $1.lexema, 1);
            if (flag_lista_exp == 1) {
                operandoEnPilaAArgumento(fout, 1);
            }
        }

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
    TOK_IDENTIFICADOR '(' activar_flag_lista_exp lista_expresiones ')'
    {
        flag_lista_exp = 0;

        strcat(fname_aux, $1.lexema);
        strcat(fname_aux, aux);


        if (buscarIdNoCualificado(NULL, tabla_main, fname_aux, "main", &elem, nombre_ambito_encontrado) != OK) {
            error_semantico = 1;
            sprintf(msg, "Acceso a variable no declarada <%s>\n", $1.lexema);
            yyerror(msg);
        }
        if (elem->clase != FUNCION) {
            error_semantico = 1;
            sprintf(msg, "Acceso a variable no declarada <%s>\n", $1.lexema);
            yyerror(msg);
        }

        llamarFuncion(fout, fname_aux, nargs);

        $$.tipo = elem->tipo;
        $$.direcciones = 0;
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

activar_flag_lista_exp:
    {
        if (flag_lista_exp) {
                error_semantico = 1;
                sprintf(msg, "No esta permitido el uso de llamadas a funciones como parametros de otras\n");
                yyerror(msg);
        }
        flag_lista_exp = 1;
    }

identificador_clase: TOK_IDENTIFICADOR
    {
    }
    |
    TOK_ITSELF
    {
    }
;

lista_expresiones: intermedio exp resto_lista_expresiones
    {
        
        if ($2.tipo == ENTERO) {
            strcat(aux, "@1");
        } else {
            strcat(aux, "@3");
        }
    }
    |
    /*vacio*/
    {
        nargs = 0;
    }
;

intermedio: 
    {
        nargs = 1;
        aux[0] = '\0';
    }

resto_lista_expresiones: ',' exp resto_lista_expresiones
    {
        nargs++;
        if ($2.tipo == ENTERO) {
            strcat(aux, "@1");
        } else {
            strcat(aux, "@3");
        }
    }
    |
    /*vacio*/
    {
    }
;

comparacion: exp TOK_IGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
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
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        distinto(fout, $1.direcciones, $3.direcciones, etiqueta);
        etiqueta++;

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_MENORIGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        menor_igual(fout, $1.direcciones, $3.direcciones, etiqueta);
        etiqueta++;

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp TOK_MAYORIGUAL exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        mayor_igual(fout, $1.direcciones, $3.direcciones, etiqueta);
        etiqueta++;

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp '<' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        menor(fout, $1.direcciones, $3.direcciones, etiqueta);
        etiqueta++;

        $$.tipo = BOOLEAN;
        $$.direcciones = 0;
    }
    |
    exp '>' exp
    {
        if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN) {
            error_semantico = 1;
            sprintf(msg, "Comparacion con datos boolean.\n");
            yyerror(msg);
        }

        mayor(fout, $1.direcciones, $3.direcciones, etiqueta);
        etiqueta++;

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
    if (!flag_error && error_semantico == 0)
    {
        fprintf(stderr, "ERROR SINTÁCTICO:%d:%d\n", fila, columna);
    }
    if (error_semantico)
    {
        fprintf(stderr, "****Error semantico en lin %d: %s\n", fila, s);
    }
    flag_error = 0;
    error_semantico = 0;
    return -1;
}
