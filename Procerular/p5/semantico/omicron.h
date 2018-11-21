#ifndef OMICRON_H
#define OMICRON_H

#include <stdio.h>
#include <string.h>

#define ENTERO 1
#define BOOLEAN 2

#define MAX_LONG_ID 50
#define MAX_LEN 100

typedef struct
{
    char lexema[MAX_LONG_ID+1]; /* nombre si identificador */
    int valor_entero; /* valor si numerico */
    int tipo; /* enteros o booleanos */
    int direcciones;
    int etiqueta;
} tipo_atributos;

#endif
